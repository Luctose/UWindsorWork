def divides(i, b):
    if i % b == 0:
        return True
    else:
        return False

items = [0]*100
for i in range(100):
    items[i] = i+1

buckets = [[0]*100]*100

for j in range(100):
    for i in range(100):
        if divides(i + 1, j + 1):
            buckets[j][i] = i

print(buckets)
