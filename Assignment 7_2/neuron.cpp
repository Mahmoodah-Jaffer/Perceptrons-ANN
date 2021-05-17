#include <string>   // Needed for strings
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <cmath>
#include <vector>
#include <math.h>
#include <algorithm>
#include "neuron.h"

using namespace JFFMAH001;
using namespace std;

//constructor
JFFMAH001::Neuron::Neuron(){}


//destructor
JFFMAH001::Neuron::~Neuron(){}

//setters
void JFFMAH001::Neuron::setOutputLayerBias(double outputlBias){
	this->outputlBias = outputlBias;
}

void JFFMAH001::Neuron::setTarget(double target){
	this->target = target;
}


void JFFMAH001::Neuron::setInput(std::vector<double> inputs){
	this->inputs = inputs;
}
		
void JFFMAH001::Neuron::setBias(std::vector<double> bias){
	this->bias = bias;
}


void JFFMAH001::Neuron::setHiddenLayerWeights(std::vector<double> hiddenlWeight){
	this->hiddenlWeight = hiddenlWeight;
}


void JFFMAH001::Neuron::setWeights(std::vector<std::vector<double>> weights){
	this->weights = weights;
}

double JFFMAH001::Neuron::prodSum(int i){
	double sum;

	for(size_t x = 0; x < (this->weights.size()); x++){
		sum = sum + ((this->inputs[x])*(this->weights[x][i]));
	}

	return sum;
}

double JFFMAH001::Neuron::hiddenProdSum(void){

	double sum;

	for(size_t x = 0; x < (this->hiddenlWeight.size()); x++){
		sum = sum + ((this->hiddenlWeight[x])*(this->hiddenlOutput[x]));
	}

	return sum;

}

double JFFMAH001::Neuron::mse(void){
		double error = ((this->target)-(this->sigmoid((this->hiddenProdSum()) + (this->outputlBias))));
		return pow(error, 2.0);
}

double JFFMAH001::Neuron::sigmoid(double net){
	return 1/(1+exp(-net));
}


void JFFMAH001::Neuron::printToFile(void){
	std::ofstream outfile;

  	outfile.open("answers.txt"); 
	outfile << "Question 3:" << '\n';

	for (size_t x = 0; x < 2; x++) {
		this->hiddenlOutput.push_back(this->sigmoid(this->prodSum(x) + this->bias[x]));
	}


	for (size_t j = 0; j < this->hiddenlOutput.size(); j++) {
		outfile << "Output of hidden layer neuron " << (j+1) << ": " << (this->hiddenlOutput[j]) << '\n';
	}

	outfile << "Question 4:" << '\n';

	outfile << "Output Neuron: " << this->sigmoid(this->hiddenProdSum() + this->outputlBias) << '\n';

	outfile << "Question 5:" << '\n';

	outfile << "Mean Squared Error: " << (this->mse()) << '\n';

	outfile.close();
}
