//Candlestick.h
// Created by Lena on 02/06/2025.
//

#ifndef CANDLESTICK_H
#define CANDLESTICK_H

// ----- CODE WRITTEN BY ME START -----

#pragma once
#include <string>

// Candlestick class
class Candlestick {
private:
    std::string date;
    double open;
    double high;
    double low;
    double close;

public:
    // constructor
    Candlestick(const std::string& date, double open, double high, double low, double close);

    // getters
    std::string getDate() const;
    double getOpen() const;
    double getHigh() const;
    double getLow() const;
    double getClose() const;
};

// ----- CODE WRITTEN BY ME END -----

#endif //CANDLESTICK_H
