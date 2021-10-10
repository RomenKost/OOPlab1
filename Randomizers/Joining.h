class Joining : public Randomizer{
public:
    static const std::string NAME;

    int intRand() override {
        int z;
        z = xRandomizer->intRand() - yRandomizer->intRand();
        if (z < 0) {
            z += m;
        }
        return z;
    }

    double rand() override {
        return ((double) intRand())/m;
    }

    std::string getName() override{
        return NAME;
    }

    int getM() override{
        return m;
    }

    int min() override{
        return 0;
    }

    int max() override{
        return 1;
    }
private:
    Randomizer * xRandomizer = new FibonacciNumbers();
    Randomizer * yRandomizer = new InverseCongruential();
    int m = std::max(xRandomizer->getM(), yRandomizer->getM());
};

