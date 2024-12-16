#include <iostream>
//#include <bites>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

struct node {
	int count;
	node* left_1;
	node* right_0;

	node(int value){
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
	vector<node> count_symb;

	static bool compare_value_map(const pair<char,int>& a, const pair<char,int>& b){
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
	
	void count_symbols_return_map(){
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
		sort(count_map.begin(),count_map.end(),compare_value_map);
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
	
	void print_sort_node(){
		for(const auto& n: count_symb){
			cout << n.count << endl;
		}
	}
//оператор присваивания полетел лол	
	void build_node_bin (){
		node* root = node(0);
		while (count_symb.size() > 1){
			node* root = node(count_symb[0].count + count_symb[1].count);
			count_symb.push_back(root);
			if (count_symb[0].count > count_symb[1].count){
				(*count_symb[count_symb.size()]).left_1 = count_symb[1];
				(*count_symb[count_symb.size()]).right_0 = count_symb[0];
			}
			else{
				(*count_symb[count_symb.size()]).right_0 = count_symb[1];
				(*count_symb[count_symb.size()]).left_1 = count_symb[0];
			}
			auto iter = count_symb.cbegin();
			count_symb.erase(iter);
			count_symb.erase(iter + 1 );
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
	main_arch.print_sort_node();

	main_arch.build_node_bin();

	cout << main_arch.count_symb[0].count;



}
