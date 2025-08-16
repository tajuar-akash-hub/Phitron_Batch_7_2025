// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void codeforces_range_sum_query_bruteforce()
{

    int n, q;
    cin >> n >> q;

    vector<long long int> v;

    // portion 1

    for (int i = 0; i < n; i++)
    {
        long long int value;
        cin >> value;       // compelxity O(n)
        v.push_back(value); // is there better way of doing thsi?
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    // sum l to r

    // portion 2
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        // cout << l << " " << r << endl;
        int sum = 0;

        for (int j = l - 1; j <= r - 1; j++)
        {

            sum += v[j]; // complexity O(q*n)
        }

        cout << sum << endl;
    }

    /*
    Complexity Analysis

    first portion = O(n)
    second portion = O(q*n) = 10^9 * 10^5 = 10^14
    but second for are allowed to have 10^7 operation

    */
}

void codeforces_binary_search(){

    int size,q;

    cin>>size>>q;

    vector<int> v(size);

    // size input

    for(int i=0;i<size;i++){

        cin>>v[i];
    }

    //sort the array
    sort(v.begin(),v.end());


    // for(int i=0;i<size;i++){

    //     cout << v[i]<<" ";
    // }

  

    while(q--){

        int value;
        cin>>value;


        int l=0 , r = size-1;
        int mid;

        while(l<=r)
        {

            mid = (l+r)/2;

            if(v[mid] == value) {
                cout<<"found"<<endl;
                break;
            }

            if (v[mid] < value  ){
                l = mid + 1;

            }

            if (v[mid] > value  ){
                r = mid - 1;
            }


            



            
            



        }

        if(l>r) cout<<"Not found"<<endl;

        





    }


}

void Prefix_sum()
{
    int n, q;
    cin >> n >> q;

    vector<long long int> v(n);

    vector<long long int> prefix_sum(n);

    // portion 1

    for (int i = 0; i < n; i++)
    {
        // int value;
        // cin >> value;       // compelxity O(n)
        // v.push_back(value);
        cin >> v[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<v[i]<<" ";

    // }

    // prefix sum

    /*
    first = prefix_sum[0] = vector[0];
    second = prefix_sum[i] = prefix_sum[i-1] + vector[i];

    */

    prefix_sum[1] = v[0];

    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    // for (int i = 1; i < n; i++)
    // {
    //     cout<<prefix_sum[i]<<" ";
    // }

    // result based on l, r

    // cout<<endl;

    // for 1 to 3

    // cout << prefix_sum[r] - v[l-1] << endl;

    while (q--)
    {
        long long int l, r;
        cin >> l >> r;
         
        // cout<<l<<" " <<r<<" "<<endl;

        if (l == 1)
            cout << prefix_sum[r - 1] << endl;

        else
            {
                
                cout << prefix_sum[r - 1] - prefix_sum[l - 2] << endl;

            }
            
    }
    // 2 to 5
    // cout<<prefix_sum[r] <<endl;
}
int main()
{
    // codeforces_range_sum_query_bruteforce();
    // Prefix_sum();

    codeforces_binary_search();
}