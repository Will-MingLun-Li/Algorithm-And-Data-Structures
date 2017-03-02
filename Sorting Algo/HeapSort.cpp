// Heap sort
// Avg run-time: O(nlogn)
// Space complexity: O(1)

#include <iostream>
using namespace std;

void heapify(int arr[], int length, int root) {
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < length && arr[left] > arr[largest])
		largest = left;

	if (right < length && arr[right] > arr[largest])
		largest = right;

	if (largest != root) {
		swap(arr[largest], arr[root]);
		heapify(arr, length, largest);
	}
}

void heapsort(int arr[], int length) {

	for (int i = length / 2 - 1; i >= 0; i--) {
		heapify(arr, length, i);
	}

	for (int i = length - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	int n, *arr;
	cin >> n;

	arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	heapsort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}