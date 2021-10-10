class ArensGammaDelimitation : public Randomizer {
public:
    static const std::string NAME;

    int intRand() override {
        return -1;
    }

    double rand() override {
        goto point10_1;
        point10_1:
        {
            y = std::tan(randomizer->rand() * atan(1) * 4);
            x = std::sqrt(2 * a - 1) * y + a - 1;
        }
        if (x <= 0) {
            goto point10_1;
        }
        double v = randomizer->rand();
        if (v > (1 + y * y) * std::exp((a - 1) * std::log(x / (a - 1)) - std::sqrt(2 * a - 1) * y)) {
            goto point10_1;
        }
        return x;
    }

    std::string getName() override {
        return NAME;
    }

    int getM() override {
        return -1;
    }

    int min() override {
        return 0;
    }

    int max() override {
        return 100;
    }

private:
    int a = 56;
    double x{}, y{};

    Randomizer *randomizer = new FibonacciNumbers();
};
