cmake_minimum_required(VERSION 3.14)
project(Synth_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Synth_test main.cpp FIFO.cpp FIFO.h Sinusoid.h Oscillator.cpp Oscillator.h SimpleSawtoothOscillator.h)