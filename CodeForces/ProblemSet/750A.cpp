#include<iostream>
#include<climits>
#include<algorithm>
#include<ctype.h>

using namespace std;

int main(){
    int n , k;
    cin >> n >> k;

    int quesMin = 240-k;

    int cnt = 0;

    int time = 0;

    int i =1;

    while(time+5*i <= quesMin && i<=n){
        time+=(5*i);
        i++;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}