// CSVReader.h
// Created by Lena on 02/06/2025.
//

#pragma once
#include <string>
#include <vector>

// ----- CODE WRITTEN BY ME START -----

// TempRecord struct for storing year and temperature values
struct TempRecord {
    std::string timestamp;
    double value;
};

class CSVReader {
public:
    // CSVReader constructor
    CSVReader(const std::string& path);
    // vector for country temps
    std::vector<TempRecord> readDataForCountry(const std::string& countryCode);

private:
    std::string filepath;
    std::vector<std::string> tokenize(const std::string& line, char delimiter);
    TempRecord parseLine(const std::string& line, int countryIndex);
};

// ----- CODE WRITTEN BY ME END -----
