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
numbers = list(map(int, file.read().split()))
file = open("output.txt", "w")
mergeSort(numbers)
print(' '.join(map(str, numbers)))
# file.write()
