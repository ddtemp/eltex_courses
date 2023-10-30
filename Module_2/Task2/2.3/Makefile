CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -ldl
SOURCES = main.c
EXECUTABLE = calculator
SHARED_LIB = libcalc.so

all: $(SHARED_LIB) $(EXECUTABLE)

$(SHARED_LIB): calc.c calc.h
	$(CC) $(CFLAGS) -shared -o $(SHARED_LIB) calc.c

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) $(LIBS)

clean:
	rm -f $(EXECUTABLE) $(SHARED_LIB)

.PHONY: all clean
