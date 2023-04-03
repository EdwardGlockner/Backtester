def construct_all_positions():
    """
    Constructs the positions list using the start_date
    to determine when the time index will begin.
    """
    d = dict( (k,v) for k, v in [(s, 0) for s in ["AAPL", "GOOG", "FB"]] )
    d['datetime'] = "2022-01-01"
    return [d]

print(construct_all_positions())


