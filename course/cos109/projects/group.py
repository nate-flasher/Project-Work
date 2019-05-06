import sqlite3

menutext = """
C) Create a group
R) Show records in group table
U) Update a group
D) Delete a group
X) Exit the program
"""


connection = sqlite3.connect("AddressBook")
cursor = connection.cursor()


def create_group():

    print("\nCreate a new group")

    new_group = input(">>> Group name: ")
    new_notes = input(">>> Notes: ")

    values = (new_group, new_notes)

    cursor.execute('INSERT INTO group (group_name, notes) VALUES (?, ?, ?)', values)
    connection.commit()


def read_course():

    print("\nCourse records:")
    for row in cursor.execute('SELECT * FROM course'):
        print(row)


def update_course():
    read_course()
    modify_this_id = input(">>> Modify course (integer course identifier): ")

    cursor.execute("SELECT * FROM course WHERE course_id = ?", (modify_this_id))
    (course_id, cur_code, cur_title, cur_credit) = cursor.fetchone()

    new_code = input(">>> Course code [%s]: " % cur_code)
    if new_code == '':
        new_code = cur_code

    new_title = input(">>> Course title [%s]: " % cur_title)
    if new_title == '':
        new_title = cur_title

    new_credit = input(">>> Course credit [%s]: " % cur_credit)
    if new_credit == '':
        new_credit = cur_credit

    values = (new_code, new_title, new_credit, modify_this_id)
    cursor.execute("UPDATE course SET code = ?, title = ?, credit = ? WHERE course_id = ?", values)
    connection.commit()



def delete_course():

    read_course()
    delete_this_id = input(">>> Delete course(integer course identifier): ")

    cursor.execute("DELETE FROM course WHERE course_id = ?", delete_this_id)
    connection.commit()



while True:

    print(menutext)
    selection = input(">>> C,R,U,D, or X ot exit")

    if selection == 'X':
        break

    elif selection == 'C':
        create_group()

    elif selection == 'R':
        read_course()

    elif selection == 'U':
        update_course()

    elif selection == 'D':
        delete_course()