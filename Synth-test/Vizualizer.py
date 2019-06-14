PATH = r'C:\Users\josef\Documents\Mega\Kod\C++\DigitalSynth\Synth-test\cmake-build-debug\Synth_test.exe'

import matplotlib.pyplot as plt
from subprocess import Popen, PIPE

def main():

    # Runs the C++ program
    process = Popen(PATH + ' 4100', stdout=PIPE)
    (output, err) = process.communicate()
    exit_code = process.wait()

    # Parses the output string to a shorter list
    output = str(output).split(' ')[1:100]
    output = [float(instance) for instance in output]

    # Plots with pyplot
    plt.plot(output)
    plt.show()


if __name__ == '__main__': main()