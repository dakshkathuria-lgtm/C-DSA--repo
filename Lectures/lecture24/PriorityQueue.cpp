#include<iostream>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;

int main(){

    // Max heap
    priority_queue<int> pq1;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        pq1.push(x);
        pq2.push(x);
    }

    cout << pq1.top() << " " << pq2.top() << endl;

    cout << endl << "--------------------------" << endl;

    while(!pq1.empty()){
        cout << pq1.top() << " ";
        pq1.pop();
    }

    cout << endl << "--------------------------" << endl;

    while(!pq2.empty()){
        cout << pq2.top() << " ";
        pq2.pop();
    }

    return 0;
}