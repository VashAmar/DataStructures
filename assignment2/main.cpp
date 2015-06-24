#include <iostream>
#include "node.h"
#include "priority_queue.h"

using namespace std;

void randomlyInsert(PriorityQueue&, int);
void deleteAll(PriorityQueue&);

const int NUM_VALUES(1000);

int main() {
	PriorityQueue pq(NUM_VALUES);
	randomlyInsert(pq, NUM_VALUES);
	deleteAll(pq);
	cin.ignore();
	return 0;
}

void randomlyInsert(PriorityQueue& pq, int numVals) {
	string title = "element ";
	for (int i = 0; i < numVals; ++i) {
		int priority = rand();
		string name = title + to_string(i);
		pq.insert(priority, name);
	}
}

void deleteAll(PriorityQueue& pq) {
	for (int i = 0; i < pq.size(); ++i) {
		Node* removed = pq.delete_max();
		cout << removed->m_priority << " " << removed->m_value << endl;
	}
}
