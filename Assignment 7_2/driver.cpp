#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "neuron.h"

int main(int argc, char* argv[]){
	using namespace std;
	using namespace JFFMAH001;

	Neuron n;

	n.setInput({1.30, 2.70, 0.80});
	n.setTarget(0.36);
	n.setBias({0.1, -0.3});
	n.setWeights({{0.1, -0.4}, {0.2, 1.0}, {0.5, -0.6}});
	n.setHiddenLayerWeights({0.8, 1.0});
	n.setOutputLayerBias(-0.3);
	n.printToFile();


	return 0;

}