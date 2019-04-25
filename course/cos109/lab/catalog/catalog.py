import sqlite3

menutext = """
C) Create new course
R) Show records in course table
U) Update a course
D) Delete a course
X) Exit the program
"""


connection = sqlite3.connect("catalog.sqlite")
cursor = connection.cursor()


def create_course():

    print("\nCreate a new course")

    new_code = input(">>> Course code: ")
    new_title = input(">>> Course title: ")
    new_credit = input(">>> Course credit hours: ")

    values = (new_code, new_title, new_credit)

    cursor.execute('INSERT INTO course (code, title, credit) VALUES (?, ?, ?)', values)
    connection.commit()


def read_course():

    print("\nCourse records:")
    for row in cursor.execute('SELECT * FROM course'):
        print(row)



while True:

    print(menutext)
    selection = input(">>> C,R,U,D, or X ot exit")

    if selection == 'X':
        break

    elif selection == 'C':
        create_course()

    elif selection == 'R':
        read_course()