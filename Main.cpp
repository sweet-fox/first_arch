#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Main.h"
#include <list>

using namespace std;

//sort for Map
static bool CompareValueMap(const pair<char,int>& a, const pair<char,int>& b){
	return a.second < b.second;
}

//sort for Node
static bool CompareByNode(Node* a, Node* b){
	return (*a).count < (*b).count;
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
		main_count_symb.emplace_back(pair.second, pair.first);
	}

}

//buid copy main_count_symb to count_symb
void ArchAlgorithm::CopySortNode(){
	for (auto& node : main_count_symb){
		count_symb.push_back(&node);
	}
}

void ArchAlgorithm::PrintCopySortNode(){
	for (Node* node : count_symb){
		cout << "c_s" << (*node).count << endl; 
	}
}

	
//print this node vector
void ArchAlgorithm::PrintSortNode(){
	cout << "Node" << endl;
	for(Node* n: count_symb){
		cout << (*n).count << " " << (*n).ch << endl;
	}
	cout << "Node1" << endl;
	for(const auto& n: main_count_symb){
		cout << n.count << " " << n.ch << endl;
	}
}

//building node tree
void ArchAlgorithm::BuildNodeBin (){
	PrintSortNode();
	while (count_symb.size() > 1){
		auto iter {count_symb.begin()};

		main_count_symb.emplace_back(((*iter)->count) + ((*(++iter))->count));

		main_count_symb.back().right_1 = count_symb.front();
		count_symb.pop_front();

		main_count_symb.back().left_0 = count_symb.front();

		count_symb.push_back(&main_count_symb.back());

		count_symb.pop_front();

	
		
		count_symb.sort(CompareByNode);

		

		PrintSortNode();
	}
}

void Node::GoBinNode(string bin_str,vector<pair<char,string>>& Node_Map){
	cout << "start GoBinNode" << endl;

	if (ch=='%'){
		left_0->GoBinNode(bin_str+"0",Node_Map);
		right_1->GoBinNode(bin_str+"1",Node_Map);	
	}
	else{
		Node_Map.emplace_back(make_pair(ch,bin_str));
	}
}


void ArchAlgorithm::PrintBinMap(){
	for(const auto& pair : Node_Map){
		cout << "Node_Map " << pair.first << " " << pair.second <<  endl;
	}

}


int main(){
	
	ArchAlgorithm main_arch;

	main_arch.ReadFileName();
//	main_arch.PrintFileName();
	
	main_arch.ReadFileString();

//	main_arch.PrintMainLine();

	main_arch.CountSymbolsReturnMap();
	main_arch.PrintMapCount();

	main_arch.AddMapToSortNode();
	main_arch.CopySortNode();
	main_arch.BuildNodeBin();
	
//	cout << "node_test" << (*(*main_arch.count_symb.back()).left_0).count << endl;
	
	main_arch.count_symb.front()->GoBinNode(main_arch.bin_str,main_arch.Node_Map);	
	main_arch.PrintBinMap();
}
