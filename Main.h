#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node{
public:
	int count;
	Node* left_1;
	Node* right_0;

	Node(int value){
		count = value;
		left_1 = nullptr;
		right_0 = nullptr;
	}
};
class ArchAlgorithm {
public:
	string file_name;
	string main_line;

	vector<pair<char,int>> count_map;
	vector<Node> count_symb;

	static bool CompareValueMap();
	void ReadFileName();
	void PrintFileName();
	void ReadFileString();
	void PrintMainLine();
	void CountSymbolsReturnMap();
	void PrintMapCount();
	void AddMapToSortNode();
	void PrintSortNode();
	void BuildNodeBin();
};
