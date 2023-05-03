//
//  main.cpp
//  week_6_In_class_Thao_Pham
//
//  Created by Thao Pham on 2/16/22.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void display_zipcodes(const vector<string>& zipcodes)
{
    cout << "\n----- Zipcodes -----\n";
    /*Range-based for loop to go through all the elements in the loop*/
    int i = 1;
    for(auto zc: zipcodes)
        cout << i++ << " - " << zc << endl;
    cout << endl;
}

void change_zipcode(vector<string>& zipcodes, int current_zipcode, int new_zipcode)
{
    if(current_zipcode > 0 && new_zipcode > 0 && current_zipcode <= zipcodes.size() && new_zipcode<= zipcodes.size())
    {
        /*When displayed ranking start @ 1*/
        --current_zipcode;
        --new_zipcode;
        string zipcode = zipcodes[current_zipcode];
        
        zipcodes.erase(zipcodes.begin() + current_zipcode); //the position to erase
        zipcodes.insert(zipcodes.begin() + new_zipcode, zipcode); //the position to insert, the new string value
    }
}

int main()
{
    /*Vector*/
    vector<string> zipcodes{ "36107", "36114", "36105", "36110", "36107", "360116", "36117", "36101"};
    
    display_zipcodes(zipcodes);
    
    int current_zipcode = 0, new_zipcpde = 0;
    cout << "Please enter current ranking of a zipcode: ";
    cin >> current_zipcode;
    cout << "Please enter new ranking of the zipcode: ";
    cin >> new_zipcpde;
    change_zipcode(zipcodes, current_zipcode, new_zipcpde);
    display_zipcodes(zipcodes);
    cout << "\nThank you for using the program\n";
    return 0;
}
