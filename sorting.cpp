#include<iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void showArray(int A[], int n) {
	printf("\n");
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	printf("\n");
}

void insertionSort(int A[], int n) {
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = A[i];
		for (j = i - 1; j >= 0 && temp < A[j]; j--) {
			A[j + 1] = A[j];
		}
		A[j + 1] = temp;
	}
}

void selectionSort(int A[], int n) {
	for (int index = 0; index < n; index++) {
		int min_index = index;
		for (int i = index + 1; i < n; i++) {
			if (A[i] < A[min_index]) {
				min_index = i;
			}
		}
		swap(&A[index], &A[min_index]);
	}
}

void merge(int A[], int l, int m, int u) {
	int L[m - l + 1], R[u - m];
	int i, j, k;
	for (i = 0; i < m - l + 1; i++) L[i] = A[l + i];
	for (j = 0; j < u - m; j++) R[j] = A[m + 1 + j];

	for (k = l, i = 0, j = 0; i < m - l + 1 && j < u - m; k++) {
		if (L[i] < R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}

	while (i < m - l + 1) {
		A[k] = L[i];
		i++;
		k++;
	}

	while (j < u - m) {
		A[k] = R[j];
		j++;
		k++;
	}



}


void merge_sort(int A[], int l, int u) {
	int m;
	if (l < u) {
		m = (l + u) / 2;
		merge_sort(A, l, m);
		merge_sort(A, m + 1, u);
		merge(A, l, m, u);
	}
}


int quick(int A[], int l, int u) {
	int loc, left, right;
	loc = l;
	left = l;
	right = u;

	while (left < right) {
		while (left < right && A[loc] <= A[right]) right--;
		if (left == right) break;
		else {
			swap(&A[loc], &A[right]);
			loc = right;
		}

		while (left < right && A[loc] >= A[left]) left++;
		if (left == right) break;
		else {
			swap(&A[loc], &A[left]);
			loc = left;
		}
	}
	return loc;
}


void quicksort(int A[], int l, int u) {
	int loc = quick(A, l, u);
	if (loc > l + 1) quicksort(A, l, loc - 1);
	if (loc < u - 1) quicksort(A, loc + 1, u);

}


int main() {
	int A[] = {19, 21, 53, 22, 10, 4, 25, 91};
	showArray(A, 8);
	quicksort(A, 0, 7);
	showArray(A, 8);
}