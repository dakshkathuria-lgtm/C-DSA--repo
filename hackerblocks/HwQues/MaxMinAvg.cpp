#include<iostream>
#include<limits.h>
using namespace std;

int main(){
  int n ;
  cin >> n;
  int c =1;

  int max = INT_MIN;
  int min = INT_MAX;
  double totalSum = 0;

  while(c<=n){
    int x;
    cin >> x;
    c++;

    for(int i =1;i<=n;i++){
      if(x>max) max=x;
      if(x<min) min = x;
    }

    totalSum = totalSum + x;
  }


  cout << "max is " << max << endl;
  cout << "min is " << min << endl;
  cout << "avg is " << totalSum/n << endl;


  return 0;
}