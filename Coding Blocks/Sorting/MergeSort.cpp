#include<iostream>
using namespace std;

void merge (int arr[], int l, int r, int mid) {
    // length of left and right subarrays
	int llen = mid - l + 1;
	int rlen = r - mid;

    // temporary arrays
	int larr[llen], rarr[rlen];
	for (int i = 0; i < llen; i++) {
		larr[i] = arr[l+i];
	}
	for (int i = 0; i < rlen; i++) {
		rarr[i] = arr[mid +  1 + i];
	}

	int i = 0, j = 0, k = l;

    // merge step → O(n)
	while (i < llen && j < rlen) {
		if (larr[i] < rarr[j]) arr[k++] = larr[i++];
		else arr[k++] = rarr[j++];
	}

    // copy leftovers
	while (i < llen ) arr[k++] = larr[i++];
    while (j < rlen) arr[k++] = rarr[j++];
}

void mergeSort(int arr[],int n, int l, int r) {
	if (l >= r) return; // base case → 1 element
	int mid = l + (r - l) / 2;

    // recursive calls → T(n/2) + T(n/2)
	mergeSort(arr, n, l, mid);
	mergeSort(arr, n, mid+1, r);

    // merge step
	merge(arr, l, r, mid);
}

int main() {
	int n;
	cin >> n;
	int arr[n];

	for (int i =0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, n, 0, n-1);

	for (int i =0; i < n; i++) {
		cout << arr[i] <<  " ";
	}
	return 0;
}
