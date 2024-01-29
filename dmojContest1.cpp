#include <bits/stdc++.h>
using namespace std;

bool arr[260][260];

void recurse(int x1, int y1, int x2, int y2, int leng1th);

long long fastExp(long long a, long long n)
{
    long long ans = 1;

    while (n > 0)
    {
        if (n & 1)
            ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

int main()
{

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    arr[x][y] = true;
    recurse(0, 0, pow(2, n) - 1, pow(2, n) - 1, pow(2, n));
}

void recurse(int x1, int y1, int x2, int y2, int length)
{

    if (length == 2)
    {
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                if (!arr[i][j])
                    cout << i << " " << j << " ";
                arr[i][j] = true;
            }
        }
        cout << "\n";
    }
    else
    {
        double centerX = (x1 + x2) / 2.0;
        double centerY = (y1 + y2) / 2.0;

        // find the square thats filled
        int Xfilled, Yfilled;

        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                if (arr[i][j])
                {
                    Xfilled = i;
                    Yfilled = j;
                }
            }
        }

        // determine which quadrant is the Xfilled Yfilled in
        if (Xfilled < centerX && Yfilled < centerY)
        {
            arr[(int)floor(centerX)][(int)ceil(centerY)] = true;
            arr[(int)ceil(centerX)][(int)ceil(centerY)] = true;
            arr[(int)ceil(centerX)][(int)floor(centerY)] = true;
            cout << (int)floor(centerX) << " " << (int)ceil(centerY) << " ";
            cout << (int)ceil(centerX) << " " << (int)ceil(centerY) << " ";
            cout << (int)ceil(centerX) << " " << (int)floor(centerY) << "\n";
        }
        else if (Xfilled < centerX && Yfilled > centerY)
        {
            arr[(int)floor(centerX)][(int)floor(centerY)] = true;
            arr[(int)ceil(centerX)][(int)ceil(centerY)] = true;
            arr[(int)ceil(centerX)][(int)floor(centerY)] = true;
            cout << (int)floor(centerX) << " " << (int)floor(centerY) << " ";
            cout << (int)ceil(centerX) << " " << (int)ceil(centerY) << " ";
            cout << (int)ceil(centerX) << " " << (int)floor(centerY) << "\n";
        }
        else if (Xfilled > centerX && Yfilled < centerY)
        {
            arr[(int)floor(centerX)][(int)floor(centerY)] = true;
            arr[(int)floor(centerX)][(int)ceil(centerY)] = true;
            arr[(int)ceil(centerX)][(int)ceil(centerY)] = true;

            cout << (int)ceil(centerX) << " " << (int)ceil(centerY) << " ";
            cout << (int)floor(centerX) << " " << (int)ceil(centerY) << " ";
            cout << (int)floor(centerX) << " " << (int)floor(centerY) << "\n";
        }
        else
        {
            arr[(int)floor(centerX)][(int)floor(centerY)] = true;
            arr[(int)floor(centerX)][(int)ceil(centerY)] = true;
            arr[(int)ceil(centerX)][(int)floor(centerY)] = true;
            cout << (int)floor(centerX) << " " << (int)ceil(centerY) << " ";
            cout << (int)ceil(centerX) << " " << (int)floor(centerY) << " ";
            cout << (int)floor(centerX) << " " << (int)floor(centerY) << "\n";
        }

        // bottom left
        recurse(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2, length / 2);
        // top right
        recurse((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2, length / 2);
        // top left
        recurse(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2, length / 2);
        // bottom right
        recurse((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2, length / 2);
    }

    return;
}