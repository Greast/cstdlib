CFLAGS= -fPIC -std=c11 -pedantic -Wall -Werror -Wextra -Wuninitialized -Wmaybe-uninitialized -Werror=unused-function

FILES = std.o tree.o list.o queue.o

std: $(FILE)

shared : $(FILES)
	$(CC) -shared -o libstd.so $(CFLAGS)  $^

static : $(FILES)
	ar -rc libstd.a $^

clean :
	rm *.o *.so *.a
