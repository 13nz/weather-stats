// WeatherData.h
// Created by Lena on 02/06/2025.
//

#ifndef WEATHERDATA_H
#define WEATHERDATA_H



#pragma once
#include "Candlestick.h"
#include "CSVReader.h"
#include <vector>
#include <map>

// ----- CODE WRITTEN BY ME START -----

class WeatherData {
public:
    // function to load records
    void load(const std::vector<TempRecord>& records);
    // gets all candlestick data
    std::vector<Candlestick> getCandlestickData() const;
    // filters candlestick data
    std::vector<Candlestick> filterByYearRange(int startYear, int endYear) const;

private:
    // map of yearly data
    std::map<int, std::vector<double>> yearlyData;
    // vector of candlesticks
    std::vector<Candlestick> candlesticks;
};

// ----- CODE WRITTEN BY ME END -----

#endif //WEATHERDATA_H
