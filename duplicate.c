#include <stdio.h>

void duplicate(int *a, int s) {
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {           // fixed loop control
            if (a[i] == a[j]) {
                printf("Duplicate found: %d\n", a[i]);
                for (int k = j; k < s - 1; k++) {
                    a[k] = a[k + 1];
                }
                a[s - 1] = 0;                       // set last slot to 0 after shift
                j--;                                // re-check current index after shift
            }
        }
    }
}

void main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    duplicate(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}