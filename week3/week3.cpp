//
//  main.cpp
//  week3
//
//  Created by Thao Pham on 1/25/22.
//
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*MARK: serviceType Function*/
void serviceType(char serviceCode, string accountNumber)
{
    
    /*MARK: Regular Service Calculation*/
    if(serviceCode == 'r' || serviceCode == 'R')
    {
        //Regular service: $10.00 plus first 50 minutes are free. Charges for over 50 minutes are $0.20 per minute

        cout << "Enter Minutes: ";
        int minute;
        cin >> minute;
                
        const float regular_charge = 10.00;
        const float regular_over_charge = 0.2;
        float amount_due;

        if (minute < 50.0)
        {
            amount_due = regular_charge;
        }
        else
        {
            amount_due = regular_charge + regular_over_charge * (minute - 50);
        }
        cout << "\n----- Printing Bill -----"
             << "\nAccount Number: " << accountNumber
             << "\nService Type: Regular"
             << "\nAmount Due: $" << fixed << setprecision(2) << amount_due
             << "\nBye!\n";
        
    }
    
    /*MARK: Premium Service Calculation*/
    //else if(serviceCode == 'p' || serviceCode == 'P')
    else if (tolower(serviceCode)=='p')
    {
        //Premium service: $25.00 plus:
        //For calls made from 6:00 a.m. to 6:00 p.m., the first 75 minutes are free; charges for more than 75 minutes are $0.10 per minute.
        //For calls made from 6:00 p.m. to 6:00 a.m., the first 100 minutes are free; charges for more than 100 minutes are $0.05 per minute.
        cout << "Enter Daytime minute: ";
        int dayMinute;
        cin >> dayMinute;

        cout << "\nEnter Nighttime minute: ";
        int nightMinute;
        cin >> nightMinute;
        
        const float premium_charge = 25.0;
        const float premium_day_charge = 0.1;
        const float premium_night_charge = 0.05;
        float day_amount_due, night_amount_due;

        if(dayMinute < 75)
            day_amount_due = premium_charge;
        else
            day_amount_due = premium_charge + premium_day_charge * (dayMinute - 75);

        if(nightMinute < 100)
            night_amount_due = premium_charge;
        else
            night_amount_due = premium_charge + premium_night_charge * (nightMinute - 100);

        float amount_due = day_amount_due + night_amount_due - premium_charge;

        cout << "\n----- Printing Bill -----"
             << "\nAccount Number: " << accountNumber
             << "\nService Type: Premium"
             << "\nAmount Due: $" << fixed << setprecision(2) << amount_due
             << "\nBye!\n";
    }
    
    /*MARK: Exception Throw*/
    else
    {
        throw invalid_argument("Invalid Service Code. Please try entrying a character as the service code again.\n\nBye!\n");
    }
}

int main()
{
    cout << "Cell Phone Calculator\n\nEnter your account number: ";
    string accountNumber;
    cin >> accountNumber;
    
    cout << "\nEnter your service code: ";
    char serviceCode;
    cin >> serviceCode;
    cout << endl;
    
    /*MARK: Try and Catch block*/
    try
    {
        serviceType(serviceCode, accountNumber); //Calling the serviceType function
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << "\n\n";
    }
    
    return 0;
}
