#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node{
public:
	char ch;
	int count;
	Node* left_0;
	Node* right_1;
	
	Node(){}

	Node(int value){
		count = value;
		ch = '%';
		left_0 = nullptr;
		right_1 = nullptr;
	}
	Node(int value, char _ch){
		count = value;
		ch = _ch;
		left_0 = nullptr;
		right_1 = nullptr;
	}
	/*
	~Node(){
		ch='0';
		count = 0;
		left_0 = nullptr;
		right_1=nullptr;
	}
	*/
	void GoBinNode(string bin_str, vector<pair<char,string>>& Node_Map);
};

class ArchAlgorithm {
public:
	string file_name;
	string main_line;

	vector<pair<char,int>> count_map;
	vector<Node> main_count_symb;
	vector<Node*> count_symb;

	Node main_root = Node(0);	
	vector<pair<char,string>> Node_Map;
	string bin_str ="";

	void ReadFileName();
	void ReadFileString();
	void PrintMainLine();
	void CountSymbolsReturnMap();
	void PrintMapCount();
	void AddMapToSortNode();
	void PrintSortNode();
	void BuildNodeBin();
	void BuildBinMap();
	void PrintBinMap();
	void CopySortNode();
	void PrintCopySortNode();
};
