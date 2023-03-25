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
print("------START DATE------")
strt_year = int(input("Year: "))
strt_month = int(input("Month: "))
strt_day = int(input("Day: "))

strt_dt = datetime.datetime(strt_year, strt_month, strt_day)

print("\n------END DATE------")
end_year = int(input("Year: "))
end_month = int(input("Month: "))
end_day = int(input("Day: "))

end_dt = datetime.datetime(end_year, end_month, end_day)

clear()

tickers = []
print("Select tickers. 'Q' to quit")
while True:
    ticker = input("Input ticker: ")
    if ticker == "Q":
        break
    tickers.append(ticker)
clear()

#--START READING DATA------------+
print("Reading stock information")
for tick in tickers:
    ticker = yf.Ticker(tick)
    info = None
    
    """
    try:
        info = tick.info
    except:
        print(f"Cannot get info of {ticker}. Ticker probably does not exist")
        continue
    """
    
    data = yf.download(tickers = tick, period="7d", interval = "1m")
    dataname = dirname + "/data/" + tick + "_" + str(strt_dt) + "to" + str(end_dt)
    dataname.strip()
    data.to_csv(dataname)
    print(f"Stock data for ticker {tick} finished reading")

