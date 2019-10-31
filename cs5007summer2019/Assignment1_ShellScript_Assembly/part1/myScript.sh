#!/bin/bash
#my bash script does some nice jobs. First it asks user name. 
#And it ask user to remove a file. User will give a name of file to remove.
#file will be removed.
#first ask the user for their name
#print a message asking the user for input.
echo Hello, who am I talking to?
#run the command read and save the users response into the variable varname
read varname
#echo another message just to verify the read command worked.
echo It\'s nice to meet you $varname

#This command read -p asks the user for input and saves the input to answer
#The answer is an name of the varible, you can change to another name as well

read -p "$varname you can choose remove(delete)file. Please choose yes or no." answer
#echo the message from user's answer. It will print out on the screen
echo "You said $answer."
#if stament to check the user's response is yes
if [ $answer == 'yes' ]
then
  #ask the user to give a name to remove the file
  read -p "$varname could you please let me know which file you want to remove?" name
  #the echo give the message from user's answer.
echo "You said $name"
#use rm -v command remove file based on user's input
rm -v $name
#you can echo message to user 
echo "$varname you removed $name"
#when the code finish 
fi 
#if statment checks the if the answer is no, do the next line
if [ $answer == 'no' ]
then
#message the user no file will removed 
  read -p"$varname ok, no file will be removed"
#echo the message back to user
echo "$varname you are all set!"
fi
