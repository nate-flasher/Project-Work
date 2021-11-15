# Essay for Web Security Project Part 3

For this part of the assignment I first looked through the php code in all of the different files to find all instances where an SQL query was used to acess the database. There were a few different locations I could choose to perform an SQL attack at, but I chose show.php.

It was a lot more of a struggle to craft the attack than I thought it was going to be. There are many different ways to perform a SQL injection attack. I decided to UNION the first table (threads, non-malicious) with the second table (users, malicious in the sense that the information (passwords) I was taking from the table should not be seen to any user). The specifically crafted input (URL) involved unioning the first part of the query that was already in the code with my attack where I selected columns from the users table to replace columns in the threads table in a very specific pattern. I then added a WHERE that specifified that the username is equal to any string you actually want since there is an OR that says a = a. This will always be true and since it's and OR and at least one side of the OR is true it doesn't matter what string/username you actually input into that part of the URL. 

With all of this being said, the easily readable added malicious input to the URL is this: a' UNION SELECT fname, username, lname, pass, lname FROM user WHERE username = 'randomString' OR 'a'='a

To perform this attack for yourself, log in to any account on my website and copy and paste the URL in the file called part4SQLinjectionAttackURLPayload.txt.

This will inject the payload into the SQL query and perform that action on behalf of the attacker.   

I patched/fixed the SQL injection vulnerability by using parameterized queries. I took user input and passed them into a built in php function to escape certain characters in their input so they could not be interpreted as certain delimiters that allow for injection attacks. I then set each of the escaped inputs equal to corresponding variables. I finally then put those variables themselves into the query. This was all done to prevent user input being directly injected into the sql query. 
