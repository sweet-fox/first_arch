#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class DeArchAlgorithm{
private:
	vector<pair<string,string>> symb_Map_val;
	string main_bin_line;
	string main_line;
public:
	void ReadBinFile();
	void ConvertBinFile(string _file_name);
};
