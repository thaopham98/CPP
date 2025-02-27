//
//  main.cpp
//  mergeSort
//
//  Created by Thao Pham on 15/06/2022.
//

#include <iostream>
#include <algorithm>

using namespace std;

/*MARK: Merging step*/
/*
    merging 2 subarrays to create a sorted array
    sub1[start...mid] + sub2[mid+1...end] = sorted[start...end]
*/
void dividing(int arr1[], int start, int end){
    int arrSize = sizeof(arr1)/sizeof(arr1[0]);
    cout << arrSize << endl;
//    for (int i = start; i < end; i++){
//        cout << arr1[i] << endl;
//    }
    
    //  left : sub1[start...mid]
    
    //  right: sub2[mid+1...end]
}

int main()
{
//    int arr[] = {7,1,8,2,6,3,0,4};
    
//    dividing(arr, 0, 8);
    
    int arr[] = {10,20,30,40,50,60};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int middle = arrSize/2;
    for (int i = 0; i < middle; i++){
        cout << arr[i]<< endl;
        
    }
    
    
    
    
    return 0;
}
