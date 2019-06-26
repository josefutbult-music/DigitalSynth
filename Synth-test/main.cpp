#include <vector>
#include <iostream>
#include "SimpleSawtoothOscillator.h"

using namespace std;

int main(int argc, char **argv) {

    // Reads the generateSignal rate from the program argument
    const int rate = atoi(argv[1]);

    SimpleSawtoothOscillator oscillator(200, rate);

    // Runs a bunch of samples on the resulting sinuid
    for(int i = 0; i < rate * 3; i++){
        cout << oscillator.generateSignal((double) i / rate)  << ' ';
    }


}