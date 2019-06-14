//
// Created by josef on 2019-06-13.
//

#include "Sequenser.h"
#include <vector>
#include <cstdlib>
#include <math.h>
#include <iostream>

// Goes through the sinuid array and checks the used flag
int getZeroPosition(Sinouid* sinouid, int sinouidLength){
    for(int zeroPosition = 0; zeroPosition < sinouidLength; zeroPosition++ ){
        if(!sinouid[zeroPosition].used){
            return zeroPosition;
        }
    }
}

double sample(Sinouid* sinouid, int sinouidLength, double t){

    double result = 0;
    for(int i = 0; i < sinouidLength; i++){

        if(!sinouid[i].used){
            break;
        }

        // Where the magic happens. The cosinus value of the frequency multiplied by the current time and
        // offcet with the phase
        result += sinouid[i].amplitude * cos(sinouid[i].frequency * t + sinouid[i].phase);

    }

    return result;

}

void generateSawtoothWave(Sinouid* sinouid, int sinouidLength, Sinouid* model){

    int zeroPosition = getZeroPosition(sinouid, sinouidLength);

    // Appends sinuids to the sinuid array
    for(int k = 1; k < 50; k++ ){


        if(k >= sinouidLength){
            sinouid[k + zeroPosition].used = 0;
        }
        else{
            sinouid[k + zeroPosition - 1].used = 1;
            sinouid[k + zeroPosition - 1].amplitude = (pow(-1, k) * 2.0 * model->amplitude) / ((double)k * M_PI);
            sinouid[k + zeroPosition - 1].frequency = 2.0 * M_PI * k * model->frequency;
            sinouid[k + zeroPosition - 1].phase = M_PI / 2.0 + model->phase;
        }


    }


}

void generateSinusWave(Sinouid* sinouid, int sinouidLength, Sinouid* model){

    int zeroPosition = getZeroPosition(sinouid, sinouidLength);

    sinouid[zeroPosition].used = 1;
    sinouid[zeroPosition].amplitude = model->amplitude;
    sinouid[zeroPosition].frequency = model->frequency * 2.0 * M_PI;
    sinouid[zeroPosition].phase = model->phase;

}

void generateSquareWave(Sinouid* sinouid, int sinouidLength, Sinouid* model){

    int zeroPosition = getZeroPosition(sinouid, sinouidLength);

    for(int k = 1; k < 50; k++ ){

        sinouid[zeroPosition + k - 1].used = 1;
        sinouid[zeroPosition + k - 1].amplitude = (4.0 * model->amplitude) / (M_PI * (2.0 * k - 1.0));
        sinouid[zeroPosition + k - 1].frequency = 2.0 * M_PI * (2.0 * k - 1.0) * model->frequency;
        sinouid[zeroPosition + k - 1].phase = (M_PI / 2.0) + model->phase;

    }

}


void lowpassFilter(Sinouid* sinouid, int sinouidLength, double cutoffFreq){

    for(int i = 0; i < sinouidLength; i++ ){

        if(!sinouid[i].used){
            return;
        }

        else if(sinouid[i].amplitude > cutoffFreq){



        }

    }

}