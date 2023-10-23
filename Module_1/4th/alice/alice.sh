#!/bin/bash

# Подсчет количества букв в произведении
text=$(<alice.txt)
letter_count=$(echo "$text" | tr -cd '[:alpha:]' | wc -m)
echo "Количество букв в произведении: $letter_count"

# Подсчет количества слов в произведении
word_count=$(echo "$text" | tr -s '[:space:]' | wc -w)
echo "Количество слов в произведении: $word_count"

# Поиск первого предложения, в котором упоминается королева
sentence=$(echo "$text" | grep -oE "[^.!?]*королева[^.!?]*[.!?]" | head -n 1)
echo "Первое предложение, в котором упоминается королева: $sentence"
