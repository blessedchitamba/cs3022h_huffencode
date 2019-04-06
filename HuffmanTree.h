// Header file for HuffmanTree class.

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

//using my own student number as namespace
namespace chtble001 {

	//Struct to compare two nodes
	 struct Compare  
 	 {  
   		bool compare(const HuffmanNode& a, const HuffmanNode& b) {
			return a.frequency <= b.frequency;
		}  
 	 };

	class HuffmanTree {
		/*This class is responsible for creating the tree structure and holds the pointer to the 
		root node of the tree. It also has all the other associated methods:
		1) Constructor to create the tree. Constructor takes in unordered map of char frequencies.
		2) Destructor
		3) Copy and Copy Assignment constructors
		4) Move and Move Assignment constructors
		5) Create priority queue from the unordered map
		6) Recursive function to create nodes from the P.Queue
		7) Boolean function to compare two nodes. 
		8) 
		*/ 

		private:  //private members
			std::shared_ptr<HuffmanNode> root;       //root node of the tree
			std::priority_queue<HuffmanNode, vector<HuffmanNode>, Compare> queue;  //to store the nodes in ascending order
			std::unordered_map<char, int> huffmap;       //contains key value pairs of each char from the input file
														 //and its frequency
			HuffmanNode left, right;

		public:
			//Default constructor
			HuffmanTree(std::unordered_map<char, int> & huffmap);

			//Destructor
			~HuffmanTree();

			//Copy Constructor. Copies the contents of a HuffmanTree object into another
			HuffmanTree (const HuffmanTree & rhs);

			//Copy Assignment Operator
			HuffmanTree & operator=(const HuffmanTree & rhs);

			//Move Constructor
			HuffmanTree (HuffmanTree && rhs);

			//Move Assignment Operator
			HuffmanTree & operator=(HuffmanTree && rhs);

			//Function to load the queue with nodes initially.
			//It does both creating and pushing the nodes.
			void loadQueue( std::priority_queue<HuffmanNode> & queue, std::unordered_map<char, int> & huffmap );

			//no argument version
			void HuffmanTree::loadQueue();

			//Function to compare two nodes to determine their position in the queue
			bool compare(const HuffmanNode& a, const HuffmanNode& b);

			//Function to build the tree using the nodes in the queue using the compare function
			bool buildTree(std::shared_ptr<HuffmanNode> & root, std::priority_queue<HuffmanNode> & queue);

			//no argument version
			bool HuffmanTree::buildTree();


	};


}

#endif