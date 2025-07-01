// CSVReader.cpp
// Created by Lena on 02/06/2025.
//

#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// ----- CODE WRITTEN BY ME START -----

// constructor
CSVReader::CSVReader(const std::string& path) : filepath(path) {}

// Reads data for country using country code and stores in TempRecord vector
// returns vector of TempRecord (year & temp)
std::vector<TempRecord> CSVReader::readDataForCountry(const std::string& countryCode) {
    std::vector<TempRecord> records;
    std::ifstream file(filepath);
    std::string line, header;

    // error handling for bad file
    if (!file.is_open()) {
        std::cerr << "CSVReader::readDataForCountry - Failed to open file: " << filepath << std::endl;
        return records;
    }

    // parse header
    std::getline(file, header);
    std::vector<std::string> columns = tokenize(header, ',');

    // get correct header names for csv data
    std::string targetColumn = countryCode + "_temperature";
    int countryIndex = -1;

    for (size_t i = 0; i < columns.size(); ++i) {
        if (columns[i] == targetColumn) {
            countryIndex = static_cast<int>(i); // type check
            break;
        }
    }

    // error handlong for invalid country code
    if (countryIndex == -1) {
        std::cerr << "CSVReader::readDataForCountry - Country code not found in header: " << countryCode << std::endl;
        return records;
    }

    // loop & add data to vector
    while (std::getline(file, line)) {
        try {
            TempRecord record = parseLine(line, countryIndex);
            records.push_back(record);
        } catch (const std::exception& e) {
            // skip bad line
            continue;
        }
    }

    //std::cout << "CSVReader::readDataForCountry - Read " << records.size() << " records for country: " << countryCode << std::endl;
    // return found records
    return records;
}

// tokenize function to split cvs by line
// returns vector of strings (lines)
std::vector<std::string> CSVReader::tokenize(const std::string& line, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(line);

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

// get values for each line
// returns one temp record
TempRecord CSVReader::parseLine(const std::string& line, int countryIndex) {
    std::vector<std::string> tokens = tokenize(line, ',');

    // error handling for wrong values
    if (tokens.size() <= countryIndex) {
        throw std::runtime_error("CSVReader::parseLine - Not enough tokens in line.");
    }

    const std::string& timestamp = tokens[0];
    double temp = std::stod(tokens[countryIndex]);

    return TempRecord{ timestamp, temp };
}

// ----- CODE WRITTEN BY ME END -----
