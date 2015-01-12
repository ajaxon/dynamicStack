clean:
	rm main


compile: main.cpp dstack.cpp
	g++ main.cpp -o main

run:
	./main