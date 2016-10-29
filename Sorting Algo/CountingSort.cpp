// Counting Sort
// Time complexity: O(n + size)
// Space complexity: O(n)

#include <iostream>
using namespace std;

int main() {
    int size, n, *arr;
    cin >> size >> n;
    
    arr = new int[size];
    int num[n] = {0};
        
    for (int i = 0; i < size; i++){
        cin >> arr[i];
        
        num[arr[i]]++;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < num[i]; j++)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}