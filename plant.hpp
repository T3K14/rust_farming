#include <vector>
#include <string_view>
#include <stdexcept>      // std::invalid_argument
#include <array>

class Plant {

    private:
        // U for no change
        enum Gene {X, W, Y, G, H, YG, YH, GH, U=99};
        std::array<Gene, 6> genes;
        std::vector<Plant> neighbours;



    public:
        Plant();
        Plant(std::string_view str);

        void crossbread();
        void addNeighbour(const Plant & neighbour);

        const std::array<Gene, 6> & getGenes() const;

};


struct Gene {
    float value;
};