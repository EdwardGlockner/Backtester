import pandas as pd
from matplotlib import pyplot as plt
from pylab import title, figure, xlabel, ylabel, xticks, bar, legend, axis, savefig
from fpdf import FPDF
import os
import sys
import datetime
import matplotlib.dates as mdates
import mplfinance as mpf


class StockReport():
    def __init__(self, csv_path):
        sys.path.append(str(sys.path[0][:-14]))
        dirname = os.getcwd()
        dirname = dirname.replace("/Reports", "")
        self.csv_path = dirname + csv_path
        self.ticker = csv_path.split("/")[-1].split("_")[0]
        self.df = pd.read_csv(self.csv_path, index_col=0, parse_dates=True)

    def generate_plot(self):
        mpf.plot(self.df, type="line", axtitle="Closing price of " + self.ticker)
        
csv_path = "/Data/YahooData/data/TSLA_2023-03-25_1m"
Report = StockReport(csv_path)
Report.generate_plot()
