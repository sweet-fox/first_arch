#include <iostream>
//#include <bites>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

class alg_arch
{
public:
	string file_name;
	string main_line;
	
	map<char,int> count_map;
	

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
		for (char i : main_line){
			if (count_map.find(i) == count_map.end()){
				count_map[i] = 1;
			}
			else{
				count_map[i] += 1;
			}
		}
	}
	
	void print_map_count(){
		for (const auto& pair : count_map){
			cout << pair.first << pair.second << endl;

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



}
