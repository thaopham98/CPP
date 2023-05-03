//
//  classProject_Thao_Pham.cpp
//  classProject_Thao_Pham
//
//  Created by Thao Pham on 01/04/2022.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/* DISPLAYING FUNCTIONS */
void displayMenu(map<string, float> menu) {
    cout << "\n --- Menu Item --- \n";
    int index = 0;
    for (auto i = menu.begin(); i != menu.end(); i++)
    {
        index += 1;
        cout << index << ". " << i->first << " - $" << i->second << endl;
    }
}
void displayOptions() {
    cout << "\na - Adding an item to cart." // count()
        << "\nd - Deleting an item from cart." // remove() & copy()
        << "\ns - Sorting the cart in ascending price." //sort()
        << "\nl - Lowest price item." // min_element()
        << "\nh - Highest price item." // max_element()
        << "\nt - Display the total value." //accumulate()
        << "\nq - Quantity editing." // find()
        << "\ne - exiting."
        << "\nPlease select an option: ";
}
void displayCart(map<string, float> cart) { //Looping throught cart and display the current cart.
    cout << "\n --- Your cart --- \n";
    int j = 0;
    for (map<string, float>::iterator it = cart.begin(); it != cart.end(); it++) {
        j += 1;
        cout << j << ". " << it->first << " - $" << it->second << endl;
    }
}

/* OPTION FUNCTIONS */

/*Comparing the price for minmax()*/
bool comparePrice(pair<string, float> a, pair<string, float> b){
    return a.second < b.second;
}

/*Sorting in ascending price*/
map<string, float> sorting(map<string, float>& cart) {
    int index = 0;

    vector<pair<string, float>> items{cart.begin(), cart.end() };

    sort(items.begin(), items.end(), comparePrice); //Sorting element in vector

    cout << "\n --- Your Cart in Ascending Price --- \n";
    for (auto& item : items) {
        index += 1;
        cout << index << ". " << item.first << " - $" << item.second << endl;
    }

    return cart;
}

/*Min and Max price*/
void minmax(map<string, float> cart, char option){
    if (option == 'l') {
        pair<string, float> min = *min_element(cart.begin(), cart.end(), comparePrice);
        cout << "\nLowest price: " << min.first << " - $" << min.second << endl;
    }
    else {
        pair<string, float> max = *max_element(cart.begin(), cart.end(), comparePrice);
        cout << "\nHighest price: " << max.first << " - $" << max.second << endl;
    }
}

/*Adding an item from menu to cart*/
map<string, float> addItem(map<string, float> menu, map<string, float>& cart) // getting the menu, editing the cart
{
    /*Getting input item index in menu*/
    int index;
    cout << "\nEnter the item's index in menu: ";
    cin >> index;

    /*Selecting the pair using the input index from menu*/
    auto selected = menu.begin();
    advance(selected, --index);

    /*Checking if the item's already exist in the cart or not*/
    if (cart.count(selected->first) == 0) {
        cout << "\nAdding an item from menu to cart...\n";
        cart.insert(pair<string, float>(selected->first, selected->second)); // adding that pair to cart
    }
    else
        throw "\nThe item has already been added to the cart.";

    return cart; // return the current cart.
}

/*Deleting an item from cart.*/
map<string, float> deleteItem(map<string, float> menu, map<string, float>& cart){ //getting the menu, editing the cart
    string name;
    int index;
    vector<pair<string, float>> items{ cart.begin(), cart.end() }; //adding everything from cart into items.

    /*Getting input item index in cart*/
    cout << "\nEnter an item's index in cart: ";
    cin >> index;
    index--;


    cart.erase(cart.begin(), cart.end()); // delete everything in cart map.
    items.erase(remove(items.begin(), items.end(), items[index]), items.end()); // delete the selected item from vector.
    cout << "\nDeleting an item from cart...\n";
    copy(items.begin(), items.end(), inserter(cart, cart.begin())); //copying everything from vector into the empty cart map.
    return cart; // return the current cart.
}

/*Editing quantity of items.*/
map<string, float> quantity(map<string, float> menu, map<string, float>& cart) {
    cout << "\nEnter an item's index in cart: ";
    int index;
    cin >> index; // Example: index = 2.

    auto selected1 = cart.begin();
    advance(selected1, --index); //index: is decremented by 1; index = 1.

    auto search1 = cart.find(selected1->first); // finding the item's key in cart
    auto search2 = menu.find(selected1->first); // finding the item's key in menu

    cout << "\nEnter the item's quantity: ";
    int quantity;
    cin >> quantity;

    cout << "\nEditing the item's quantity...\n";
    search1->second = search2->second * quantity;

    return cart;
}

/*Calculating the total price*/
float totalPrice(float total, pair<string, float> cart){
    return total + cart.second;
}
int main() {
    cout << "\n --- Pastry Store --- \n";
    /*MARK: containers*/
    map<string, float>menu{{"Cheesecake",3.99},{"Cupcake",2.99},{"Apple pie",4.99},{"Croissant",3.97},{"Strawberry Short Cake",5.50},{"Muffin",2.25}};
    map<string, float>cart;

    char option;
    displayMenu(menu);
    displayOptions();
    cin >> option;

    try {
        while (option != tolower('e'))
        {
            if (option == tolower('s'))
            {
                if (!cart.empty())
                    sorting(cart);
                else
                    throw "\n\n **** Empty Cart ****\n\n";
            }
            else if (option == tolower('a'))
                addItem(menu, cart);
            else if (option == tolower('d')) {
                if (!cart.empty()) {
                    displayCart(cart);
                    deleteItem(menu, cart);
                }
                else
                    throw "\n\n **** Empty Cart ****\n\n";
            }
            else if (option == tolower('l')) {
                if (!cart.empty())
                    minmax(cart, option);
                else
                    throw "\n\n **** Empty Cart ****\n\n";
            }
            else if (option == tolower('h')) {
                if (!cart.empty())
                    minmax(cart, option);
                else
                    throw "\n\n **** Empty Cart ****\n\n";
            }
            else if (option == tolower('t')) {
                if (!cart.empty()) {
                    displayCart(cart);
                    float sum = accumulate(cart.begin(), cart.end(), 0.0, totalPrice);
                    cout << "\nYour total price is: $" << sum << "\nThank you for shopping with us." << endl;
                    cart.erase(cart.begin(), cart.end());//break;
                }
                else
                    throw "\n\n **** Empty Cart ****\n\n";
            }
            else if (option == tolower('q')) {
                if (!cart.empty())
                    quantity(menu, cart);
                else
                    throw "\n\n**** Empty Cart ****\n\n";
            }
            else
                throw "\n **** Invalid Option ****\n";
            displayCart(cart);
            if (option == 't')
            {
                cout << "\nYour cart is empty\n";
            }
            displayMenu(menu);
            displayOptions();
            cin >> option;
        }
    }
    catch (string invalid_input) {
        cout << invalid_input;
    }
    cout << "Bye!\n";
    return 0;
}
