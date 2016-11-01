// Stack
// Push: O(1)
// Pop: O(1)

#include <iostream>
using namespace std;

template <typename T>
struct node {
	T data;
	node *next;
};

template <typename T>
class stack {
public:
	stack();
	~stack();

	void push(T val);
	T pop();
	bool isEmpty();
	void print();

private:
	node<T> *topNode;
	int size;
};

template <typename T>
stack<T>::stack() {
	topNode = NULL;
	size = 0;
}

template <typename T>
stack<T>::~stack() {
	while (!isEmpty()) {
		pop();
	}
}

template <typename T>
void stack<T>::push(T val) {
	if (size == 0) {
		node<T> *newNode = new node<T>();
		newNode->data = val;
		topNode = newNode;
	}
	else {
		node<T> *newNode = new node<T>();
		newNode->data = val;
		newNode->next = topNode;
		topNode = newNode;
	}

	size++;
}

template <typename T>
T stack<T>::pop() {
	if (!isEmpty()) {
		node <T> *temp = topNode;
		T poppedData = topNode->data;
		topNode = topNode->next;
		delete temp;
		size--;

		return poppedData;
	}
}

template <typename T>
bool stack<T>::isEmpty() {
	return size == 0;
}

template <typename T>
void stack<T>::print() {
	node<T> *temp = topNode;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	delete temp;
}


int main() {
	stack<int> s;
	s.push(3);
	s.push(1);
	s.push(4);
	s.push(1);
	s.push(5);
	s.print();
	s.pop();
	s.print();
	s.pop();
	s.print();
	s.pop();
	s.print();

	system("pause");
}