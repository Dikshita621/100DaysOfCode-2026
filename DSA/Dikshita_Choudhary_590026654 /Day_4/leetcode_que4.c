int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColSizes) {
    int m = matrixSize;      // original rows
    int n = *matrixColSize;  // original cols
    
    *returnSize = n;         
    *returnColSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColSizes)[i] = m; 
    }
    int** result = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
}

