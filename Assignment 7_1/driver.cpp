#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "perceptron.h"

using namespace std;
using namespace JFFMAH001;


Perceptron train(std::vector<std::vector<float>> trainingData, int max_iter, float eta){
    Perceptron p(trainingData);

    p.learningRule(max_iter, eta);

    std::cout << "Weight 1: " << p.weights[0] << std::endl;
    std::cout << "Weight 2: " << p.weights[1] << std::endl;
    std::cout << "Weight 3: " << p.weights[2] << std::endl;

    int input1 = 0;
    int input2 = 0;

    std::cout << "[" << input1 << "," << input2 << "]: " << p.output(input1, input2) << std::endl;

    input1 = 1;
    input2 = 0;

    std::cout << "[" << input1 << "," << input2 << "]: "  << p.output(input1, input2) << std::endl;

    input1 = 0;
    input2 = 1;

    std::cout << "[" << input1 << "," << input2 << "]: "  << p.output(input1, input2) << std::endl;

    input1 = 1;
    input2 = 1;

    std::cout << "[" << input1 << "," << input2 << "]: "  << p.output(input1, input2) << std::endl;

    return p;
}

//connects perceptrons using logic to get XOR implementation
int XOR(float in1, float in2, Perceptron AND, Perceptron OR, Perceptron NAND){
	// A XOR B =  (A OR B) AND (A NAND B);

	//NAND perceptron
    int NANDo = NAND.output(in1, in2);

    //OR perceptron
    int ORo = OR.output(in1, in2);

    //AND perceptron
    return AND.output(NANDo, ORo);
}

int main(int argc, char* argv[]){

	std::vector<std::vector<float>> trainingData; //holds inputs and outputs for each perceptron

	// A XOR B =  (A OR B) AND (A NAND B);

	//AND logic
	std::vector<float> AND_1;
	AND_1.push_back(0);
	AND_1.push_back(0);
	AND_1.push_back(0);

	std::vector<float> AND_2;
	AND_2.push_back(0);
	AND_2.push_back(1);
	AND_2.push_back(0);

	std::vector<float> AND_3;
	AND_3.push_back(1);
	AND_3.push_back(0);
	AND_3.push_back(0);

	std::vector<float> AND_4;
	AND_4.push_back(1);
	AND_4.push_back(1);
	AND_4.push_back(1);

	//TRAINING AND
	trainingData.push_back(AND_1);
	trainingData.push_back(AND_2);
	trainingData.push_back(AND_3);
	trainingData.push_back(AND_4);


    Perceptron AND = train(trainingData,50,0.1);

     std::cout << "AND Perceptron trained!" << std::endl << std::endl;

    //Training for AND perceptron
/////////////////////////////////////////////////////////////////////////////////////////////////////////
    trainingData.clear(); //empty dataset

    //OR logic
    std::vector<float> OR_1;
	OR_1.push_back(0);
	OR_1.push_back(0);
	OR_1.push_back(0);

	std::vector<float> OR_2;
	OR_2.push_back(0);
	OR_2.push_back(1);
	OR_2.push_back(1);

	std::vector<float> OR_3;
	OR_3.push_back(1);
	OR_3.push_back(0);
	OR_3.push_back(1);

	std::vector<float> OR_4;
	OR_4.push_back(1);
	OR_4.push_back(1);
	OR_4.push_back(1);

    //TRAINING OR
    trainingData.push_back(OR_1);
	trainingData.push_back(OR_2);
	trainingData.push_back(OR_3);
	trainingData.push_back(OR_4);

    Perceptron OR = train(trainingData,50,0.1);

     std::cout << "OR Perceptron trained!" << std::endl << std::endl;
 /////////////////////////////////////////////////////////////////////////////////////////////////////////
    trainingData.clear(); //empty dataset

    //NAND logic
    std::vector<float> NAND_1;
	NAND_1.push_back(0);
	NAND_1.push_back(0);
	NAND_1.push_back(1);

	std::vector<float> NAND_2;
	NAND_2.push_back(0);
	NAND_2.push_back(1);
	NAND_2.push_back(1);

	std::vector<float> NAND_3;
	NAND_3.push_back(1);
	NAND_3.push_back(0);
	NAND_3.push_back(1);

	std::vector<float> NAND_4;
	NAND_4.push_back(1);
	NAND_4.push_back(1);
	NAND_4.push_back(0);
	
	//TRAINING NAND
	trainingData.push_back(NAND_1);
	trainingData.push_back(NAND_2);
	trainingData.push_back(NAND_3);
	trainingData.push_back(NAND_4);

    Perceptron NAND = train(trainingData,50,0.1);

    std::cout << "NAND Perceptron trained!" << std::endl << std::endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////

    float in1, in2;

    //pair 1
    in1 = 0;
    in2 = 0;

    std::cout << in1 << " XOR " << in2 << " gives an output of: " << XOR(in1,in2,AND,OR,NAND) << std::endl;

    //pair 2
    in1 = 0;
    in2 = 1;

    std::cout << in1 << " XOR " << in2 << " gives an output of: " << XOR(in1,in2,AND,OR,NAND) << std::endl;

    //pair 3
    in1 = 1;
    in2 = 0;

    std::cout << in1 << " XOR " << in2 << " gives an output of: " << XOR(in1,in2,AND,OR,NAND) << std::endl;

    //pair 4
    in1 = 1;
    in2 = 1;

    std::cout << in1 << " XOR " << in2 << " gives an output of: " << XOR(in1,in2,AND,OR,NAND) << std::endl;

   Perceptron p;
   p.printToFile();

    return 0;
}