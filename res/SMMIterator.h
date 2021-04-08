#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART LOL
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

	node* curr;

public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

