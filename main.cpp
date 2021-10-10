#include "Randomizer.h"
#include "RamdomizerService.h"

#include "Randomizers/LinearCongruential.cpp"
#include "Randomizers/QuadraticCongruential.cpp"
#include "Randomizers/FibonacciNumbers.cpp"
#include "Randomizers/InverseCongruence.cpp"
#include "Randomizers/Joining.cpp"

#include "Randomizers/ThreeSigma.cpp"
#include "Randomizers/PolarCoordinate.cpp"
#include "Randomizers/Ratio.cpp"

#include "Randomizers/Logarithm.cpp"
#include "Randomizers/ArensGammaDelimitation.cpp"

int getMethodNumber(){
    std::cout << "Please, chose the method of random:\n"
                 "1)\t" + LinearCongruential::NAME + " method\n" +
                 "2)\t" + QuadraticCongruential::NAME + " method\n" +
                 "3)\t" + FibonacciNumbers::NAME + " method\n" +
                 "4)\t" + InverseCongruential::NAME + " method\n" +
                 "5)\t" + Joining::NAME + " method\n\n" +
                 "6)\t" + ThreeSigma::NAME + " method\n"
                 "7)\t" + PolarCoordinate::NAME + " method\n" +
                 "8)\t" + Ratio::NAME + " method\n\n" +
                 "9)\t" + Logarithm::NAME + " method\n"+
                 "10)\t" + ArensGammaDelimitation::NAME + " method\n\n"+
                 "Number of method:";
    int method;
    std::cin >> method;
    return method;
}

int main(){
    RandomizerService randomizerService = RandomizerService();

    switch (getMethodNumber()){
        case 1: {
            randomizerService.setRandomize(new LinearCongruential());
            break;
        }
        case 2: {
            randomizerService.setRandomize(new QuadraticCongruential());
            break;
        }
        case 3: {
            randomizerService.setRandomize(new FibonacciNumbers());
            break;
        }
        case 4: {
            randomizerService.setRandomize(new InverseCongruential());
            break;
        }
        case 5: {
            randomizerService.setRandomize(new Joining());
            break;
        }
        case 6:{
            randomizerService.setRandomize(new ThreeSigma());
            break;
        }
        case 7: {
            randomizerService.setRandomize(new PolarCoordinate());
            break;
        }
        case 8:{
            randomizerService.setRandomize(new Ratio());
            break;
        }
        case 9: {
            randomizerService.setRandomize(new Logarithm());
            break;
        }
        case 10:{
            randomizerService.setRandomize(new ArensGammaDelimitation());
            break;
        }
        default: {
            std::cout << "Wrong input!";
            return -1;
        }
    }
    randomizerService.countStatistic();
}
