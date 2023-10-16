# Financial Data Analysis and EDA using the Federal Reserve Economic Data (FRED) API

Financial Data Analysis is a Python project that allows you to fetch, analyze, and visualize financial data from the FRED API. This project provides tools for exploring and understanding the dynamics of financial markets.

## Features

- Fetch financial data from FRED using an API key.
- Calculate percentage changes and analyze trends over time.
- Visualize financial data using Matplotlib.
- Export the analyzed data to an Excel file.
- Detailed exploratory data analysis (EDA) with summary statistics.

## Getting Started

### Prerequisites
- **Python**: Python 3.x is recommended. You can download it from [Python's official website](https://www.python.org/downloads/).
- **FRED API Key**: A valid FRED API Key is required to fetch financial data. You need to copy your API Key into the `main_pythonfile.py` file.
- **Folder Path for XLSX Files**: To create XLSX files, you must specify a folder path in the `main_pythonfile.py` file. Modify the `folder_path` variable (line 37) to the directory where you want the XLSX files to be saved.
   ```python
   folder_path = r''  # Specify the path where the XLSX file should be stored
- Required Python packages:
  - `pandas`
  - `matplotlib`
  - `fredapi`
 
### Installation
- Clone this repository
  
