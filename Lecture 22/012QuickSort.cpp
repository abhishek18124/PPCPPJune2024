// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int pivot = arr[e];

	int j = s;
	int i = s - 1;

	// while (j < e) {

	// 	if (arr[j] > pivot) {

	// 		// put arr[j] in right partition

	// 		j++;

	// 	} else {

	// 		// put arr[j] in left partition

	// 		i++;
	// 		swap(arr[i], arr[j]);
	// 		j++;

	// 	}

	// }

	while (j < e) {

		if (arr[j] < pivot) {

			// put arr[j] in left partition

			i++;
			swap(arr[i], arr[j]);


		}

		j++;

	}


	// bring pivot to its correct position i+1

	swap(arr[i + 1], arr[e]);

	return i + 1;

}

void quickSort(int arr[], int s, int e) {

	// base case

	if (s > e) { // mandatory
		return;
	}

	if (s == e) { // optional
		return;
	}

	// recursive case

	int pidx = partition(arr, s, e);
	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}