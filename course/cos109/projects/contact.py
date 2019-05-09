import sqlite3

menutext = """
C) Create a contact
R) Show records in contact table
U) Update a contact
D) Delete a contact
E) Export to CSV file
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

    cursor.execute(
        "INSERT INTO 'contact' (Firstname, Lastname, Email_address, Secondary_email_address, "
        "Organization, Phone, Secondary_phone, Birthday, Notes) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", values)
    connection.commit()


def read_contact():

    print("\nContact records: ")
    for row in cursor.execute('SELECT * FROM "contact"'):
        print(row)


def update_contact():
    read_contact()
    modify_this_id = input(">>> Modify contact (Which contact number?): ")

    cursor.execute("SELECT * FROM 'contact' WHERE Contact_number = ?", (modify_this_id))
    (cur_firstname, cur_lastname, cur_emailaddress, cur_secondaryemailaddress, cur_organization, cur_phone, cur_secondaryphone, cur_birthday, cur_notes, Contact_number) = cursor.fetchone()

    new_firstname = input(">>> Contact Firstname [%s]: " % cur_firstname)
    if new_firstname == '':
        new_firstname = cur_firstname

    new_lastname = input(">>> Contact Lastname [%s]: " % cur_lastname)
    if new_lastname == '':
        new_lastname = cur_lastname

    new_emailaddress = input(">>> Contact email address [%s]: " % cur_emailaddress)
    if new_emailaddress == '':
        new_emailaddress = cur_emailaddress

    new_secondaryemailaddress = input(">>> Contact secondary email address [%s]: " % cur_secondaryemailaddress)
    if new_secondaryemailaddress == '':
        new_secondaryemailaddress = cur_secondaryemailaddress

    new_organization = input(">>> Contact organization [%s]: " % cur_organization)
    if new_organization == '':
        new_organization = cur_organization

    new_phone = input(">>> Contact phone number [%s]: " % cur_phone)
    if new_phone == '':
        new_phone = cur_phone

    new_secondaryphone = input(">>> Contact secondary phone number [%s]: " % cur_secondaryphone)
    if new_secondaryphone == '':
        new_secondaryphone = cur_secondaryphone

    new_birthday = input(">>> Contact birthday [%s]: " % cur_birthday)
    if new_birthday == '':
        new_birthday = cur_birthday

    new_notes = input(">>> Contact notes [%s]: " % cur_notes)
    if new_notes == '':
        new_notes = cur_notes


    values = (new_firstname, new_lastname, new_emailaddress, new_secondaryemailaddress, new_organization, new_phone, new_secondaryphone, new_birthday, new_notes, modify_this_id)
    cursor.execute("UPDATE 'contact' SET Firstname = ?, Lastname = ?, Email_address = ?, Secondary_email_address = ?, Organization = ?, Phone = ?, Secondary_phone = ?, Birthday = ?, Notes = ? WHERE Contact_number = ?", values)
    connection.commit()



def delete_contact():

    read_contact()
    delete_this_id = input(">>> Delete contact (Which contact number?): ")

    cursor.execute("DELETE FROM 'contact' WHERE Contact_number = ?", delete_this_id)
    connection.commit()


def export_contact():
    file = open("addressBook.csv","w")
    begin = True
    file.write("Firstname, Lastname, Email_address, Secondary_email_address, Organization, Phone, Secondary_phone, Birthday, Notes, Contact_number\n")
    for line in cursor.execute("SELECT * FROM 'contact'"):
        for field in line:
            if begin:
                file.write(str(field))
                begin = False
            else:
                file.write(", " + str(field))
        file.write('\n')
        begin = True
    file.close()




while True:

    print(menutext)
    selection = input(">>> C,R,U,D,E or X or exit")

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

    elif selection == 'E':
        export_contact()
