#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

/*
 * There are 4 things that associated with
 * classes jo c++ ne aapko already bana ke di hain
 * and these are self invoked.
 * 1. Constructor
 * 2. Copy Constructor
 * 3. Copy Assignment
 * 4. Destructor
 *
 * strcpy : It copies the content of one character array to another.
 * this keyword: hold karta hai address of the current ohject
 * 1) Resolving name conflicts
 * 2) 
 */

class Car {
private:
  int Price{100000};

public:
  char name[100];
  string color;
  double model;

  char *engine = new char[100]; // THis will be a Dynamic Array defined in
                                // Dynamic Memory(Heap) Currently this is a
                                // pointer in the static memory that will point
                                // to the array defined in head/dynamic memory.

  //  Getter :
  int GetPrice() { return Price; }

  // Setter :
  void SetPrice(int Discount) {
    if (Discount <= 25000) {
      Price = (Price - Discount);
    } else {
      Price = (Price - 25000);
    }
  }

  Car() {
    cout << "I am Inside My Default Constructor";
    cout << endl << "------------------------------" << endl;
  }

  // Parameterised Constructor:
  Car(char n[], string color, double model, char *e, int P) {
    cout << "Inside My Parameterised Constructor";
    cout << endl << "------------------------------" << endl;
    strcpy(name, n);

    this -> color = color;
    // (*this).model = model;
    // this -> model = model;

    // Resource Allocation should be done optimally.
    // Jitna mujhe chahiye utna hi use karna chahiye.
    engine = new char[strlen(e) + 1];
    strcpy(engine, e);

    SetPrice(P);
  }

  
  void Print() {
    cout << "Name of the Car is      : " << name << endl;
    cout << "Color of the Car is     : " << color << endl;
    cout << "Model No. of the Car is : " << model << endl;
    cout << "Engine of the Car is    : " << engine << endl;
    cout << "Price of the Car is     : " << GetPrice() << endl;
    cout << endl << "---------------------------------------" << endl;
  }

protected:
};

int main() {

  // Variable :
  int x{10};

  // This is an object of the class car, defined by default constructor:
//   Car c;
//   strcpy(c.name, "BMW\0"); // It is a function that helps you to copy the string
//                            // in character array direclty.

//   // c.name[0] = 'B';
//   // c.name[1] = 'M';
//   // c.name[2] = 'W';
//   // c.name[3] = '\0';
//   c.color = "Black";
//   c.model = 5.3;
//   strcpy(c.engine, "V8");
//   c.SetPrice(19000);
//   c.Print();

  // Constructors Can only be invoked at the time of variable/object defintion.
  Car d("Audi\0", "Grey", 4.3, "Z9", 5000);
  d.Print();

//   Car e("Alto\0", "White", 3.2);
//   e.Print();

  // I want to have all values of this Card d in another car f, for this we r
  // using copy constructor

  // Default copy constructor
  Car f(d);
  f.Print();

  d.name[0] = 'T';
  d.engine[0] = 'W';

  d.Print();
  f.Print();

  return 0;
}