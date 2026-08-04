#include<iostream>
#include<climits>
#include<cstring>
#include<set>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        set<int> x, y;
        multiset<int> sx, sy;

        x.insert(0);
        x.insert(n);
        y.insert(0);
        y.insert(m);

        sx.insert(n);
        sy.insert(m);

        for(int i =0;i<q;i++){
            int a, b;
            cin >> a >> b;
            if(a==0){
                // vertical division
                if(x.count(b)>0){
                    // u already had a division on this b
                    // just print max area
                    int LXS = *(--sx.end());
                    int LYS = *(--sy.end());

                    int area = LXS * LYS;
                    cout << area << endl;
                    continue;
                }

                // new division being made
                auto large = x.upper_bound(b);
                auto small = large;
                small--;

                int length = (*large - *small);
                sx.erase(sx.find(length));

                sx.insert(b-*small);
                sx.insert(*large - b);

                x.insert(b);

                int LXS = *(--sx.end());
                int LYS = *(--sy.end());

                int area = LXS * LYS;
                cout << area << endl;
            } else{
                if(y.count(b)>0){
                    // u already had a division on this b
                    // just print max area
                    int LXS = *(--sx.end());
                    int LYS = *(--sy.end());

                    int area = LXS * LYS;
                    cout << area << endl;
                    continue;
                }

                auto large = y.upper_bound(b);
                auto small = y.upper_bound(b);
                small--;

                int length = (*large - *small);
                sy.erase(sy.find(length));

                sy.insert(b-*small);
                sy.insert(*large - b);

                y.insert(b);

                int LXS = *(--sx.end());
                int LYS = *(--sy.end());

                int area = LXS * LYS;
                cout << area << endl;
            }
        }
    }
    return 0;
}