//*************************************** 
//
//      Pointers Manipulation Program
//
//      This program demonstrates various uses of arrays and pointers, including printing the values of an array using 
//      pointers, and addresses of array elements, getting user input to access specific array elements, and 
//      performing pointer arithmetic to aadd values of two pointers
//
//
//
//***************************************
#include <iostream>
using namespace std;

int f1(int nums[], int size);
int f2(int *ptr, int size);
int f3(int nums[], int size);
int f4(int nums[], int size);


int main()
{
    int size = 5;
    int nums[size] = {10, 20, 30, 40, 50};
    int *ptr = nums;

    f1(nums, size);
    f2(ptr, size);
    f3(nums, size);
    f4(nums, size);
    
    return 0;

}

// value and address of array
int f1(int nums[], int size)
{
    
    cout << "------------------------------------" << endl;
    cout << "Values and Addresses of Array: Using Arrays\n" << endl;
    cout << "------------------------------------" << endl;

    for(int i = 0; i < size; i++)
    {
        cout << "Value of nums[" << i << "] = " << nums[i] << endl;
        cout << "Address of nums[" << i << "] = " << &nums[i] << endl;
    }


}

// value and address of pointer
int f2(int *ptr, int size)
{
    cout << "------------------------------------" << endl;
    cout << "Values and Addresses of Array: Using Pointers\n" << endl;
    cout << "------------------------------------" << endl;

    for(int i = 0; i < size; i++)
    {
        cout << "Value of nums[" << i << "] = " << *(ptr + i) << endl;
        cout << "Address of nums[" << i << "] = " << (ptr + i) << endl;
    }
    

}

// user input to access specific array elements
int f3(int nums[], int size)
{
    const int SIZE = 3;
    int *p = nums;
    int input;
    cout << "input 3 integers and make sure they are within the index range [0, " << size << "): " << endl;
    for(int i = 0; i < SIZE; i++)
    {
        while(true)
        {
            cin >> input;
            if(input >= 0 && input < size)
            {
                p = &nums[input];
                break;
            } else {
                cerr << "\nERROR ERROR ERROR: Invalid Entry";
            }
        }
        cout << "Value of nums[" << input << "] = " << *p << endl;
        cout << "Address of nums[" << input << "] = " << p << endl;
    }

}

// Adding values of two pointers
int f4(int nums[], int size)
{
    int *p1 = nums, *p2 = nums;

    int input1, input2;
    cout << "input 2 integers and make sure they are within the index range [0, " << size << "): " << endl;
    while(true)
    {

        cout << "Input 1: ";
        cin >> input1;
        if(input1 >= 0 && input1 < size)
        {
            p1 = &nums[input1];
            break;
        } else{
            
            cerr << "\nERROR ERROR ERROR: Invalid Entry";
        }

    }

    cout << "Value of nums[" << input1 << "] = " << *p1 << endl;
    cout << "Address of nums[" << input1 << "] = " << p1 << endl;
    while(true)
    {
        cout << "Input 2: ";
        cin >> input2;
        if(input2 >= 0 && input2 < size)
        {
            p2 = &nums[input2];
            break;
        } else{
            cerr << "\nERROR ERROR ERROR: Invalid Entry";
        }
    }
    cout << "Value of nums[" << input2 << "] = " << *p2 << endl;
    cout << "Address of nums[" << input2 << "] = " << p2 << endl;

    
    cout << "Sum of nums[" << input1 << "] + nums[" << input2 << "] = " << *p1 + *p2 << endl;

}