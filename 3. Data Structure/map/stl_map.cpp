#include <iostream>
#include <map>
#include <sstream>
using namespace std;
// we need map to count 

void count_word_using_map(){
    map<string,int> mp;
    string s; 
    getline(cin,s);

    stringstream ss(s); 
    string word;
    while(ss >> word){
        
        mp[word]++ ;

    }

    cout <<"print specific word " << mp["love"]<<endl;

    // print map 
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << " " << endl;
    }


}

int main()
{
    count_word_using_map();

    // map<string, int> mp;
    // mp["Tanim"] = 2;
    // // print whole map

    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << it->first << " " << it->second << " " << endl;
    // }
    // // to check whetehr a value exist in map or not
    // if (mp.count("hanim"))
    //     cout << "yes"; // return true/false
    // else
    //     cout << "NO";
}