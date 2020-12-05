def main():
    while True:                         # input from user makes sure its between 1 and 8 inclusive
        try:
            a = int(input("Height: "))
        except ValueError:
            continue
        if a > 0 and a < 9:
            break

    i = 1
    while i > 0 and i < a + 1:          # this does the printing of the hashes
        print(" "*(a - i), end="")
        print("#"*(i), end="")
        print("  ", end="")
        print("#"*(i))
        i = i + 1


if __name__ == "__main__":
    main()

