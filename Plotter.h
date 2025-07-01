// Plotter.h
// Created by Lena on 02/06/2025.
//

#ifndef PLOTTER_H
#define PLOTTER_H



#pragma once
#include <map>

#include "Candlestick.h"
#include <vector>

// ----- CODE WRITTEN BY ME START -----

class Plotter {
public:
    // NOT USED - function to plot using only ASCII characters
    void plotCandlesticksASCII(const std::vector<Candlestick>& candles);
    // function to plot cabndlesticks using Unicode
    void plotCandlesticksUnicode(const std::vector<Candlestick>& candles);

    // prediction plotting
    void plotPredictions(const std::map<int, double>& predictions);

    // color consts
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string CYAN    = "\033[36m";
    const std::string MAGENTA = "\033[35m";
    const std::string PURPLE  = "\033[95m";
    // reset color
    const std::string RESET   = "\033[0m";

    // color vector
    std::vector<std::string> colors = { RED, GREEN, YELLOW, CYAN, MAGENTA, PURPLE };
};

// ----- CODE WRITTEN BY ME END -----

#endif //PLOTTER_H
