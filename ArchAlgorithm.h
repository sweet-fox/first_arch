#include <vector>
#include <iostream>
#include <algorithm>
#include <list>


using namespace std;

class ArchAlgorithm {
public:
	string file_name;
	string main_line;
	string bin_main_line;

	vector<pair<char,int>> count_map;
	vector<Node*> main_count_symb;
	list<Node*> count_symb;
	
	vector<pair<char,string>> Node_Map;
	string bin_str ="";

	void ReadFileName(string _file_name);
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
	void BuildBinString();
	void BuildBinFile();	
	
	~ArchAlgorithm();
};
