//
// Created by josef on 2019-06-26.
//

#include "Oscillator.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <algorithm>

Oscillator::Oscillator(double frequency, int _length) {

    // Generates an array for holding sinuids
    sinusoid = new Sinusoid[length];
    length = _length;

    for(int i = 0; i < length; i++){
        sinusoid[i].used = 0;
    }

}

Oscillator::~Oscillator() {

    delete sinusoid;

}

double Oscillator::generateSignal(double t) {

    double result = 0;
    for(int i = 0; i < length; i++){

        if(!sinusoid[i].used){
            break;
        }

        // Where the magic happens. The cosinus value of the frequency multiplied by the current time and
        // offcet with the phase
        result += sinusoid[i].amplitude * cos(sinusoid[i].frequency * 2.0 * M_PI * t + sinusoid[i].phase);

    }

    return result;
}

// Goes through the sinuid array and checks the used flag
int Oscillator::getZeroPosition(){
    for(int zeroPosition = 0; zeroPosition < length; zeroPosition++ ){
        if(!sinusoid[zeroPosition].used){
            return zeroPosition;
        }
    }
}


void Oscillator::generateSawtoothWave(Sinusoid* model){

    int zeroPosition = getZeroPosition();

    // Appends sinuids to the sinuid array
    for(int k = 1; k < 50; k++ ){
        
        if(k >= length){
            sinusoid[k + zeroPosition].used = 0;
        }
        else{
            sinusoid[k + zeroPosition - 1].used = 1;
            sinusoid[k + zeroPosition - 1].amplitude = (pow(-1, k) * 2.0 * model->amplitude) / ((double)k * M_PI);
            sinusoid[k + zeroPosition - 1].frequency = k * model->frequency;
            sinusoid[k + zeroPosition - 1].phase = M_PI / 2.0 + model->phase;
        }

    }

}

void Oscillator::generateSinusWave(Sinusoid* model){

    int zeroPosition = getZeroPosition();

    sinusoid[zeroPosition].used = 1;
    sinusoid[zeroPosition].amplitude = model->amplitude;
    sinusoid[zeroPosition].frequency = model->frequency;
    sinusoid[zeroPosition].phase = model->phase;

}

void Oscillator::generateSquareWave(Sinusoid* model){

    int zeroPosition = getZeroPosition();

    for(int k = 1; k < 50; k++ ){

        sinusoid[zeroPosition + k - 1].used = 1;
        sinusoid[zeroPosition + k - 1].amplitude = (4.0 * model->amplitude) / (M_PI * (2.0 * k - 1.0));
        sinusoid[zeroPosition + k - 1].frequency = (2.0 * k - 1.0) * model->frequency;
        sinusoid[zeroPosition + k - 1].phase = (M_PI / 2.0) + model->phase;

    }

}