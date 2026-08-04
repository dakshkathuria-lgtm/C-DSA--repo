#include<iostream>
#include<cstring>
#include<map>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<pair<string, int>, int>mp;
    multimap<string, int> mp1;

    for(int i=0;i<n;i++){
        string s;
        int x;
        cin >> s >> x;
        mp.insert({{s,i}, x});
        mp1.insert({s,x});
    }

    for(auto x:mp){
        cout << x.first.first << " " << x.second << endl;
    }

    cout << endl << "--------------------------------" << endl;

    for(auto x:mp1){
        cout << x.first << " " << x.second << endl;
    }

    //not allowed
    // cout << mp1["Mayank"] << endl;


    // since there can be duplicate values hum log yaha rnage iteration karte hai

    string key{"Mayank"};
    auto range = mp1.equal_range(key); // equalrange returns a pair of iterators...first and second(1 posn after the last occurence)
    for(auto it = range.first;it!=range.second;it++){
        cout << it->first << " " << it->second  << endl;
    }

    cout << mp1.count("Mayank") << endl;

    if(mp1.find("Mayank")!=mp1.end()){
        cout << "yes" << endl;
    }

    return 0;
}
