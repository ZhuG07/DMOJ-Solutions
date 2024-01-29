#include <bits/stdc++.h>
using namespace std;

long long diff[1000001];

// using binary search, find the maximum x such that f(x) = true
bool f(int x)
{
    if (x > 7)
        return true;
    return false;
}

bool f(double x){
    if(x<1.2384982342)
    return true; 
    return false; 
}

int last_true(int lo, int hi) // false false false.... false (this value) true true true 
{
    int l = lo;
    int r = hi;

    l--;
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (f(m)){
            l = m;
        }
        else{
            r = m - 1;
        }
    }
    return l;
}

int first_true(int lo, int hi) // true true true ...  true (this value) false false false 
{
    int l = lo;
    int r = hi;

    r++;
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (f(m)){
            r = m;
        }
        else{
            l = m - 1;
        }
    }
    return l;
}

double last_True(double lo, double hi)
{
    double l = lo;
    double r = hi;


    while (abs(l-r)<0.0000000000001)
    {
        double m = (l+r) / 2;
        if (f(m)){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    //cout << last_true(5, 10);
   cout<< last_True(1, 2);
}