#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include "Node.h"

using namespace std;

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


