// Binary Search Tree
// Insertion: 
// Deletion: 
// Destroy BST: O(n)
// Traversals: O(n)

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

void bst::destroyBST(node *node) {
	if (node != NULL) {
		destroyBST(node->left);
		destroyBST(node->right);

		delete node;
	}
}

void bst::preorder(node *node) {
	if (node == NULL)
		return;

	cout << node->data << " ";
	preorder(node->left);
	preorder(node->right);
}

void bst::inorder(node *node) {
	if (node == NULL)
		return;

	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

void bst::postorder(node *node) {
	if (node == NULL)
		return;

	postorder(node->left);
	postorder(node->right);
	cout << node->data << " ";
}

int main() {

	return 0;
}