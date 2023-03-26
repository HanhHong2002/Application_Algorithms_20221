#include <bits/stdc++.h>

using namespace std;

int N;
int d[1000000];
struct Edge
{
    int node;
    int w;
};
vector<Edge> E[1000000];

int BFS(int u)
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        d[i] = -1;
    }
    q.push(u);
    d[u] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < E[v].size(); i++)
        {
            Edge e = E[v][i];
            int x = e.node;
            int w = e.w;
            if (d[x] == -1)
            {

                q.push(x);
                d[x] = d[v] + w;
            }
        }
    }
    int maxD = -1;
    int x;
    for (int i = 1; i <= N; i++)
    {
        if (maxD < d[i])
        {
            maxD = d[i];
            x = i;
        }
    }
    return x;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }

    int x = BFS(1);
    int y = BFS(x);
    cout << d[y];
    return 0;
}
