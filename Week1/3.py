file = open("input.txt", "r")
quantity = int(file.readline())
array = file.readline().split()
firstLine = list()
for i in range(0, quantity):
    j = i
    while j > 0 and int(array[j]) < int(array[j - 1]):
        tmp = array[j]
        array[j] = array[j - 1]
        array[j - 1] = tmp
        j -= 1
    firstLine.append(str(j + 1))
file = open("output.txt", "w")
str1 = ' '.join(firstLine)
str2 = ' '.join(array)

file.write(str1 + "\n")
file.write(str2)
