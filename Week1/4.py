def swap(i, j):
    array[i], array[j] = array[j], array[i]


def heapify(end, i):
    l = 2 * i + 1
    r = 2 * (i + 1)
    max = i
    if l < end and float(array[i]) < float(array[l]):
        max = l
    if r < end and float(array[max]) < float(array[r]):
        max = r
    if max != i:
        swap(i, max)
        heapify(end, max)


def heap_sort():
    end = len(array)
    start = end // 2 - 1  # use // instead of /
    for i in range(start, -1, -1):
        heapify(end, i)
    for i in range(end - 1, 0, -1):
        swap(i, 0)
        heapify(i, 0)


file = open("input.txt", "r")
quantity = int(file.readline())
array = file.readline().split()
copied = array.copy()
n = 1
heap_sort()
biggest = array[quantity - 1]
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
