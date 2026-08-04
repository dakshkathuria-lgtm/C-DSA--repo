#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<utility>
#include<climits>
#include<cstring>
using namespace std;

int main(){
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;

    string prev{""}; // pichli trip ka end pt

    map<pair<string, string>, int>mp; // {route, cost of the route}
    int ctc = 0; // current trip ki cost

    for(int i =0;i<n;i++){
        string sp, ep;
        cin >> sp >> ep;

        if(sp==prev){
            ctc = b;
        } else{
            ctc = a;
        }

        prev = ep;

        if(sp>ep){
            swap(sp, ep);
        }

        mp[{sp, ep}] += ctc;
    }

    vector<int> cost;
    int TotalCost = 0;
    for(auto x: mp){
        // total trip cost without travel card
        TotalCost+=x.second;
        cost.push_back(x.second);
    }

    sort(cost.rbegin(), cost.rend());

    // now back travel cards for the respective route
    for(int i =0;i<cost.size();i++){
        if(cost[i]>f){
            TotalCost = (TotalCost - cost[i] + f);
        } else{
            break;
        }
    }

    cout << TotalCost << endl;
 
    return 0;


}