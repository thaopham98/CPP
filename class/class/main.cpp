//
//  main.cpp
//  class-oop
//
//  Created by Thao Pham on 3/21/22.
//

#include <iostream>
#include <cmath>

using namespace std;

/*MARK: parent class*/
class Polygon{
public:
    int Sides;

    int get_perimeter(int sides){
        int perimeter ;
        perimeter = sides++;
        return perimeter;
    }

    void display_info()
    {
        cout << "A polygon is a 2D shape with straight lines.";
    }
    
    Polygon(int sides){ // Constructor
        Sides = sides;
        
        cout << "The side: " << sides << endl;
        get_perimeter(sides);
        display_info();
        
    }
};

/*MARK: 1st child class*/
class Triangle: public Polygon{
public:

    void display_info(){
        cout << "\nA triangle is a polygon with 3 edges.";
    }
    
    Triangle(int sides): Polygon(sides){ //Constructor
        display_info();
//        Polygon::display_info(); //caling a function of parent class
    }
};

/*MARK: 2nd child class*/
class Quadrilateral: public Polygon{
public:

    void display_info(){
        cout << "\nA quadrilateral is a polygon with 4 edges.";
    }
    
    Quadrilateral(int sides): Polygon(sides){ //Constructor
        display_info();
//        Polygon::display_info(); //caling a function of parent class
    }
};

/*MARK: 3th child class*/
class Square: public Polygon{
public:
    void display_info(){
        cout << "\nA square is a polygon with 4 even edges.";
    }
    
    Square(int sides): Polygon(sides){//Constructor
        display_info();
    }
};
int main() {
    
    /*User input*/
    int side;
    
    cout << "Enter your side for object 1: ";
    cin >> side;
    Polygon object1(side); // create an object
    
    cout << "\n\nEnter your side for object 2: ";
    cin >> side;
    Polygon object2(side); // create an object
    
    /*  Triangle Class  */
    cout << "\n\nEnter your side for triangle object 1: ";
    cin >> side;
    Triangle tObject1(side);
//    tObject1.Polygon::display_info(); //caling a function of parent class

    /*  Quadrilateral class */
    cout << "\n\nEnter your side for quadrilateral object 1: ";
    cin >> side;
    Quadrilateral qObject1(side);
//    qObject1.Polygon::display_info(); //caling a function of parent class
    
    cout << "\n\n";
    return 0;
}
