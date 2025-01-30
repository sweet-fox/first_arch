#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include "ProgressBar.h"
#include "Node.h"
#include "ArchAlgorithm.h"
#include <gmpxx.h>

using namespace std;

//sort for Map
static bool CompareValueMap(const pair<char,int>& a, const pair<char,int>& b){
	return a.second < b.second;
}

//sort for Node
static bool CompareByNode(Node* a, Node* b){
	return (*a).count < (*b).count;
}

ArchAlgorithm::~ArchAlgorithm(){
	for(Node* n: main_count_symb){
		if(n != nullptr)
			delete n;
	}
}

//read file name
void ArchAlgorithm::ReadFileName(){
	cin >> file_name;
}

//write to string file
void ArchAlgorithm::ReadFileString  (){
	string line;
	ifstream in(file_name);
	if (in.is_open()){
		while(getline(in, line)){
			main_line = main_line + line;
		}
	}
}

//print this string
void ArchAlgorithm::PrintMainLine(){
	cout << main_line << endl;
}

//create map (count how many symb we have)
void ArchAlgorithm::CountSymbolsReturnMap(){
	int pos = 0;
	for (char i : main_line){
		auto iter = find_if(count_map.begin(), count_map.end(), [&i](const pair<char,int>& pair){
					return pair.first == i;
				});
		if (iter == count_map.end()){
			count_map.push_back(make_pair(i,1));
		}
		else{
			for(int j = 0;j < count_map.size();j++){
				if (count_map[j].first == i){
					pos = j;
					break;
				}
			}
			count_map[pos].second ++;
		}
	}
	sort(count_map.begin(), count_map.end(), CompareValueMap);
}

//print this map
void ArchAlgorithm::PrintMapCount(){
	for (const auto& pair : count_map){
		cout << "count_map " << pair.first << pair.second << endl;

	}
}
	
//create Node vector from map
void ArchAlgorithm::AddMapToSortNode(){
	for(const auto& pair : count_map){
		main_count_symb.push_back(new Node(pair.second, pair.first));
	}

}

//buid copy main_count_symb to count_symb
void ArchAlgorithm::CopySortNode(){
	for (auto node : main_count_symb){
		count_symb.push_back(node);
	}
}

void ArchAlgorithm::PrintCopySortNode(){
	for (Node* node : count_symb){
		cout << "c_s" << node->count << endl; 
	}
}

	
//print this node vector
void ArchAlgorithm::PrintSortNode(){
	cout << "Node" << endl;
	for(Node* n: count_symb){
		cout << n->count << " \"" << n->ch << "\""<< endl;
	}
	cout << "Node1" << endl;
	for(const auto n: main_count_symb){
		cout << n->count << " \"" << n->ch << "\""<< endl;
	}
}

//building node tree
void ArchAlgorithm::BuildNodeBin (){
	PrintSortNode();
	while (count_symb.size() > 1){
		auto iter = count_symb.begin();
		Node* n(new Node(((*iter)->count) + ((*(++iter))->count)));
		//Node *n(new Node(3));

		main_count_symb.push_back(n);

		main_count_symb.back()->right_1 = count_symb.front();
		count_symb.pop_front();

		main_count_symb.back()->left_0 = count_symb.front();
		
		count_symb.push_back(main_count_symb.back());
		count_symb.pop_front();
		
		count_symb.sort(CompareByNode);		
		PrintSortNode();
	}
}


void ArchAlgorithm::PrintBinMap(){
	for(const auto& pair : Node_Map){
		cout << "Node_Map " << pair.first << " " << pair.second <<  endl;
	}

}
void ArchAlgorithm::BuildBinString(){
	bin_main_line = "";
	unsigned long int progress = 0;
	ProgressBar prog_bar(main_line.length());
	for (char i:main_line){
		progress ++;
		for (int n = 0;n < Node_Map.size();n++){
			if (Node_Map[n].first == i){
//				cout << Node_Map[n].second << endl;
				bin_main_line = bin_main_line + Node_Map[n].second;
				break;
			}
		}
		prog_bar.showProgressBar(progress);
	}
	cout<< endl << " BUild Bin line end" << endl;
	cout << bin_main_line << endl;	
}

void ArchAlgorithm::BuildBinFile(){
	ofstream key_out_file("out_key_file.txt");

	int i = 0;
	char a = bin_main_line[i];
	while(a!='1'){
		a= bin_main_line[i];
		cout<<a;
		i++;
	}

	key_out_file << to_string(i)<<endl;
	for (const auto& pair : Node_Map){
		char symb = pair.first;
		string symb_bin_val = pair.second;
		key_out_file << symb << endl;
		key_out_file << symb_bin_val << endl;
	}

	key_out_file.close();

	mpz_class bigNumber = mpz_class(bin_main_line, 2);
	cout << bigNumber;

	ofstream out_file("out_file.bin");
	out_file << bigNumber.get_str(16);

	string filename = "out_file.bin";
	FILE* file = fopen(filename.c_str(),"wb");
	mpz_out_raw(file,bigNumber.get_mpz_t());
	fclose(file);

}

