#!/bin/bash

#reading directory
echo "Input files directory"
read main_directory
echo ""

#check if directory is exist
if [ ! -d "$main_directory" ]; then
        echo "Directory is not found"
        exit 1
fi


#reading number of folders, subfolders, files
echo "Input number of folders, subfolders and files
Use space as separator between values"
read num_of_folders num_of_subfolders num_of_files

#reading folder's, subfolder's, file's name
echo "Input folder's, subfolder's, file's names
Use space as separator between names"
read folder_name subfolder_name file_name

#check if numbers in input
if ! [[ "$num_of_folders" =~ ^[0-9]+$ ]] || ! [[ "$num_of_subfolders" =~ ^[0-9]+$ ]] || ! [[ "$num_of_files" =~ ^[0-9]+$ ]]; then
	echo "Invalid numbers"
	exit 1
fi

for ((folder_num = 1; folder_num <= num_of_folders; folder_num++)); do
	folder="$main_directory/${folder_name}_$folder_num"
	mkdir -p "$folder"

	for ((subfolder_num = 1; subfolder_num <= num_of_subfolders; subfolder_num++)); do
		subfolder="$folder/${subfolder_name}_$subfolder_num"
		mkdir -p "$subfolder"

		for ((file_num = 1; file_num <= num_of_files; file_num++)); do
			touch "$subfolder/${file_name}_$file_num"
		done
	done
done

