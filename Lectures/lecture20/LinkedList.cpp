#include"../HeaderFiles/LinkedList.h"
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin >> n;

    ListNode<int> *head = nullptr;
    ListNode<int> *head01 = nullptr;

    for(int i =0;i<n;i++){
        int x;
        cin >>x;
        InsertAtHead(head, x);
        InsertAtTail(head01, x);
    }

    PrintLL(head);
    PrintLL02(head01);
    cout << SearchInLL(head,1) << endl;
    cout << SearchInLLRecursively(head,11) << endl;
    cout << length(head) << endl;
    cout << midPoint01(head) << endl;
    cout << midpoint02(head)->val << endl;

    ReverseLLIteratively(head);
    PrintLL02(head);
    return 0;
}