// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>


using namespace std;

//work with myspace 
namespace my_space{
    void func(){
        std::cout<<"hey mama ami namespace banaichi";
    }
}

namespace my_space2{
    void func(){
        std::cout<<"baprebap";
    }
}

using namespace my_space;
using namespace my_space2;


//EOF and Setprecision 

void Eof_in_cpp(){

    int n;
    
    while (cin>>n)
    {
        cout<<n<<endl;
    }
}

void set_precision_in_cpp(){
    // we need iomanip for setprecision

    double n;
    cin>>n;
    cout<<fixed << setprecision(3) << n;
}

// switch case in c 
void switch_case_in_cpp(){
    int choice; 
    cin>>choice;

    /*The way switch case works is when case is true 
    its automatically turns rest of the cases true*/

    switch(choice){
        case 1:
            cout<<"Hello"<<endl;
            break;
            
        case 2:
            cout<<"Gello"<<endl;
            break;

        case 3:
            cout<<"Mllo"<<endl;
            break;

        default:
            cout<<"Is above's cases are false, then i run";

    }


}

void string_input_output(){
    char s[100];
    //string wihout space
    // cin>>s;
    // cout<<s;

    //string with space 


}


// using namespace std;
int main()
{
    // Eof_in_cpp();
    // set_precision_in_cpp();
    // switch_case_in_cpp();
    string_input_output();
    
}