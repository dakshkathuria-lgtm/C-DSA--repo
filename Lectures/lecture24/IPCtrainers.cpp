#include<iostream>
#include<cstring>
#include<climits>
#include<queue>
#include<set>
using namespace std;
const int N = 1e5 + 3;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;

        int AD[N]{}, Lectures[N]{}, Sadness[N]{};
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            cin >> AD[i] >> Lectures[i] >> Sadness[i];
            pq.push({Sadness[i], i});
        }
        
        set<int> AvailableDays;
        for (int i = 1; i <= d; i++) {
            AvailableDays.insert(i);
        }

        int LecturesTaken[N]{};
        while(!pq.empty()){
            pair<int, int> CurrentProf = pq.top();
            pq.pop();

            int ArrivalDay = AD[CurrentProf.second];
            int OptimisticEndDay = ArrivalDay + Lectures[CurrentProf.second] -1;

            for(int i = ArrivalDay;i<=OptimisticEndDay;i++){
                set<int> :: iterator it = AvailableDays.lower_bound(i);
                if(it!=AvailableDays.end()){
                    LecturesTaken[CurrentProf.second]++;
                    AvailableDays.erase(it);
                } else{
                    break;
                }
            }
        }

        int totalSadness = 0;
        for(int i =0;i<n;i++){
            totalSadness+= (Lectures[i] - LecturesTaken[i]) * Sadness[i];

        }

        cout << totalSadness << endl;
    }

    return 0;
}