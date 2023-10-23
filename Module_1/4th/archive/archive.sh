#!/bin/bash

# Создание архива с одним файлом
tar -cvf my_archive.tar file1.txt

# Показать содержимое архива
tar -tvf my_archive.tar

# Добавить второй файл в архив
tar -rvf my_archive.tar file2.txt

# Показать содержимое архива после добавления второго файла
tar -tvf my_archive.tar

# Добавить третий файл в архив
tar -rvf my_archive.tar file3.txt

# Показать содержимое архива после добавления третьего файла
tar -tvf my_archive.tar

# Удалить второй файл из архива
tar -xvf my_archive.tar --exclude=file2.txt
tar -cvf my_new_archive.tar *

# Создать папку для распаковки архива
mkdir my_folder

# Распаковать архив в созданную папку
tar -xvf my_new_archive.tar -C my_folder/
