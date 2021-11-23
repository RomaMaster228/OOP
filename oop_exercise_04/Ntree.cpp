#include "Ntree.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

Ntree::Ntree() {}

Ntree::Ntree(Triangle value, int N) {
	this->root = new node(value, N);
	if (!this->root) {
		throw "N-tree wasn't created";
	}
	this->N = N;
}

bool Ntree::insert(Triangle value) {
	queue<node*> nodes_to_visit;
	node* current_node;
	nodes_to_visit.push(root);

	while (!nodes_to_visit.empty()) {
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		for (int i = 0; i < N; i++) {
			if (!current_node->children[i]) {
				current_node->children[i] = new node(value, N);
				if (!current_node->children[i]) {
					return false;
				}
				else {
					return true;
				}
			}
			else {
				nodes_to_visit.push(current_node->children[i]);
			}
		}
	}
}

bool Ntree::find(int pos) {
	queue<node*> nodes_to_visit;
	node* current_node;
	nodes_to_visit.push(root);
	if (root == NULL) {
		throw "В дереве нет этого элемента";
		return false;
	}

	while (!nodes_to_visit.empty()) {
		current_node = nodes_to_visit.front();
		if (!current_node) {
			throw "В дереве нет этого элемента";
			return false;
		}
		nodes_to_visit.pop();
		if (pos == 1) {
			cout << current_node->value << '\n';
			return true;
		}

		for (int i = 0; i < N; i++) {
			if (current_node->children[i]) {
				nodes_to_visit.push(current_node->children[i]);
			}
		}
		pos--;
	}
}

bool Ntree::remove(int pos) {
	queue<node*> nodes_to_visit;
	node* current_node;
	nodes_to_visit.push(root);

	while (!nodes_to_visit.empty()) {
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();
		if (pos == 1) {
			delete current_node;
			root = nullptr;
			return true;
		}

		for (int i = 0; i < N; i++) {
			if (current_node->children[i]) {
				pos--;
				if (pos == 1) {
					delete current_node->children[i];
					current_node->children[i] = NULL;
					return true;
				}
				nodes_to_visit.push(current_node->children[i]);
			}
		}

	}
	return false;
}

void PrintTree(node* current_node, ostream& os, int N) {
	static int level = 0;
	level++;
	if (current_node) {
		os << "\\__" << current_node->value << '\n';
		for (int j = 0; (j < N); j++) {
			if (current_node->children[j]) {
				for (int i = 0; i < level; i++) {
					cout << "   ";
				}
				PrintTree(current_node->children[j], os, N);
			}
		}
	}
	level--;
}

ostream& operator<<(ostream& os, const Ntree& obj) {
	PrintTree(obj.root, os, obj.N);
	return os;
}

Ntree::~Ntree() {
	queue<node*> nodes_to_visit;
	node* current_node;
	nodes_to_visit.push(root);

	while (!nodes_to_visit.empty()) {
		current_node = nodes_to_visit.front();
		nodes_to_visit.pop();

		for (int i = 0; i < N; i++) {
			if (current_node && current_node->children[i]) {
				nodes_to_visit.push(current_node->children[i]);
			}
		}
		delete current_node;
	}
}

node* Ntree::get_root() {
	return root;
}

