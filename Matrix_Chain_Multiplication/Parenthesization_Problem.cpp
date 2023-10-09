#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to print the optimal parenthesization
void printParenthesis(vector<vector<int>>& bracket, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1;
        return;
    }

    cout << "(";
    printParenthesis(bracket, i, bracket[i][j]);
    printParenthesis(bracket, bracket[i][j] + 1, j);
    cout << ")";
}

void matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1; // Number of matrices
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[0][n - 1] << endl;
    cout << "Optimal Parenthesization: ";
    printParenthesis(bracket, 0, n - 1);
    cout << endl;
}

int main() {
    int n; // Number of matrices
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> dimensions(n + 1); // Dimensions of matrices

    // Input the dimensions of each matrix
    cout << "Enter the dimensions of the matrices:" << endl;
    for (int i = 0; i <= n; i++) {
        cin >> dimensions[i];
    }

    matrixChainOrder(dimensions);

    return 0;
}
