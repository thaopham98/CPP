//
//  Test&Debug.cpp
//  Test&Debug
//
//  Created by Thao Pham on 1/16/22.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    string firstName = "Thao";
    string lastName = "Pham" ;
    /*When the breakpoint is here, we can see the memory of the program that are execute before this line. It also means that this line is still NOT being execute. So if there's a code here, it's still not show in the memory.*/
    int currentYear, birthYear;
    
    cout << "Please input your birth year : ";
    cin >> birthYear;
    cout <<"Please input the current year : ";
    cin >> currentYear;
    
    int age = currentYear - birthYear ;
    
    cout << "You're " << age << " years old this year.\n";
    
    return 0;
}
