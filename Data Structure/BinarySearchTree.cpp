// Binary Search Tree
// Insertion: O(logn)
// Deletion: O(logn)
// Search: O(logn)
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

		void insert(int val);
		void remove(int val);
		void destroy();
		node *search(int val);

		void preorder(node *node);
		void inorder(node *node);
		void postorder(node *node);

	private:
		node *root;

		void insertNode(int val, node *node);
		void removeNode(int val, node *node);
		void destroyBST(node *node);	
		node *searchNode(int val, node *node);
};

bst::bst() {
	root = NULL;
}

bst::~bst() {
	destroy();
}

void bst::insert(int val) {

}

void bst::insertNode (int val, node *node) {

}

void bst::destroy() {
	destroyBST(root);
}

void bst::destroyBST(node *node) {
	if (node != NULL) {
		destroyBST(node->left);
		destroyBST(node->right);

		delete node;
	}
}

node *bst::search(int val) {
	return searchNode(val, root);
}

node *bst::searchNode(int val, node *node){

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