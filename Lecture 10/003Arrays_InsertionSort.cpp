#include<iostream>

using namespace std;

void insertionSort(int arr[], int n) {

	for (int i = 1; i <= n - 1; i++) {

		// in the ith pass, we've to insert the 1st element of the unsorted part of the arr[] to its correct position in the sorted part of arr[]

		int key = arr[i];

		int j = i - 1;

		while (j >= 0 and key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;

	}

}

int main() {

	int arr[] = {50, 40, 10, 30, 20};
	int n = sizeof(arr) / sizeof(int);

	insertionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}