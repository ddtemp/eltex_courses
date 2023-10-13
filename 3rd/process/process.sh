#!/bin/bash

read -p "Enter period of time (in seconds): " check_interval

#main
while true; do
	if ! pgrep telegram-desktop > /dev/null; then
	    telegram-desktop &	    
  	fi
  sleep "$check_interval"
done


