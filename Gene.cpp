#include <stdexcept>
#include "Gene.hpp"

Gene::Gene(char name) {

    switch (name) {
        case 'Y':
        case 'G':
        case 'H':
            isBad = false;
            priority = 0.6f;
            break;
        case 'W':
        case 'X':
            isBad = true;
            priority = 1.0f;
            break;
        default:
            throw std::invalid_argument("This char is not valid!\n");
            break;
    }
    genetype = name;
}



void Gene::setGene(const Gene & other) {

    multipleGenetype = std::string{};

    genetype = other.genetype;
    isBad = other.isBad;
}

void Gene::setGeneProb(const Gene & first, const Gene & second) {

    // if two genes are equalliy likely, then the one which comes first in the alphabet will be written first
    std::string g1(1, first.genetype);
    std::string g2(1, second.genetype);
    multipleGenetype = (g1 < g2 ? g1 + g2 : g2 + g1);

    // reset to 'U' for unknown (reset it at the end of the function in case, that one of the passed arguments is *this)
    genetype = 'U';

}

std::string Gene::getGeneType() const {
    if (genetype != 'U') {
        return std::string(1, genetype);
    }
    return multipleGenetype;
}

char Gene::getGeneTypeChar() const {
    if (genetype == 'U') {
        throw std::invalid_argument("This Plant has no unambiguous genes!\n");
    }
    return genetype;
}

bool Gene::isAmbiguouse() const {

    return (multipleGenetype.size() == 2 ? true : false);
}

bool operator==(const Gene & lhs, const Gene & rhs) {
    // getGeneType checks intern if the future gene is ambiguous
    if (lhs.getGeneType() == rhs.getGeneType()) {
        return true;
    }
    return false;
}