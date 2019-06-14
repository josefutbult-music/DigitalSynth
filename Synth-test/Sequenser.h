#ifndef SYNTH_TEST_SEQUENSER_H
#define SYNTH_TEST_SEQUENSER_H

typedef struct Sinouid {

    double frequency;
    double amplitude;
    double phase;
    int used;

};

// Converts the array of sinuids to an output value for a time t
double sample(Sinouid* sinouid, int sinouidLength, double t);

// Generates a bunch of sinuids and appends them to the sinuid array
void generateSawtoothWave(Sinouid* sinouid, int sinouidLength, Sinouid* model);
void generateSinusWave(Sinouid* sinouid, int sinouidLength, Sinouid* model);
void generateSquareWave(Sinouid* sinouid, int sinouidLength, Sinouid* model);

// Goes through the sinuids and modulates the amplitude after its frequency
void lowpassFilter(Sinouid* sinouid, int sinouidLength, double cutoffFreq);


#endif //SYNTH_TEST_SEQUENSER_H
