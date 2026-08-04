#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

class CoOrdinates{
    private:
        int x, y;
    public:
        CoOrdinates(){
            // Default constructor
        }

        CoOrdinates(int x1, int y1){
            x = x1;
            y = y1;
        }

        // operator overloading with the help of member function 
        CoOrdinates operator+(CoOrdinates n){
            CoOrdinates t;
            t.x = x+n.x;
            t.y = y + n.y;
            return t;
        }

        void Print(){
            cout << x << " " << y << endl;
        }
};



int main(){
    CoOrdinates m(10,7);
    CoOrdinates n(2,4);

    // by default error dega
    // menaing of + operator is not defined
    CoOrdinates o =m+n;  // 12, 11
    CoOrdinates g = m.operator+(n);
    o.Print();
    g.Print();


    return 0;
}