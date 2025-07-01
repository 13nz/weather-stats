// main.cpp
// Created by Lena on 02/06/2025.
//

#include <iostream>
#include "CSVReader.h"
#include "WeatherData.h"
#include "Candlestick.h"
#include "Plotter.h"
#include "Predictor.h"

// ----- CODE WRITTEN BY ME START -----

int main() {
    // title in ASCII art
    std::cout << "   ______                ____          __  _      __       \n";
    std::cout << "  / ____/___ _____  ____/ / /__  _____/ /_(_)____/ /_______\n";
    std::cout << " / /   / __ `/ __ \\/ __  / / _ \\/ ___/ __/ / ___/ //_/ ___/\n";
    std::cout << "/ /___/ /_/ / / / / /_/ / /  __(__  ) /_/ / /__/ ,< (__  ) \n";
    std::cout << "\\____/\\__,_/_/ /_/\\__,_/_/\\___/____/\\__/_/\\___/_/|_/____/  \n";
    std::cout << "                                                           \n";
    std::cout << "                                                           \n";
    std::cout << "                                                           \n";


    std::wcout.imbue(std::locale("")); // enable Unicode output for graph

    // prompt the user to input country code and year range
    std::string countryCode;
    int startYear, endYear;

    std::cout << "Enter country code (e.g. GR, ES, FR...): ";
    std::cin >> countryCode;

    // convert to uppercase
    std::transform(countryCode.begin(), countryCode.end(), countryCode.begin(), ::toupper);

    std::cout << "Enter start year (1980 - 2019): ";
    std::cin >> startYear;

    std::cout << "Enter end year (1980 - 2019): ";
    std::cin >> endYear;


    // load csv data
    CSVReader reader("weather_data.csv");
    // process csv
    std::vector<TempRecord> rawData = reader.readDataForCountry(countryCode);

    // initialize weather data
    WeatherData weatherData;
    // load weather data
    weatherData.load(rawData);

    // get candlesticks
    std::vector<Candlestick> candles = weatherData.getCandlestickData();
    // filter by year range
    std::vector<Candlestick>  filtered = weatherData.filterByYearRange(startYear, endYear);

    Plotter plotter;

    std::cout << " " << std::endl;
    plotter.plotCandlesticksUnicode(filtered);
    std::cout << " " << std::endl;

    // predict future temperatures (5 years after last data)
    Predictor predictor;
    std::map<int, double> predictions = predictor.predictFutureTemperatures(candles, 5);

    plotter.plotPredictions(predictions);

    return 0;
}

// build with: g++
// g++ -std=c++17 main.cpp Candlestick.cpp CSVReader.cpp Plotter.cpp Predictor.cpp WeatherData.cpp -o candlesticks

// run with:
// ./candlesticks

// ----- CODE WRITTEN BY ME END -----