def mergeSort(array):
    if len(array) > 1:
        middle = len(array) // 2
        leftPart = array[:middle]
        rightPart = array[middle:]
        inversion = mergeSort(leftPart) + mergeSort(rightPart)
        leftIndex = 0
        rightIndex = 0
        position = 0
        leftLen = len(leftPart)
        rightLen = len(rightPart)
        while leftIndex < leftLen and rightIndex < rightLen:
            if leftPart[leftIndex] <= rightPart[rightIndex]:
                array[position] = leftPart[leftIndex]
                leftIndex += 1
            else:
                inversion += leftLen - leftIndex
                array[position] = rightPart[rightIndex]
                rightIndex += 1
            position += 1
        while leftIndex < leftLen:
            array[position] = leftPart[leftIndex]
            position += 1
            leftIndex += 1
        while rightIndex < rightLen:
            array[position] = rightPart[rightIndex]
            position += 1
            rightIndex += 1
        return inversion
    return 0


file = open("input.txt", "r")
quantity = int(file.readline())
numbers = list(map(int, file.read().split()))
file = open("output.txt", "w")
file.write(f"{mergeSort(numbers)}")
