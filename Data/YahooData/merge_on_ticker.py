#--IMPORTS--------------------+
import sys
import os
import pandas as pd
import numpy as np
import glob

#--FIXING PATH----------------+
sys.path.append(str(sys.path[0][:-14]))
dirname = os.getcwd()

#--GLOBALS--------------------+
directory = dirname + "/data/"

#--FUNCTIONS------------------+
def create_dict():
    """ 
    
    @params:
        None
    @returns:
        tick_map:
    """
    
    tick_map = {}
    for filename in os.listdir(directory):
        f = os.path.join(directory, filename)

        # checking if it is a file
        if not os.path.isfile(f):
            break

        ticker = f.split("_")[0].split("/")[-1]
        if ticker in tick_map:
            tick_map[ticker].append(f)
        else:
            tick_map[ticker] = [f]

    return tick_map


def merge_files(tick_map):
    for tick in tick_map:
        combined_csv = pd.concat([pd.read_csv(f) for f in tick_map[tick]])
        new_name = tick + "_1m" + ".csv"
        combined_csv.to_csv(directory + new_name, index=False, encoding="unicode_escape")
        for file in tick_map[tick]:
            os.remove(file)
        print(f"Done merging {tick}")

def cleaning_csv(csv):
    pass

#--MAIN----------------------+
def main():
    tick_map = create_dict()
    merge_files(tick_map)
    
#--RUN CODE------------------+
if __name__ == "__main__":
    main()
