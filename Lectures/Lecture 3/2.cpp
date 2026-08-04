#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool prime = true;

    if(n==0 || n==1){
        cout << "neither prime nor composite " << endl;
    } else {

        for(int i=2;i<n;i++){     
            if(n%i==0){
                prime = false;
                break;
            }
        }

        if(prime) cout << "prime"<< endl;
        else cout << "not prime" << endl;
    }

    return 0;   
}