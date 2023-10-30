CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCES = main.c
EXECUTABLE = main.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean
