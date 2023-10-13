#!/bin/bash

read -p "Enter period of time (in seconds): " check_interval
read -p "Enter the path to source catalog: " source_directory
read -p "Enter the destination path for the backup: " backup_directory
read -p "Enter archive name: " archive_name

while true; do
	archive_name="${archive_name}_$(date "+%Y%m%d_%H%M%S").tar"
	tar -cvf "$backup_directory/$archive_name" "$source_directory"
	sleep "$check_interval"
done
