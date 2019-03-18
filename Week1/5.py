file = open("input.txt", "r")
quantity = int(file.readline())
array = file.readline().split()
file = open("output.txt", "w")
str1 = ""
for i in range(quantity - 1):
    minimum = int(array[i])
    minIndex = i
    for j in range(i, quantity):
        if int(array[i]) > int(array[j]) and int(array[j]) < int(minimum):
            minIndex = j
            minimum = array[j]
    if minIndex != i:
        array[i], array[minIndex] = array[minIndex], array[i]
        str1 += (f'Swap elements at indices {i + 1} and {minIndex + 1}.\n')
str2 = ' '.join(array)
file.write(str1)
file.write("No more swaps needed.\n")
file.write(str2)