#ifndef PQUEUE_H
#define PQUEUE_H

#include <vector>
#include "node.h"
using namespace std;

class PriorityQueue {
public:
	PriorityQueue(int);
	~PriorityQueue();
	int size();
	void insert(int, string);
	Node* delete_max();
private:
	void swap_w_max(int);
	int m_next;
	vector<Node*> m_pqueue;
};

#endif