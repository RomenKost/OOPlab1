class Ratio : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override{
        return -1;
    }

    int getM() override{
        return -1;
    }

    double rand() override {
        double u, v;

        goto point8_1;
        point8_1:{
            u = randomizer1->rand();
            v = randomizer2->rand();
        }
        if (u == 0){
            goto point8_1;
        }

        double x;
        x = std::sqrt(8.0/std::exp(1))*(v-1.0/2)/u;


        if (x*x <= 5 - 4*std::exp(1.0/4)*u){
            return x;
        }
        if (x*x >= 4*std::exp(4*std::exp(-1.35)/u+1.4)){
            goto point8_1;
        }
        if (x*x <= -4*std::log(u)){
            return x;
        } else {
            goto point8_1;
        }
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
    Randomizer * randomizer1 = new LinearCongruential();
    Randomizer * randomizer2 = new FibonacciNumbers();
};

