/*
  This class represents a single HuffmanTree object which will hold the 
  root to the tree, and have other necessary functions to implement the 
  Huffman Encoding.
*/

#include "HuffmanTree.h"
#include "HuffmanNode.cpp"
#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <sstream>  // Needed for string stream objects
#include <string>   // Needed for strings
#include <iterator>  //Needed for the iterator
#include <cstdlib>
#include <math.h>

using namespace std;
using namespace chtble001;

//Define the class methods

//Constructor
HuffmanTree::HuffmanTree(unordered_map<char, int> & huffmap) : root(nullptr){
	this.huffmap = huffmap;
}

//Destructor
HuffmanTree::~HuffmanTree(){
	root = nullptr;
}

/*
  Six special constructors come here
*/

//Load queue
void HuffmanTree::loadQueue( priority_queue<HuffmanNode> & queue, unordered_map<char, int> & huffmap ) {
	//Create nodes and be adding them to the queue
	cout << "Loading the queue..." << endl;

	for (const auto & [ key, value ] : huffmap) {
    	huffmap.push(new HuffmanNode(key, value));
	}

	cout << "Queue loaded with nodes.." << endl;
}