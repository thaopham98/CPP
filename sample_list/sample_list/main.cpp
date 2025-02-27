//
//  main.cpp
//  sample_list
//
//  Created by Thao Pham on 2/25/22.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    
    /*MARK: ARRAY */
//    int a[6] = {10,2,7,1,8};
//    int n = 6;
//    int sum = 0;
//    for (int i =0; i < n-1; ++i)
//    {
//        sum += a[i];
//        cout << a[i] << endl << endl;
//    }
//    cout << "Sum: "<< sum << endl << endl;
    
    /*MARK: LIST */
    list<int> myList = {8,9,10,5,1,3,7};
    myList.push_back(15);
    
    cout << "Numbers of myList: ";
    
    for(auto iter=myList.end(); iter != myList.begin(); iter--)
    {
        cout <<  *iter << " ";
    }
    cout << endl;

    cout <<"The numbers in 1 line: ";
    for(auto number:myList){
        cout << number << " ";
    }
    cout << endl;

    //costly
    vector<int> myVec = {8,9,10,5,1,3,7};
    myVec.push_back(15);

    cout << "The index in vector myVec: " << myVec[3] << endl;
    
    return 0;
}
