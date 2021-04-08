#include "SMMIterator.h"
#include "SortedMultiMap.h"

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d) {
	curr = d.head; // set current element to head of smm d
} // All cases: Theta(1)

void SMMIterator::first() {
	curr = map.head;
} // All cases: Theta(1)

void SMMIterator::next() {
	if (valid()) {
		curr = curr->next;
	}
	else throw exception();
} // All cases: Theta(1)

bool SMMIterator::valid() const {
	if (map.size() == 0) { // size zero cannot itterate
		return false;
	}
	else if (curr != NULL) { // out of bounds
		return true;
	}
	return false;
} // All cases: Theta(1)

TElem SMMIterator::getCurrent() const {
	if (map.size() != 0) {
		return curr->data;
	}
	else throw exception();
} // All cases: Theta(1)


