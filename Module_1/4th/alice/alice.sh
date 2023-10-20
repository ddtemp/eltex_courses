#!/bin/bash

book_file="/home/ddtemp/Desktop/Eltex/Eltex_courses/Module_1/4th/alice/alice.txt"

# Задача 1: Вывести количество букв в произведении
letters_count=$(cat "$book_file" | sed -e 's/[^[:alpha:]]//g' | wc -m)

# Задача 2: Вывести количество слов в произведении
words_count=$(cat "$book_file" | sed -e 's/[^[:alpha:]]/ /g' | tr -s ' ' | wc -w)

# Задача 3: Вывести первое предложение, в котором упоминается королева
queen_sentence=$(sed -n '/[.!?]/{s/.*королев[а-я]*[.!?].*/&/p;q}' "$book_file")

# Задача 4: Вывести всех участников чаепития
tea_party_participants=$(sed -n '/чаепитие/,$s/[^[:alpha:]]/ /g;p' "$book_file" | grep -o -w '\w\+' | sort | uniq)

echo "Количество букв в произведении: $letters_count"
echo "Количество слов в произведении: $words_count"
echo "Первое упоминание королевы: $queen_sentence"
echo "Участники чаепития: $tea_party_participants"
