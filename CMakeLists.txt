cmake_minimum_required(VERSION 3.30)
project(midterm)

set(CMAKE_CXX_STANDARD 17)

add_executable(midterm main.cpp
        CSVReader.cpp
        CSVReader.h
        Candlestick.cpp
        Candlestick.h
        Plotter.cpp
        Plotter.h
        Predictor.cpp
        Predictor.h
        WeatherData.cpp
        WeatherData.h)
