/*the driver file for the huffencode application
  It will do the file I/O, loading of the huffmap with
  character sequences, as well as the bit encoding
*/

#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <sstream>  // Needed for string stream objects
#include <string>   // Needed for strings
#include <vector>   // Needed for the vector container
#include <unordered_map>
#include "HuffmanTree.h"  // the file containing the functions

using namespace std;
using namespace chtble001;

unordered_map<char, int> makeMap(string filename);

int main(int argc, char * argv[])
{
	//get input and output file from arguments
	string inputFile = argv[1];
	string outputFile = argv[2];

	cout << "Building unordered map of character sequences..." << endl;

	//call makeMap to make the map and create the tree object
	HuffmanTree huffTree = new HuffmanTree(makeMap(inputFile));
	huffTree.loadQueue();
	huffTree.buildTree();

}  //End of main

//method to make the huffmap
unordered_map<char, int> makeMap(string filename) {
	unordered_map<char, int> huffmap;
	bool charExists;  //boolean to indicate if the char is in the map already

	//open the file and read byte by byte
	char ch;  //to store each char
	ifstream ifs(filename, fstream::in);
	while(!ifs.eof()){
		//noskipws: read one char at a time and dont terminate at white space
		while (ifs >> noskipws >> ch) {
	    	//if the char is a whitespace then ignore
			if(char == " ") {continue; }
			else {
				//else check if the value is not in the map already
				 for(const auto& n: huffmap){
            		if(n.first == ch) {charExists = true; }
        		 }

        		 //if charExists is not true, create new entry, else add 1 to the existing frequency
        		 if(charExists) {
        		 	huffmap[ch] += 1;
        		 }
        		 else {
        		 	huffmap[ch] = 1;
        		 }
			}
		}
	}

	ifs.close();

	cout << "Loaded character frequencies into huffmap." << endl;
	cout << "Frequency of 'a' is " << map['a'] << endl;
	cout << "Frequency of 'd' is " << map['d'] << endl;
	return huffmap;
}
