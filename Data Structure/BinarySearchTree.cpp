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

void bst::insert(int val) {
	insertNode(val, root);
}

void bst::insertNode (int val, node *node) {
	if (node == NULL) {
		node = new node;
		node->data = val;
		node->left = NULL;
		node->right = NULL;
	}
	else if (val < node->data) {
		node->left = insertNode(val, node->left);
	}
	else if (val >= node->data) {
		node->right = insertNode(val, node->right);
	}
}

void bst::remove(int val) {
	removeNode(val, root);
}

void bst::removeNode(int val, node *node) {
	if (node == NULL) {
		return node;
	}
	else if (val < node->data) {
		node->left = removeNode(val, node->left);
	}
	else if (val > node->data) {
		node->right = removeNode(val, node->right);
	}
	else {
		if (node->left == NULL && node->right == NULL) {
			delete node;
			node = NULL;
		}
		else if (node->left == NULL) {
			node *temp = node;
			node = node->right;
			delete temp;
		}
		else if (node->right == NULL) {
			node *temp = node;
			node = node->left;
			delete temp;
		}
		else {
			node *check = node->right;
			while (check->left != NULL) {
				check = check->left;
			}

			node->data = check->data;
			node->right = removeNode(check->data, node->right);
		}
	}

	return node;
}

node *bst::search(int val) {
	return searchNode(val, root);
}

node *bst::searchNode(int val, node *node){
	if (node != NULL) {
		if (val == node->data)
			return node;

		if (val < node->data)
			return searchNode(val, node->left);
		else
			return searchNode(val, node->right);
	}
	else {
		return NULL;
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