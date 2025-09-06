#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int greatest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > greatest) {
            greatest = arr[i];
        }
    }
    printf("%d\n", greatest);

    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    printf("%d\n", smallest);

    return 0;
}
