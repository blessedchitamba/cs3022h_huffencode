/*
  This class represents a single HuffmanNode object which will be used
  in the building of the HuffmanTree object. Each node holds an int value
  and an optional char value which can be 0 (only leaf nodes have char values)
*/

#include <string>

class HuffmanNode {

	friend class HuffmanTree;  //to give HuffmanTree access to node variables
	//private members
	private:
		//std::weak_ptr<HuffmanNode> leftChild;
		//std::weak_ptr<HuffmanNode> rightChild;
		char value;
		int frequency;  //will be 0 if its not a leaf node

	//public members
	public:
		//Constructor
		HuffmanNode(char value, int frequency, HuffmanNode & left, HuffmanNode & right) : value(value), frequency(frequency){
			std::shared_ptr<HuffmanNode> leftChild(*left);
			std::shared_ptr<HuffmanNode> rightChild(*right);
		}

		//Destructor. Sets weak pointers to null
		~HuffmanNode() {
			leftChild = nullptr;
			rightChild = nullptr;
		}

};