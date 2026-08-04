#include<iostream>
#include<climits>
#include<cstring>
#include<string.h>    

using namespace std;

/*
There are 4 things that are associated with classes jo c++ ne aapko
already bana ke di hai and these are self invoked.
1) constructor
2) copy constructor
3) copy assignment
4) destructor

strcpy : It copies the ocntent of 1 char array to another



*/

class Car{
    private:
        int Price{100000};

    public: 
        char name[100];
        string color{"Black"};
        double model;
        char *engine = new char[100]; // this will be a dynamic arrays defined in dynamic memory
        // currently this is a pointer in the static memory that will point to the array defined in heap/dynamic memory



        // getter
        int GetPrice() {
            return Price;
        }

        // setter
        void SetPrice(int Discount){
            if(Discount<=25000){
                Price =  (Price - Discount);
            } else{
                Price = (Price - 25000);
            }
        }

        //Constructor overlaoding
        // agar aapne paramtriesd constructor banaya hai then aapko defaul constructor banana padega

        // Default constructor : 
        Car(){
            cout << "I am inside my default constructor";
            cout << endl << "------------------" << endl;
        }

        // Paramterized constructor(jisme user kaam karta)
        Car(char n[], string c, double m, char *e, int P){
            cout << "inside my paramtriesed constructor";
            cout << endl << "---------------------" << endl; 
            strcpy(name, n);
            color = c;
            model = m;

            //resource allocation shld be done optimsally..jitna chiaye utna hi
            engine = new char[strlen(e)]+1;
            strcpy(engine, e);


            SetPrice(P);
        }

        Car(char n[], string c, double m){
            cout << "inside my paramtriesed constructor02";
            cout << endl << "---------------------" << endl; 
            strcpy(name, n);
            color = c;
            model = m;

        }

        // memeber fn : name: ek attribute h jo assign hoga ek vairable 
        void Print(){
            cout << "name of the car is:" << name << endl;
            cout << "color of the car is:" << color << endl;
            cout << "model no of the car is:" << model << endl;
            cout << "Enginee of the car is :" << engine<< endl;
            cout << "Price of the car is : " << GetPrice() << endl;
            cout << endl << "---------------------------" << endl;
        }



    protected:




};

int main(){
     
    int x{10}; //variable

    // this is an object of the clas car defined by default constructor
    Car c;
    strcpy(c.name, "BMW\0");  // strcpy helps u to copy string in ch array directly
    c.color = "Black";
    c.model = 5.3;
    strcpy(c.engine, "V8");
    c.SetPrice(19000);

    c.Print();
    
    Car d("Audi\0", "Grey", 4.3, "Z9", 5000);
    d.Print();

    Car e("Alto\0", "White", 3.2);
    e.Print();
    

    return 0;
}