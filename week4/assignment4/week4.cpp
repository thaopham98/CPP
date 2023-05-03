//
//  week4.cpp
//  week_4_Thao_Pham
//
//  Created by Thao Pham on 2/4/22.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*MARK: struct MenuItem */
struct MenuItem{
    string name;
    int price;
    string day;
};

/*MARK: vector<MenuItem function */
vector<MenuItem> read_items_from_file()
{
    vector<MenuItem> objects;
    ifstream input_file("/Applications/Studying/SP22/CSCI_4100/Week 4/week_4_Thao_Pham/week_4_Thao_Pham/menu.txt");
    
    if (input_file) {    // if file opened successfully...
        MenuItem item;
        string line;
        
        while (getline(input_file, line)) {
            stringstream ss(line);
            getline(ss, item.name, '\t');   // get title
            ss >> item.price >> item.day;  // get year and stars
            objects.push_back(item);          // add movie to vector
        }
        input_file.close();
    }
    else
        cout << "Cannot open menu.txt file.\n"
        << "Since I used XCode to make this project,\n"
        << "please check the input_file and add the menu.txt to the header source\n"
        << "if you're using Visual Studio.\n\n";
    return objects;
}

int main()
{
    cout<< "Menu of the Day\n\nCOMMAND MENU\nSpecify the day using the three-letter format (mon, tue, wed, thu, fri, sat, sun). Or, enter 'exit' to exit.\n\n";
    
    //Creating vector
    vector<MenuItem> objects = read_items_from_file();
    
    //User input
    cout << "Day: ";
    string day_command;
    cin >> day_command;

    while (day_command != "exit")
    {
        for (int i =0; i<objects.size(); i++)
        {
    //        cout << objects[i].name << '\t' << objects[i].price << '\t' << objects[i].day << endl;
            
            if(objects[i].day == day_command)
                cout << objects[i].name << '\t' << objects[i].price << endl;
        }
        
        cout << "\nDay: ";
        cin >> day_command;
    }
    cout << "\nBye!\n\n";
    return 0;
}
