#!/bin/bash

pids=$(ps -eo pid)

for pid in $pids; do
	ppid=$(ps -o ppid= -p $pid)

	if [ "$ppid" = "1"]; then
		ps -p $pid -o pid,ppid,cmd
	fi
done
