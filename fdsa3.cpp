#include <bits/stdc++.h>
using namespace std;

bool partOfTree[100005];
int dist[100005];

int p[100005];
int height[100050];

tuple<int, int, int> edges[100050];

void initialize(int N)
{

    for (int i = 0; i < N; ++i)
        p[i] = i;
}

bool compare1(int a, int b)
{
    // return get<2>(edges[a]) < get<2>(edges[b]);
}

int findSet(int i)
{
    if (p[i] == i)
        return i;
    p[i] = findSet(p[i]); // Path Compression
    return p[i];
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
    if (isSameSet(i, j)) // i and j are in same set
        return;
    int x = findSet(i); // find rep items
    int y = findSet(j); // find rep items
    if (height[x] > height[y])
        swap(x, y); // Union by rank
    p[x] = y;       // set x under y
    if (height[x] == height[y])
        ++height[y]; // optional speedup
}

int pens[1000];

int main()
{

    cin.sync_with_stdio(0);
    cin.tie(0);

    int M;
    cin>>M;




    initialize(M + 1);

    for (int i = 0; i < M; i++)
    {
        
    }

    for(int i = 1 ; i <= N-K ; i ++){
        unionSet(i, i + K);
    }

sort(edges, edges+N);
    vector<int> ans;
    int count = 0;
    int edgeNumber = 0;
    int usedEdge = 0;
    for (auto x : edges)
    {
        // cout<<get<0>(x)<<" "<<get<2>(x)<<" "<<get<1>(x)<<"\n";
        if (!isSameSet(get<1>(x), get<2>(x)))
        {
            unionSet(get<1>(x), get<2>(x));
           
            count+=get<0>(x);
            
        }
        edgeNumber++;
    }
    cout<<count<<"\n";
}
