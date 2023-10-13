#!/bin/bash

read -p "Enter alarm time (format hours:minutes): " alarm_time
read -p "Enter alarm's sound directory: " audio_file

echo "aplay $audio_file" | at $alarm_time
echo "Alarm is set on $alarm_time."
