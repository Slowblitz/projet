CFLAGS=-Wall
EXEC=pentago

all: $(EXEC)

$(EXEC): main.o plateau.o
		g++ -o $@ $^

main.o: main.cpp
		g++ -o $@ -c $^ $(CFLAGS)

plateau.o: plateau.cpp
		g++ -o $@ -c $^ $(CFLAGS)

clean: 
	rm -rf *.o


