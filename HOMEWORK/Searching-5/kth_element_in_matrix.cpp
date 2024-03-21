
int possible(int mat[MAX][MAX], int n, int mid) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] <= mid) {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

int kthSmallest(int mat[MAX][MAX], int n, int k) {
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = possible(mat, n, mid);

       if (count < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low; // If kth smallest element is not found
}
