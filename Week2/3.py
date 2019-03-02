def anti_quicksort(quantity):
    indexes = [i for i in range(quantity)]
    result = [None for i in range(quantity)]
    for i in range(quantity - 1, -1, -1):
        result[indexes[i // 2]] = i + 1
        indexes[i // 2], indexes[i] = indexes[i], indexes[i // 2]
    if quantity > 1:
        result[result.index(1)], result[result.index(2)] = result[result.index(2)], result[result.index(1)]
    output = (result)
    return (' '.join(map(str, result)))


quantity = int(open("input.txt", "r").readline())
open("output.txt", "w").write(anti_quicksort(quantity))
