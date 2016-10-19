// Insertion Sort 
// Avg time complexity: O(n^2) 	
// Space complexity: O(1)

#include <iostream>
using namespace std;

void insertionSort(int arr_size, int *arr) {
	int temp, j;
	for (int i = 1; i < arr_size; i++) {
		j = i;

		while (j > 0 && arr[j] < arr[j - 1]) {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

int main() {

	int arr_size;
	cin >> arr_size;

	int arr[arr_size];
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
	}

	insertionSort(arr_size, arr);

	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}