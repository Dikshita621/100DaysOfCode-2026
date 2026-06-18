#include <stdio.h>

void rotateArray(int arr[], int n, int k) {
    k = k % n;  // Handle cases where k > n
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotateArray(arr, n, k);

    printf("Output: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(",");
    }
    printf("]\n");

    return 0;
}
