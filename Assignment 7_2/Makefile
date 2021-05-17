CC = g++
CCFLAGS=-O 
LIB = --std=c++11

neuron: driver.o #making an executable file that can be run
	$(CC) $(CCFLAGS) -o neuron driver.o neuron.o $(LIB)

driver.o:neuron.o driver.cpp 
	$(CC) $(CCFLAGS) -c driver.cpp $(LIB)

neuron.o: neuron.h neuron.cpp 
	$(CC) $(CCFLAGS) -c neuron.cpp $(LIB)

run: #change command line parameters here
	./neuron
clean:
	@rm -f *.o #removing object files
	@rm neuron #removing the executable produced 