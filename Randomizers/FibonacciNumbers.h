class FibonacciNumbers : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override {
        x1 = (x2 + x1) % m;
        std::swap(x1, x2);

        if (x2 < 0){
            x2 += m;
        }
        return x2;
    }

    double rand() override {
        return ((double ) intRand())/m;
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
    int m = 37633;

    int x1 = 18253, x2 = 20173;
};

