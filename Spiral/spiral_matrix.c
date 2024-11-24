#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);

    int arr[n][n];
    
    int value = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (value <= n * n) {
        for (int i = left; i <= right; i++)
            arr[top][i] = value++;
        top++;

        for (int i = top; i <= bottom; i++)
            arr[i][right] = value++;
        right--;

        for (int i = right; i >= left; i--)
            arr[bottom][i] = value++;
        bottom--;

        for (int i = bottom; i >= top; i--)
            arr[i][left] = value++;
        left++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}