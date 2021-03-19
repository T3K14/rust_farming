#include <iostream>
// #include <array>
#include <stdexcept>
#include "Gene.hpp"
#include "plant.hpp"


Plant::Plant(std::string_view str){
    // std::cout << "Generated with string\n";
    if (str.size() != 6) {
        // std::cout << "Error\n";
        throw std::invalid_argument("A plant has 6 geneslots!\n");
    }

    for (int i=0;i<6;i++) {
        genes[i] = Gene(str[i]);
    }
}


// void Plant::setGene(size_t index, const Gene & newGene) {
//     genes[index].setGene(newGene);
// }


void Plant::crossbread() {

    std::array<float, 5> priorities {0.6f, .6f, 0.6f, 1.0f, 1.0f};
    std::array<char, 5> geneNames {'Y', 'G', 'H', 'W', 'X'};

    // for every geneslot
    for (int i=0; i<6; i++) {

        // store old Gene temporary if it is not replaced
        Gene oldGene(genes[i]);

        // counter indices for Y, G, H, W, X
        std::array<unsigned int, 5> counter {};

        for (Plant n : neighbours) {
            
            switch (n.getGenes()[i].getGeneTypeChar())
            {
            case 'Y':
                counter[0] += 1;
                break;
            case 'G':
                counter[1] += 1;
                break;
            case 'H':
                counter[2] += 1;
                break;
            case 'W':
                counter[3] += 1;
                break;
            case 'X':
                counter[4] += 1;
                break;
            default:
                throw std::invalid_argument("Something went wrong: A Gene returned a Type that should not be returned!\n");
                break;
            }
        }


        // for (int j = 0; j<5;j++) {
        //     std::cout << counter[j] << ", ";
        // }
        // std::cout << std::endl;

        // Gene newGene;
        // size_t maxIndex = 0;
        float maxVal=.6f;       // 0.6 because if there is no new gene stronger than 0.6 then there will be no change for that slot
        // get the gene that has the maximum value for this slot
        for (int j=0;j<5;j++) {
            float val = priorities[j] * counter[j];

            // std::cout << val << '\n';

            if (val > maxVal) {
                // std::cout << "maxval wird gesetzt\n";
                maxVal = val;
                // setGene(i, Gene(geneNames[j]));
                genes[i].setGene(Gene(geneNames[j])); // ???
                // std::cout << "newgene " << newGene << '\n';
            } else if(val > 0.6f && val == maxVal) {

                // ANNAHME TESTEN: Dass wenn zB fuer einen Genslot 8 Nachbarn mit den Genen YYYYYXXX vorhanden sind, dass es dann auch 50/50 ist (3 * 1 = 0.6 * 5)
                // das kann nur bei 8 Nachbarn passieren
                // if (neighbours.size() == 8 && ){

                // }
                // if new gene is already ambiguouse, then the old gene will not be changed
                if (genes[i].isAmbiguouse()) {
                    genes[i].setGene(oldGene);
                } else {
                    genes[i].setGeneProb(genes[i], Gene(geneNames[j]));
                }


                // newGene = static_cast<Gene>(newGene + j);       //if there are Genes with the same value, both are equally possible
                // newGene = ( newGene == Gene::U ?  :static_cast<Gene>(newGene + j));       //if there are Genes with the same value, both are equally possible

            }
            // std::cout << std::endl;
        }
    }

    // std::cout << "New Genes:\n";
    //     for (int i=0; i<6;i++) {
    //         std::cout << genes[i] << " ";
    //     }
    //     std::cout << '\n';

}

void Plant::addNeighbour(const Plant & neighbour){

    if (neighbours.size() == 8) {
        std::cout << "There cannot be more than 8 neighbours! The passed plant is not added to the neighbourlist!\n";
        return;
    }

    std::cout << "neighbour added\n";
    neighbours.push_back(neighbour);
}



const std::array<Gene, 6> & Plant::getGenes() const {
    return genes;
}

void Plant::printGenes() const {

    for (auto i : getGenes()) {

        // if (i.isAmbiguouse()) {
        //     std::cout << i.getGeneTypeChar() << "; ";
        // } else {
        std::cout << i.getGeneType() << ", ";
        // }

    }
    std::cout << '\n';
}

// int main() {

//     Plant a("WWXXHY");
    
//     Plant b("XXXGGG");
//     Plant c("WWGGGW");
//     Plant d("YGGWWX");
//     Plant e("YGGWXX");


//     auto genes = a.getGenes();

//     for (int i=0; i<6;i++) {
//         std::cout << genes[i] << ", ";
//     }
//     std::cout << "\n";


//     a.addNeighbour(b);
//     a.addNeighbour(c);
//     a.addNeighbour(d);
//     a.addNeighbour(e);
//     a.crossbread();

// }