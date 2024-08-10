#include<iostream>

using namespace std;

int main() {

    int arr[][4] = { // specifying #rows while init a 2D array is optional
        {10, 15, 20, 25},
        {30, 35, 40, 45},
        {50, 55, 60, 65}
    };

    int m = 3;
    int n = 4;

    cout << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << " " << arr[0][3] << endl;
    cout << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << " " << arr[1][3] << endl;
    cout << arr[2][0] << " " << arr[2][1] << " " << arr[2][2] << " " << arr[2][3] << endl << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;

}