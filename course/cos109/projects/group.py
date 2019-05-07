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

    new_gName = input(">>> Group name: ")
    new_Notes = input(">>> Notes: ")

    values = (new_gName, new_Notes)

    cursor.execute('INSERT INTO "group" (Group_name, Notes) VALUES (?, ?)', values)
    connection.commit()


def read_group():

    print("\nGroup records:")
    for row in cursor.execute('SELECT * FROM "group"'):
        print(row)


def update_group():
    read_group()
    modify_this_id = input(">>> Modify group (Which group number?): ")

    cursor.execute("SELECT * FROM 'group' WHERE Group_number = ?", (modify_this_id))
    (cur_name, cur_note, Group_number) = cursor.fetchone()

    new_note = input(">>> Group notes [%s]: " % cur_note)
    if new_note == '':
        new_note = cur_note

    new_name = input(">>> Group name [%s]: " % cur_name)
    if new_name == '':
        new_name = cur_name


    values = (new_note, new_name, modify_this_id)
    cursor.execute("UPDATE 'group' SET Notes = ?, Group_name = ? WHERE Group_number = ?", values)
    connection.commit()



def delete_group():

    read_group()
    delete_this_id = input(">>> Delete group (Which group number?): ")

    cursor.execute("DELETE FROM 'group' WHERE Group_number = ?", delete_this_id)
    connection.commit()



while True:

    print(menutext)
    selection = input(">>> C,R,U,D, or X ot exit")

    if selection == 'X':
        break

    elif selection == 'C':
        create_group()

    elif selection == 'R':
        read_group()

    elif selection == 'U':
        update_group()

    elif selection == 'D':
        delete_group()