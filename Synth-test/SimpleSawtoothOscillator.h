//
// Created by josef on 2019-06-26.
//

#ifndef SYNTH_TEST_SIMPLESAWTOOTHOSCILLATOR_H
#define SYNTH_TEST_SIMPLESAWTOOTHOSCILLATOR_H

#include "Oscillator.h"

class SimpleSawtoothOscillator: public Oscillator{

public:
    SimpleSawtoothOscillator(double frequency, int length) : Oscillator(frequency, length) {
        Sinusoid modell = {frequency, BASEAMPLITUDE, BASEPHASE};
        generateSawtoothWave(&modell);
    }
};


#endif //SYNTH_TEST_SIMPLESAWTOOTHOSCILLATOR_H
