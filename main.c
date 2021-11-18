#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int array[], int low, int high) {

  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      i++;

      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
             while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {

   int data[100000];
   for(int i=0;i<=100000;i++)
   {
       data[i]=rand()%100;
   }

   int n = sizeof(data) / sizeof(data[0]);
   clock_t start , endd;
    start = clock();
    quickSort(data, 0, n - 1);
    endd = clock() - start;
    double time_taken = ((double)endd)/CLOCKS_PER_SEC; //
    printf("The array is sorted using quick sort in %f seconds to execute \n", time_taken);
    int data1[100000];
    for(int i=0;i<=100000;i++)
    {
       data1[i]=rand()%100;
    }

   int n1 = sizeof(data1) / sizeof(data1[0]);
    start = clock();
    insertionSort(data1, n1);
    endd = clock() - start;
    double time_taken2 = ((double)endd)/CLOCKS_PER_SEC;
    printf("The array is sorted using insertion Sort in %f seconds to execute \n", time_taken2);
  return 0;

}
