# Essay for Web Security Project Part 1

I began this part by looking at the members.php file. Inside I saw that the there was a cookie check for authentication
that was based off of a user's username. I changed that to be based off of a user's password. 

I then saw that the database was storing password in plain text. I used the password hash function to hash and salt the passwords before storing them in the database. I then used the password verify function, when users logged in, to check their plain text password input with the corresponding stored hash value.

I then implemented code to make it so the passwords could not be less than 8 characters in length when a user registered. I also made it so it could be a plain dictionary string. I made it so when users registered, they're password must have at least one special character in it to make it a non-dictionary password.   

I did not implement any functionality for part 3 as it's not really possible to prevent snooping completely with ssl (HTTPS). This is because HTTPS uses a private and public key to encrypt the data before transferring it over the network, then after it's tranferred it able to be decrypted with a users public key. There's no other way to do this fully with HTTPS. There ways to put in stumbling blocks such as using hashes etc, but nothing to fully prevent snooping besides HTTPS. 
