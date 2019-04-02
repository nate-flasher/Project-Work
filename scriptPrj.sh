#!/bin/bash

# make this executable: chmod +x /path/to/myfilename.sh
# run this file: ./myfilename.sh


#Print stuff out
echo  "What is your name my friend?:"
# get user intput
read name


if [[ $name =~ \w* ]]; then
 echo "That's such a nice name!"
 echo $name >> test.txt
else
 echo "Hey! That's not your actual name!"
fi

echo  "May I ask how old you are" $name "?:"
#selection
if [[ $testvar =~ ^(yes)[0-9]$ ]]; then
 echo "ayyy works"
else
 echo ":("
fi

#get date and print it
echo "here is the date"
now=$(date)
    
    echo $now

# write data to a file
echo $name >>test.txt
echo \ "----------------" >> test.txt
echo $(date) >> test.txt
echo \ >> test.txt
echo $testvar >> test.txt
echo "wrote this to a file ha"

# iteration
for i in $(seq 1 10);
do
   echo $i
done

# read file and print it line by line
input="test.txt"
while IFS= read -r var
do
 echo "$var"
done < "$input"

# declare an array variable
declare -a arr=("element1" "element2" "element3")
# now loop through the above array
for i in "${arr[@]}"
do
  echo "$i"
  # or do whatever with individual element of the array
done
