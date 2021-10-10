#include <vector>
#include <string>
#include <iostream>

struct Randomizer {
public:
    virtual int intRand() = 0;

    virtual double rand() = 0;

    virtual std::string getName() = 0;

    virtual int getM() = 0;

    virtual int min() = 0;

    virtual int max() = 0;
};
