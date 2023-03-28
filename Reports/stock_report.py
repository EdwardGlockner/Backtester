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
        """
        
        @params:

        @returns:

        """
        # Stock variables
        sys.path.append(str(sys.path[0][:-14]))
        dirname = os.getcwd()
        self.dirname = dirname.replace("/Reports", "")
        self.csv_path = self.dirname + csv_path
        self.ticker = csv_path.split("/")[-1].split("_")[0]
        self.df = pd.read_csv(self.csv_path, index_col=0, parse_dates=True)
        self.strt_dt = str(self.df.index[0].replace(tzinfo=None))
        self.end_dt = str(self.df.index[-1].replace(tzinfo=None))
        
        # PDF variables
        self.WIDTH = 216
        self.HEIGHT = 280
        self.pdf = FPDF()
        self.today = str(datetime.date.today())


    def _generate_plot(self):
        """

        @params:

        @returns:

        """
        mpf.plot(self.df, type="line", axtitle="Closing price of " + self.ticker, savefig='stock.png')

    
    def _hist_returns(self):
        """

        @params:

        @returns:

        """
        df_returns = self.df['Close'].pct_change()
        fig = plt.figure()
        ax1 = fig.add_axes([0.1,0.1,0.8,0.8])
        df_returns.plot.hist(bins = 60)
        ax1.set_xlabel("Daily returns %")
        ax1.set_ylabel("Percent")
        ax1.set_title(f"Daily returns of {self.ticker}")
        plt.savefig('hist.png')

    def _create_title(self):
        """

        @params:

        @returns:

        """
        self.pdf.set_font("Arial", "", 36)
        self.pdf.ln(20)
        self.pdf.write(5, "Stock Report")
        self.pdf.ln(10)
        self.pdf.set_font("Arial", "", 12)
        self.pdf.write(5, "Stock ticker: " + self.ticker)
        self.pdf.ln(5)
        self.pdf.write(5, "Report generated on: " + self.today)
        self.pdf.ln(5)
        self.pdf.write(5, "Interval: " + "1 minute")
        self.pdf.ln(5)
        self.pdf.write(5, "Stock data start date: " + self.strt_dt)
        self.pdf.ln(5)
        self.pdf.write(5, "Stock data end date: " + self.end_dt)
        

    def create_report(self):
        """

        @params:

        @returns:

        """
        # First page
        self.pdf.add_page()
        self._create_title()
        self._generate_plot()
        self.pdf.image(self.dirname + "/Reports/stock.png", 5, 85, w=self.WIDTH-20)
        os.remove("stock.png")

        # Second page
        self.pdf.add_page()
        self._hist_returns()
        self.pdf.image(self.dirname + "/Reports/hist.png", self.WIDTH/4, 20, w=self.WIDTH/2)
        os.remove("hist.png")
        self.pdf.output("test.pdf", "F")
       

        
csv_path = "/Data/YahooData/data/TSLA_2023-03-25_1m"
Report = StockReport(csv_path)
Report.create_report()
