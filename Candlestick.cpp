//Candlestick.cpp
// Created by Lena on 02/06/2025.
//


// ----- CODE WRITTEN BY ME START -----
#include "Candlestick.h"
#include <iostream>

// Candlestick class constructor
Candlestick::Candlestick(const std::string& date, double open, double high, double low, double close)
    : date(date), open(open), high(high), low(low), close(close) {}



// getters for private members
std::string Candlestick::getDate() const {
    return date;
}

double Candlestick::getOpen() const {
    return open;
}

double Candlestick::getHigh() const {
    return high;
}

double Candlestick::getLow() const {
    return low;
}

double Candlestick::getClose() const {
    return close;
}

// ----- CODE WRITTEN BY ME END -----