#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
	head = NULL;
	tail = NULL;
	length = 0;
	rel = r;
} // All cases: Theta(1)

void SortedMultiMap::add(TKey c, TValue v) {
	node* n = new node; //creating node no matter what
	n->data.first = c;
	n->data.second = v;

	if (isEmpty()) { //case empty
		n->next = NULL;
		head = n;
		tail = n;
		length++;
		return; //case end
	}

	if (rel(n->data.first, head->data.first)) { // case first
		n->next = head; // link n to head
		head = n; //move head
		length++;
		return; // case end
	}

	if (rel(tail->data.first, n->data.first)) { // case last
		tail->next = n; // link tail to n
		tail = n; // move tail
		length++;
		tail->next = NULL; // set tail next to NULL
		return; // case end
	}

	node* curr = head; // case any
	while (curr->next != NULL && (rel(curr->data.first, n->data.first) || rel(n->data.first, curr->next->data.first))) { // find case any
		curr = curr->next; // iterate until case any
	} // case any is on curr

	if (curr->next == NULL) return; // case end - relation doesn't fit
	else { // not end
		n->next = curr->next; // set next el after n to be next after current
		curr->next = n; // set next after current to be n
		return;// case end
	}

} // Best case: Theta(1), Worst case: Theta(n) = Average case, General Case: O(n);

vector<TValue> SortedMultiMap::search(TKey c) const {
	vector<TValue> vect;

	//checks if list empty for best case
	if (isEmpty()) { // case empty
		return vect;
	}

	node* curr = head;
	while (curr != NULL) { // case key match
		if (curr->data.first == c) {
			vect.push_back(curr->data.second); // push value
		}
		curr = curr->next; // iterate
	}

	return vect; //return finished vector
} // Best case: Theta(1), Worst case: Theta(n) = Average case, General Case: O(n);

bool SortedMultiMap::remove(TKey c, TValue v) {

	//checks if list empty for best case
	if (isEmpty()) { // case empty
		return false; // bye bye
	}

	node* curr = head;
	node* prev = NULL;
	while (curr != NULL && (curr->data.first != c || curr->data.second != v)) { // find matching key and value
		prev = curr; // set to last curr
		curr = curr->next; // iterate
	}
	if (curr != NULL && prev == NULL) { // remove head
		head = head->next; // pass tp next
		length--;
		return true;
	}
	else if (curr != NULL) { // all other
		prev->next = curr->next; // ignore curr
		curr->next = NULL;
		length--;
		return true;
	}
	return false; //case not found
} // Best case: Theta(1), Worst case: Theta(n) = Average case, General Case: O(n);


int SortedMultiMap::size() const {
	return length;
} // All cases: Theta(1)

bool SortedMultiMap::isEmpty() const {
	return (!length) ? true : false;
} // All cases: Theta(1)

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
} // All cases: Theta(1)

SortedMultiMap::~SortedMultiMap() {
	if (!isEmpty()) {
		while (head->next != NULL) { // iterate and del
			node* curr = head;
			head = head->next;
			delete curr;
		}
		delete head; // del remaining head
	}
} // Best case: Theta(1), Worst case: Theta(n) = Average case, General Case: O(n);
