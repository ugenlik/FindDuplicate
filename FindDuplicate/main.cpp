//
//  main.cpp
//  FindDuplicate
//
//  Created by umut can genlik on 7/15/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

/*
 
 To find duplicates in a large array, assuming wors cases, first we need to sort the array. Sorting algorithm should be reliable and in all cases it should give efficent result.
 
 I have used Merge Sort, because of in all cases Merge Sort compeltes its duty in O(nlgn).
 
 After sorting integers we need to store the duplicates in an array and print it.Finding duplicates is just a simple for loop that test if index=index+1, so finding duplicate loop has to visit all the indexes it works in O(n)
 
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int size = 1000001;
int array[size];// create an array


void print(int *input)
{
    //print out the array 
    for(int i=0; i<size; i++)
        cout <<"Array  item " <<i<<" is =" << array[i] << endl;
    
    
    for (int i=0; i<size; i++) {
        if(array[i]==array[i+1])
        {
            cout<<"Duplicated Integer is = "<< array[i]<< endl;
        }
    }
    
    
}

void merge(int* input, int p, int r)
{
    int mid = floor((p + r) / 2);
    int i1 = 0;
    int i2 = p;
    int i3 = mid + 1;
    
    // Temp array
    int temp[r-p+1];
    
    // Merge in sorted form the 2 arrays
    while ( i2 <= mid && i3 <= r )
        if ( input[i2] < input[i3] )
            temp[i1++] = input[i2++];
        else
            temp[i1++] = input[i3++];
    
    // Merge the remaining elements in left array
    while ( i2 <= mid )
        temp[i1++] = input[i2++];
    
    // Merge the remaining elements in right array
    while ( i3 <= r )
        temp[i1++] = input[i3++];
    
    // Move from temp array to master array
    for ( int i = p; i <= r; i++ )
        input[i] = temp[i-p];
}

void merge_sort(int* input, int p, int r)
{
    if ( p < r )
    {
        int mid = floor((p + r) / 2);
        merge_sort(input, p, mid);
        merge_sort(input, mid + 1, r);
        merge(input, p, r);
    }
}


void shuffle(int* input){
    
    srand((unsigned)time(NULL));
    
    
    // fill the array numbers with range in sequence
    for (int i=0; i<size-1; i++) {
        array[i]=i;
    }

    array[size-1]=rand() % size-1; // add the duplicate to the array
    
    random_shuffle(array, array+size);// shuffle the array
    
}


int main( void )
{
    
    shuffle(array);//fill the array and shuflle it
    merge_sort(array, 0, size-1);//sort the array
    print(array);//print the duplicate
    
    
    
    return 0;
}


