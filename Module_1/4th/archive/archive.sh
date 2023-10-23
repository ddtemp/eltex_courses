#!/bin/bash
tar -cvf my_archive.tar file1.txt
tar -tvf my_archive.tar
tar -rvf my_archive.tar file2.txt
tar -tvf my_archive.tar
tar -rvf my_archive.tar file3.txt
tar -tvf my_archive.tar
tar -xvf my_archive.tar --exclude=file2.txt
tar -cvf my_new_archive.tar *

mkdir my_folder

tar -xvf my_new_archive.tar -C my_folder/
