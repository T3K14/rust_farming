#include <vector>
#include <string_view>
#include <stdexcept>      // std::invalid_argument
#include <array>
#include <string>

// U for no change
// enum Gene {X, W, Y, G, H, YG, YH, GH, U=99};

class Gene {

    std::string genetype;

    public:
        Gene(char name);
        virtual ~Gene() = default;

};


class Plant {


    private:
        // U for no change
        // enum Gene {X, W, Y, G, H, YG, YH, GH, U=99};
        std::array<Gene, 6> genes;
        std::vector<Plant> neighbours;



    public:

        // enum Gene {X, W, Y, G, H, YG, YH, GH, U=99};


        Plant();
        Plant(std::string_view str);

        void crossbread();
        void addNeighbour(const Plant & neighbour);

        const std::array<Gene, 6> & getGenes() const;
        void printGenes() const;
};


// struct Gene {
//     float value;
// };