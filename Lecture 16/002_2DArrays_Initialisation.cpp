#include<iostream>

using namespace std;

int main() {

    int arr[2][3] = {
        {10, 15, 20},
        {30, 35, 40}
    };

    int m = 2;
    int n = 3;

    for (int i = 0; i < m; i++) {
        for (int  j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int brr[][3] = {
        {10, 20, 30},
        {40, 50}
    };

    int mm = 2;
    int nn = 3;

    for (int i = 0; i < mm; i++) {
        for (int j = 0; j < nn; j++) {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}