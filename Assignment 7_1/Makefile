CC = g++
CCFLAGS=-std=c++11

perceptron: driver.o perceptron.o #making an executable file that can be run
	$(CC) $(CCFLAGS) -o perceptron driver.o perceptron.o 

driver.o: driver.cpp perceptron.o
	$(CC) $(CCFLAGS) -c -o driver.o driver.cpp 

perceptron.o: perceptron.cpp perceptron.h
	$(CC) $(CCFLAGS) -c -o perceptron.o perceptron.cpp 

run: #change command line parameters here
	./perceptron
clean:
	@rm -f *.o #removing object files
	@rm perceptron #removing the executable produced 