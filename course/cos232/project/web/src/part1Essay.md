# Essay for Web Security Project Part 1

I began this part by looking at the members.php file. Inside I saw that the there was a cookie check for authentication
that was based off of a user's username. I changed that to be based off of a user's password. 

I then saw that the database was storing password in plain text. I used the password hash function to hash and salt the passwords before storing them in the database. I then used the password verify function, when users logged in, to check their plain text password input with the corresponding stored hash value.

I then implemented code to make it so the passwords could not be less than 8 characters in length when a user registered. I also made it so it could be a plain dictionary string. I made it so when users registered, they're password must have at least one special character in it to make it a non-dictionary password.   
