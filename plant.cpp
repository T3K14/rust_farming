#include <iostream>
// #include <array>

#include "plant.hpp"


Plant::Plant(std::string_view str){
    // std::cout << "Generated with string\n";
    if (str.size() != 6) {
        std::cout << "Error\n";
        throw std::invalid_argument("A plant has 6 geneslots!\n");
    }

    //Markus fragen
    for (int i=0;i<6;i++) {
        Gene g;

        switch (str[i]) {
            case 'X':
                g = Gene::X;
                break;
            case 'W':
                g = Gene::W;
                break;
            case 'Y':
                g = Gene::Y;
                break;
            case 'G':
                g = G;
                break;
            case 'H':
                g = H;
                break;
            default:
                throw std::invalid_argument("This letter is not valid!\n");
        }

        genes[i] = g;
    }

}

void Plant::crossbread() {
    std::array<float, 5> priorities {1.0f, 1.0f, .6f, .6f, .6f};

    // for every geneslot
    for (int i=0; i<6; i++) {

        std::array<unsigned int, 5> counter {};

        for (Plant n : neighbours) {
            // std::cout <<"drin\n";
            // switch(n.genes[i]) {
            //     case Plant::Gene::G
            // }
            // std::cout <<n.genes[i] << '\n';
            counter[n.genes[i]] += 1;
        }


        for (int j = 0; j<5;j++) {
            std::cout << counter[j] << ", ";
        }
        std::cout << std::endl;

        Gene newGene = Gene::U;
        // size_t maxIndex = 0;
        float maxVal=.6f;       // 0.6 because if there is no new gene stronger than 0.6 then there will be no change for that slot
        // get the gene that has the maximum value for this slot
        for (int j=0;j<5;j++) {
            float val = priorities[j] * counter[j];

            std::cout << val << '\n';

            if (val > maxVal) {
                // std::cout << "maxval wird gesetzt\n";
                maxVal = val;
                // maxIndex = j;
                newGene = static_cast<Gene>(j);
                std::cout << "newgene " << newGene << '\n';
            } else if(val > 0.6f && val == maxVal) {

                // ANNAHME TESTEN: Dass wenn zB fuer einen Genslot 8 Nachbarn mit den Genen YYYYYXXX vorhanden sind, dass es dann auch 50/50 ist (3 * 1 = 0.6 * 5)
                // das kann nur bei 8 Nachbarn passieren
                if (neighbours.size() == 8 && ){

                }

                newGene = static_cast<Gene>(newGene + j);       //if there are Genes with the same value, both are equally possible
                // newGene = ( newGene == Gene::U ?  :static_cast<Gene>(newGene + j));       //if there are Genes with the same value, both are equally possible

            }
            std::cout << std::endl;
        }

        if (newGene == Gene::U) {
            newGene = genes[i];
        }

        genes[i] = newGene;

    }

    std::cout << "New Genes:\n";
        for (int i=0; i<6;i++) {
            std::cout << genes[i] << " ";
        }
        std::cout << '\n';

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

        switch(i) {
            case Y:
            std::cout << "Y ";
            break;
            case G:
            std::cout << "G ";
            break;
            case H:
            std::cout << "H ";
            break;
            case W:
            std::cout << "W ";
            break;
            case X:
            std::cout << "X ";
            break;
            default:
            std::cout << (int) i;
        }
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