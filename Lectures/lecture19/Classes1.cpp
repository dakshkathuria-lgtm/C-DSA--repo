#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

// u r trying to create ur own data type of the name car

// these are a way of representation of ur own data type hence we call them 
// the blueprint of ur user defiend data type
class Car{

    // 1) Data memebrs
    // 2) Member fn


    // Access Modifiers:
    public: 
        string name{"BMW"};
        string color{"Black"};

    private:
        int Price{100000};

    protected:

};

int main(){
     
    int x{10}; //variable

    //variable of tyep car or this is an object off the class car whose identifier is c
    // this variable c will have all the proeprties that are of class car ie data memeber and member fn
    Car c;

    // to accress any data memenr/member fn of current class/contanier the i use dot operator

    cout << c.name << endl;
    // cout << c.Price << endl; // can't be done as price is pvt

    return 0;
}