class PolarCoordinate : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override{
        return -1;
    }

    int getM() override{
        return -1;
    }

    double rand() override {
        if(x2 != 1000000){
            double x1 = x2;
            x2 = 1000000;
            return x1;
        }

        double u1, u2;
        double v1, v2;

        goto point7_1;
        point7_1: {
            u1 = randomizer1->rand();
            u2 = randomizer2->rand();
        }

        v1 = 2 * u1 - 1;
        v2 = 2 * u2 - 1;
        double s = v1*v1 + v2*v2;

        if (s>=1){
            goto point7_1;
        }

        x2 = v2*(std::sqrt(-2*std::log(s)/s));
        return v1*(std::sqrt(-2*std::log(s)/s));
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
    double x2 = 1000000;
    Randomizer * randomizer1 = new LinearCongruential();
    Randomizer * randomizer2 = new FibonacciNumbers();
};
