class ThreeSigma : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override{
        return -1;
    }

    int getM() override{
        return -1;
    }

    double rand() override {
        double sum = 0;
        for (int i=0; i<12; i++){
            sum += randomizer->rand();
        }
        return sum-6;
    }

    std::string getName() override{
        return NAME;
    }

    int min() override{
        return -3;
    }

    int max() override{
        return 3;
    }
private:
    Randomizer * randomizer = new FibonacciNumbers();
};

