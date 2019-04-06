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
	//root = nullptr;
}

/*
  Six special constructors come here
*/

//no argument version of load queue.
void HuffmanTree::loadQueue() {
	loadQueue(queue, huffmap);
}

//argument version of Load queue
void HuffmanTree::loadQueue( priority_queue<HuffmanNode> & queue, unordered_map<char, int> & huffmap ) {
	//Create nodes and be adding them to the queue
	cout << "Loading the queue..." << endl;

	for (const auto & [ key, value ] : huffmap) {
    	queue.push(new HuffmanNode(key, value, nullptr, nullptr));
	}

	cout << "Queue loaded with nodes.." << endl;
	cout << "Char with smallest frequency is " << queue.top().value << " and frequency is " << queue.top().frequency << endl;
}


//no argument version of buildTree
bool HuffmanTree::buildTree() {
	buildTree(root, queue);
}

//Build the tree
bool HuffmanTree::buildTree( shared_ptr<HuffmanNode> & root, priority_queue<HuffmanNode> & queue ) {
	cout << "Building the tree.." << endl;
	//The tree is built from the leaves going up, not from the root
	
	//take the least two items and add to create a node
	while(queue.size() > 1)
	{
		int parentFrequency = 0;
		left = queue.top();
		queue.pop();
		right = queue.top();
		queue.pop();
		parentFrequency = left.frequency + right.frequency;

		//create new parent node with char as '0' to indicate a null char value
		queue.push(new HuffmanNode("0", parentFrequency, left, right));
	}

	//if the queue has left with one element
	if(queue.size() == 1) {
		root = queue.top();
		queue.pop();
	}

	cout << "Tree created and root frequency is " << root->frequency << endl;
	return true;
}