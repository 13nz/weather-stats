// WeatherData.cpp
// Created by Lena on 02/06/2025.
//

#include "WeatherData.h"
#include <sstream>
#include <iomanip>
#include <numeric> // for std::accumulate (calc averages)
#include <algorithm> // for std::max_element & std::min_element

// ----- CODE WRITTEN BY ME START -----

// load vector of TempRecord structs extracted by CSVReader with temperature data
// computes needed values and initializes candlestick objects using them
void WeatherData::load(const std::vector<TempRecord>& records) {
    // clear any existing data
    yearlyData.clear();
    // group records by year
    for (const TempRecord& rec : records) {
        std::istringstream ss(rec.timestamp);
        std::string yearStr;
        // split timestamp to get year
        std::getline(ss, yearStr, '-');
        int year = std::stoi(yearStr);
        yearlyData[year].push_back(rec.value);
    }

    // clear any candlestick data
    candlesticks.clear();
    double prevAvg = 0;
    // loop & compute candlestick data
    for (auto it = yearlyData.begin(); it != yearlyData.end(); ++it) {
        int year = it->first;
        const std::vector<double>& temps = it->second;
        if (temps.empty()) continue;

        // stats for each year
        double avg = std::accumulate(temps.begin(), temps.end(), 0.0) / temps.size();
        double high = *std::max_element(temps.begin(), temps.end());
        double low = *std::min_element(temps.begin(), temps.end());

        // initialize candlestick
        Candlestick c(std::to_string(year) + "-01-01", prevAvg, high, low, avg);
        candlesticks.push_back(c);

        // save previous average for next loop
        prevAvg = avg;
    }
}

// returns vector of Candlesticks (candlestick data)
std::vector<Candlestick> WeatherData::getCandlestickData() const {
    return candlesticks;
}

// filter data by year range
// returns vector of Candlestick
std::vector<Candlestick> WeatherData::filterByYearRange(int startYear, int endYear) const {
    std::vector<Candlestick> result;
    for (const Candlestick& c : candlesticks) {
        int year = std::stoi(c.getDate().substr(0, 4));
        if (year >= startYear && year <= endYear) {
            result.push_back(c);
        }
    }
    return result;
}

// ----- CODE WRITTEN BY ME END -----