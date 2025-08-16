// #include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

void logarithmic_complexity_example1()
{
    // logarithmic complexity

    // example : 1
    int n;
    cin >> n;

    for (int i = 1; i < n; i *= 2)
    {
        cout << i << endl;
    }
}

void linearithmic_complexity(){

    int n; 
    cin>>n ;
    for(int i=1;i<=n;i++){

        //logarithmic compelxity 

        for(int j=1;j<=sqrt(n);j++){

            cout<<"hi"<<endl;

        }

    }

}
void logarithmic_complexity_example2()
{
    // logarithmic complexity

    // example : 1
    int n, k;
    cin >> n;
    k = 2;

    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
        i = i * k;
    }
}

void square_root_complexity()
{
    // divisor of 36
    int n = 36;

    // variation : 1

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (36 % i == 0) cout << i<< n / 2 << endl;
        else continue;
    }

    // variation 2 : 

    for (int i = 1; i*i <= n; i++)
    {
        if (36 % i == 0) cout << i<<endl;
        else continue;
    }
    

}
int main()
{
    // logarithmic_complexity2();
    // logarithmic_complexity_example2();
    // square_root_complexity();
    linearithmic_complexity();
}