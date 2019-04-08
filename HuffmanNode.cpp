#include "HuffmanNode.h"



chtble001::HuffmanNode::HuffmanNode(char value, int frequency): value(value), frequency(frequency){
	//does nothing here
}



chtble001::HuffmanNode::HuffmanNode(int frequency): frequency(frequency){
    value = '0';
}

chtble001::HuffmanNode::HuffmanNode(const chtble001::HuffmanNode& rhs): value(rhs.value), frequency(rhs.frequency){
    left = rhs.left;
    right = rhs.right;
}

chtble001::HuffmanNode::~HuffmanNode(){}

bool chtble001::HuffmanNode::operator < (const chtble001::HuffmanNode& other){
    return (frequency < other.frequency);

}

//comparison method to compar two nodes based on their frequency falues
bool chtble001::Compare::operator()(chtble001::HuffmanNode& a, chtble001::HuffmanNode& b){
    return (b < a);
}
