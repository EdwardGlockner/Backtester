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
        # Stock variables
        sys.path.append(str(sys.path[0][:-14]))
        dirname = os.getcwd()
        self.dirname = dirname.replace("/Reports", "")
        self.csv_path = self.dirname + csv_path
        self.ticker = csv_path.split("/")[-1].split("_")[0]
        self.df = pd.read_csv(self.csv_path, index_col=0, parse_dates=True)
        
        # PDF variables
        self.WIDTH = 216
        self.HEIGHT = 280
        self.pdf = FPDF()

    def _generate_plot(self):
        mpf.plot(self.df, type="line", axtitle="Closing price of " + self.ticker, savefig='stock.png')


    def _create_title(self):
        self.pdf.set_font("Arial", "", 24)
        self.pdf.ln(60)
        self.pdf.write(5, self.ticker + " Stock Report")
        self.pdf.ln(10)

    def create_report(self):
        # First page
        self.pdf.add_page()
        self._create_title()
        self._generate_plot()
        self.pdf.image(self.dirname + "/Reports/stock.png", 5, 100, self.WIDTH-20)
        self.pdf.output("test.pdf", "F")
        os.remove("stock.png")

        
csv_path = "/Data/YahooData/data/TSLA_2023-03-25_1m"
Report = StockReport(csv_path)
Report.create_report()
