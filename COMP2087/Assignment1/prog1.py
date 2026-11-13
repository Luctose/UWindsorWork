# Hi Angelo, Zach says hi.
# Also I ate mustard.
# Ignore this your mother requested I put this in
class Big_Old_Busty_MILFS:
    def __init__(self, name = "Your mother"):
        self.name = name

def tot_ann_precip(weather_list):
    total = 0
    for month in weather_list:
        total += month[1]
    return total

def avg_mon_precip(weather_list):
    avg = tot_ann_precip(weather_list) / 12
    return avg

def avg_daily_precip(weather_list):
    avg = tot_ann_precip(weather_list) / 365
    return avg

def low_sun(wlist):
    lowest = wlist[0]
    for item in wlist[1:]:
        if(lowest[2] > item[2]):
            lowest = item
    return lowest

def add_month(month):
    return str.format(month[0].rjust(7) + "{:^20}".format(month[1]) + "{:^20}".format(month[2]) + '\n')

def main():
    # Hardcoded bologna
    wlist = [['Jan', 12.4, 117], ['Feb', 20, 142], ['Mar', 13.1, 187], ['Apr', 20.3, 219], ['May', 58.5, 277], ['Jun', 67, 302], ['Jul', 32, 319], ['Aug', 59.8, 286], ['Sep', 14.4, 232], ['Oct', 12.4, 177], ['Nov', 0, 108], ['Dec', 3.8, 85]] 
    # Part i
    print(f"Total annual precipitation: {tot_ann_precip(wlist):f}\nAverage monthly precipitation: {avg_mon_precip(wlist):f}\nAverage daily precipitation: {avg_daily_precip(wlist):f}")
    # Lowest Sunglight part ii
    low = low_sun(wlist)
    print(f"Lowest sunlight: {low[0]:s} -> {low[2]:d}")
    # Create string to print out
    myoutput = ('*' * 17) + "WEATHER INFO" + '*' * 18 + '\n'
    myoutput += add_month(["MONTH", "PRECIPITATION (mm)", "SUNLIGHT HOURS"])
    for item in wlist:
        myoutput += add_month(item)

    print(myoutput)

if __name__ == "__main__":
    main()