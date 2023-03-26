#include <bits/stdc++.h>

using namespace std;

int N, M;
int p[100000];
int r[100000];
int sum = 0;

typedef struct
{
    int u;
    int v;
    int weight;
} edge;
edge E[100000];
vector<edge> result;

int Find(int x)
{
    if (p[x] == x)
        return x;
    else
    {
        p[x] = Find(p[x]);
    }
    return p[x];
}

void Unify(int x, int y)
{
    if (r[x] > r[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
        if (r[x] == r[y])
        {
            r[y]++;
        }
    }
}

bool ascending(edge a, edge b)
{
    return a.weight < b.weight;
}

void Kruskal()
{
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
        r[i] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        int u = E[i].u;
        int v = E[i].v;
        int ru = Find(u);
        int rv = Find(v);
        if (ru != rv)
        {
            sum += E[i].weight;
            Unify(ru, rv);
            result.push_back(E[i]);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E[i].u = u;
        E[i].v = v;
        E[i].weight = w;
    }
    sort(E, E + M, ascending);
    Kruskal();
    cout << sum << endl;
}
