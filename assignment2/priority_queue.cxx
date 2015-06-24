#include "priority_queue.h"

void PriorityQueue::insert(int priority, string value) {
	m_pqueue[m_next] = new Node(priority, value);
	int last = m_next;
	int previous = last;
	while(last > 0 && previous >= 0) {
		int remainder = last % 5;
		int previous = (last - remainder) / 5;
		if (m_pqueue[last]->m_priority > m_pqueue[previous]->m_priority) {
			Node* temp = m_pqueue[previous];
			m_pqueue[previous] = m_pqueue[last];
			m_pqueue[last] = temp;
		}
		last = previous;
	}
	++m_next;
}

Node* PriorityQueue::delete_max() {
	Node* retVal = m_pqueue[0];
	m_pqueue[0] = m_pqueue[--m_next];
	m_pqueue[m_next] = NULL;
	swap_w_max(0);
	return retVal;
}

void PriorityQueue::swap_w_max(int index) {
	if (index == m_next) return;
	int maxPriority = m_pqueue[index]->m_priority;
	int swapIndex = index;
	for (int i = 1; i < 6; ++i) {
		int nextIndex = index * 5 + i;
		if (nextIndex >= m_next) break;
		if (m_pqueue[nextIndex]->m_priority > maxPriority) {
			swapIndex = nextIndex;
			maxPriority = m_pqueue[nextIndex]->m_priority;
		}
	}
	if (swapIndex > index) {
		Node* tmp = m_pqueue[index];
		m_pqueue[index] = m_pqueue[swapIndex];
		m_pqueue[swapIndex] = tmp;
		swap_w_max(swapIndex);
	}
}

PriorityQueue::PriorityQueue(int size) {
	m_next = 0;
	m_pqueue = vector<Node*>(size);
}

PriorityQueue::~PriorityQueue() {
	for (size_t i = 0; i < m_pqueue.size(); ++i) {
		delete m_pqueue[i];
	}
}

int PriorityQueue::size() {
	return m_pqueue.size();
}