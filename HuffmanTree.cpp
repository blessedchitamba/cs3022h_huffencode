/*
  This class represents a single HuffmanTree object which will hold the 
  root to the tree, and have other necessary functions to implement the 
  Huffman Encoding
  */

#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <sstream>  // Needed for string stream objects
#include <string>   // Needed for strings
#include <iterator>  //Needed for the iterator
#include <cstdlib>
#include <math.h>
#include <memory>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;
using namespace chtble001;

//Define the class methods

//Constructor
chtble001::HuffmanTree::HuffmanTree(){
}

//Destructor
chtble001::HuffmanTree::~HuffmanTree(){
    root = nullptr;
}

//Build the code table
void chtble001::HuffmanTree::generateCodeTable(){
    std::string code = "";
    generateCodeTable(code, root);
}

/**
 * Recursively builds the code table by traversing down the HuffmanTree
 */
void chtble001::HuffmanTree::generateCodeTable(std::string code, std::shared_ptr<chtble001::HuffmanNode> current){
    //if the node is a leaf node, add the character to the code table
    if(!(current->value == '0')){
        codeTable[current->value] = code;
    }

    //if the node has a left child, traverse recusrively
    if(!(current->left == nullptr)){
        generateCodeTable(code + "0", current->left);
    }

    if(!(current->right == nullptr)){
        generateCodeTable(code + "1", current->right);
    }
}


//Use the nodes in the priority queue to construct the tree
bool chtble001::HuffmanTree::buildTree(std::priority_queue<chtble001::HuffmanNode, std::vector<chtble001::HuffmanNode>, chtble001::Compare> queue){
    cout << "Building tree..." <<endl;

    int parentFrequency;

    //Iterate through the queue repeatedly combining the two nodes with the smallest frequencies
    //into a single parent node until the size of the queue is 1
    while(queue.size() > 1){
        
        //Create the left and right shared pointer. New returns a pointer.
        //These represent the left and right children of the parent
        shared_ptr<HuffmanNode> leftChild(new HuffmanNode(queue.top()));
	parentFrequency += queue.top().frequency;
        queue.pop();
        shared_ptr<HuffmanNode> rightChild(new HuffmanNode(queue.top()));
        parentFrequency += queue.top().frequency;
        queue.pop();

        //parentFrequency = left->frequency + right->frequency;

        shared_ptr<HuffmanNode> parentNode(new HuffmanNode(parentFrequency));

        //assign the children of the parent node.
        parentNode->left = leftChild;
        parentNode->right = rightChild;

        //push the parent node into the queue
        queue.push(*parentNode);

        //if the queue is left with one node, make that the root
        if(queue.size() == 1){
            root = parentNode;
        }
        
    }

    return true;
}

 //Write the outputs to the appropriate files. start by writing header
void chtble001::HuffmanTree::writeToFile(string inputFile, string outputFile){
    writeHeader(outputFile + ".h");
    writeOutput(inputFile, outputFile);
}


void chtble001::HuffmanTree::writeOutput(string inputFile, string outputFile){
    cout << "Writing to file.." << endl;
    string output = "";
    char buffer[1];
    ifstream ifs;
    ifs.open(inputFile);
    while(!ifs.eof()){
        ifs.read(buffer, sizeof(buffer[0]));
        output+=codeTable[buffer[0]];
    }
    ifs.close();

    cout << "Done writing to file..." << endl;
    ofstream ofs;
    ofs.open(outputFile);
    ofs << output.c_str();
    ofs.close();
}

//write to the header file
void chtble001::HuffmanTree::writeHeader(string headerFile){
    ofstream ofs;
    ofs.open(headerFile);

    //start by writing the size to the top of the file
    ofs << codeTable.size() << endl;
    
    //iterate through code table
    for(const auto &element: codeTable){
        ofs << element.first << " -> " << element.second << endl;
    }
    
    ofs.close();
}

//create the bitstream
void chtble001::HuffmanTree::output_bitstream(string inputFile, string outputFile){
    //Int variables to store number ot bits and bytes
    int numBytes = 0;
    int numBits = 0;
    
    //write to file
    string output = "";
    char array[1];
    ifstream ifs;
    cout << inputFile << endl;
    ifs.open(inputFile);
    while(!ifs.eof()){
        ifs.read(array, sizeof(array[0]));
        output+=codeTable[array[0]];
    }
    ifs.close();
    
    //number of bits is the size of the output
    numBits = output.size();

    numBytes = numBits/8 + (numBits%8 ? 1: 0);
    if(numBytes == 0) {
    	 return;
    }
    
    //char array to store the stream of bits for the original text
    char bitstream[numBytes];

    // Intialize the bitstream to 0s
    for(int i = 0; i < numBytes; i++){
        bitstream[i] = 0;
    }

    // Iterate through the bits in the output
    int count, byte, value;
    for(int i = 0; i < numBits; i++){
        if (i % 8 == 0 && i != 0){
            byte++;
        }
        if (output[i] == '1'){
            bitstream[byte] |= 1 << count;
        }
        count = (count + 1) % 8;

    }

}
