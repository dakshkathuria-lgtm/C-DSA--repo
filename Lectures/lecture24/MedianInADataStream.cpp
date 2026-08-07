#include<iostream>
#include<climits>
#include<cstring>
#include<queue>
using namespace std;

class MedianFinder {
public:

    priority_queue<int> maxi;
    priority_queue<int, vector<int> , greater<int>> mini;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxi.push(num);
        mini.push(maxi.top());
        maxi.pop();

        if(mini.size()>maxi.size()){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if((maxi.size() + mini.size()) % 2==0){
            double ans = (maxi.top() + mini.top())/2.0;
            return ans;
        }
        return maxi.top();
        
    }
};

int main(){

    return 0;
}