#include <stdbool.h>
#include <stdio.h>

void bubbleSort(int arr[], size_t len) {
  bool swapped;
  for (size_t i = 0; i < len; i++) {
    swapped = false;
    for (size_t j = 0; j < len - i - 1; j++) {
      size_t leftBound = j;
      size_t rightBound = j + 1;
      if (arr[leftBound] > arr[rightBound]) {
        int temp = arr[leftBound];
        arr[leftBound] = arr[rightBound];
        arr[rightBound] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

int main() {
  int arr[] = {999, 1, 3, 5, 2, 4, 123};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  printf("Input array is \n");
  for (size_t i = 0; i < arr_size; ++i) {
    printf("%d ", arr[i]);
  }

  bubbleSort(arr, arr_size);

  printf("\nSorted array is \n");
  for (size_t i = 0; i < arr_size; ++i) {
    printf("%d ", arr[i]);
  }
}