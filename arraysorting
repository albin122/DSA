#include <stdio.h> 
#include <stdlib.h> 
int bubble_sort = 0, insertion_sort = 0, quick_sort = 0, merge_sort = 0; 
// Bubble Sort 
void bubbleSort(int arr[], int n) { 
int i, j, temp; 
for (i = 0; i < n-1; i++) { 
for (j = 0; j < n-i-1; j++) { 
bubble_sort++; 
if (arr[j] > arr[j+1]) { 
temp = arr[j]; 
arr[j] = arr[j+1]; 
arr[j+1] = temp; 
} 
} 
} 
} 
// Insertion Sort 
void insertionSort(int arr[], int n) { 
int i,j,key; 
for(i = 1; i < n; i++) { 
key = arr[i]; 
j = i - 1; 
while(j >= 0 && arr[j] > key) { 
insertion_sort++; 
arr[j + 1] = arr[j]; 
j--; 
} 
arr[j + 1] = key; 
} 
} 
// Quick Sort 
int partition(int arr[], int low, int high) { 
int pivot = arr[high]; 
int i = (low - 1); 
for (int j = low; j < high; j++) { 
quick_sort++; 
if (arr[j] < pivot) { 
i++; 
int temp = arr[i]; 
arr[i] = arr[j]; 
arr[j] = temp; 
quick_sort++; 
} 
} 
int temp = arr[i + 1]; 
arr[i + 1] = arr[high]; 
arr[high] = temp; 
quick_sort++; 
return (i + 1); 
} 
void quickSort(int arr[], int low, int high) { 
if (low < high) { 
quick_sort++;  
int pivot = partition(arr, low, high); 
quickSort(arr, low, pivot - 1); 
quickSort(arr, pivot + 1, high); 
} 
} 
// Merge Sort 
void merge(int arr[], int left, int middle, int right) { 
int n1 = middle - left + 1; 
int n2 = right - middle; 
int L[n1], R[n2]; 
for (int i = 0; i < n1; i++) L[i] = arr[left + i]; 
for (int j = 0; j < n2; j++) R[j] = arr[middle + 1 + j]; 
int i = 0, j = 0, k = left; 
while (i < n1 && j < n2) { 
merge_sort++; 
if (L[i] <= R[j]) { 
arr[k++] = L[i++]; 
} else { 
arr[k++] = R[j++]; 
} 
} 
while (i < n1) { 
arr[k++] = L[i++]; 
merge_sort++; 
} 
while (j < n2) { 
arr[k++] = R[j++]; 
merge_sort++; 
} 
} 
void mergeSort(int arr[], int left, int right) { 
if (left < right) { 
merge_sort++; 
int middle = left + (right - left) / 2; 
mergeSort(arr, left, middle); 
mergeSort(arr, middle + 1, right); 
merge(arr, left, middle, right); 
} 
} 
void copyArray(int original[], int copied[], int n) { 
for (int i = 0; i < n; i++) { 
copied[i] = original[i]; 
} 
} 
void printArray(int arr[], int n) { 
for (int i=0; i<n; i++) 
printf("%d ", arr[i]); 
printf("\n"); 
} 
int main() { 
int n; 
printf("Enter the number of elements: "); 
scanf("%d", &n); 
int arr[n]; 
printf("Enter %d elements:\n", n); 
for (int i = 0; i < n; i++) 
scanf("%d", &arr[i]); 
int b[n], ins[n], q[n], m[n]; 
copyArray(arr, b, n); 
copyArray(arr, ins, n); 
copyArray(arr, q, n); 
copyArray(arr, m, n); 
bubbleSort(b, n); 
insertionSort(ins, n); 
quickSort(q, 0, n - 1); 
mergeSort(m, 0, n - 1); 
printf("\nSorted Arrays:\n"); 
printf("Bubble Sort: "); 
printArray(b, n); 
printf("Insertion Sort: "); 
printArray(ins, n); 
printf("Quick Sort: "); 
printArray(q, n); 
printf("Merge Sort: "); 
printArray(m, n); 
printf("\nStep Comparison\n"); 
printf("Bubble Sort Steps:    %d\n", bubble_sort); 
printf("Insertion Sort Steps: %d\n", insertion_sort); 
printf("Quick Sort Steps:     
printf("Merge Sort Steps:    
return 0; 
} 
%d\n", quick_sort); 
 %d\n", merge_sort);
