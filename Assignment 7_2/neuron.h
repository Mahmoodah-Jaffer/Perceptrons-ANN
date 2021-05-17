#ifndef NEURON_H
#define NEURON_H
#include <string>   // Needed for strings
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <math.h>
#include <vector>

using namespace std;

namespace JFFMAH001{
	class Neuron
	{
	private:
		double outputlBias;
		double target;
		std::vector<double> inputs;
		std::vector<double> bias;
		std::vector<double> hiddenlOutput;
		std::vector<double> hiddenlWeight;
		std::vector<std::vector<double>> weights;

	public: // public members
		Neuron(); // default constructor 
		~Neuron(); // destructor 

		//setters
		void setOutputLayerBias(double outputlBias);
		void setTarget(double target);
		void setInput(std::vector<double> inputs);
		void setBias(std::vector<double> bias);
		void setHiddenLayerWeights(std::vector<double> hiddenlWeight);
		void setWeights(std::vector<std::vector<double>> weights);

		double prodSum(int i);
		double hiddenProdSum(void);
		double mse(void); //mean square error
		double sigmoid(double net);

		void printToFile(void);

	};
}

#endif