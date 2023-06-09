FLAGS = -Wall -Werror -Wextra
EXE = div

all: main.o natural.o divisible.o divider.o
	g++ $(FLAGS) main.o natural.o divisible.o divider.o -o $(EXE)

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

natural.o: natural.cpp
	g++ $(FLAGS) -c natural.cpp

divisible.o: divisible.cpp
	g++ $(FLAGS) -c divisible.cpp

divider.o: divider.cpp
	g++ $(FLAGS) -c divider.cpp

clean:
	rm -f *.o $(EXE)

rebuild: clean all