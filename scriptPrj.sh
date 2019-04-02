#!/bin/bash

# make this executable: chmod +x /path/to/myfilename.sh
# run this file: ./myfilename.sh

echo  "What is your name my friend?:"

read name

if [[ $name =~ \D* ]]; then
 echo "That's such a nice name!"
 echo "Name:"$name >> outFile.txt
else
 echo "Hey! That's not your actual name!"
fi


echo  "May I ask how old you are" $name "?:"

read age
#selection
if [[ $age =~ [0-99] ]]; then
 echo "You're a youngin'! Got your whole life ahead of you still!"
 echo "Age:"$age >> outFile.txt
else
 echo "Please enter a valid age!"
fi


# iteration
echo "Would you like to count from 0 up to your age" $name "?: (yes/no)"

read answer

if [[ $answer =~ "yes" ]]; then

for i in $(seq 0 $age)
    do
        echo $i
    done
   
    else
        echo "You're a loser, no fun =("
fi

echo "Let's have some more fun!"

echo "Give me an adjective"

read adj

echo "Give me another adjective"

read adjj

echo "Give me a noun" 

read noun

echo "Your rapper name is" $adj $adjj $noun"!"


# declare an array variable
declare -a arr=("$adj" "$adjj" "$noun")
# now loop through the above array
for i in "${arr[@]}"
do
  echo "$i" >> outFile.txt
done

echo "________________________________________________" >> outFile.txt

echo "Also here's the date by the way!"

#get date and print it
now=$(date)
    
    echo $now
