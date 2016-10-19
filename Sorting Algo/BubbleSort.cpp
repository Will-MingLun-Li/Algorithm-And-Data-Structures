// Bubble Sort
// Avg time complexity: O(n^2)
// Space complexity: O(1)

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size) {
	int temp;

	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

int main() {
	int arr_size;
	cin >> arr_size;

	int arr[100];
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
	}

	BubbleSort(arr, arr_size);

	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}