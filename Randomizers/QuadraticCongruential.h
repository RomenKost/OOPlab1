class QuadraticCongruential : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override{
        x = (d*x*x + a*x + c) % m;
        if (x < 0) {
            x += m;
        }
        return x;
    }

    double rand() override {
        return ((double) intRand()) / m;
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
    int m = 1162261467, d = 14348907, a = 14348908, c = 65536;

    int x = 1;
};