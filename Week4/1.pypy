file = open("input.txt", "r")
quantity = int(file.readline())
outstring=""
outfile = open("output.txt", "w")
last_el = 0
elements = [0] * 1000000
for i in range (quantity):
    currstr = file.readline()
    if (currstr[0] == '-'):
        last_el -= 1
        outstring += (elements[last_el])
    else:
        elements[last_el] = currstr.split(" ")[1]
        last_el += 1

outfile.write(outstring)