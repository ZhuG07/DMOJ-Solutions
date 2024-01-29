#include <bits/stdc++.h>
using namespace std;

int main()
{

    cin.sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {4, 3, 2, 13, 1, 2, 3, 4, 5};

    int left = 0;
    int right = 0;

    sort(arr, end(arr));

/*
        int k = 3;
        int currentLength = 0;
        int currentSum = 0 ;
        int max1 = -1111000;

        for(int i = 0 ; i < 9; i ++){
            if(currentLength<k){
                currentLength++;
                currentSum += arr[i];
                max1 = max(max1, currentSum);
            }else{
                currentSum += arr[i];
                currentSum -= arr[i-k];
                max1 = max(max1, currentSum);
            }
        }
        cout<<max1;
    */
}