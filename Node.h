#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class Node{
public:
	char ch;
	int count;
	Node* left_0;
	Node* right_1;
	
	Node() = delete;
	Node(Node&) = delete;
	Node(const Node&) = delete;

	Node(int value, char _ch = '%'):
		count(value), ch(_ch), left_0(nullptr), right_1(nullptr)
	{ }
	
	~Node(){
		ch = 0;
		count = 0;
		left_0 = nullptr;
		right_1 = nullptr;
	}
	
	void GoBinNode(string bin_str, vector<pair<char,string>>& Node_Map);
};

