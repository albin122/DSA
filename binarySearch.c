#include<stdio.h> 
int main() { 
int n, key, flag = 0, count = 2; 
printf("Enter the number of elements: "); 
scanf("%d", &n); 
count++; 
int sortedArray[n]; 
printf("Enter %d sorted elements\n", n); 
for(int i = 0; i < n; i++) { 
scanf("%d", &sortedArray[i]); 
count++; 
} 
printf("Enter the element to search: "); 
scanf("%d", &key); 
count++; 
int start = 0, end = n - 1; 
count += 3; 
while(start <= end) { 
int mid = (start + end) / 2; 
count++; 
if(sortedArray[mid] == key) { 
printf("Element %d found at index %d\n", key, mid); 
flag = 1; 
count++; 
break; 
} 
else if(sortedArray[mid] > key) { 
end = mid - 1; 
count++; 
} 
else { 
start = mid + 1; 
count++; 
} 
} 
if(flag == 0) { 
printf("Element %d not found in the array\n", key); 
} 
int space = 8*4 + n*4; // Approximate memory usage in bytes 
printf("Space complexity = %d bytes\n", space); 
printf("Time complexity = %d units\n", count); 
return 0; 
}
