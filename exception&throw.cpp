//
//  main.cpp
//  exception&throw
//
//  Created by Thao Pham on 1/19/22.
//

#include <iostream>

using namespace std;

class Printer // a printer
{
    //private variable members
    string _name;
    int _availablePaper;
    
    //public members
public:
    
    Printer(string name, int paper) //a constructor
    {
        _name = name;
        _availablePaper = paper;
        
    }
    
    void Print(string txtDoc) //its function (that will receive a text document for it to print)
    {
        cout << "Printing ... " << txtDoc << endl; // here is what the class, Printer, able to do. Printing the txtDoc that is'll receive.
    }
};

int main()
{
    Printer myPrint;//constructing an object of the class Printer
    
    
    return 0;
}
