#include<iostream>
#include "ProgressBar.h"

using namespace std;

void ProgressBar::showProgressBar(unsigned long int progress){
	if (size_total ==0){
		return;
	}
	int pos = progress / size_total;
	cout << '[';		 
	for (int i = 0; i < count; i++){
		if (i < pos){
			cout << '#';
		}							                        
		else{
			cout << ' ';	
		}				
	}
	cout << ']'<< int((progress/(total*1.0)*100.0)) << "%\r";
	cout.flush();
}
