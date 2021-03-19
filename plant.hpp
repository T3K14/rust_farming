#pragma once
#include <vector>
#include <string_view>
#include <array>
#include <string>
#include "Gene.hpp"

// U for no change
// enum Gene {X, W, Y, G, H, YG, YH, GH, U=99};


class Plant {

    private:
        // U for no change
        // enum Gene {X, W, Y, G, H, YG, YH, GH, U=99};
        std::array<Gene, 6> genes;
        std::vector<Plant> neighbours;

    public:

        Plant() = default;
        // creates plant from a string of the format "XXHWGY"
        Plant(std::string_view str);

        // calculates the new Gene for every geneslot according to the neighbour genes in this slot, the result might not be unambiguous because of the same impact of two different genetypes
        void crossbread();

        void addNeighbour(const Plant & neighbour);

        const std::array<Gene, 6> & getGenes() const;
        void printGenes() const;
        
        // void setGene(size_t index, const Gene & newGene);
};


// struct Gene {
//     float value;
// };