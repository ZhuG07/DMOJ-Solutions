#include <bits/stdc++.h>
using namespace std;

bool isSameSet(int a, int b);
int findSet(int n);
void joinSet(int a, int b);
void makeSet(int n);
int findLeader(int n);

int arr[500001];
int height[500001];
deque<pair<int, int>> Revert;
deque<pair<int, int>> RevertHeight;

void Init(int N)
{
    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
        height[i] = 1;
    }
}

int GetSize(int U)
{
    return height[findLeader(U)];
}

void RemoveLastEdge()
{
    bool Break = true;
    while (Break)
    {
        auto temp = Revert.back();
        int x = temp.first;
        int y = temp.second;
        if (x == 0 && y == 0)
            Break = false;
        arr[x] = y;
        Revert.pop_back();
    }
    Break = true;
    while (Break)
    {
        auto temp = RevertHeight.back();
        int x = temp.first;
        int y = temp.second;
        if (x == 0 && y == 0)
            Break = false;
        height[x] = y;
        RevertHeight.pop_back();
    }
}

void AddEdge(int a, int b)
{
    Revert.push_back(make_pair(0, 0));
    RevertHeight.push_back(make_pair(0, 0));
    if (isSameSet(a, b))
        return;

    a = findSet(a);
    b = findSet(b);

    if (height[a] < height[b])
    {
        Revert.push_back(make_pair(a, arr[a]));
        RevertHeight.push_back(make_pair(b, height[b]));
        arr[a] = b;
        height[b] += height[a];
    }
    else
    {
        Revert.push_back(make_pair(b, arr[b]));
        RevertHeight.push_back(make_pair(a, height[a]));
        arr[b] = a;
        height[a] += height[b];
    }
}

vector<int> adjList[100];
bool visited[100];
void dfs(int v)
{
    for (int x : adjList[v])
    {
        if (!visited[x])
        {
            visited[x] = true;
            dfs(x);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    Init(10);
    AddEdge(2, 3);
    cout << GetSize(3) << "\n";
    RemoveLastEdge();
    cout << GetSize(2) << "\n";
}

int findSet(int n)
{

    if (arr[n] == n)
        return n;

    Revert.push_back(make_pair(n, arr[n]));
    RevertHeight.push_back(make_pair(n, height[n]));
    arr[n] = findSet(arr[n]);
    return arr[n];
}

int findLeader(int n)
{

    if (arr[n] == n)
        return n;

    return findLeader(arr[n]);
}

bool isSameSet(int a, int b)
{
    return (findSet(a) == findSet(b));
}

void makeSet(int n)
{
    arr[n] = n;
    height[n] = 1;
}