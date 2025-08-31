#include<iostream>
#include<vector>
using namespace std;

// Partition function: places pivot at correct position
// and arranges smaller elements to the left,
// greater elements to the right
int pivot(vector<int> &vec,int l,int h) {
    int pivot = vec[h];  // choose last element as pivot
    int i = l;
    for (int j = l; j < h; j++) {
        if (pivot > vec[j]) swap(vec[i++], vec[j]);
    }
    swap(vec[i], vec[h]);  // place pivot in correct position
    return i;
}

// QuickSort function (recursive)
// Worst case: O(n^2) [when pivot divides badly, e.g., sorted array]
// Best/Average case: O(n log n)
void quickSort(vector<int> &vec,int l,int h) {
    if(l < h) {
        int pi = pivot(vec, l, h);   // partition index
        quickSort(vec, l, pi-1);     // sort left part
        quickSort(vec, pi+1, h);     // sort right part
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);

    // input array
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    // call quicksort
    quickSort(vec, 0, n-1);

    // print sorted array
    for ( int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}
