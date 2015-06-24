#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

struct Node {
	Node(int, string);
	int m_priority;
	string m_value;
};

#endif