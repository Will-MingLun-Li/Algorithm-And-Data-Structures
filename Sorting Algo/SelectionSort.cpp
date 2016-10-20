// Selection Sort
// Avg time complexity: O(n^2)
// Space complexity: O(1)

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size) {
	int temp, min;

	for (int i = 0; i < size - 1; i++) {
		
		min = i;
		for (int j = i; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

}

int main() {
	int arr_size;
	cin >> arr_size;

	int arr[100];
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
	}

	SelectionSort(arr, arr_size);

	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}