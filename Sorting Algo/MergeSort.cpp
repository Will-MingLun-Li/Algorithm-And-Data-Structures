// Merge Sort
// Avg time complexity: O(nlogn)
// Space complexity: O(n)
#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
	int i = start, j = start, k = mid + 1, *temp;
	temp = new int[end+1];

	while (i <= mid && k <= end) {
		if (arr[i] <= arr[k]) {
			temp[j] = arr[i];
			i++;
		}
		else {
			temp[j] = arr[k];
			k++;
		}
		j++;
	}
	
	if (i > mid) {
		for (int l = k; l <= end; l++) {
			temp[j] = arr[l];
			j++;
		}
	}
	else {
		for (int l = i; l <= mid; l++) {
			temp[j] = arr[l];
			j++;
		}
	}

	for (int l = start; l <= end; l++) {
		arr[l] = temp[l];
	}
}

void mergeSort(int arr[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);

		merge(arr, start, mid, end);
	}
}

int main() {
	int n, *arr;
	cin >> n;

	arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}