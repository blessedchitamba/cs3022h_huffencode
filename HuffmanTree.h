//Header file for the HuffmanTree.cpp file. contains the method declarations and all

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

#include "HuffmanNode.h"

//using my own namespace
namespace chtble001{

    class HuffmanTree{
        
        public:
        std::shared_ptr<HuffmanNode> root;
        
        //to store the bit representation of each char
        std::unordered_map<char, std::string> codeTable;

        // Constructor
        HuffmanTree();
        //Destructor
        ~HuffmanTree();

        //to build the tree itself
        bool buildTree(std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> queue);
	
	//the no argument version of teh function
        void generateCodeTable();
        
        void writeHeader(std::string headerFile);
	
	//the argument version
        void generateCodeTable(std::string code, std::shared_ptr<HuffmanNode> current);

        void writeOutput(std::string inputFile, std::string outputFile);

        void writeToFile(std::string inputFile, std::string outputFile);

        void output_bitstream(std::string inputFile, std::string outputFile);
    };

}

#endif
