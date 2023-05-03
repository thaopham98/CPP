//
//  main.cpp
//  week_6_samples
//
//  Created by Thao Pham on 2/16/22.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//void display_zipcodes(const vector<string>& zipcodes);
//char get_choice();
//void change_zipeCode(vector<string>& zipcodes, int current_zipCode, int new_zipCode);
//
//int main()
//{
//    vector<string> zipcodes { "36107", "36114", "36105", "36110", "36107", "360116", "36117", "36101" };
//
//    cout << "The Zip Code program\n";
//    display_zipcodes(zipcodes);
//    char choice = get_choice();
//    while (tolower(choice) == 'y')
//    {
//        int current_zipCode = 0;
//        cout << "Enter current ranking of a zipcode: ";
//        cin >> current_zipCode;
//        int new_zipCode = 0;
//        cout << "Enter new ranking of the zipcode: ";
//        cin >> new_zipCode;
//
//        change_zipeCode(zipcodes, current_zipCode, new_zipCode);
//        display_zipcodes(zipcodes);   // show updated rankings
//        choice = get_choice();      // ask if user wants to continue
//
//        cout << endl;
//    }
//}
//
//void display_zipcodes(const vector<string>& zipcodes)
//{
//    cout << "\nZipcodes\n--------------\n";
////    for (int i = 0; i < zipcodes.size(); ++i)
////    {
////        cout << (i + 1) << " - " << zipcodes[i] << endl;
////    }
//
//    /*Range-based for loop*/
//    int i = 1;
//    for(auto zc: zipcodes)
//    {
//
//        cout << i++ << " - " << zc << endl;
//    }
//    cout << endl;
//}
//
//char get_choice()
//{
//    char choice;
//    cout << "Do you want to change any rankings? (y/n): ";
//    cin >> choice;
//    cin.ignore(10000, '\n');
//    return choice;
//}
//
//void change_zipeCode(vector<string>& zipcodes, int current_zipCode, int new_zipCode)
//{
//      // make sure rankings are in bounds
//      if (current_zipCode > 0 && new_zipCode > 0 && current_zipCode <= zipcodes.size() && new_zipCode <= zipcodes.size())
//      {
//
//          // decrement rankings to create valid indexes
//          --current_zipCode;
//          --new_zipCode;
//          // store element
//          string movie = zipcodes[current_zipCode];
//
//          // remove element at old location
//          zipcodes.erase(zipcodes.begin() + current_zipCode);
//
//          // insert element at new location
//          zipcodes.insert(zipcodes.begin() + new_zipCode, movie);
//      }
//}

int main(){
    vector<double> prices { 9.99, 18.99, 19.99, 23.99, 40.99 };
    //This for loop print out ever element in vector by looping through it.
    for (auto iter = prices.begin(); iter != prices.end(); ++iter) {
        cout << "This is the output: " << *iter << '\n';
    }

    return 0;
}
