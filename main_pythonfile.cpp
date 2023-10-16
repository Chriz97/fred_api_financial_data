from fredapi import Fred
import matplotlib.pyplot as plt
import pandas as pd
from datetime import datetime
pd.set_option('display.max_columns', None)

# Code to fetch the SP500 data

fred_key = "XXX" # Paste you API Key here

fred = Fred(fred_key)

# Assuming you have already fetched the SP500 data using `fred.get_series("SP500")`
sp500 = fred.get_series("SP500")

# Retrieve the Dow Jones Industrial Average (DJIA) data from FRED and assign it to the variable 'dow_jones'
dow_jones = fred.get_series("DJIA")

# Retrieve the Volatility Index (VIX) data from FRED and assign it to the variable 'vix'
vix = fred.get_series("VIXCLS")

# Constructing a DataFrame for EDA and generating a XLSX File to store the date
df = pd.DataFrame(sp500, columns=["SP500"])
# Calculate percentage changes and add a new column 'SP500_PctChange'. Same for the following columns DOW and VIX
df['SP500_PctChange'] = df['SP500'].pct_change() * 100
df["Dow Jones"] = dow_jones
df["DOW_PctChange"] = df["Dow Jones"].pct_change() * 100
df["VIX"] = vix
df["VIX_PctChange"] = df["VIX"].pct_change() * 100

# Get the current date and time
current_datetime = datetime.now()
formatted_datetime = current_datetime.strftime("%Y_%m_%d_%H_%M")  # Format the datetime

# Specify the folder and create the full path
folder_path = r''  # Specify the path where the xlsx file should be store
filename = f"stock_indices_{formatted_datetime}.xlsx"
full_path = f"{folder_path}\\{filename}"

# Format the index to exclude the time component
df.index = df.index.date

# Sort the DataFrame in descending order based on the date index
df = df.sort_index(ascending=False)

# Save the sorted DataFrame to the specified folder and path, including the formatted date index
df.to_excel(full_path, index=True)

# This section is about Exploratory Data Analysis

# Print the last 10 rows of the DataFrame
print(df.tail(10))

# Print the shape of the DataFrame (number of rows, number of columns)
print("Shape: ", df.shape)

# Print the column names of the DataFrame
print(df.columns)

# Compute and print descriptive statistics of the DataFrame
print(df.describe())

# Compute and print the number of null values in each column of the DataFrame
print(df.isnull().sum())

# Print the data types of each column in the DataFrame
print(df.dtypes)

# Retrieve the last row of the DataFrame and assign it to the variable 'first_value'
first_value = df.iloc[-1]
print(first_value)

# Plotting the SP500 data
plt.plot(sp500)

# Adding labels and title to the plot
plt.xlabel("Date")
plt.ylabel("SP500")
plt.title("SP500 Data")

# Displaying the plot
plt.show()
