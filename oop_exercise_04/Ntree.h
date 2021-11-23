#ifndef NTREE_H
#define NTREE_H
#include "Triangle.h"
#include <vector>
using namespace std;

struct node {
	Triangle value; // data
	vector<node*> children; // child nodes
	node(Triangle v, int max_children_size) {
		value = v;
		children.resize(max_children_size);
	}
};

class Ntree {

public:
	Ntree();
	Ntree(Triangle value, int N);
	bool insert(Triangle value);
	bool find(int pos);
	bool remove(int pos);
	friend ostream& operator<<(ostream& os, const Ntree& obj);
	node* get_root();
	~Ntree();

private:
	node* root;
	int N;
};










#endif


