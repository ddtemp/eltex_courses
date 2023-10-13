#!/bin/bash

echo "Enter your sentence"
read input
echo "$input" | sed 's/a/а/g; s/b/б/g; s/c/ц/g; s/d/д/g; s/e/е/g; s/f/ф/g; s/g/г/g; s/h/х/g; s/i/и/g; s/j/й/g; s/k/к/g; s/l/л/g; s/m/м/g; s/n/н/g; s/o/о/g; s/p/п/g; s/q/к/g; s/r/р/g; s/s/с/g; s/t/т/g; s/u/у/g; s/v/в/g; s/w/в/g; s/x/кс/g; s/y/у/g; s/z/з/g; s/A/А/g; s/B/Б/g; s/C/Ц/g; s/D/Д/g; s/E/Е/g; s/F/Ф/g; s/G/Г/g; s/H/Х/g; s/I/И/g; s/J/Й/g; s/K/К/g; s/L/Л/g; s/M/М/g; s/N/Н/g; s/O/О/g; s/P/П/g; s/Q/К/g; s/R/Р/g; s/S/С/g; s/T/Т/g; s/U/У/g; s/V/В/g; s/W/В/g; s/X/КС/g; s/Y/У/g; s/Z/З/g'

