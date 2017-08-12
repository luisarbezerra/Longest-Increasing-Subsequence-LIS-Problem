CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c99 -pedantic
DEPS = auxiliares.h forcabruta.h guloso.h dinamico.h
Vflags = valgrind --leak-check=full
OBJ = main.o auxiliares.o forcabruta.o guloso.o dinamico.o
%.o: %.c $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

exec: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

	rm -rf *.o

run: exec
	./exec

val: exec
	$(Vflags) ./exec

exec_all: exec
	./exec < toy_0
	./exec < toy_1
	./exec < toy_2
	./exec < toy_3
	./exec < toy_4
	./exec < toy_5
	./exec < toy_6
	./exec < toy_7
	./exec < toy_8
	./exec < toy_9

testes: exec
	$(Vflags) ./exec < toy_0
	$(Vflags) ./exec < toy_1
	$(Vflags) ./exec < toy_2
	$(Vflags) ./exec < toy_3
	$(Vflags) ./exec < toy_4
	$(Vflags) ./exec < toy_5
	$(Vflags) ./exec < toy_6
	$(Vflags) ./exec < toy_7
	$(Vflags) ./exec < toy_8
	$(Vflags) ./exec < toy_9
