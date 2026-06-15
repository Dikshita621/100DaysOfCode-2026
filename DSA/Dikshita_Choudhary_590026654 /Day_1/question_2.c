#include <stdio.h>
int arraySum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    int arr[] = {3, 8, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", arraySum(arr, size));  
    return 0;
}
