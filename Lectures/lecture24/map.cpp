#include<iostream>
#include<algorithm>
#include<utility>
#include<map>
#include<vector>
using namespace std;

int main(){
    map<string, int> mp{
        {"Mayank", 10000},
        {"Rahul", 4000},
    };

    int n;
    cin >> n;

    map<string, int> mp1;

    for(int i =0;i<n;i++){
        string s;
        int x;
        cin >> s >> x;

        // when u are adding element through insertion so the 1st occurence is stored
        mp1.insert({s,x});

        // when u are adding through updation the last occurence is stored
        mp1[s] = x;


        // 2 ways to print map
        // method 1: using iterator
        for(map<string, int>::iterator it = mp1.begin();it!=mp1.end();it++){
            cout << (*it).first <<" " << it->second;
        }

        cout << endl << "-------------------------" << endl;

        // method 2 : for each loop
        // for every element of this container mp1 u wld wnat to represent it as x and perform the following task;

        for(pair<string, int> x:mp1){
            cout << x.first << " " << x.second << endl;    
        }

        cout << mp1["Mayank"] << endl;

        cout << mp1.size() << endl;
        cout << endl << "-------------------------" << endl;
        cout << mp1.empty() << endl;
        cout << endl << "-------------------------" << endl;
        if(mp1.count("mayank")==1){
            cout << "yes" << endl;
        } else{
            cout << "no" << endl;
        }

        if(mp1.find("Mayank")!=mp1.end()){   // find address laakar deta
            cout << "yes" << endl;
        } else{
            cout << "no" << endl;
        }
    }


    return 0;
}