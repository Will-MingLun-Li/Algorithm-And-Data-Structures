// Quick Sort
// Avg time complexity: O(nlogn)
// Space complexity: O(logn)

#include <vector>
#include <iostream>
using namespace std;

void quickSort(vector <int> &arr, int left, int right) {
	int i = left, j = right;
	int temp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main() {

	int arr_size, val;
	cin >> arr_size;

	vector <int> arr;
	for (int i = 0; i < arr_size; i++) {
		cin >> val;
		arr.push_back(val);
	}

	quickSort(arr, 0, arr.size()-1);

	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
