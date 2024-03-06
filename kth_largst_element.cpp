#include<bits/stdc++.h>
using namespace std;

int partition(int numbers[], int left, int right) {
    int pivot = numbers[left];
    int l = left + 1, r = right;
    while (l <= r) {
        if (numbers[l] < pivot && numbers[r] > pivot)
            swap(numbers[l++], numbers[r--]);
        if (numbers[l] >= pivot)
            l++;
        if (numbers[r] <= pivot)
            r--;
    }
    swap(numbers[left], numbers[r]);
    return r;
}

int findKthLargest(int numbers[], int n, int k) {
    int left = 0, right = n - 1, Kth_element;
    while (true) {
        int id = partition(numbers, left, right);
        if (id == k - 1) {
            Kth_element = numbers[id];
            break;
        }
        if (id < k - 1)
            left = id + 1;
        else
            right = id - 1;
    }
    return Kth_element;
}

int main() {
    int n, k;
    cin >> n >> k;
    int numbers[n];
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    cout << findKthLargest(numbers, n, k) << endl;
    return 0;
}
