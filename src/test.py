

def construct_all_positions(symbol_list):
        """
        Constructs the positions list using the start_date
        to determine when the time index will begin.
        """
        d = dict( (k,v) for k, v in [(s, 0) for s in symbol_list] )
        d['datetime'] = "start_date"
        return [d]


def construct_all_holdings(symbol_list):
        """
        Constructs the holdings list using the start_date
        to determine when the time index will begin.
        """
        d = dict( (k,v) for k, v in [(s, 0.0) for s in symbol_list] )
        d['datetime'] = "start date"
        d['cash'] = 1000
        d['commission'] = 0.0
        d['total'] = 1000
        return [d]


def construct_current_holdings(symbol_list):
        """
        This constructs the dictionary which will hold the instantaneous
        value of the portfolio across all symbols.
        """
        d = dict( (k,v) for k, v in [(s, 0.0) for s in symbol_list] )
        d['cash'] = 1000
        d['commission'] = 0.0
        d['total'] =1000 
        return d

symbol_list = ["A","B","C","D","E"]

current_positions = dict( (k,v) for k, v in [(s, 0) for s in symbol_list] )
print("current_positions", current_positions)
print("current_holdings",construct_current_holdings(symbol_list))
print("all_positions",construct_all_positions(symbol_list))
print("all holdings",construct_all_holdings(symbol_list))
