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

		void push();
		void pop();
		
	private:
};

int main () {

	return 0;
}