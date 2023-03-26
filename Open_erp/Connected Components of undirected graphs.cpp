#include <bits/stdc++.h>

using namespace std;

int n, m;
int nbCC = 0;
int cc[1000000];
vector<int> s[1000000];

void init()
{
    int a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        s[a].push_back(b);
        s[b].push_back(a);
    }
}

void Try(int node)
{
    cc[node] = nbCC;
    // cout << cc[node] << " " << node << endl;
    for (int i = 0; i < s[node].size(); i++)
    {
        if (cc[s[node][i]] == 0)
            Try(s[node][i]);
    }
}

int main()
{
    init();
    for (int i = 1; i <= n; i++)
    {
        if (cc[i] == 0)
        {
            // cout << "cii" << cc[i] << " " << i << endl;
            nbCC += 1;
            Try(i);
        }
    }
    cout << nbCC;
}
