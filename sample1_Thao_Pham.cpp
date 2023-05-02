//
//  main.cpp
//  sample1
//
//  Created by Thao Pham on 4/27/22.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

struct employeeInfo{
    string name;
    char status;
    string number;
    double hours;
    double pay_rate;
    double salary;
    double hourly;
};
int main() {
    employeeInfo employee; //creating an object, you can understand this as you're creating an file for an employee of yours.
    employeeInfo Brittany_Saylor; //an employee called Brittany Saylor.
    vector<employeeInfo> employees;
    
    //adding information of your employee
    cout << "Name: ";
    cin >>employee.name;
    cout << "Status: ";
    cin >>employee.status;
    if (employee.status == tolower('p'))
        cout << "\nPart-time\n";
    else if (employee.status == tolower('f'))
        cout << "\nFull-time\n";
    else
        throw "\nInvalid input for status\n";
    cout << "Number: ";
    cin >>employee.number;
    
    cout << "\nInformation of Brittany Saylor: \n";
    cout << "Name: ";
    cin >>Brittany_Saylor.name;
    cout << "Status: ";
    cin >>Brittany_Saylor.status;
    cout << "Number: ";
    cin >>Brittany_Saylor.number;
    
    //Now your storing the employee information in vector employees
    employees.push_back(employee);
    employees.push_back(Brittany_Saylor);

//    for (auto i : employees){
//        cout << i.name <<endl;
//        cout << i.status<< endl;
//        cout << i.number << endl;
//    }
    
    /*This is your sorting option*/
    vector<string> names;
    for(auto j: employees){
        names.push_back(j.name);
    }
    sort(names.begin(), names.end()); // sorting
    cout << "\nStoring name\n";
    for (auto i : names) // looping though that vector
        cout << i<< endl; // printing all the elements in that vectors.
    
    return 0;
}
