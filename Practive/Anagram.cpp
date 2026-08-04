#include<iostream>
using namespace std;
int main(){
    char ch1[100], ch2[100];
    cin >> ch1 >> ch2;

    int freq[256]{};
    for(int i =0;ch1[i]!='\0';i++){
        int ce = ch1[i];
        freq[ce]+=1;
    }

    for(int i =0;ch2[i]!='\0';i++){
        int ce = ch2[i];
        freq[ce]-=1;
    }

    for(int i =0;i<256;i++){
        if(freq[i]>0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}