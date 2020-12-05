import sys
import sqlite3


connection = sqlite3.connect("students.db")
cursor = connection.cursor()


def main():
    if not len(sys.argv) == 2:
        print("Usage: python roster.py house")
        sys.exit(1)
    sql_command = "SELECT * FROM students WHERE house = '{}' ORDER BY last, first".format(sys.argv[1])
    cursor.execute(sql_command)
    data = cursor.fetchall()
    for row in data:
        if row[2] == None:
            print("{} {}, born {}".format(row[1], row[3], row[5]))
        else:
            print("{} {} {}, born {}".format(row[1], row[2], row[3], row[5]))
    connection.close()


if __name__ == "__main__":
    main()

