#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <string>   // Needed for strings
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <vector>

using namespace std;

namespace JFFMAH001{
    class Perceptron {
        private:
            std::vector<std::vector<float>> trainingData;
            int theta;
        public:
        	std::vector<float> weights;
        	Perceptron();
            Perceptron(std::vector<std::vector<float>> trainingData);
            ~Perceptron();
            void learningRule(int max_iter, float eta);
            int output(float input1, float input2);
            void printToFile(void);
    };
}

#endif