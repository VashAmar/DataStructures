#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

enum Amounts : int { SMALL = 50, MEDIUM = 10000, LARGE = 10000000 };

int MAX_VALUE(100000000);
int NUM_TO_FIND(10000);

struct ListNode;
struct TreeNode;
class List;
class Tree;

void handleListInsertFind(int amount);
void handleTreeInsertFind(int amount);

int main() {
	srand((unsigned int)time(NULL));

	cout << "Binary search tree:" << endl;
	handleTreeInsertFind(SMALL);
	handleTreeInsertFind(MEDIUM);
	handleTreeInsertFind(LARGE);
	
	cout << "\nList:" << endl;
	handleListInsertFind(SMALL);
	handleListInsertFind(MEDIUM);
	handleListInsertFind(LARGE);
	cout << "Job done." << endl;

	cin.ignore();
	return 0;
}

double getAverage(vector<double> vDoubles) {
	double average = 0;
	for (size_t i = 0; i < vDoubles.size(); ++i) {
		average += vDoubles[i];
	}
	return average /= vDoubles.size();
}

void outputResults(int numIterations, double insertTime, double findTime) {
	cout << "n=" << numIterations << " insert: " << insertTime << " ms; find: " << findTime << " ms\n";
}

double getElapsedTime(time_point<high_resolution_clock>& start) {
	auto elapsed = high_resolution_clock::now() - start;
	double ms = duration_cast<microseconds>(elapsed).count() / 1000.0;
	start = high_resolution_clock::now();
	return ms;
}

class Tree {
public:
	Tree();
	~Tree();
	bool find(int);
	void insert(int);
private:
	TreeNode* m_head;
};

class List {
public:
	List();
	~List();
	bool find(int);
	void insert(int);
private:
	ListNode* m_head;
	vector<bool> m_bitmap;
};

template<typename T>
void insertRandomValues(T& container, int amount) {
	for (int i = 0; i < amount; ++i) {
		int rng = rand() % MAX_VALUE + 1;
		container.insert(rng);
	}
}

template<typename T>
void findRandomValues(T& container) {
	for (int i = 0; i < NUM_TO_FIND; ++i) {
		int rng = rand() % MAX_VALUE +1;
		container.find(rng);
	}
}

void handleTreeInsertFind(int amount) {
	Tree tree;
	vector<double> vInsertTime(100);
	vector<double> vFindTime(100);
	auto now = high_resolution_clock::now();
	for (int i = 0; i < 100; ++i) {
		insertRandomValues(tree, amount);
		vInsertTime[i] = getElapsedTime(now);
		findRandomValues(tree);
		vFindTime[i] = getElapsedTime(now);
	}
	double avgInsertTime = getAverage(vInsertTime);
	double avgFindTime = getAverage(vFindTime);
	outputResults(amount, avgInsertTime, avgFindTime);
}

void handleListInsertFind(int amount) {
	List list;
	vector<double> vInsertTime(100);
	vector<double> vFindTime(100);
	auto now = high_resolution_clock::now();
	for (int i = 0; i < 100; ++i) {
		insertRandomValues(list, amount);
		vInsertTime[i] = getElapsedTime(now);
		findRandomValues(list);
		vFindTime[i] = getElapsedTime(now);
	}
	double avgInsertTime = getAverage(vInsertTime);
	double avgFindTime = getAverage(vFindTime);
	outputResults(amount, avgInsertTime, avgFindTime);
}

// Binary Search Tree Stuff
struct TreeNode {
	TreeNode(int);
	~TreeNode();
	bool find(int);
	void insert(int);

	int m_value;
	TreeNode* m_left;
	TreeNode* m_right;
};

Tree::Tree() {
	m_head = NULL;
}

Tree::~Tree() {
	if (m_head != NULL) {
		delete m_head;
	}
}

bool Tree::find(int value) {
	if (m_head != NULL) {
		return m_head->find(value);
	} else {
		return false;
	}
}

void Tree::insert(int value) {
	if (m_head != NULL) {
		m_head->insert(value);
	} else {
		m_head = new TreeNode(value);
	}
}

TreeNode::TreeNode(int value) {
	m_value = value;
	m_right = NULL;
	m_left  = NULL;
}

TreeNode::~TreeNode() {
	if (m_left != NULL) {
		delete m_left;
	}
	if (m_right != NULL) {
		delete m_right;
	}
}

bool TreeNode::find(int value) {
	if (m_value == value) {
		return true;
	} else if (value < m_value && m_left != NULL) {
		return m_left->find(value);
	} else if (value > m_value && m_right != NULL) {
		return m_right->find(value);
	} else {
		return false;
	}
}

void TreeNode::insert(int value) {
	if (value < m_value) {
		if (m_left != NULL) {
			m_left->insert(value);
		} else {
			m_left = new TreeNode(value);
		}
	} else if (value > m_value) {
		if (m_right != NULL) {
			m_right->insert(value);
		} else {
			m_right = new TreeNode(value);
		}
	}
}

// Linked List stuff
struct ListNode {
	int m_data;
	ListNode* m_next;
};

List::List() {
	m_head = NULL;
	m_bitmap.resize(50000);
}

List::~List() {
	ListNode* curr = m_head;
	ListNode* next;
	while(curr != NULL) {
		next = curr->m_next;
		delete curr;
		curr = next;
	}
}

bool List::find(int value) {
	if ( value < m_bitmap.size() ) {
		return m_bitmap[value];
	}
	return false;
}

void List::insert(int value) {
	if (!find(value)) {
		ListNode* toInsert = new ListNode();
		toInsert->m_data = value;
		toInsert->m_next = m_head;
		m_head = toInsert;
		if (value > m_bitmap.size()) {
			m_bitmap.resize(2 * value);
		}
		m_bitmap[value] = true;
	}
}
