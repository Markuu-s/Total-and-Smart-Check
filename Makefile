all:
	g++ -std=c++2a main.cpp classFiles/*.cpp headerFiles/*.h -o TSC
clean:
	rm -rf *.o TSC