class LinearCongruential : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override {
        x = (a * x + c) % m;
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

    int x = 0;
};
