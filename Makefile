CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic

simple_shell: main.o shell.o builtins.o
	$(CC) $(CFLAGS) main.o shell.o builtins.o -o simple_shell

main.o: main.c shell.h
	$(CC) $(CFLAGS) -c main.c

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

builtins.o: builtins.c shell.h
	$(CC) $(CFLAGS) -c builtins.c

clean:
	rm -f *.o simple_shell

