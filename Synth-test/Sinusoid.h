//
// Created by josef on 2019-06-26.
//

#ifndef SYNTH_TEST_SINUSOID_H
#define SYNTH_TEST_SINUSOID_H

#define BASEAMPLITUDE 10
#define BASEPHASE 0

typedef struct Sinusoid{

    double frequency;
    double amplitude;
    double phase;
    int used;

};


#endif //SYNTH_TEST_SINUSOID_H
