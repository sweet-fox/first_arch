#include<iostream>

using namespace std;

class ProgressBar{
private:
	unsigned long int total;
	int size_total;
	int size_total_rem;
	int count=50; 
public:
	ProgressBar(unsigned long int _total){
		total = _total;
		size_total = total / count;
		size_total_rem = total-size_total;
	}
	void showProgressBar(unsigned long int progress);
};
