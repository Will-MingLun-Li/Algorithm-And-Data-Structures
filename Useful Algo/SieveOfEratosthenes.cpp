//Sieve Of Eratosthenes
//Runtime complexity: O(nlog(logn))
#include <iostream>
using namespace std;

void sieve(int arr[], int n) {
	if (n <= 1)
		return;

	arr[0] = 0;
	arr[1] = 0;

	for (int i = 2; i < n; i++)
		arr[n] = 1;

	for (int i = 2; i*i < n; i++) {
		if (arr[i]) {
			for (int j = 2 * i; j < n; j += i)
				arr[j] = 0;
		}
	}
}

int main() {
	int n, *arr;
	cin >> n;

	arr = new int[n+1];

	sieve(arr, n+1);

	for (int i = 2; i <= n; i++) {
		if (arr[i])
			cout << i << " ";
	}
	cout << endl;
	
	return 0;
}