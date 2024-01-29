#include <bits/stdc++.h>
using namespace std;

int arr[200000];
int height[200000];

int findRepresentative(int n)
{
    int f = 0;
    if (arr[n] == n)
        return n;

    arr[n] = findRepresentative(n);
    return arr[n];
}

bool collidesQueen(int x, int y, bool arr[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        if (arr[x][i])
            return false;
        if (arr[i][y])
            return false;
    }
    for (int i = 0; i < 8; i++)
    {
        if (x - i >= 0 && y - i >= 0 && arr[x - i][y - i])
            return false;
        if (x + i < 8 && y + i < 8 && arr[x + i][y + i])
            return false;
        if (x + i < 8 && y - i >= 0 && arr[x + i][y - i])
            return false;
        if (x - i >= 0 && y + i < 8 && arr[x - i][y + i])
            return false;
    }
    return true;
}

void queen(int n, bool arr[8][8])
{
    if (n == 0)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (collidesQueen)
            {
                arr[i][j] = true;
                queen(n - 1, arr);
                arr[i][j] = false;
            }
        }
    }
}

bool isSameSet(int a, int b)
{
    return (findRepresentative(a) == findRepresentative(b));
}

void unionSet(int a, int b)
{
    if (isSameSet(a, b))
        return;

    a= findRepresentative(a);
    b= findRepresentative(b);

    if (height[a] < height[b])
    {
        arr[a] = b;
        height[b] += height[a];
    }
    else
    {
        arr[b] = a;
        height[a] += height[b];
    }
}

void makeSet(int n)
{
    arr[n] = n;
    height[n] = 1;
}

bool hehe[8][8];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

#define int long long

    //queen(8, hehe);

    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);
    unionSet(1, 2);
    unionSet(2, 3);
    cout << findRepresentative(2);
    cout << findRepresentative(3);
    cout << isSameSet(2, 3);
}
