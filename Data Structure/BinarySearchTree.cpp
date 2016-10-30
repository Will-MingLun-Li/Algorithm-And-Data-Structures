// Binary Search Tree
// Insertion: O(logn)
// Search: O(logn)
// Removal: O(logn)
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
	void destroy();
	node *remove(int val);
	node *search(int val);

	void print_preorder();
	void print_inorder();
	void print_postorder();

private:
	node *root;

	void insertNode(int val, node *leaf);
	void destroyBST(node *leaf);
	node *removeNode(int val, node *leaf);
	node *searchNode(int val, node *leaf);

	void preorder(node *leaf);
	void inorder(node *leaf);
	void postorder(node *leaf);
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

void bst::destroyBST(node *leaf) {
	if (leaf != NULL) {
		destroyBST(leaf->left);
		destroyBST(leaf->right);

		delete leaf;
	}
}

void bst::insert(int val)
{
	if (root != NULL)
		insertNode(val, root);
	else
	{
		root = new node;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
}

void bst::insertNode(int val, node *leaf) {
	if (val < leaf->data) {
		if (leaf->left != NULL) {
			insertNode(val, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->data = val;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (val >= leaf->data) {
		if (leaf->right != NULL) {
			insertNode(val, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->data = val;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

node *bst::remove(int val) {
	return removeNode(val, root);
}

node *bst::removeNode(int val, node *leaf) {
	if (leaf == NULL) {
		return leaf;
	}
	else if (val < leaf->data) {
		leaf->left = removeNode(val, leaf->left);
	}
	else if (val > leaf->data) {
		leaf->right = removeNode(val, leaf->right);
	}
	else {
		if (leaf->left == NULL && leaf->right == NULL) {
			delete leaf;
			leaf = NULL;
		}
		else if (leaf->left == NULL) {
			node *temp = leaf;
			leaf = leaf->right;
			delete temp;
		}
		else if (leaf->right == NULL) {
			node *temp = leaf;
			leaf = leaf->left;
			delete temp;
		}
		else {
			node *check = leaf->right;
			while (check->left != NULL) {
				check = check->left;
			}

			leaf->data = check->data;
			leaf->right = removeNode(check->data, leaf->right);
		}
	}

	return leaf;
}

node *bst::search(int val) {
	return searchNode(val, root);
}

node *bst::searchNode(int val, node *leaf) {
	if (leaf != NULL) {
		if (val == leaf->data) 
			return leaf;

		if (val < leaf->data)
			return searchNode(val, leaf->left);
		else
			return searchNode(val, leaf->right);
	}
	else {
		cout << 2 << endl;
		return NULL;
	}
}

void bst::print_preorder() {
	preorder(root);
}

void bst::print_inorder() {
	inorder(root);
}

void bst::print_postorder() {
	postorder(root);
}

void bst::preorder(node *leaf) {
	if (leaf == NULL)
		return;

	cout << leaf->data << " ";
	preorder(leaf->left);
	preorder(leaf->right);
}

void bst::inorder(node *leaf) {
	if (leaf == NULL)
		return;

	inorder(leaf->left);
	cout << leaf->data << " ";
	inorder(leaf->right);
}

void bst::postorder(node *leaf) {
	if (leaf == NULL)
		return;

	postorder(leaf->left);
	postorder(leaf->right);
	cout << leaf->data << " ";
}