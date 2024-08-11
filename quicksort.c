#include <stdbool.h>
#include <stdio.h>

int partition_and_swap(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivotIndex = partition_and_swap(arr, low, high);
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int main() {
  int arr[] = {999, 1, 3, 5, 2, 4, 123};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  printf("Input array is \n");
  for (size_t i = 0; i < arr_size; ++i) {
    printf("%d ", arr[i]);
  }

  quickSort(arr, 0, arr_size - 1);

  printf("\nSorted array is \n");
  for (size_t i = 0; i < arr_size; ++i) {
    printf("%d ", arr[i]);
  }
}