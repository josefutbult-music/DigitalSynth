//
// Created by josef on 2019-06-26.
//

#ifndef SYNTH_TEST_OSCILLATOR_H
#define SYNTH_TEST_OSCILLATOR_H

#include "Sinusoid.h"

class Oscillator {

public:
    explicit Oscillator(double frequency, int _length);
    ~Oscillator();

    // Converts the array of sinusoid to an output value for a time t
    double generateSignal(double t);

protected:
    Sinusoid *sinusoid;
    int length;

    int getZeroPosition();
    void generateSawtoothWave(Sinusoid *model);
    void generateSinusWave(Sinusoid *model);
    void generateSquareWave(Sinusoid *model);
};


#endif //SYNTH_TEST_OSCILLATOR_H
