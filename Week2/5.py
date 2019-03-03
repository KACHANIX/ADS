file = open("input.txt", "r")
firstLine = list(map(int, file.read().split()))
quantity = firstLine[0]
armSpan = firstLine[1]
array = firstLine[2:]

arrays = []
for i in range(armSpan):
    tmpArr = []
    for j in range (i, quantity, armSpan):
        tmpArr.append(array[j])
    tmpArr.sort()
    arrays.append(tmpArr)
result = "YES"
for i in range(1, quantity):
    if arrays[i % armSpan][i // armSpan] < arrays[(i - 1) % armSpan][(i - 1) // armSpan]:
        result = "NO"
        break
file = open("output.txt", "w")
file.write(result)
