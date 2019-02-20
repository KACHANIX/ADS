file = open("input.txt", "r")
numbers = file.read().split()
total = int(numbers[0]) + int(numbers[1]) ** 2
file = open("output.txt", "w")
file.write(str(total))
