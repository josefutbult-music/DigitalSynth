#include <vector>
#include <iostream>
#include <math.h>
#include "Sequenser.h"

using namespace std;

int main(int argc, char **argv) {

    // Generates a temporary output vector
    vector<double> output;

    // Reads the sample rate from the program argument
    const int rate = atoi(argv[1]);

    // Generates an array for holding sinuids
    const int sinouidLength = 300;
    Sinouid sinouid[sinouidLength];

    // Generates 3 models that the oscillators are modeled after, to get a fitting amplitude, frequency and phase
    Sinouid model1 = {200, 10, 0};
    Sinouid model2 = {200, 3, M_PI * 3.0 / 4.0};
    Sinouid model3 = {200, 5, M_PI};

    // Creates two sawtooth waves and appends them to the sinouid array
    generateSawtoothWave(sinouid, sinouidLength, &model1);
    generateSinusWave(sinouid, sinouidLength, &model3);

    // Runs a bunch of samples on the resulting sinuid
    for(int i = 0; i < rate * 3; i++){
        output.push_back(sample(sinouid, sinouidLength, (double)i/rate));
    }

    // Outputs the samples
    for(int i = 0; i < output.size(); i++){
        cout << output.at(i) << ' ';
    }

}