//Queue
//Enqueue: O(1)
//Dequeue: O(1)
#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

class queue {
	public:
		queue();
		~queue();
		void enqueue(int value);
		void dequeue();
		void print();

	private:
		node *front;
		node *back;
		int size;
};

queue::queue() {
	front = NULL;
	back = NULL;
	size = 0;
}

queue::~queue() {
	while (size != 0) {
		dequeue();
	}
}

void queue::enqueue(int val) {
	node *newNode = new node;

	newNode->data = val;
	newNode->next = NULL;

	if (size == 0) {
		front = newNode;
	}
	else {
		back->next = newNode;
	}

	back = newNode;
	size++;
}

void queue::dequeue() {
	if (size != 0) {
		node *temp = front;
		front = front->next;
		delete temp;

		size--;
	}
}

void queue::print() {
	node *temp = front;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	queue q;
	q.enqueue(3);
	q.print();
	q.enqueue(1);
	q.enqueue(4);
	q.enqueue(1);
	q.enqueue(5);
	q.print();
	q.dequeue();
	q.print();
	q.dequeue();
	q.print();
	q.enqueue(124);
	q.print();
}