#include <stdio.h>
#include <stdbool.h>

bool areEqual(int arr1[], int arr2[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {4, 3, 2, 1};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    if (n1 != n2) {
        printf("False\n");
    } else {
        if (areEqual(arr1, arr2, n1))
            printf("True\n");
        else
            printf("False\n");
    }

    return 0;
}
