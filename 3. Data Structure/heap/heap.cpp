#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void max_heap_insert(vector<int> &v,int value){


//    int value; cin >> value;
//    cout << value;
   v.push_back(value);

   // main logic 

   int current_indx = v.size()-1;

   while(current_indx!=0){

    int parent_indx = (current_indx -1) / 2 ;

    if( v[parent_indx] < v[current_indx] ) swap( v[parent_indx] , v[current_indx]);
    else break;
    
    current_indx = parent_indx;
    
   }

}

void min_heap_insert(vector<int> &v, int value)
{
    //    cout << value;
    v.push_back(value);

    // main 
    int current_indx = v.size() - 1;
    while (current_indx != 0)
    {
        int parent_indx = (current_indx - 1) / 2;

        if (v[parent_indx] > v[current_indx])
            swap(v[parent_indx], v[current_indx]);
        else
            break;

        current_indx = parent_indx;
    }
}

void print_(vector<int> v)
{
    for (int val : v)
    {
        cout << val << " ";
    }
}

void delete_from_max_heap(vector<int> &v)
{
    // Corner case
    if(v.empty()) return;

    // Step1  : last value in root node
    v[0] = v.back();
    v.pop_back();
    // step 2 : change the root in its appropriate postion
    int current_indx = 0;

    while (true)
    {

        int left_child_idx = current_indx * 2 + 1;
        int right_child_idx = current_indx * 2 + 2;

        int left_value = INT_MIN;
        int right_value = INT_MIN;
        /*
        check whether left or right value exist or not, way to do it is ,
        take very small value in left_value, right_value ,
        */

        if (left_child_idx < v.size())
            left_value = v[left_child_idx]; // that means value exixt

        if (right_child_idx < v.size())
            right_value = v[right_child_idx]; // to check value exist or not

        if (left_value >= right_value && left_value > v[current_indx])
        {
            swap(v[current_indx], v[left_child_idx]);
            current_indx = left_child_idx;
        }
        else if (right_value > left_value && right_value > v[current_indx])
        {
            swap(v[current_indx], v[right_child_idx]);
            current_indx = right_child_idx;
        }
        else break;
    }
}

void delete_from_min_heap(vector<int> &v)
{
    // Corner case
    if(v.empty()) return;

    // Step1  : last value in root node
    v[0] = v.back();
    v.pop_back();
    // step 2 : change the root in its appropriate postion
    int current_indx = 0;
    while (true)
    {
        int left_child_idx = current_indx * 2 + 1;
        int right_child_idx = current_indx * 2 + 2;

        int left_value = INT_MAX;   // these values are to compare , if no values exist
        int right_value = INT_MAX;
        /*
        check whether left or right value exist or not, way to do it is ,
        take very small value in left_value, right_value ,
        */

        if (left_child_idx < v.size())
            left_value = v[left_child_idx]; // that means value exixt

        if (right_child_idx < v.size())
            right_value = v[right_child_idx]; // to check value exist or not

        if (left_value <= right_value && left_value < v[current_indx])
        {
            swap(v[current_indx], v[left_child_idx]);
            current_indx = left_child_idx;
        }
        else if (right_value < left_value && right_value < v[current_indx])
        {
            swap(v[current_indx], v[right_child_idx]);
            current_indx = right_child_idx;
        }
        else break;
    }
}



int main()
{
    int size;
    cin >> size;
    vector<int> v;

    for (int i = 0; i < size; i++)
    {
        int val; cin >> val;
        
        min_heap_insert(v,val);
    }

    //  for (int i = 0; i < size; i++)
    // {
    //     cout << v[i]<<" ";
    // }
    // max_heap_insert(v);
   
   
    // print_(v);

    delete_from_min_heap(v);

    print_(v);


    

}