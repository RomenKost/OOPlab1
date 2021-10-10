class RandomizerService {
private:
    const int len = 10000;
    Randomizer * randomizer;

    double step{};

    void display(const std::string& name, std::vector<int> statistic) const {
        std::cout << "\nStatistic for " + name + " method:\n\n";
        for (int i = 0; i < 9; ++i) {
            std::printf("[%.1f;\t%.1f):\t%.4f\n",
                        randomizer->min()+(double) i*step,
                        randomizer->min()+(double) (i+1)*step,
                        ((double) statistic[i]) / len
                        );
        }
        std::printf("[%.1f;\t%.1f]:\t%.4f\n",
                    randomizer->min()+(double) 9*step,
                    randomizer->min()+(double) 10*step,
                    ((double) statistic[9]) / len
        );
    }
public:
    RandomizerService() : randomizer(nullptr) {}

    void countStatistic() {
        double u;
        std::vector<int> res(10);
        for (int i=0; i < len; ++i)
        {
            u = (randomizer -> rand() - randomizer -> min())/(randomizer -> max() - randomizer -> min());
            if (0<=u && u<1) {
                res[(int) (10 * u)]++;
            }
        }
        display(randomizer->getName(), res);
    }

    void setRandomize(Randomizer * rand){
        *&randomizer = rand;
        step = ((double)(rand->max()-rand->min()))/10;
    }
};
