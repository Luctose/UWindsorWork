# Project 1
# COMP-4250 Winter 2024
# Lucas Sarweh
# Due: 03/06/2024 11:59pm

# Load modules
import os.path
import time
import matplotlib.pyplot as plt
# Absolute path of this script
__location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
# This code provides implementations of the A-priori and PCY algorithms
# for finding similar-itemsets

# Function to extract data from text file and put it into a container
def filetolist(filename):
    newlist = []
    temp = []
    
    fp = open(os.path.join(__location__, filename), 'r')
    nextline = fp.readline()

    while(nextline != ""):
        for item in nextline.split(' ')[:-1]:
            temp.append(int(item))
        
        newlist.append(temp.copy())
        temp.clear()

        nextline = fp.readline()

    fp.close()
    return newlist

# Hash function 1
def hash1(item1, item2, bucket_size = 100):
    return (30 * item1 + item2) % bucket_size

# Hash function 2
def hash2(item1, item2, bucket_size = 100):
    return (item1 + 23 * item2) % bucket_size

# apriori(data, s) finds the candidate pairs (frequent item pairs) of
# a dataset where each row is a basket and an item in a row is an item in
# a basket
# Args:
# data - the dataset containing baskets with items
# s - the support threshold for frequent items
def apriori(data, s):
    # Item counter (Dictionary)
    item_count = {}
    # Frequent item holder (Set)
    frequent_singles = set()

    # Iterate through each item to count their support
    # Pass 1
    for basket in data:
        for item in basket:
            # If item is in dict
            if item_count.get(item) != None:
                # Increment counter
                item_count[item] += 1
                # Add to threshold list if required
                if item_count[item] >= s:
                    frequent_singles.add(item)
            # If item needs to be inserted
            else:
                item_count.update({item : 1})
    # Clear item_count
    item_count.clear()

    # Pass 2
    for basket in data:
        # Intersection of each basket and frequent items from pass 1 to obtain count
        inter_set = frequent_singles.intersection(set(basket))
        # Add each count of pairs found for current bucket
        for i in inter_set:
            for j in inter_set:
                # Keep the pairs ordered lower to higher
                if i < j:
                    # Add count to dictionary
                    item_count.update({(i, j) : item_count.get((i, j), 0) + 1})
    
    # Remove items that don't meet the threshold
    for key in item_count.copy():
        if item_count[key] < s:
            item_count.pop(key)
    
    # Return candidate pairs
    return item_count.keys()

# PCY algorithm to find frequent item candidate pairs of a data set
# Args:
# data - the data set
# s - the support threshold
# b - the number of buckets to hash
def pcy(data, s, b):
    # Item counter (Dictionary)
    item_count = {}
    # Frequent item holder (Set)
    frequent_singles = set()
    # Track buckets
    bucket_count = {}

    # Iterate through each item to count their support
    # Pass 1
    for basket in data:
        for item in basket:
            # If item is in dict
            if item_count.get(item) != None:
                # Increment counter
                item_count[item] += 1
                # Add to threshold list if required
                if item_count[item] >= s:
                    frequent_singles.add(item)
            # If item needs to be inserted
            else:
                item_count.update({item : 1})
            # hash pairs to find buckets
            for item2 in basket:
                # ensure pairs are lowest to highest order
                if item < item2:
                    # Find bucket using hash for pair item, item2
                    bucket = hash1(item, item2, b)
                    bucket_count.update({ bucket : bucket_count.get(bucket, 0) + 1})

    # Clear item_count
    item_count.clear()
    # convert bucket table values to bit vectors
    for bucket in bucket_count:
        if bucket_count[bucket] >= s:
            bucket_count[bucket] = True
        else:
            bucket_count[bucket] = False
    
    # Pass 2
    # Second pass over only frequent items
    for item1 in frequent_singles:
        for item2 in frequent_singles:
            # If both are frequent and map to 1 in the bit vector
            if item1 < item2 and bucket_count.get(hash1(item1, item2, b), False):
                # Add to frequent pair list
                item_count.update({(item1, item2) : None})
    
    return item_count.keys()

# PCY multistage (3 stages) algorithm to find frequent item candidate pairs of a data set
# Args:
# data - the data set
# s - the support threshold
# b - the number of buckets to hash
def pcy_multistage(data, s, b):
    # Item counter (Dictionary)
    item_count = {}
    # Frequent item holder (Set)
    frequent_singles = set()
    # Track buckets
    bucket_count = {}
    bucket_count2 = {}

    # Iterate through each item to count their support
    # Pass 1
    for basket in data:
        for item in basket:
            # If item is in dict
            if item_count.get(item) != None:
                # Increment counter
                item_count[item] += 1
                # Add to threshold list if required
                if item_count[item] >= s:
                    frequent_singles.add(item)
            # If item needs to be inserted
            else:
                item_count.update({item : 1})
            # hash pairs to find buckets
            for item2 in basket:
                # ensure pairs are lowest to highest order
                if item < item2:
                    # Find bucket using hash for pair item, item2
                    bucket = hash1(item, item2, b)
                    bucket_count.update({ bucket : bucket_count.get(bucket, 0) + 1})

    # Clear item_count
    item_count.clear()
    # convert bucket table values to bit vectors
    for bucket in bucket_count:
        if bucket_count[bucket] >= s:
            bucket_count[bucket] = True
        else:
            bucket_count[bucket] = False
    
    # Pass 2
    for basket in data:
        for item1 in basket:
            for item2 in basket:
                # ensure pairs are lowest to highest order
                if item1 < item2 and bucket_count.get(hash1(item1, item2, b), False) and item1 in frequent_singles and item2 in frequent_singles:
                    # Find bucket using hash for pair item, item2
                    bucket = hash2(item1, item2, b)
                    bucket_count2.update({ bucket : bucket_count2.get(bucket, 0) + 1})
    
    # convert bucket table values to bit vectors
    for bucket in bucket_count2:
        if bucket_count2[bucket] >= s:
            bucket_count2[bucket] = True
        else:
            bucket_count2[bucket] = False

    # Pass 3
    # Second pass over only frequent items
    for item1 in frequent_singles:
        for item2 in frequent_singles:
            # If both are frequent and map to 1 in both bit vectors
            if item1 < item2 and bucket_count.get(hash1(item1, item2, b), False) and bucket_count2.get(hash2(item1, item2, b), False):
                # Add to frequent pair list
                item_count.update({(item1, item2) : None})
    
    return item_count.keys()

# PCY multihash (2 functions) algorithm to find frequent item candidate pairs of a data set
# Args:
# data - the data set
# s - the support threshold
# b - the number of buckets to hash
def pcy_multihash(data, s, b):
    # Item counter (Dictionary)
    item_count = {}
    # Frequent item holder (Set)
    frequent_singles = set()
    # Track buckets
    bucket_count = {}
    bucket_count2 = {}
    # Multihash two functions gives half room, b/2 to simulate
    b = b//2

    # Iterate through each item to count their support
    # Pass 1
    for basket in data:
        for item in basket:
            # If item is in dict
            if item_count.get(item) != None:
                # Increment counter
                item_count[item] += 1
                # Add to threshold list if required
                if item_count[item] >= s:
                    frequent_singles.add(item)
            # If item needs to be inserted
            else:
                item_count.update({item : 1})
            # hash pairs to find buckets
            for item2 in basket:
                # ensure pairs are lowest to highest order
                if item < item2:
                    # Find bucket using hash for pair item, item2
                    bucket = hash1(item, item2, b)
                    bucket_count.update({ bucket : bucket_count.get(bucket, 0) + 1})
                    bucket = hash2(item, item2, b)
                    bucket_count2.update({ bucket : bucket_count2.get(bucket, 0) + 1})

    # Clear item_count
    item_count.clear()
    # convert bucket table values to bit vectors
    for bucket in bucket_count:
        if bucket_count[bucket] >= s:
            bucket_count[bucket] = True
        else:
            bucket_count[bucket] = False
    for bucket in bucket_count2:
        if bucket_count2[bucket] >= s:
            bucket_count2[bucket] = True
        else:
            bucket_count2[bucket] = False
    
    # Pass 2
    # Second pass over only frequent items
    for item1 in frequent_singles:
        for item2 in frequent_singles:
            # If both are frequent and map to 1 in both bit vectors
            if item1 < item2 and bucket_count.get(hash1(item1, item2, b), False) and bucket_count2.get(hash2(item1, item2, b), False):
                # Add to frequent pair list
                item_count.update({(item1, item2) : None})
    
    return item_count.keys()

# Main function
def main():
    # Retreive data from retail.txt
    mydata = filetolist('retail.txt')
    # number of baskets
    data_size = len(mydata)

    # This loop gets time data for the graphs
    # i is percentage of data to use
    for i in range(10, 101, 10):
        # Each function will be called 3 times per iteration for 1, 5, and 10 percent threshold
        # It will iterate 10 times for dataset size percentages of 10 - 100 incrementing by 10

        # Apriori
        apri1 = []
        apri5 = []
        apri10 = []
        
        start = time.time()
        apriori(mydata[0:int((i/100)*data_size)], int(0.01 * (i/100) * data_size))
        end = time.time()

        apri1.append(end - start)

        start = time.time()
        apriori(mydata[0:int((i/100)*data_size)], int(0.05 * (i/100) * data_size))
        end = time.time()

        apri5.append(end - start)

        start = time.time()
        apriori(mydata[0:int((i/100)*data_size)], int(0.1 * (i/100) * data_size))
        end = time.time()

        apri10.append(end - start)
        
        # PCY
        pcy1 = []
        pcy5 = []
        pcy10 = []
        
        start = time.time()
        pcy(mydata[0:int((i/100)*data_size)], int(0.01 * (i/100) * data_size), 100)
        end = time.time()

        pcy1.append(end - start)

        start = time.time()
        pcy(mydata[0:int((i/100)*data_size)], int(0.05 * (i/100) * data_size), 100)
        end = time.time()

        pcy5.append(end - start)

        start = time.time()
        pcy(mydata[0:int((i/100)*data_size)], int(0.1 * (i/100) * data_size), 100)
        end = time.time()

        pcy10.append(end - start)
        
        # PCY multistage
        pcy1_s = []
        pcy5_s = []
        pcy10_s = []
        
        start = time.time()
        pcy_multistage(mydata[0:int((i/100)*data_size)], int(0.01 * (i/100) * data_size), 100)
        end = time.time()

        pcy1_s.append(end - start)

        start = time.time()
        pcy_multistage(mydata[0:int((i/100)*data_size)], int(0.05 * (i/100) * data_size), 100)
        end = time.time()

        pcy5_s.append(end - start)

        start = time.time()
        pcy_multistage(mydata[0:int((i/100)*data_size)], int(0.1 * (i/100) * data_size), 100)
        end = time.time()

        pcy10_s.append(end - start)

        # PCY multihash
        pcy1_h = []
        pcy5_h = []
        pcy10_h = []
        
        start = time.time()
        pcy_multihash(mydata[0:int((i/100)*data_size)], int(0.01 * (i/100) * data_size), 100)
        end = time.time()

        pcy1_h.append(end - start)

        start = time.time()
        pcy_multihash(mydata[0:int((i/100)*data_size)], int(0.05 * (i/100) * data_size), 100)
        end = time.time()

        pcy5_h.append(end - start)

        start = time.time()
        pcy_multihash(mydata[0:int((i/100)*data_size)], int(0.1 * (i/100) * data_size), 100)
        end = time.time()

        pcy10_h.append(end - start)
    
    # X-axis
    
    x = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

    # Plot 1
    plt.plot(x, apri1, label = "A-priori")
    plt.plot(x, pcy1, label = "PCY")
    plt.plot(x, pcy1_s, label = "Multistage")
    plt.plot(x, pcy1_h, label = "Multihash")
    plt.xlabel('Dataset Size')
    plt.ylabel('Run Time (ms)')
    plt.title('Support Threshold: 1%')
    plt.legend()
    plt.savefig('theshold_1.png')

    plt.clf()

    # Plot 2
    plt.plot(x, apri5, label = "A-priori")
    plt.plot(x, pcy5, label = "PCY")
    plt.plot(x, pcy5_s, label = "Multistage")
    plt.plot(x, pcy5_h, label = "Multihash")
    plt.xlabel('Dataset Size')
    plt.ylabel('Run Time (ms)')
    plt.title('Support Threshold: 5%')
    plt.legend()
    plt.savefig('theshold_5.png')

    plt.clf()

    # Plot 3
    plt.plot(x, apri10, label = "A-priori")
    plt.plot(x, pcy10, label = "PCY")
    plt.plot(x, pcy10_s, label = "Multistage")
    plt.plot(x, pcy10_h, label = "Multihash")
    plt.xlabel('Dataset Size')
    plt.ylabel('Run Time (ms)')
    plt.title('Support Threshold: 10%')
    plt.legend()
    plt.savefig('theshold_10.png')

    plt.close()
    
# Testing apriori
if __name__ == "__main__":
    main()