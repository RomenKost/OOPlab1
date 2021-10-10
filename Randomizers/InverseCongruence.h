class InverseCongruential : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override {
        x = (a * binpow(x, m-2) + c) % m;
        if (x < 0) {
            x += m;
        }
        return x;
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
    int a = 8253729, c = 2396403, m = 37633;

    int x = 3;

    int binpow (int number, int pow) {
        number = number % m;
        if (number < 0){
            number += m;
        }
        if (pow == 0)
            return 1;
        if (pow % 2 == 1)
            return binpow(number, pow-1) * number % m;
        else {
            int b = binpow(number, pow/2);
            return b * b % m;
        }
    }
};