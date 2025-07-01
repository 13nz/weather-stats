// Predictor.h
// Created by Lena on 02/06/2025.
//

#ifndef PREDICTOR_H
#define PREDICTOR_H



#pragma once
#include <map>

#include "Candlestick.h"
#include <vector>

// ----- CODE WRITTEN BY ME START -----

class Predictor {
public:
    // multiple year linear regression prediciton function
    std::map<int, double> predictFutureTemperatures(const std::vector<Candlestick>& candles, int numYears);
};

// ----- CODE WRITTEN BY ME END -----

#endif //PREDICTOR_H
