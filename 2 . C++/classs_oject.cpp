// #include <bits/stdc++.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>

using namespace std;

class Student
{
public: // access modifier ,two more types. protected, private
    char name[30];
    int roll;
    double gpa;

    // constructor

    /*Constructor is a special type of function which get called
    automatically with the object,
    constructor doesn't have any return type
    */

    Student(char n[30], int r, double g)
    {
        strcpy(name, n);
        roll = r;
        gpa = g;
    }

    // using 'this' keyword
    // 'this' keyword is pointer, which points to the object, made of of the class

    // Student(char name[30],int roll, double gpa){

    // strcpy((*this).name,name);

    // (*this).roll = roll;
    // (*this).gpa = gpa ;

    // }

    // using this->

    // Student(char name[30],int roll, double gpa){

    // strcpy(this->name,name);

    // this->roll = roll;
    // this->gpa = gpa ;

    // }

    // function to display item

    void display()
    {
        cout << name << " " << roll << " " << gpa << endl;
    }
};

class Student2
{

public:
    int id;
    string name;
    char section;
    int total_marks;


    // default constrictior 

    Student2(){

    }

    //parameterized constructor 

    Student2(int i, string nme, char sec, int ttl_mrks)
    {

        this->id = i;
        this->name = nme;
        this->section = sec;
        this->total_marks = ttl_mrks;
    }

    void display()
    {
        cout << id << " " << name << " " << section << " " << total_marks << endl;
    }
};

void create_dynamic_object(){

    Student2 rakib;  // static object

    rakib.name = "nothing";

    cout<<rakib.name;

    Student2* sakib = new Student2;  // dynamic object 

    sakib->name = "batash";

    cout<<sakib->name;

    //array of object 
    Student2* array_of_object[3];
}

// void create_object(){

//     Student rakib();

//     char temp[30] = "Rakib";
//     strcpy(rakib.name,temp);
//     rakib.roll = 10;
//     rakib.gpa = 4.5;

//     cout<<rakib.name<<endl;
//     cout<<rakib.roll<<endl;
//     cout<<rakib.gpa<<endl;
// }

// return Static Object from a function

Student Sakib()
{

    char temp[30] = "sakib";

    Student sakib(strcpy(sakib.name, temp), 10, 10.00);

    return sakib;
}


void Array_of_object(){

    Student2 students_obj[3];

}

int main()
{
    // create_object();
    // char temp[30]= "sakib";

    // Student rakib(strcpy(rakib.name,temp),10,4.5);

    // rakib.display();

    // create_dynamic_object();
    Array_of_object();

}