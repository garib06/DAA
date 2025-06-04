//code for Longest Common Subsequence (LCS) problem
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

int lcs(char X[], char Y[], int m, int n) {
    int L[MAX][MAX];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main() {
    char X[MAX], Y[MAX];
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;
    int m = strlen(X);
    int n = strlen(Y);
    cout << "Length of LCS: " << lcs(X, Y, m, n) << endl;
    return 0;
}
