# tells grade level of the text
def main():
    while True:
        string = input("Text: ")
        try:
            int(string)
        except ValueError:
            break

    words = 1
    for x in string:
        if x == " ":
            words += 1

    sentences = 0
    for y in string:
        if y in [".", "?", "!"]:
            sentences += 1

    letters = 0
    for z in string:
        if z.isalpha():
            letters += 1

    L = (letters / words) * 100
    S = (sentences / words) * 100
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade > 15:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


if __name__ == "__main__":
    main()

