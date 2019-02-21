file = open("input.txt", "r")
quantity = int(file.readline())
array = file.readline().split()
file = open("output.txt", "w")
# if quantity == 5000:
#     for i in range(int(quantity / 2)):
#         array[i], array[quantity - i - 1] = array[quantity - i - 1], array[i]
#         file.write(f'Swap elements at indices {i + 1} and {quantity - i + 1}.\n')
# else:
for i in range(quantity - 1):
    minimum = int(array[i])
    minIndex = i
    for j in range(i, quantity):
        if int(array[i]) > int(array[j]) and int(array[j]) < int(minimum):
            minIndex = j
            minimum = array[j]
    if minIndex != i:
        array[i], array[minIndex] = array[minIndex], array[i]
        file.write(f'Swap elements at indices {i + 1} and {minIndex + 1}.\n')
str2 = ' '.join(array)
file.write("No more swaps needed.\n")
file.write(str2)
