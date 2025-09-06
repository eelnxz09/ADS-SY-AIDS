#include <stdio.h>

int main() {
    int numbers[10];
    int sum = 0;
    int average;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = sum / 10;
    printf("%d\n", average);

    return 0;
}
