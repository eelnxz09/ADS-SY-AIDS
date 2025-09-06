#include <stdio.h>

int main() {
    int a[100], i, k, n;

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    printf("Enter %d Elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter Search Key: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        if (a[i] == k) {
            printf("Element %d Found at %d\n", a[i], i + 1);
            return 0;
        }
    }

    printf("Element not found.\n");
    return 0;
}
