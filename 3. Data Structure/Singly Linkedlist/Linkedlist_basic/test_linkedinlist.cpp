// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

void fun(){

    class my_class{
        public:
        string name;

        my_class(string n){
            this->name = n;

        }

        void display(){
            cout<<name;

        }


    };


    my_class my_obj = my_class("Akash");




}
int main()
{

    fun();


    
}