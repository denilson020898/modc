#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], size_t lIndex, size_t half, size_t rIndex) {
  // temp arrays
  int lHalf = half - lIndex + 1;
  int rHalf = rIndex - half;

  int L[lHalf];
  int L_size = sizeof(L) / sizeof(L[0]);

  int R[rHalf];
  int R_size = sizeof(R) / sizeof(R[0]);

  for (size_t i = 0; i < lHalf; ++i) {
    L[i] = arr[lIndex + i];
  }

  for (size_t i = 0; i < rHalf; ++i) {
    R[i] = arr[half + 1 + i];
  }

  int i, j, k;
  i = 0;
  j = 0;
  k = lIndex;

  while (i < lHalf && j < rHalf) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < lHalf) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < rHalf) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], size_t lIndex, size_t rIndex) {
  if (lIndex < rIndex) {
    int half = lIndex + (rIndex - lIndex) / 2;
    mergeSort(arr, lIndex, half);
    mergeSort(arr, half + 1, rIndex);
    merge(arr, lIndex, half, rIndex);
  }
}

int main() {
  int arr[] = {999, 1, 3, 5, 2, 4, 123};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  printf("Input array is \n");
  for (size_t i = 0; i < arr_size; ++i) {
    printf("%d ", arr[i]);
  }

  mergeSort(arr, 0, arr_size - 1);

  printf("\nSorted array is \n");
  for (size_t i = 0; i < arr_size; ++i) {
    printf("%d ", arr[i]);
  }
}