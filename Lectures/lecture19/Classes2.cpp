#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

class Car{

    public: 
        string name{"BMW"};
        string color{"Black"};

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



    private:
        int Price{100000};
    protected:




};

int main(){
     
    int x{10}; //variable

    
    Car c;

    

    cout << c.name << endl;
    cout << c.GetPrice()<< endl;
    c.SetPrice(100000);
    cout << c.GetPrice() << endl;
    

    return 0;
}