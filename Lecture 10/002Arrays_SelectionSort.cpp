#include<iostream>

using namespace std;

void selectionSort(int arr[], int n) {

	for (int i = 0; i <= n - 2; i++) {

		// in the ith pass, place the smallest element in the unsorted part of the arr[] to its correct position

		int cPos = i;
		int minIdx = i;

		for (int j = i + 1; j <= n - 1; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}

		swap(arr[cPos], arr[minIdx]);

	}

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	selectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}