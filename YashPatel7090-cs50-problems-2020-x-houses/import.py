import sys
import sqlite3
import csv


connection = sqlite3.connect("students.db")
cursor = connection.cursor()
sql_command = "DELETE FROM students;"
cursor.execute(sql_command)
connection.commit()


def main():
    if not len(sys.argv) == 2:
        print("Usage: python import.py characters.csv")
        sys.exit(1)

    with open(sys.argv[1], "r") as csvfile:
        csvcontent = csv.DictReader(csvfile, delimiter=",")
        for row in csvcontent:
            space = 0
            for x in row["name"]:
                if x == " ":
                    space += 1
            if space == 1:
                first, last = row["name"].split(sep=" ")
                sql_command = "INSERT INTO students (first, last, house, birth) VALUES ('{}', '{}', '{}', {});".format(
                    first, last, row["house"], row["birth"])
                cursor.execute(sql_command)
                connection.commit()
            if space == 2:
                first, middle, last = row["name"].split(sep=" ")
                sql_command = "INSERT INTO students (first, middle, last, house, birth) VALUES ('{}', '{}', '{}', '{}', {});".format(
                    first, middle, last, row["house"], row["birth"])
                cursor.execute(sql_command)
                connection.commit()
    connection.close()


if __name__ == "__main__":
    main()

