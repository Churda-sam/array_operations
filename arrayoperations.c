#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert a value into the array at a specific position
int insertValue(int arr[], int *size, int capacity, int value, int position) {
    if (*size >= capacity) {
        printf("Error: Array capacity reached. Cannot insert.\n");
        return 0;
    }
    if (position < 0 || position > *size) {
        printf("Error: Invalid position for insertion.\n");
        return 0;
    }

    // Shift elements to the right to make space
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the value and increment size
    arr[position] = value;
    (*size)++;
    return 1;
}

// Function to delete a value from the array at a specific position
int deleteValue(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Error: Array is empty. Cannot delete.\n");
        return 0;
    }
    if (position < 0 || position >= *size) {
        printf("Error: Invalid position for deletion.\n");
        return 0;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement size
    (*size)--;
    return 1;
}

int main() {
    int capacity = 100; // Maximum capacity of the array
    int *arr = (int *)malloc(capacity * sizeof(int));
    int size = 0;
    int choice, value, position;

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initial population of the array
    printf("Enter initial number of elements: ");
    if (scanf("%d", &size) != 1 || size < 0 || size > capacity) {
        printf("Invalid size.\n");
        free(arr);
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Display Array\n");
        printf("2. Insert Value\n");
        printf("3. Delete Value\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                insertValue(arr, &size, capacity, value, position);
                displayArray(arr, size);
                break;
            case 3:
                if (size == 0) {
                    printf("Array is already empty.\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &position);
                deleteValue(arr, &size, position);
                displayArray(arr, size);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    free(arr);
    return 0;
}