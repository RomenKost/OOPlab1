class Logarithm : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override {
        return -1;
    }

    double rand() override {
        x = -p * log(randomizer->rand());
        return x;
    }

    std::string getName() override{
        return NAME;
    }

    int getM() override{
        return -1;
    }

    int min() override{
        return 0;
    }

    int max() override{
        return 100;
    }
private:
    int p = 11;
    double x{};

    Randomizer * randomizer = new InverseCongruential();
};
