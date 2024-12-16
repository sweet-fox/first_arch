#include <iostream>
//#include <bites>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;
//you need to write map to vector in this open


struct Node {
	int count;
	Node* left_1;
	Node* right_0;

	Node(int value){
		count = value;
		left_1=nullptr;
		right_0=nullptr;
	}

};

class alg_arch
{
public:
	string file_name;
	string main_line;
	
	vector<pair<char,int>> count_map;
	vector<Node> count_symb;

	static bool compareByValue(const pair<char,int>& a, const pair<char,int>& b){
		return a.second < b.second;
	}

	void read_file_name(){
		cin >> file_name;
	}

	void print_file_name(){
		cout << file_name << endl;
	}
	
	void read_file_string  (){
		string line;
		ifstream in(file_name);
		if (in.is_open()){
			while(getline(in, line)){
				main_line = main_line + line;
			}
		}
	}
	void print_main_line(){
		cout << main_line << endl;
	}
	
	//in proces(writing vector tipe)
	void count_symbols_return_map(){
		int pos = 0;
		for (char i : main_line){
			if (count_map.find(i) == count_map.end()){
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
		sort(count_map.begin(),count_map.end(),compareByValue);
	}
	
	void print_map_count(){
		for (const auto& pair : count_map){
			cout << pair.first << pair.second << endl;

		}
	}
	
	void add_map_to_sort_Node(){
		for(const auto& pair : count_map){
			count_symb.push_back(pair.second);
		}
	
	}
	
	void print_sort_Node(){
		for(const auto& n: count_symb){
			cout << n.count << endl;
		}
	}
	
};


int main(){
	
	alg_arch main_arch;

	main_arch.read_file_name();
	main_arch.print_file_name();
	
	main_arch.read_file_string();

	main_arch.print_main_line();

	main_arch.count_symbols_return_map();
	main_arch.print_map_count();

	main_arch.add_map_to_sort_Node();
	main_arch.print_sort_Node();



}
