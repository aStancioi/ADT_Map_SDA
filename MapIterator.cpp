#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	//TODO - Implementation
	//best,worst,avg: T(1)
	i = 0;
}


void MapIterator::first() {
	//TODO - Implementation
	//best,worst,avg: T(1)
	i = 0;
}


void MapIterator::next() {
	//TODO - Implementation
	//best,worst,avg: T(1)
	if(!valid()){
		throw exception();
	}
	i++;
}


TElem MapIterator::getCurrent() {
	//TODO - Implementation
	//best,worst,avg: T(1)
	if (valid())
		return map.m[i];
	throw exception();
}


bool MapIterator::valid() const {
	//TODO - Implementation
	//best,worst,avg: T(1)
	if (!map.isEmpty() && i < map.l) 
	{
		return true;
	}
	return false;
}



