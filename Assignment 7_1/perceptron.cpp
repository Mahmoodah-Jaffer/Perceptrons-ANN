#include <string>   // Needed for strings
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <cmath>
#include <vector>
#include <math.h>
#include <algorithm>
#include "perceptron.h"

using namespace JFFMAH001;
using namespace std;


//constructor
JFFMAH001::Perceptron::Perceptron(){}


//constructor
JFFMAH001::Perceptron::Perceptron(std::vector<std::vector<float>> trainingData):theta(1),weights(3, 0.0F){
    this->trainingData.resize(trainingData.size());

    for (int k = 0; k < trainingData.size(); ++k) {
        this->trainingData[k] = std::move(trainingData[k]);
    }

}


//destructor
JFFMAH001::Perceptron::~Perceptron(){
    for (int k = 0; k < trainingData.size(); ++k){
        trainingData[k].clear(); //empty pair
    }
        trainingData.clear(); //empty vector
}

void JFFMAH001::Perceptron::learningRule(int max_iter, float eta){
    for (int j = 0; j < max_iter; ++j){

        int errors = 0; //when actual output and target output don't match

        for (auto pair : trainingData){

            float input1 = pair[0];
            float input2 = pair[1];
            int tOutput = (int)pair[2];
            int output = 0;


            float sum = (input1*weights[0]) + (input2*weights[1]) + weights[2];

            if (sum > theta) {
                output = 1;
            }

            if (output != tOutput) {
                errors = errors +1;
                weights[0] = weights[0]  + (eta*(tOutput - output)*input1);
                weights[1] = weights[1]  + (eta*(tOutput - output)*input2);
                weights[2] = weights[2]  + (eta*(tOutput - output));
            }

        }
        if (errors == 0) {
            std::cout << "Number of iterations: " << j+1 << std::endl;
            break;
        }
    }
}

//returns perceptron output
int JFFMAH001::Perceptron::output(float input1, float input2){
        float sum = (input1*weights[0]) + (input2*weights[1]) + weights[2];
        int output;
        if (sum > theta){
        	output = 1;
        }else{
        	output = 0;
        }
        return output;
}

void JFFMAH001::Perceptron::printToFile(void){

	std::ofstream outfile;

  	outfile.open("answers.txt"); 
  	outfile << "Question 1:" << '\n';
  	outfile << "The minimum number of perceptrons required to solve the XOR problem is 3 perceptrons. The XOR logic gate is implemented by using an OR, NAND and AND gate.The logic that indicates how the perceptrons should be connected is given by the equation: A XOR B =  (A OR B) AND (A NAND B). The perceptrons should be connected in two layers, the first layer consisting of the OR and NAND perceptrons, and the output layer consisting of the AND perceptron." << '\n';
  	outfile << '\n';
  

  	outfile << '\n' << "Question 2:" << '\n';
  	outfile << "Each perceptron required the use of 4 training examples. Therefore, 12 training examples were used in total." << '\n';

  	outfile.close();

}
