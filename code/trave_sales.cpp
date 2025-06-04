//travelling salesperson problem code in cpp
#include <iostream>
#include <climits>
using namespace std;

#define N 10 

int tsp(int graph[N][N], bool visited[N], int currPos, int n, int count, int cost, int& ans) {
    if (count == n && graph[currPos][0]) {
        if (ans > cost + graph[currPos][0])
            ans = cost + graph[currPos][0];
        return ans;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            tsp(graph, visited, i, n, count + 1, cost + graph[currPos][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of cities (max " << N << "): ";
    cin >> n;
    int graph[N][N];
    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    bool visited[N] = {false};
    visited[0] = true;
    int ans = INT_MAX;
    tsp(graph, visited, 0, n, 1, 0, ans);

    cout << "Minimum cost: " << ans << endl;
    return 0;
}
