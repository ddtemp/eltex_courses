#!/bin/bash

main_directory="/home/ddtemp/Desktop/Eltex/3rd"

for folder_num in {1..10}; do
	folder_name="$main_directory/folder_number_$folder_num"
	mkdir -p "$folder_name"

	for subfolder_num in {1..11}; do
		subfolder_name="$folder_name/subfolder_number_$subfolder_num"
		mkdir -p "$subfolder_name"

		for file_num in {1..12}; do
			touch "$subfolder_name/file_number_$file_num"
		done
	done
done
