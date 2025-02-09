#include <iostream>
#include <vector>
#include <fstream>
#include "DeArchAlgorithm.h"
#include <gmpxx.h>

void DeArchAlgorithm::ReadBinFile(){
	string filename = "out_file.bin";
	FILE* file = fopen(filename.c_str(),"rb");
	mpz_class LoadNumber;
	size_t num_read = mpz_inp_raw(LoadNumber.get_mpz_t(),file);
	if (num_read == 0){
		cout << "ERROR:file couldnt be read" << endl;
		fclose(file);
		return;
	}

	main_bin_line = LoadNumber.get_str(2);
	fclose(file);
	cout << LoadNumber;
	cout << main_bin_line << endl;

}
void DeArchAlgorithm::ConvertBinFile(string _file_name){
	
	ifstream file("out_key_file.txt");
	int zero_count;
	bool flag = 0;
	bool flag_for_zero = 0;
	string symb;
	string bin_char;
	string line;


	while (getline(file,line)){
		if (flag_for_zero == 0){
			zero_count = stoi(line);
			flag_for_zero=1;
		}
		else{
			if (flag == 0){
				symb=line;
				flag=1;
			}
			else{
				bin_char=line;
				symb_Map_val.push_back(make_pair(bin_char,symb));
				flag=0;

//				cout << symb << bin_char << endl;
			}
		}
	}
	
	for(int i =0;i<zero_count;i++){
		main_bin_line = "0"+main_bin_line;
	}
	


	ofstream out_file ("New_out_txt.txt");
	string buff_str = "";
	for(char st_symb : main_bin_line){
		buff_str = buff_str+st_symb;
		for(const auto& pair : symb_Map_val){
			if(buff_str == pair.first){
				if (pair.second != "|"){
					out_file << pair.second;
					buff_str="";
				}
				else{
					out_file << endl;
					buff_str="";
				}
			}
		}
	}
	

}


