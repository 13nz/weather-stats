// Plotter.cpp
// Created by Lena on 02/06/2025.
//

#include "Plotter.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>

// ----- CODE WRITTEN BY ME START -----


// Plots candlestick graph
void Plotter::plotCandlesticksUnicode(const std::vector<Candlestick>& candles) {
    // check for empty data
    if (candles.empty()) return;

    // title
    std::cout << "=========================" << std::endl;
    std::cout << "Candlestick data: " << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // determine min & max temperatures
    double minTemp = candles.front().getLow();
    double maxTemp = candles.front().getHigh();
    for (const Candlestick& c : candles) {
        minTemp = std::min(minTemp, c.getLow());
        maxTemp = std::max(maxTemp, c.getHigh());
    }

    // graph parameters
    const int graphHeight = 25; // number of rows in vertical plot
    const int spacing = 5; // spacing between candlesticks
    const double scale = (maxTemp - minTemp) / (graphHeight - 2); // temperature units per row

    // create empty 2D grid
    // wstring: wide character string type
    // L prefix: wide character literal.
    std::vector<std::wstring> grid(graphHeight + 1, std::wstring(candles.size() * spacing, L' '));

    // loop thru candlesticks & draw
    for (size_t i = 0; i < candles.size(); ++i) {
        const Candlestick& c = candles[i];
        // calculate vertical positions for each candlestick
        int col = static_cast<int>(i * spacing + spacing / 2);

        // convert temperatures to row positions
        // round double and convert to int (avoid errors)
        int highRow = graphHeight - static_cast<int>(std::round((c.getHigh() - minTemp) / scale));
        int lowRow = graphHeight - static_cast<int>(std::round((c.getLow() - minTemp) / scale));
        int openRow = graphHeight - static_cast<int>(std::round((c.getOpen() - minTemp) / scale));
        int closeRow = graphHeight - static_cast<int>(std::round((c.getClose() - minTemp) / scale));

        // shift rows to make space for top bar
        highRow++;
        lowRow++;
        openRow++;
        closeRow++;

        int top = std::min(openRow, closeRow); // top of candle
        int bot = std::max(openRow, closeRow); // bottom of candle

        // line above top bar
        for (int row = highRow; row < top - 1; ++row) {
            grid[row][col] = L'│';
        }

        // top bar (unicode to get perfect corners)
        grid[top - 1][col - 1] = L'┌';
        grid[top - 1][col]     = L'─';
        grid[top - 1][col + 1] = L'┐';

        // candle sides
        for (int row = top; row < bot; ++row) {
            grid[row][col - 1] = L'│';
            grid[row][col]     = L' ';
            grid[row][col + 1] = L'│';
        }

        // bottom bar with corners
        grid[bot][col - 1] = L'└';
        grid[bot][col]     = L'─';
        grid[bot][col + 1] = L'┘';

        // line below box
        for (int row = bot + 1; row <= lowRow; ++row) {
            grid[row][col] = L'│';
        }
    }

    // print graph row by row
    for (int row = 1; row <= graphHeight; ++row) {
        double label = maxTemp - (row - 1) * scale;
        // temperature labels
        std::wcout << std::setw(5) << std::fixed << std::setprecision(1) << label << L" ┤ ";

        // assign colors
        for (size_t i = 0; i < candles.size(); ++i) {
            int colStart = i * spacing;
            // use mod to get index that will be in colors array
            std::string color = colors[i % colors.size()];

            for (int col = colStart; col < colStart + spacing; ++col) {
                wchar_t ch = grid[row][col];
                // make sure graph characters
                if (ch == L'│' || ch == L'─' || ch == L'┌' || ch == L'┐' || ch == L'└' || ch == L'┘') {
                    std::cout << color;
                    std::wcout << ch;
                    std::cout << RESET; // reset color after printing
                } else {
                    std::wcout << ch; // print default white
                }
            }
        }

        std::wcout << std::endl;
    }

    // X-axis
    std::wcout << L"      └" << std::wstring(candles.size() * spacing, L'─') << std::endl;
    std::wcout << L"       ";

    // print year labels (last 2 digits for space)
    for (size_t i = 0; i < candles.size(); ++i) {
        std::string date = candles[i].getDate();
        // extract last 2 digits as wide string (positions 2 & 3)
        // "??" as fallback
        std::wstring yr = (date.length() >= 4)
            ? std::wstring(date.begin() + 2, date.begin() + 4)
            : L"??";
        std::wcout << std::setw(spacing) << yr;
    }
    std::wcout << std::endl;
}

// plots predicted temperature data based on historical data
void Plotter::plotPredictions(const std::map<int, double>& predictions) {
    // exit if no data
    if (predictions.empty()) {
        std::cout << "No prediction data to plot." << std::endl;
        return;
    }

    // title
    std::cout << "=========================" << std::endl;
    std::cout << "Predictions: " << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;

    // find min and max temperature values
    double minTemp = predictions.begin()->second;
    double maxTemp = predictions.begin()->second;

    for (const std::pair<int, double>& entry : predictions) {
        minTemp = std::min(minTemp, entry.second);
        maxTemp = std::max(maxTemp, entry.second);
    }

    const int graphHeight = 10;
    const int spacing = 5; // horizontal space
    const double scale = (maxTemp - minTemp) / (graphHeight - 1);

    // create 2d grid
    std::vector<std::string> grid(graphHeight + 1, std::string(predictions.size() * spacing, ' '));

    size_t i = 0;
    // loop through predictions
    for (const std::pair<int, double>& entry : predictions) {
        int col = static_cast<int>(i * spacing + spacing / 2);
        // vertical position relative to y axis
        int row = graphHeight - static_cast<int>((entry.second - minTemp) / scale);
        // convert to row index & clamp temp
        row = std::clamp(row, 0, graphHeight);
        // plot * at correct column and move to next
        grid[row][col] = '*';
        ++i;
    }

    // track used temp labels to avoid duplicates
    // set doesn't allow duplicate values
    std::set<double> printedLabels;

    // for each row calcuate & round temp label
    for (int row = 0; row <= graphHeight; ++row) {
        double rawLabel = maxTemp - row * scale;
        double roundedLabel = std::round(rawLabel * 10.0) / 10.0;

        std::cout << std::setw(5); //minimum width of the next field to print
        // if not printed, print and mark
        if (printedLabels.count(roundedLabel) == 0) {
            std::cout << std::fixed << std::setprecision(1) << roundedLabel; // how many digits to show after the decimal point
            printedLabels.insert(roundedLabel);
        } else {
            std::cout << "     "; // blank space instead of duplicate
        }

        // prints default white asterisks
        //std::cout << " ┤ " << grid[row] << std::endl;

        std::cout << " ┤ ";

        size_t colIndex = 0;
        // prints color asterisks, depending on index
        for (const std::pair<const int, double>& entry : predictions) {
            int currentRow = graphHeight - static_cast<int>((entry.second - minTemp) / scale);
            currentRow = std::clamp(currentRow, 0, graphHeight);

            if (row == currentRow) {
                // use mod size to get index in bounds
                int colorIndex = colIndex % colors.size();
                std::cout << std::setw(spacing - 1) << "" << colors[colorIndex] << "*" << RESET; // reset color after print
            } else {
                std::cout << std::setw(spacing) << " ";
            }

            // increase colors index
            ++colIndex;
        }
        std::cout << std::endl;

    }

    // x axis
    std::cout << "      └" << std::string(predictions.size() * spacing, '-') << std::endl;
    std::cout << "       ";

    // year labels
    i = 0;
    for (const std::pair<int, double>& entry : predictions) {
        std::string yr = std::to_string(entry.first).substr(2, 2);
        std::cout << std::setw(spacing) << yr;
        ++i;
    }
    std::cout << " " << std::endl;
}





// NOT USED
// ASCII implementation: simpler solution but bad looking graph
void Plotter::plotCandlesticksASCII(const std::vector<Candlestick>& candles) {
    if (candles.empty()) return;

    double minTemp = candles.front().getLow();
    double maxTemp = candles.front().getHigh();
    for (const Candlestick& c : candles) {
        minTemp = std::min(minTemp, c.getLow());
        maxTemp = std::max(maxTemp, c.getHigh());
    }

    const int graphHeight = 20;
    const int spacing = 5;
    const double scale = (maxTemp - minTemp) / (graphHeight - 2);  // leave room for top bar

    std::vector<std::string> grid(graphHeight + 1, std::string(candles.size() * spacing, ' '));

    for (size_t i = 0; i < candles.size(); ++i) {
        const Candlestick& c = candles[i];
        int col = static_cast<int>(i * spacing + spacing / 2);

        int highRow = graphHeight - static_cast<int>(std::round((c.getHigh() - minTemp) / scale));
        int lowRow = graphHeight - static_cast<int>(std::round((c.getLow() - minTemp) / scale));
        int openRow = graphHeight - static_cast<int>(std::round((c.getOpen() - minTemp) / scale));
        int closeRow = graphHeight - static_cast<int>(std::round((c.getClose() - minTemp) / scale));

        highRow++;
        lowRow++;
        openRow++;
        closeRow++;

        int top = std::min(openRow, closeRow);
        int bot = std::max(openRow, closeRow);

        // line above top bar
        for (int row = highRow; row < top - 1; ++row) {
            grid[row][col] = '|';
        }

        // top bar
        grid[top - 1][col - 1] = '_';
        grid[top - 1][col]     = '_';
        grid[top - 1][col + 1] = '_';

        // sides
        for (int row = top; row < bot; ++row) {
            grid[row][col - 1] = '|';
            grid[row][col]     = ' ';
            grid[row][col + 1] = '|';
        }

        // bottom bar
        grid[bot][col - 1] = '|';
        grid[bot][col]     = '_';
        grid[bot][col + 1] = '|';

        // line below box
        for (int row = bot + 1; row <= lowRow; ++row) {
            grid[row][col] = '|';
        }
    }

    for (int row = 1; row <= graphHeight; ++row) {
        double label = maxTemp - (row - 1) * scale;
        std::cout << std::setw(5) << std::fixed << std::setprecision(1) << label << " ┤ ";
        std::cout << grid[row] << std::endl;
    }

    std::cout << "      └" << std::string(candles.size() * spacing, '-') << std::endl;
    std::cout << "       ";
    for (size_t i = 0; i < candles.size(); ++i) {
        std::string yr = candles[i].getDate().substr(2, 2);
        std::cout << std::setw(spacing) << yr;
    }
    std::cout << std::endl;
}


// ----- CODE WRITTEN BY ME END -----
