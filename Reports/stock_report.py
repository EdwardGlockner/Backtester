import pandas as pd
from matplotlib import pyplot as plt
from pylab import title, figure, xlabel, ylabel, xticks, bar, legend, axis, savefig
from fpdf import FPDF
import os
import sys
import datetime
import matplotlib.dates as mdates

sys.path.append(str(sys.path[0][:-14]))
dirname = os.getcwd()
dirname = dirname.replace("/Reports", "")

def create_report(csv_path, interval):
    csv_path = dirname+"/Data/YahooData/data/TSLA_2023-03-25_1m"

    stock = csv_path.split("/")[-1].split("_")[0]
    df = pd.read_csv(csv_path)
    df.plot(x="Datetime", y="Close",rot=50)
    plt.xlabel("y")
    plt.ylabel("x")
    plt.title("title")
    plt.tight_layout()

    plt.show()

create_report("test", "1m")

