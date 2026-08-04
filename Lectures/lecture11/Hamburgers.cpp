#include<iostream>
#include<cstring>
#include<climits>
#define int long long

using namespace std;

int32_t main(){
    char ch[100];
    cin >> ch;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    int r;
    cin >> r;
    
    int sb=0, ss= 0, sc=0, cnt =0;

    for(int i =0;ch[i]!='\0';i++){
        if(ch[i]=='B') sb++;
        else if(ch[i]=='S') ss++;
        else sc++;
    }

    while(r>0){
        int EBM=0, ESM=0, ECM=0;
        nb-=sb;
        if(nb<0){
            EBM = -1 * (nb*pb);
            nb=0;
        }

        ns-=ss;
        if(ns<0){
            ESM = -1 * (ns*ps);
            ns=0;
        }

        nc-=sc;
        if(nc<0){
            ECM = -1 * (nc*pc);
            nc=0;
        }

        r-=EBM + ESM + ECM;
        if(r>=0){
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}