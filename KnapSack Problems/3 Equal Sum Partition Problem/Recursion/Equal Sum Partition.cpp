#include<iostream>
using namespace std;

//Partition problem is to determine whether a given set can be partitioned
//into two subsets such that the sum of elements in both subsets is the same.

bool solve(int *arr, int sum, int n)
{
    if(sum==0)
    {
        return true;
    }

    if(n==0)
    {
        return false;
    }
    int ans;
    if(arr[n-1]<=sum)
    {
        int a = solve(arr, sum-arr[n-1], n-1);
        int b = solve(arr, sum, n-1);
        ans = a||b;
    }
    else
    {
        ans = solve(arr, sum, n-1);
    }

    return ans;
}

int main()
{
    int arr[] = {1, 5, 11, 5};
    int n = 4;
    int sum = 0;
    for(int i =0; i<n; i++)
    {
        sum = sum + arr[i];
    }
    if(sum%2==1)
    {
        cout<<false;
    }
    else
    {
        cout<<solve(arr, sum/2,n);
    }
}
