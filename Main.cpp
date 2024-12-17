#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Main.h"

using namespace std;

static bool CompareValueMap(const pair<char,int>& a, const pair<char,int>& b){
	return a.second < b.second;
}

void ArchAlgorithm::ReadFileName(){
	cin >> file_name;
}

void ArchAlgorithm::PrintFileName(){
	cout << file_name << endl;
}
	
void ArchAlgorithm::ReadFileString  (){
	string line;
	ifstream in(file_name);
	if (in.is_open()){
		while(getline(in, line)){
			main_line = main_line + line;
		}
	}
}
void ArchAlgorithm::PrintMainLine(){
	cout << main_line << endl;
}

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

void ArchAlgorithm::PrintMapCount(){
	for (const auto& pair : count_map){
		cout << "count_map" << pair.first << pair.second << endl;

	}
}
	
void ArchAlgorithm::AddMapToSortNode(){
	Node root(0);
	for(const auto& pair : count_map){
		root.count = pair.second;
		count_symb.push_back(root);
	}

}
	
void ArchAlgorithm::PrintSortNode(){
	for(const auto& n: count_symb){
		cout << n.count << endl;
	}
}

void ArchAlgorithm::BuildNodeBin (){
	Node root(0);
	while (count_symb.size() > 1){
		root.count = count_symb[0].count + count_symb[1].count;
		root.right_0 = &count_symb[1];
		root.left_1 = &count_symb[0];
		count_symb.push_back(root);

		auto iter = count_symb.cbegin();
		count_symb.erase(iter);
		count_symb.erase(iter + 1 );
	}	
} 



int main(){
	
	ArchAlgorithm main_arch;

	main_arch.ReadFileName();
	main_arch.PrintFileName();
	
	main_arch.ReadFileString();

	main_arch.PrintMainLine();

	main_arch.CountSymbolsReturnMap();
	main_arch.PrintMapCount();

	main_arch.AddMapToSortNode();
	main_arch.PrintSortNode();

	main_arch.BuildNodeBin();

	cout << main_arch.count_symb[0].count << endl;



}
