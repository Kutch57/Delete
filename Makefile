CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic

SRC = main.c shell.c builtins.c getline_custom.c split_commands.c \
      execute.c shell_cd.c alias.c split_line.c \
      get_exit_status.c get_pid.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) -o shell $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) shell

