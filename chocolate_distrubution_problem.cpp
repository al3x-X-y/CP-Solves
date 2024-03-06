#include<bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n, int m) {
    sort(arr, arr+n);
    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++) {
        int diffence = arr[i+m-1] - arr[i];
        if (diffence < min_diff) {
            min_diff = diffence;
        }
    }
    return min_diff;
}
int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findMinDiff(arr, n, m) << endl;

return 0;
}
