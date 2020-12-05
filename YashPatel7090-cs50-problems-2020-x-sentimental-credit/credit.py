import sys


def main():
    # Gets input from user as a long integer (credit card number)
    while True:
        try:
            usr = int(input("Number: "))
        except ValueError:
            continue
        if not usr > 0:
            continue
        elif not len(str(usr)) in [13, 15, 16]:
            print("INVALID")
            sys.exit(1)
        else:
            break
    length = len(str(usr))

    # checksum
    tmp = usr
    summ = 0
    p = 1
    while True:
        if p == 1:
            tmp = int(tmp / 10)
            p = p + 1
        else:
            tmp = int(tmp / 100)
        if not tmp > 0:
            break
        digit = tmp % 10
        digit = digit * 2
        a = digit % 10
        b = int(digit / 10)
        summ = summ + a + b

    tmp2 = usr
    summ2 = 0
    while True:
        digit2 = tmp2 % 10
        summ2 = summ2 + digit2
        tmp2 = int(tmp2 / 100)
        if not tmp2 > 0:
            break

    firsttwo = usr
    while True:
        firsttwo = int(firsttwo / 10)
        if not firsttwo > 99:
            break

    first = usr
    while True:
        first = int(first / 10)
        if not first > 9:
            break

    # checks lastdigit == 0 and prints card type
    if (summ + summ2) % 10 == 0:
        if length == 13 and first == 4:
            print("VISA")
        elif length == 15 and (firsttwo in [34, 37]):
            print("AMEX")
        elif length == 16 and (firsttwo in [i + 51 for i in range(5)]):
            print("MASTERCARD")
        elif length == 16 and first == 4:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()

