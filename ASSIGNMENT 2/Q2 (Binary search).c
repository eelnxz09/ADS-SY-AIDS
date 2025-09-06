
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1, found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}
```
