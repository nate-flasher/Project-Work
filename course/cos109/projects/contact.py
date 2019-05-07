import sqlite3

menutext = """
C) Create a contact
R) Show records in contact table
U) Update a contact
D) Delete a contact
X) Exit the program
"""


connection = sqlite3.connect("AddressBook")
cursor = connection.cursor()


def create_contact():

    print("\nCreate a new contact")

    new_firstname = input(">>> Firstname: ")
    new_lastname = input(">>> Lastname: ")
    new_emailaddress = input(">>> Email address: ")
    new_secondaryemailaddress = input(">>> Secondary email address: ")
    new_organization = input(">>> Organization: ")
    new_phone = input(">>> Phone number (xxx-xxx-xxxx): ")
    new_secondaryphone = input(">>> Secondary phone number: ")
    new_birthday = input(">>> Birthday (xx/xx/xxxx): ")
    new_notes = input(">>> Notes: ")

    values = (new_firstname, new_lastname, new_emailaddress, new_secondaryemailaddress, new_organization, new_phone, new_secondaryphone, new_birthday, new_notes)

    cursor.execute('INSERT INTO "contact" (Firstname, Lastname, "Email address", "Secondary email address", Organization, Phone, "Secondary phone", Birthday, Notes) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)', values)
    connection.commit()


def read_contact():

    print("\nContact records: ")
    for row in cursor.execute('SELECT * FROM "contact"'):
        print(row)


def update_contact():
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



def delete_contact():

    read_contact()
    delete_this_id = input(">>> Delete contact (Which contact number?): ")

    cursor.execute("DELETE FROM 'contact' WHERE Contact_number = ?", delete_this_id)
    connection.commit()



while True:

    print(menutext)
    selection = input(">>> C,R,U,D, or X ot exit")

    if selection == 'X':
        break

    elif selection == 'C':
        create_contact()

    elif selection == 'R':
        read_contact()

    elif selection == 'U':
        update_contact()

    elif selection == 'D':
        delete_contact()