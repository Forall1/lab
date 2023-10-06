#include <iostream>
#include <cstdlib>

using namespace std;

void show(int matrix[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }
}
void sortArray(int all[], int k) {
    for (int i = 0; i < k-1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (all[j] < all[i]) {
                int temp = all[i];
                all[i] = all[j];
                all[j] = temp;
            }
        }
    }
}
void fillMatrix(int mat[100][100], int all[], int n, int m, int min, int max, int layer) {
    if (min > max)
        return;

    for (int j = layer; j < m - layer; j++)
        mat[layer][j] = all[min++];


    for (int i = layer + 1; i < n - layer; i++)
        mat[i][m - layer - 1] = all[min++];


    if (layer < n - layer - 1)
        for (int j = m - layer - 2; j >= layer; j--)
            mat[n - layer - 1][j] = all[min++];



    if (layer < m - layer - 1)
        for (int i = n - layer - 2; i > layer; i--)
            mat[i][layer] = all[min++];



    fillMatrix(mat, all, n, m, min, max, layer + 1);
}

void mountain(int mat[100][100], int n, int m) {
    int all[n * m];

    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            all[k++] = mat[i][j];

    sortArray(all, k);
    fillMatrix(mat, all, n, m, 0, k - 1, 0);
}

int main() {
    int n, m, matrix[100][100];
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 80 + 10;

    cout << "Initial matrix" << endl;
    show(matrix, n, m);

    mountain(matrix, n, m);

    cout << "Mountain" << endl;
    show(matrix, n, m);

    return 0;
}