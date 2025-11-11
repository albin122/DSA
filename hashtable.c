#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 10 
int hashTable[SIZE]; 
int flag[SIZE]; // 0 for empty, 1 for occupied, -1 for deleted 
// Hash function 
int hash(int key) { 
return key % SIZE; 
} 
// Insert a key 
void insert(int key) { 
int index = hash(key); 
int startIndex = index; 
while (flag[index] == 1) { 
index = (index + 1) % SIZE; 
if (index == startIndex) { 
printf("Hash Table is Full\n"); 
return; 
} 
} 
hashTable[index] = key; 
flag[index] = 1; 
printf("Inserted key %d at index %d\n", key, index); 
} 
// Search a key 
void search(int key) { 
int index = hash(key); 
int startIndex = index; 
while (flag[index] != 0) { 
if (flag[index] == 1 && hashTable[index] == key) { 
printf("Key %d found at index %d\n", key, index); 
return; 
} 
index = (index + 1) % SIZE; 
if (index == startIndex) { 
break; 
} 
} 
printf("Key %d not found\n", key); 
} 
// Delete a key 
void delete(int key) { 
int index = hash(key); 
int startIndex = index; 
while (flag[index] != 0) { 
if (flag[index] == 1 && hashTable[index] == key) { 
flag[index] = -1; // Mark as deleted 
printf("Key %d deleted from index %d\n", key, index); 
return; 
} 
index = (index + 1) % SIZE; 
if (index == startIndex) { 
break; 
} 
} 
printf("Key %d not found to delete\n", key); 
} 
// Display hash table 
void display() { 
printf("\nHash Table:\n"); 
for (int i = 0; i < SIZE; i++) { 
if (flag[i] == 1) 
printf("Index %d: %d\n", i, hashTable[i]); 
else if (flag[i] == -1) 
printf("Index %d: Deleted\n", i); 
else 
printf("Index %d: Empty\n", i); 
} 
} 
int main() { 
for (int i = 0; i < SIZE; i++) { 
flag[i] = 0; // Initialize all slots as empty 
} 
    int choice, key; 
    do { 
        printf("\nMenu\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter 
choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter key to insert: "); 
                scanf("%d", &key); 
                insert(key); 
                break; 
            case 2: 
                printf("Enter key to search: "); 
                scanf("%d", &key); 
                search(key); 
                break; 
            case 3: 
                printf("Enter key to delete: "); 
                scanf("%d", &key); 
                delete(key); 
                break; 
            case 4: 
                display(); 
                break; 
            case 5: 
                printf("Exiting Program\n"); 
                exit(0); 
            default: 
                printf("Invalid choice\n"); 
        } 
    } while (1); 
 
    return 0; 
}
