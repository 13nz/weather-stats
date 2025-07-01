# Weather Data

A command-line application for visualizing historical weather trends and predicting future temperatures using Unicode candlestick charts and linear regression.

<img width="913" alt="image" src="https://github.com/user-attachments/assets/310cb7dc-df38-4723-8f24-9e9d7a530ac7" />


## Features

- 📈 **Candlestick Charts**: Visualizes annual temperature trends using Unicode-based candlestick plots.
- 🔍 **Filtering**: View temperature trends for a specific year range and country.
- 🧠 **Prediction**: Uses linear regression to forecast future temperatures.
- 🌍 **Country-Specific Analysis**: Reads temperature data for a given country code from a CSV file.

## Technologies

- **Language:** C++
- **Standard:** C++17
- **I/O:** Terminal-based interaction
- **Dependencies:** None outside of the standard library

<img width="373" alt="image" src="https://github.com/user-attachments/assets/72ae368d-6762-4efc-b352-9153209ebd3b" />


## How to Use

### 1. Compile

```bash
g++ -std=c++17 main.cpp Candlestick.cpp CSVReader.cpp Plotter.cpp Predictor.cpp WeatherData.cpp -o candlesticks
```

### 2. Run

```bash
./candlesticks
```

### 3. Example Flow

- Enter a country code (e.g., `GR`, `ES`, `FR`)
- Enter a start and end year (range: 1980–2019)
- View the generated candlestick chart and 5-year temperature prediction

## Requirements

- A valid CSV file named `weather_data.csv` in the same directory.
- The CSV should include a header with temperature columns like `GR_temperature`, `ES_temperature`, etc.

## Sample CSV Header Format

```
timestamp,GR_temperature,ES_temperature,FR_temperature
1980-01-01,14.2,15.3,10.4
1980-02-01,13.8,15.1,9.7
...
```

## Output Preview

- Unicode-based graphs are printed directly in the terminal
- Candlestick visuals use box-drawing characters for clarity
- Temperature predictions appear as colored asterisks on a timeline

## Author

Built by Lena  
🗓️ Created: June 2025
