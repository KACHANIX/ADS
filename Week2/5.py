def answer(array, quantity):
    for i in range(1, quantity ):
        if array[i] < array[i - 1]:
            return "NO"
    return "YES"

file = open("input.txt", "r")
firstLine = list(map(int, file.read().split()))
quantity = firstLine[0]
armSpan = firstLine[1]
array = firstLine[2:]
isRunning = True
while(isRunning):
    isRunning = False
    for i in range(0, quantity - armSpan):
        if array[i] > array[i + armSpan]:
            array[i], array[i + armSpan] = array[i + armSpan], array[i]
            isRunning = True
file = open("output.txt", "w")

file.write(answer(array, quantity))

