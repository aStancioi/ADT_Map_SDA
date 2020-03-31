#include "Map.h"
#include "MapIterator.h"

Map::Map() {
	//TODO - Implementation
	//best,worst,avg: T(1)
	l = 0; //length; will be followed throughout the program
	capacity = 8; //capacity; doubled if l reaches it
	m = new TElem[capacity];
}

Map::~Map() {
	//TODO - Implementation
	delete m;
}

TValue Map::add(TKey c, TValue v) {
	//TODO - Implementation
	//best,worst,avg: O(n)

	int p, aux;

	if (l == capacity) //doebles the array's capacity
	{
		capacity *= 2;
		TElem* aux_pointer = new TElem[capacity];
		for (int i = 0; i < l; i++) {
			aux_pointer[i] = m[i];
		}
		delete m;
		m = aux_pointer;
	}

	if (l == 0) {
		// If the array is empty add the element.
		m[0] = std::make_pair(c, v);
		l++;
		return NULL_TVALUE;
	}
	
	for (p = 0; p < l; p++)
	{
		if (m[p].first == c)		//returns the old value if the key already exists; replaces it beforehand with the specified value
		{
			aux = m[p].second;
			m[p].second = v;
			return aux;
		}
	}
	m[l] = std::make_pair(c, v);
	l++;
	return NULL_TVALUE;
}

TValue Map::search(TKey c) const {
	//TODO - Implementation
	//returns the value corresponding to the key if it exists
	//best,worst,avg: T(n)
	int p;
	for (p = 0; p < l; p++)
		if (c == m[p].first)
			return m[p].second;
	return NULL_TVALUE;
}

TValue Map::remove(TKey c) {
	//TODO - Implementation
	//removes an element by moving each value to the left if the key exists, then decreases the length
	//best: O(1); worst: O(n); avg: O(n)

	int p, aux;

	if (isEmpty() || search(c) == NULL_TVALUE)
		return NULL_TVALUE;

	if (c == m[l - 1].first)
	{
		aux = m[l - 1].second;
		l--;
		return aux;
	}

	for (p = 0; p < l; p++)
	{
		if (m[p].first == c)			//removes the specified element
		{
			aux = m[p].second;
			for (int i = p; i < l - 1; i++) {
				m[i] = m[i + 1];
			}
			l--; 
			return aux;
		}
	}
	return NULL_TVALUE;

}


int Map::size() const {
	//TODO - Implementation
	//best,worst,avg: T(1)
	return l;
}

bool Map::isEmpty() const {
	//TODO - Implementation
	// best,worst,avg O(1)
	if (l == 0) {
		return true;
	}
	return false;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}



