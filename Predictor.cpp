// Predictor.cpp
// Created by Lena on 02/06/2025.
//

#include "Predictor.h"

#include <map>
#include <numeric>

// ----- CODE WRITTEN BY ME START -----

// linear regression implementation
// multiple years linear regression prediction
// returns a map of year & temperature
std::map<int, double> Predictor::predictFutureTemperatures(const std::vector<Candlestick>& candles, int numYears) {
    std::map<int, double> predictions;

    int n = candles.size();
    if (n == 0 || numYears <= 0) return predictions;


    // init vectors
    // length n
    std::vector<double> x(n); // years
    std::vector<double> y(n); // close temps

    // loop through candlestick data
    for (int i = 0; i < n; ++i) {
        // get years
        x[i] = std::stod(candles[i].getDate().substr(0, 4));
        // get close temperature
        y[i] = candles[i].getClose();
    }

    // calculate mean average
    double x_mean = std::accumulate(x.begin(), x.end(), 0.0) / n;
    double y_mean = std::accumulate(y.begin(), y.end(), 0.0) / n;


    //equation
    // y = mx + b

    double numerator = 0;
    double denominator = 0;
    // compute data needed for slope
    // m = numerator / denominator
    // numerator: sum (n) of (xi - x_mean)*(yi - y_mean)
    // denominator: sum (n) of (xi - x_mean)^2
    for (int i = 0; i < n; ++i) {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += (x[i] - x_mean) * (x[i] - x_mean);
    }


    double m = numerator / denominator; // slope
    double b = y_mean - m * x_mean; // intercept b = y - mx

    // get last year in data
    int lastYear = static_cast<int>(x.back()); // back: last element
    // from 1 to number of years to calculate
    for (int i = 1; i <= numYears; ++i) {
        int futureYear = lastYear + i;
        // predict year using regressoin equation
        predictions[futureYear] = m * futureYear + b;
    }

    return predictions;
}

// ----- CODE WRITTEN BY ME END -----

