//
//  main.cpp
//  week_5
//
//  Created by Thao Pham on 2/9/22.
//
#include <iostream>

using namespace std;

enum Scoops {Single = 1, Double = 2, Tripple = 3};

int main() {
    string customer_name;
    string ice_cream_flavor;
    int n_scoops = 0;
    
    cout << "Enter your name: ";
    cin >> customer_name;
    
    cout << "Enter ice cream flavor: ";
    cin >> ice_cream_flavor;
    
    cout << "1 - Single.\n2 - Double.\n3 - Triple.\n";
    
    cout << "Enter number of scoops (1-3): ";
    cin >> n_scoops;
    
    Scoops scoop = static_cast<Scoops>(n_scoops);

    switch (scoop)
    {
        case Scoops::Single:
            cout << "Thank you " << customer_name << " for visiting us.\nYou order: " << ice_cream_flavor << "\nTotal price: $3.75\n";
            break;
        case Scoops::Double:
            cout << "Thank you " << customer_name << " for visiting us.\nYou order: " << ice_cream_flavor << "\nTotal price: $5.50\n";
            break;
        case Scoops::Tripple:
            cout << "Thank you " << customer_name << " for visiting us.\nYou order: " << ice_cream_flavor << "\nTotal price: $7.20\n";
            break;
        default:
            cout << "\nInvalid input. Please re-enter.";
            break;
    }
    return 0;
}
