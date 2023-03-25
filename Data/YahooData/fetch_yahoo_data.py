#--IMPORTS--------------------+
import yfinance as yf
import datetime
import os
import sys
import pandas_datareader as web
import pandas as pd

#--FIXING PATH----------------+
sys.path.append(str(sys.path[0][:-14]))
dirname = os.getcwd()

#--GLOBALS--------------------+
try:
    if sys.platform == "darwin": # macOS
        clear = lambda : os.system('clear')
    else:
        clear = lambda : os.system('cls')
except OSError as e:
    print("Error identifying operating system")

clear()

#--GET PARAMETERS-------------+
today = datetime.datetime.today().strftime('%Y-%m-%d')

# Get interval and period
intervals = ["1m", "2m", "5m", "15m", "30m", "60m", "1d", "5d", "1wk", "1mo", "3mo"]
periods = ["7d", "60d", "60d", "60d", "60d", "730d", "10000d", "10000d", "10000d", "10000d", "10000d"]

print("Choose interval")
print(f"Available options: 1m, 2m, 5m, 15m, 30m, 60m, 90m, 1h, 1d, 5d, 1wk, 1mo, 3mo")

interval = input("Interval: ")
period = periods[intervals.index(interval)]
clear()

# Get ticker symbols
tickers = []
print("Select tickers. 'q' to quit")
while True:
    ticker = input("Input ticker: ")
    if ticker == "q":
        break
    tickers.append(ticker)

clear()

#--START READING DATA------------+
print("Reading stock information")
for tick in tickers:
    data = yf.download(tickers = tick, period=period, interval = interval)
    dataname = dirname + "/data/" + tick + "_" + today + "_" + interval 
    dataname.strip()
    data.to_csv(dataname)
    print(f"Stock data for ticker {tick} finished reading")

