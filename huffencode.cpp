//Driver file for the Huffman Encoder application. 

#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <sstream>  // Needed for string stream objects
#include <string>   // Needed for strings
#include <iterator>  //Needed for the iterator
#include <cstdlib>
#include <math.h>
#include <memory>
#include <vector>
#include <queue>
#include <unordered_map>

#include "HuffmanTree.h"


using namespace std;
using namespace chtble001;


//Construct the priority queue
priority_queue<HuffmanNode, vector<HuffmanNode>, Compare> makeQueue(const unordered_map<char, int>& map){
    priority_queue<HuffmanNode, vector<HuffmanNode>, Compare> queue;
    for(const auto& n: map){
        HuffmanNode node(n.first, n.second);
        queue.push(node);
    }
    return queue;
}

unordered_map<char, int> makeMap(string inputFile);

//Main method
int main(int argc, char ** argv){

	//variables
	string inputFile;
	string outputFile;
	priority_queue<HuffmanNode, vector<HuffmanNode>, Compare> queue;
	unordered_map<char, int> huffmap;

    // take filename for input
    inputFile = argv[1];

    //count the letter frequencies in the file
    huffmap = makeMap(inputFile);

    cout << "The huffmap is of size " << huffmap.size() << endl;

    //populate the queue with nodes
    queue = makeQueue(huffmap);

    //create a HuffmanTree object and put it on the heap using new then build the tree
    HuffmanTree hufftree;
    hufftree.buildTree(queue);

    // Build the code table
    hufftree.generateCodeTable();

    // Output the results of the encoding
    hufftree.writeToFile(argv[1], argv[2]);

    hufftree.output_bitstream(argv[1], argv[2]);
    return 0;
}  //End of main method

//Calculate the frequency of each character in the given file
unordered_map<char, int> makeMap(string inputFile){

    unordered_map<char, int> charmap;
    bool charExists;

    // Open the filestream.
    ifstream ifs;
    ifs.open(inputFile, ifstream::in);

    // Read file per character
    char buffer[1];
    while(!ifs.eof()){
        charExists = false;
        ifs.read(buffer, sizeof(buffer[0]));
        
        // Check if the value is not already in the map
        for(const auto& n: charmap){
            if(n.first == char(buffer[0])) {
            	charExists = true;
           	}
        }

        //if it is on the map already
        if(charExists){
            charmap[char(buffer[0])] += 1;
        } else {
            charmap[char(buffer[0])] = 1;
        }
    }

    charmap[buffer[0]] -= 1;

    ifs.close();

    cout << "Done reading in the input files to map" << endl;

    return charmap;
}


