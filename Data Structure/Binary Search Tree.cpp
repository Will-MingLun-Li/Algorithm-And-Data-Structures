// Binary Search Tree
// Insertion: 
// Deletion: 
// Destroy:
// Traversal:

#include <iostream>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

class bst {
	public:
		bst();
		~bst();

		void insert(int key);
		void remove(int key);
		void destroyBST();
		void preorder(node *node);
		void inorder(node *node);
		void postorder(node *node);

	private:
		node *root;

		void destroyBST(node *node);
};

bst::bst() {
	root = NULL;
}

bst::~bst() {
	destroyBST();
}

void bst::destroyBST() {
	destroyBST(root);
}

int main() {

	return 0;
}