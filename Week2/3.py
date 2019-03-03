quantity = int(open("input.txt", "r").readline())
array = [0 for i in range(quantity)]
for i in range(quantity):
    array[i] = i + 1
    if (i > 1):
        array[i], array[i // 2] = array[i // 2], array[i]
open("output.txt", "w").write(' '.join(map(str, array)))
