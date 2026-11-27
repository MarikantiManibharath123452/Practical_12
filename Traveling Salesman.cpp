#include <iostream>
#include <climits>
using namespace std;

#define V 4

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

bool visited[V];

int tsp(int city, int count, int cost, int &ans) {
    if (count == V && graph[city][0]) {
        ans = min(ans, cost + graph[city][0]);
        return ans;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[city][i]) {
            visited[i] = true;
            tsp(i, count + 1, cost + graph[city][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    int ans = INT_MAX;

    for (int i = 0; i < V; i++)
        visited[i] = false;

    visited[0] = true;

    cout << "Minimum travelling cost = "
         << tsp(0, 1, 0, ans);

    return 0;
}
