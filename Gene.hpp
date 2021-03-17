#include <string>

bool operator==(const Gene & lhs, const Gene & rhs);

class Gene {

    private:
        char genetype = 'U';    // U for Uninitialized
        std::string multipleGenetype;
        float priority;
        bool isBad;

        // bool calcIfBad();

    public:
        Gene() = default;
        Gene(const Gene & other) = default;
        Gene(char name);
        virtual ~Gene() = default;



        void setGene(const Gene & other);
        // if the Gene will be replaced 50/50 by one of two possible neighbour Genes in that slot
        void setGeneProb(const Gene & first, const Gene & second);

        std::string getGeneType() const;
        char getGeneTypeChar() const;

        bool isAmbiguouse() const;
};