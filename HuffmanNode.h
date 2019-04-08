//Header file for the node class
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>

namespace chtble001{
        class HuffmanNode{
        public:
        /**
         * The left and right pointers
         */

        std::shared_ptr<chtble001::HuffmanNode> left;
        std::shared_ptr<chtble001::HuffmanNode> right;

        char value;
        int frequency;

        //Default Constructor
        HuffmanNode();

        // Constructor
        HuffmanNode(char value, int frequency);
        // Frequency only constructor

        HuffmanNode(int frequency);
        
        char getValue();
        
        int getFreq();

        // Copy constructor
        HuffmanNode(const HuffmanNode& rhs);

        // Deconstructor
        ~HuffmanNode();



        // Operator overloading
        bool operator < (const HuffmanNode& other);
    };

    class Compare{
        public:
        bool operator() (HuffmanNode& a, HuffmanNode& b);
    };



}

#endif
