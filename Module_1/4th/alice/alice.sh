#!/bin/bash

book_file=$(cat "/home/ddtemp/Desktop/Eltex/4th/alice/alice.txt")

letters=$(echo $book_file | sed 's/[^[:alpha:]]//g' | wc -m)
words=$(echo $book_file | wc -w)
first_mention=$(echo $book_file | sed -n '/[.!?/{p;q;}' "$book_file" | grep -i 
королева)

echo "Amount of letters in the text: $letters"
echo "Amount of words in the text: $words"
echo "First queen's mention: $first_mention"

