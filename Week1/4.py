def mergeSort(array):
    if len(array) > 1:
        middle = len(array) // 2
        leftPart = array[:middle]
        rightPart = array[middle:]
        mergeSort(leftPart)
        mergeSort(rightPart)
        leftIndex = 0
        rightIndex = 0
        position = 0
        while (leftIndex < len(leftPart) and rightIndex < len(rightPart)):
            if (leftPart[leftIndex] < rightPart[rightIndex]):
                array[position] = leftPart[leftIndex]
                leftIndex += 1
            else:
                array[position] = rightPart[rightIndex]
                rightIndex += 1
            position += 1
        while (leftIndex < len(leftPart)):
            array[position] = leftPart[leftIndex]
            position += 1
            leftIndex += 1
        while (rightIndex < len(rightPart)):
            array[position] = rightPart[rightIndex]
            position += 1
            rightIndex += 1


file = open("input.txt", "r")
quantity = int(file.readline())
array = list(map(float, file.read().split()))
copied = array.copy()
mergeSort(array)
print(array)
biggest = array[-1]
smallest = array[0]
middle = array[int(float(len(array) / 2) - 0.5)]
smallInd = -1
midInd = -1
bigInd = -1
file = open("output.txt", "w")
for i in range(quantity):
    if copied[i] == biggest:
        bigInd = i
    if copied[i] == middle:
        midInd = i
    if copied[i] == smallest:
        smallInd = i
file.write(str(smallInd + 1) + ' ' + str(midInd + 1) + ' ' + str(bigInd + 1))
