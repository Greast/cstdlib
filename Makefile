CFLAGS= -fPIC -std=c11 -pedantic -Wall -Werror -Wextra -Wuninitialized -Wmaybe-uninitialized -Werror=unused-function

FILES = std.o tree.o list.o queue.o
NAME = std


std: $(FILES)
	$(CC) -c $^

shared : $(FILES)
	$(CC) -shared -o lib$(NAME).so $(CFLAGS) $^

static : $(FILES)
	ar -rc lib$(NAME).a $^

clean :
	rm *.o *.so *.a
