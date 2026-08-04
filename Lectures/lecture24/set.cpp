#include<iostream>
#include<climits>
#include<cstring>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> s;
    multiset<int> ms;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
        ms.insert(x);
    }

    for(set<int>::iterator it = s.begin(); it !=s.end();it++){
        cout << *it << " "; // value of ur element
    }
    cout << endl << "-------------------------" << endl;

    for(auto x:s){
        cout << x << " ";
    }
    cout << endl << "----------------------------" << endl;

    if(s.count(5)==1){
        cout << "yes" << endl;
    }

    cout << ms.count(5)<< endl;

    if(s.find(5)!=s.end()){
        cout << "yes" << endl;
    }

    cout << *s.find(5) << endl; // value hi deta

    cout << *s.lower_bound(4) << endl;
    cout << *s.upper_bound(4) << endl;
    return 0;
}