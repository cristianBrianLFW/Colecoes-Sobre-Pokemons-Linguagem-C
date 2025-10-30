
SOURCE = $(wildcard src/*.c) 

INCLUDE = $(wildcard include/*.h) 

OPTIONS = -g -Iinclude

build/main: $(SOURCE)
	$(CC) -o $@ $(OPTIONS) $^

$(info Pokemon temos que pegar voce)
