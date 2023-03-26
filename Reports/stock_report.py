import pandas as pd
from matplotlib import pyplot as plt
from pylab import title, figure, xlabel, ylabel, xticks, bar, legend, axis, savefig
from fpdf import FPDF
import os
import sys
import datetime

sys.path.append(str(sys.path[0][:-14]))
dirname = os.getcwd()
dirname = dirname.replace("/Reports", "")

def create_report(csv_path, interval):
    csv_path = dirname+"/Data/YahooData/data/TSLA_2023-03-25_1m"

    df = pd.read_csv(csv_path)
    df['Datetime'] = pd.to_datetime(df['Datetime'])
    df['Datetime'] = df['Datetime'].dt.time
    df['Datetime'] = df['Datetime'].astype(str)
    stock = csv_path.split("/")[-1].split("_")[0]

    dates = df["Datetime"]
    close_price = df["Close"]
    
    print(dates)
    print(close_price)
     
    plt.figure(figsize=(10,6), constrained_layout=True)
    plt.plot(close_price)
    plt.xlabel("Date")
    plt.ylabel("Price")
    plt.title(f"Closing price of {stock}")
    ax = plt.gca()
    ax.tick_params(axis='x', labelrotation = 45)
    plt.show()

create_report("test", "1m")



"""
df = pd.DataFrame()
df['Question'] = ["Q1", "Q2", "Q3", "Q4"]
df['Charles'] = [3, 4, 5, 3]
df['Mike'] = [3, 3, 4, 4]

title("Professor Criss's Ratings by Users")
xlabel('Question Number')
ylabel('Score')

c = [2.0, 4.0, 6.0, 8.0]
m = [x - 0.5 for x in c]

xticks(c, df['Question'])

bar(m, df['Mike'], width=0.5, color="#91eb87", label="Mike")
bar(c, df['Charles'], width=0.5, color="#eb879c", label="Charles")

legend()
axis([0, 10, 0, 8])
savefig('barchart.png')

pdf = FPDF()
pdf.add_page()
pdf.set_xy(0, 0)
pdf.set_font('arial', 'B', 12)
pdf.cell(60)
pdf.cell(75, 10, "A Tabular and Graphical Report of Professor Criss's Ratings by Users Charles and Mike", 0, 2, 'C')
pdf.cell(90, 10, " ", 0, 2, 'C')
pdf.cell(-40)
pdf.cell(50, 10, 'Question', 1, 0, 'C')
pdf.cell(40, 10, 'Charles', 1, 0, 'C')
pdf.cell(40, 10, 'Mike', 1, 2, 'C')
pdf.cell(-90)
pdf.set_font('arial', '', 12)
for i in range(0, len(df)):
    pdf.cell(50, 10, '%s' % (df['Question'].iloc[i]), 1, 0, 'C')
    pdf.cell(40, 10, '%s' % (str(df.Mike.iloc[i])), 1, 0, 'C')
    pdf.cell(40, 10, '%s' % (str(df.Charles.iloc[i])), 1, 2, 'C')
    pdf.cell(-90)
pdf.cell(90, 10, " ", 0, 2, 'C')
pdf.cell(-30)
pdf.image('barchart.png', x = None, y = None, w = 0, h = 0, type = '', link = '')
pdf.output('test.pdf', 'F')
"""
