import sys
import csv


def main():
    if not len(sys.argv) == 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    with open(sys.argv[1], mode="r") as csvfile:
        content = csv.reader(csvfile, delimiter=",")
        for row in content:
            firstrow = row
            break

    with open(sys.argv[2], mode="r") as txtfile:
        txt = txtfile.read()

    dictionary = {}
    wtmp = 1
    for w in range(len(firstrow)):
        if wtmp == 1:
            wtmp += 1
        else:
            temp = []
            for i in range(len(txt) - len(firstrow[w])):
                if txt[i] == firstrow[w][0]:
                    t = 0
                    for p in range(len(firstrow[w])):
                        if txt[i + p] == firstrow[w][p]:
                            t += 1
                    if t == len(firstrow[w]):
                        temp.append(i)
            temp2 = []
            repeats = 1
            for y in range(len(temp) - 1):
                if (temp[y] + len(firstrow[w])) == temp[y + 1]:
                    repeats += 1
                else:
                    temp2.append(repeats)
                    repeats = 1
            temp2.append(repeats)
            const = 0
            for u in temp2:
                if u > const:
                    const = u
            dictionary[f"{firstrow[w]}"] = const

    with open(sys.argv[1], mode="r") as csvfile2:
        dictionaries = csv.DictReader(csvfile2, delimiter=",")
        for row in dictionaries:
            e = 0
            c = 0
            for element in range(len(row)):
                if e == 0:
                    e += 1
                else:
                    if int(row[f"{firstrow[element]}"]) == int(dictionary[f"{firstrow[element]}"]):
                        c += 1
            if c == (len(row) - 1):
                winner = row[f"{firstrow[0]}"]
                print(winner)
                sys.exit(0)
        print("No Match")


if __name__ == "__main__":
    main()

