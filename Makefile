all:
	g++ -std=c++2a main.cpp classFiles/*.cpp headerFiles/*.h -o main
clean:
	rm -rf *.o main