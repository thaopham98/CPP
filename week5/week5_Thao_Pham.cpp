//
//  main.cpp
//  week_5_Thao_Pham
//
//  Created by Thao Pham on 2/8/22.
//
#include <iostream>

using namespace std;

enum class Classification{ Undergraduate, Graduate};
enum class Status{ Parttime, Full};
enum class Residency{ Resident, International};

void print_from_input(Classification degree, Status status, Residency residency)
{
    if (degree == Classification::Undergraduate)
        cout <<  "\nClassification: Undergraduate";
    else if (degree == Classification::Graduate)
        cout <<"\nClassification: Graduate";
    
    if (status == Status::Full)
        cout << "\nStatus: Full";
    else if(status == Status::Parttime)
        cout << "\nStatus: Parttime";
    
    if (residency == Residency::Resident)
        cout << "\nResidency: Resident";
    else if (residency == Residency::International)
        cout << "\nResidency: International";
}

int main()
{
    string student_name;

    int degree_input, status_input, residency_input, credit_hour, cost_per_hour, tuition = 0;

    cout << "--- Please these information --- \nEnter your name: ";
    cin >> student_name;
    
    cout << "\nFor parttime undergraduate, credit hour must LESS than 12 hours.\nFor parttime graduate, credit hour must LESS than 6 hours.\n";
    
    cout << "\nChoose your degree:\n0 - undergraduate.\n1 - graduate\nEnter your degree: ";
    cin >> degree_input;
    
    cout << "\nChoose your status:\n0 - part-time.\n1 - fulltime\nEnter your status: ";
    cin >> status_input;
    
    cout << "\nChoose your residency:\n0 - resident.\n1 - international\nEnter your residency: ";
    cin >> residency_input;
    
    Classification degree = static_cast<Classification>(degree_input);
    Status status = static_cast<Status>(status_input);
    Residency residency = static_cast<Residency>(residency_input);
    
    cout << "\nEnter your credit hour: ";
    cin >> credit_hour;

    try
    {
        switch (status)
        {
            case Status::Full:
            {
//                cout << "\nStatus: Full";
                switch (degree)
                {
                    case Classification::Undergraduate:
//                        cout << "\nClassification: Undergraduate";
                        switch (residency)
                        {
                            case Residency::Resident:
                                cost_per_hour = 345;
                                tuition = credit_hour * cost_per_hour ;
//                                cout << "\nResidency: Resident";
                                break;
                            case Residency::International:
                                cost_per_hour = 685;
                                tuition = credit_hour * cost_per_hour ;
//                                cout << "\nResidency: International";
                                break;
                            default:
                                throw "You enter incorrect number for residency.\n";
                                break;
                        }
                        break;
                    case Classification::Graduate:
//                        cout << "\nClassification: Graduate";
                        switch (residency)
                        {
                            case Residency::Resident:
                                cost_per_hour = 545;
                                tuition = credit_hour * cost_per_hour ;
//                                cout << "\nResidency: Resident";
                                break;
                            case Residency::International:
                                cost_per_hour = 885;
                                tuition = credit_hour * cost_per_hour ;
//                                cout << "\nResidency: International";
                                break;
                            default:
                                throw "You enter incorrect number for residency.\n";
                                break;
                        }
                        break;
                    default:
                        throw "You enter incorrect number for degree.\n";
                        break;
                }
            }
            break;
            case Status::Parttime:
            {
                switch (degree)
                {
                    case Classification::Undergraduate:
                        if(credit_hour < 12)
                        {
                            switch(residency)
                            {
                                case Residency::Resident:
                                    cost_per_hour = 345;
                                    tuition = credit_hour * cost_per_hour ;
                                    break;
                                case Residency::International:
                                    cost_per_hour = 685;
                                    tuition = credit_hour * cost_per_hour ;
                                    break;
                                default:
                                    throw "You enter invalid number of your residency.\n";
                                    break;
                            }
                        }
                        else
                        {
                            throw 400;
                        }
                        break;
                    case Classification::Graduate:
                        if (credit_hour < 6)
                        {
                            switch(residency)
                            {
                                case Residency::Resident:
                                    cost_per_hour = 545;
                                    tuition = credit_hour * cost_per_hour ;
                                    break;
                                case Residency::International:
                                    cost_per_hour = 885;
                                    tuition = credit_hour * cost_per_hour ;
                                    break;
                                default:
                                    throw "You enter invalid number of your residency.\n";
                                    break;
                            }
                        }
                        else
                            throw 400;
                        break;
                    default:
                        throw "You enter invalid number of your student status.\n";
                        break;
                    }
                break;
            default:
                throw "You enter invalid number for your status.\n";
                break;
            }
        }
    }
    catch(const char * txtError)
    {
        cout << "\nException: " << txtError << "\n\n";
    }
    catch(int exceptionCode)
    {
        cout << "\nException: " << exceptionCode << "\nInvalid input for credit hour\n\n";
    }
    catch(...){
        cout<<"\nInvalid input\n\n";
    }
    
    cout << "\nYour name: " << student_name;
    print_from_input(degree, status, residency);
    cout << "\nYour tuition is: $" << tuition << "\n\n";
    return 0;
}
