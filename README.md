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
utc_timestamp,AT_temperature,AT_radiation_direct_horizontal,AT_radiation_diffuse_horizontal,BE_temperature,BE_radiation_direct_horizontal,BE_radiation_diffuse_horizontal,BG_temperature,BG_radiation_direct_horizontal,BG_radiation_diffuse_horizontal,CH_temperature,CH_radiation_direct_horizontal,CH_radiation_diffuse_horizontal,CZ_temperature,CZ_radiation_direct_horizontal,CZ_radiation_diffuse_horizontal,DE_temperature,DE_radiation_direct_horizontal,DE_radiation_diffuse_horizontal,DK_temperature,DK_radiation_direct_horizontal,DK_radiation_diffuse_horizontal,EE_temperature,EE_radiation_direct_horizontal,EE_radiation_diffuse_horizontal,ES_temperature,ES_radiation_direct_horizontal,ES_radiation_diffuse_horizontal,FI_temperature,FI_radiation_direct_horizontal,FI_radiation_diffuse_horizontal,FR_temperature,FR_radiation_direct_horizontal,FR_radiation_diffuse_horizontal,GB_temperature,GB_radiation_direct_horizontal,GB_radiation_diffuse_horizontal,GR_temperature,GR_radiation_direct_horizontal,GR_radiation_diffuse_horizontal,HR_temperature,HR_radiation_direct_horizontal,HR_radiation_diffuse_horizontal,HU_temperature,HU_radiation_direct_horizontal,HU_radiation_diffuse_horizontal,IE_temperature,IE_radiation_direct_horizontal,IE_radiation_diffuse_horizontal,IT_temperature,IT_radiation_direct_horizontal,IT_radiation_diffuse_horizontal,LT_temperature,LT_radiation_direct_horizontal,LT_radiation_diffuse_horizontal,LU_temperature,LU_radiation_direct_horizontal,LU_radiation_diffuse_horizontal,LV_temperature,LV_radiation_direct_horizontal,LV_radiation_diffuse_horizontal,NL_temperature,NL_radiation_direct_horizontal,NL_radiation_diffuse_horizontal,NO_temperature,NO_radiation_direct_horizontal,NO_radiation_diffuse_horizontal,PL_temperature,PL_radiation_direct_horizontal,PL_radiation_diffuse_horizontal,PT_temperature,PT_radiation_direct_horizontal,PT_radiation_diffuse_horizontal,RO_temperature,RO_radiation_direct_horizontal,RO_radiation_diffuse_horizontal,SE_temperature,SE_radiation_direct_horizontal,SE_radiation_diffuse_horizontal,SI_temperature,SI_radiation_direct_horizontal,SI_radiation_diffuse_horizontal,SK_temperature,SK_radiation_direct_horizontal,SK_radiation_diffuse_horizontal
1980-01-01T00:00:00Z,-3.6400,0.0000,0.0000,-0.7200,0.0000,0.0000,4.6640,0.0000,0.0000,-6.2870,0.0000,0.0000,-3.4220,0.0000,0.0000,-1.2610,0.0000,0.0000,-1.8700,0.0000,0.0000,-7.0600,0.0000,0.0000,8.0660,0.0000,0.0000,-6.2540,0.0000,0.0000,-0.5370,0.0000,0.0000,-1.2490,0.0000,0.0000,9.9120,0.0000,0.0000,-0.8800,0.0000,0.0000,-3.0210,0.0000,0.0000,1.2920,0.0000,0.0000,0.3010,0.0000,0.0000,-6.5410,0.0000,0.0000,-5.1500,0.0000,0.0000,-7.1660,0.0000,0.0000,2.3820,0.0000,0.0000,-7.0380,0.0000,0.0000,-3.7210,0.0000,0.0000,12.8620,0.0000,0.0000,-0.0310,0.0000,0.0000,-3.9450,0.0000,0.0000,-3.0550,0.0000,0.0000,-4.6480,0.0000,0.0000
...
```

## Output Preview

- Unicode-based graphs are printed directly in the terminal
- Candlestick visuals use box-drawing characters for clarity
- Temperature predictions appear as colored asterisks on a timeline

## Author

Built by Lena  
🗓️ Created: June 2025
