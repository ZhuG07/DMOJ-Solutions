#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1000001];
int visited[1000001];
int previous[1000001];
vector<int> ans;

void dfs(int x)
{
    visited[x] = true;
    for (int v : adjList[x])
    {
        if (!visited[v])
        {
            previous[v] = x;
            dfs(v);
        }
    }
    // coming out of recursion, push the vertex into the ans[]
    ans.push_back(x);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int lol;
            cin>>lol;
            adjList[i].push_back(lol);
        }
    }
    // loop and start from each unvisitedd vertex and dfs down
    //(since you may not start from the "root" vertex everytime)
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    // output the final ans[] backwards
    for (int i = 0; i <N; i++)
    {
        cout << ans[i]<<" ";
    }
}
