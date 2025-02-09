#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include "ProgressBar.h"
#include "Node.h"
#include "ArchAlgorithm.h"
#include "DeArchAlgorithm.h"

using namespace std;

int main(int argc, char* argv[]){
	if (argc<2){
		cout<<"Error";
		return 0;
	}

	string command = argv[1];

	string file_name = argv[2];

	if (command=="arch"){
		ArchAlgorithm main_arch;

		main_arch.ReadFileName(file_name);
		main_arch.ReadFileString();
		main_arch.CountSymbolsReturnMap();
//		main_arch.PrintMapCount();

		main_arch.AddMapToSortNode();
		main_arch.CopySortNode();
		main_arch.BuildNodeBin();
	
		main_arch.count_symb.front()->GoBinNode(main_arch.bin_str,main_arch.Node_Map);	
//		main_arch.PrintBinMap();
		main_arch.BuildBinString();
		main_arch.BuildBinFile();
	}
	if (command=="dearch"){
		DeArchAlgorithm de_main_arch;

		de_main_arch.ReadBinFile();
		de_main_arch.ConvertBinFile(file_name);
		return 0;
	}
	

}
