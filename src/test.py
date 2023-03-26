import pandas as pd
import os.path
import queue

from abc import ABCMeta, abstractmethod
from datetime import datetime
from enum import Enum


class DataHandler(metaclass=ABCMeta):
    __metaclass__ = ABCMeta

    @abstractmethod
    def get_latest_data(self, symbol, N=1):
        raise NotImplementedError

    @abstractmethod
    def update_latest_data(self):
        raise NotImplementedError

class HistoricCSVDataHandler(DataHandler):
    def __init__(self, events, csv_dir, symbol_list):
        self.events = events
        self.csv_dir = csv_dir
        self.symbol_list = symbol_list

        self.symbol_data = {}
        self.symbol_dataframe = {}
        self.latest_symbol_data = {}
        self.all_data = {}
        self.continue_backtest = True

        self.time_col = 1
        self.price_col = 2

        self._open_convert_csv_files()

    def _open_convert_csv_files(self):
        combined_index = None
        for symbol in self.symbol_list:
            self.parse_yahoo_csv(symbol)

            if combined_index is None:
                combined_index = self.symbol_data[symbol].index
            else:
                combined_index.union(self.symbol_data[symbol].index)

            self.latest_symbol_data[symbol] = []

        for symbol in self.symbol_list:
            self.symbol_dataframe[symbol] = self.symbol_data[symbol].reindex(index=combined_index, method='pad')
            self.all_data[symbol] = self.symbol_dataframe[symbol].copy()
            self.symbol_data[symbol] = self.symbol_dataframe[symbol].iterrows()

    def _get_new_data(self, symbol):
        for row in self.symbol_data[symbol]:
            yield tuple([symbol, row[0], row[1][0]])

    def get_latest_data(self, symbol, N=1):
        try:
            return self.latest_symbol_data[symbol][-N:]
        except KeyError:
            print(f"{symbol} is not a valid symbol.")


    def update_latest_data(self):
        for symbol in self.symbol_list:
            data = None
            try:
                data = next(self._get_new_data(symbol))
            except StopIteration:
                self.continue_backtest = False
            if data is not None:
                self.latest_symbol_data[symbol].append(data)



    def parse_yahoo_csv(self, symbol):
        self.symbol_data[symbol] = pd.read_csv(os.path.join(self.csv_dir), header=0, index_col=0, parse_dates=True)


Data = HistoricCSVDataHandler([], "/Users/edwardglockner/OneDrive - Uppsala universitet/Big Python Projects/Backtester/Data/YahooData/data/TSLA_2023-03-25_1m", ["TSLA"])
print(Data.get_latest_data("TSLA"))
print(Data.latest_symbol_data)
print("Done!")
