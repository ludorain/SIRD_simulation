main: people.o parameters.o pandemic.o main.o
	g++ -o main $^

parameters.o: parameters.cpp
	g++ -c parameters.cpp

people.o: people.cpp
	g++ -c people.cpp

pandemic.o: pandemic.cpp
	g++ -c pandemic.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	make && ./main

clean:
	rm ./*.o && rm main