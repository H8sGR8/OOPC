#pragma once

#include <iostream>
using namespace std;

template <class P1, class P2> class Pair{
	public:
		P1 left;
		P2 right;
		Pair();
		Pair(P1, P2);
		Pair(const Pair<P1, P2>&);
		Pair<P1, P2>& operator = (const Pair<P1, P2>&);
}; 

template <class K, class V> class Map{
	private:
		Pair<K, V> *elements; 
		int numOfElements;
		void increaseSize();
	public:
		Map();
		~Map();
		int size();
		bool empty();
		void add(K, V);
		void clear();
		V* find(K);
		Pair<K, V>* begin();
		Pair<K, V>* end();
		V& operator[](K key);
		void erase(K key);
};

template <class K, class V>
ostream& operator<< (ostream&, Map<K, V>&);

template <class K, class V>
Map<K, V>::Map(){
	numOfElements = 0;
}

template <class K, class V>
Map<K, V>::~Map(){
	delete[] elements;
}

template <class K, class V>
int Map<K, V>::size(){
	return numOfElements;
}

template <class K, class V>
bool Map<K, V>::empty(){
	return numOfElements == 0;
}

template <class K, class V>
void Map<K, V>::increaseSize(){
	Pair<K, V>* newElements = new Pair<K, V>[numOfElements + 1];
	if(numOfElements > 0){
		copy(elements, elements + numOfElements, newElements);
		delete[] elements;
	}
	elements = newElements;
	numOfElements++;
}

template <class K, class V>
void Map<K, V>::add(K key, V value){
	if(find(key) != NULL) return;
	increaseSize();
	elements[numOfElements - 1] = Pair<K, V>(key, value);
}

template <class K, class V>
void Map<K, V>::clear(){
	delete[] elements;
	numOfElements = 0;
	elements = new Pair<K ,V>[numOfElements];
}

template <class K, class V>
V* Map<K, V>::find(K key){
	for(int i = 0; i < size(); i++){
		if(elements[i].left == key) return &elements[i].right;
	}
	return NULL;
}

template <class K, class V>
Pair<K, V>* Map<K, V>::begin(){
	return &elements[0];
}

template <class K, class V>
Pair<K, V>* Map<K, V>::end(){
	return &elements[numOfElements - 1];
}

template <class K, class V>
V& Map<K, V>::operator[](K key){
	V* ptr = find(key);
	if(ptr != NULL) return *ptr;
	increaseSize();
	elements[numOfElements - 1] = Pair<K, V>();
	elements[numOfElements - 1].left = key;
	return elements[numOfElements - 1].right;
}

template <class K, class V>
void Map<K, V>::erase(K key){
	V* ptr = find(key);
	if(ptr == NULL) return;
	for(Pair<K, V>* i = begin(); i < end(); i++){
		if(i->left == key){
			Pair<K, V> p(i->left, i->right);
			*i = *(i+1);
			*(i+1) = p;
		}
	}
	Pair<K, V>* newElements = new Pair<K, V>[numOfElements - 1];
	if(numOfElements > 0){
		copy(elements, elements + numOfElements - 1, newElements);
	}
	delete[] elements;
	elements = newElements;
	numOfElements--;
}

template<class P1, class P2>
Pair<P1, P2>::Pair(){}

template<class P1, class P2>
Pair<P1, P2>::Pair(P1 l, P2 r){
	this->left = l;
	this->right = r;
}

template<class P1, class P2>
Pair<P1, P2>::Pair(const Pair<P1, P2>& other){
	this->left = other.left;
	this->right = other.right;
}

template<class P1, class P2>
Pair<P1, P2>& Pair<P1, P2>::operator= (const Pair<P1, P2>& other){
	this->left = other.left;
	this->right = other.right;
	return *this;
}

template <class K, class V>
ostream& operator << (ostream& out, Map<K, V>& map){
	out << "Key" << "\t" << "Value" << endl;
	for(Pair<K, V>* i = map.begin(); i <= map.end(); i++){
		out << i->left << "\t" << i->right << endl;
	}
	return out;
}

