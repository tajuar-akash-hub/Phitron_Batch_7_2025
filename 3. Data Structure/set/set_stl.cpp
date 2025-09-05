#include <iostream>
#include <set>
using namespace std;
int main()
{
    // main purpose of set is, is doens't hold duplicate value
    // stl set maintain BST beind the scene
    set<int> s;
    int size;
    cin >> size;
    while (size--)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    for(auto it = s.begin(); it!=s.end(); it++){
        cout << *it<<" ";
    }

}