#include"../HeaderFiles/ListNode.h"
#include<iostream>
using namespace std;

template <typename T> void PrintLL(ListNode<T> *head){
    while(head!=nullptr){
        cout << head->val << " --> ";
        head=head->next;
    }
    cout << "NULL" << endl;
}

template<typename T> void PrintLL02(ListNode<T> *&head){
    ListNode<T> *temp = head;
    while(temp!=nullptr){
        cout << temp->val << " --> ";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}   

template <typename T> void InsertAtHead(ListNode<T> *&h, T data){
    ListNode<T> *newnode = new ListNode<T>(data);
    newnode->next = h;
    h = newnode;
}

template<typename T> void InsertAtTail(ListNode<T> *&h, T data){
    ListNode<T> *newnode = new ListNode<T>(data);

    if(h==nullptr){
        h= newnode;
        return ;
    }

    ListNode<T> *temp = h;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newnode;

}

template<typename T> void InsertAtPosition(ListNode<T> *&h, T data, int pos){
    if(pos<=1){
        InsertAtHead(h, data);
        return ;
    }

    ListNode<T> *temp  = h;
    for(int i =1;i<pos-1 && temp->next!= nullptr;i++){
        temp = temp->next;
    }

    ListNode<T> *newnode = new ListNode<T>(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

template<typename T> void deleteAtHead(ListNode<T> *&h){
    if(h==nullptr){
        return ;
    }
    ListNode<T> *temp = h;
    h = h->next;
    delete temp;
}

template<typename T> void deleteAtTail(ListNode<T> *&h){
    if(h==nullptr){
        return ;
    }

    if(h->next==nullptr){
        delete h;
        h = nullptr;
        return;
    }

    ListNode<T> *temp = h;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

template<typename T> void deleteAtPosition(ListNode<T> *&h, int pos){
    if(h==nullptr){
        return ;
    }

    if(pos<=1){
        deleteAtHead(h);
        return;
    }

    ListNode<T> *temp = h;
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    if(temp->next==nullptr){
        return;
    }

    ListNode<T> *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

template<typename T> void deleteByValue(ListNode<T> *&h, T val){
    if(h==nullptr){
        return ;
    }

    if(h->val==val){
        deleteAtHead(h);
        return;
    }

    ListNode<T> *temp = h;
    while(temp->next!=nullptr && temp->next->val!=val){
        temp= temp->next;
    }

    if(temp->next==nullptr){
        return;
    }

    ListNode<T> *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

template <typename T> void DeleteList(ListNode<T> *&head) {
    while (head != nullptr) {
        DeleteAtHead(head);
    }
}

template<typename T> int length(ListNode<T> *h){
    int cnt = 0;
    while(h!=nullptr){
        cnt ++;
        h = h->next;
    }
    return cnt;
}

template<typename T> bool SearchInLL(ListNode<T> *h, T key){
    ListNode<T> *temp = h;
    while(temp!=nullptr){
        if(temp->val==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

template<typename T> bool SearchInLLRecursively(ListNode<T> *h, T key){
    // STOPPING POINT
    if(h == nullptr){
        return false;
    }

    // TASK
    if(h->val == key){
        return true;
    }

    return SearchInLLRecursively(h->next, key);
}

template<typename T> T midPoint01(ListNode<T> *head){
    if(head==nullptr){
        cout << "List is empty" << endl;
        return T{};
    }

    int len = length(head)/2;
    while(len>0){
        head = head->next;
        len--;
    }
    return head->val;
}

template<typename T> ListNode<T> *midpoint02(ListNode<T> *head){
    ListNode<T> *slow = head;
    ListNode<T> *fast = head;

    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow = slow->next;
    }
    return slow;
}

template<typename T> ListNode<T> *midpoint03(ListNode<T> *head){

    if(head == nullptr){
        return nullptr;
    }

    ListNode<T> *slow = head;
    ListNode<T> *fast = head->next;

    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow = slow->next;
    }
    return slow;
}

template<typename T> void ReverseLLIteratively(ListNode<T> *&head){
    ListNode<T> *current = head;
    ListNode<T> *prev = nullptr;
    ListNode<T> *next ;

    while(current!=nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template<typename T> ListNode<T> *ReverseLLRecusrsively(ListNode<T> *head){ // here pass by value so that har call mei head change hota rhe
    if(head==nullptr or head->next==nullptr){
        return head;
    }

    ListNode<T> *ReverseHead = ReverseLLRecusrsively(head->next);

    head->next->next = head;
    head->next = nullptr;

    return ReverseHead;

}

template<typename T> void f(ListNode<T> *end, ListNode<T> *&start, bool &stop, int left, int right){
    if(right==1){
        return;
    }

    end = end->next;
    if(left>1){
        start=start->next;
    }
    f(end, start, stop, left-1, right-1);

    if(end==start or end->next==start){
        stop = true;
    }

    if(!stop){
        swap(end->val, start->val);
        start = start->next;
    }
    return;
}

// 246 and 270 interalted

template <typename T> ListNode<T> *reverseBetweenRecursive(ListNode<T> *head, int left, int right) {
  ListNode<T> *start = head;
  bool stop = false;
  f(head, start, stop, left, right);
  return head;
}

template<typename T> ListNode<T> *reversebwIteratively(ListNode<T> *head, int left, int right){
    if(head==nullptr or left == right){
        return nullptr;
    }

    ListNode<T> *dummy = new ListNode<T>();
    dummy->next = head;
    ListNode<t> *prev = dummy;
    for(int i =1;i<left;i++){
        prev = prev->next;
    }

    ListNode<T> *current = prev->next;
    ListNode<T> *subPrev = nullptr;
    ListNode<T> *subStart = current;
    ListNode<T> *next = nullptr;
    
    for(int i =0;i<right-left+1;i++){
        next = current->next;
        current->next = subPrev;
        subPrev = current;
        current = dummy;
    }

    prev->next = subPrev;
    subStart->next = current;

    ListNode<T> *newHead = dummy->next;
    delete dummy;
    return newHead;
}

template<typename T> void CycleCreation(ListNode<T> *head){
    if(head==nullptr or head->next==nullptr){
        return;
    }
    ListNode<T> *tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    // FOR ANY OTHER POSITION
    // ListNode<T> *temp = head;
    // for(int i =1;i<15;i++){
    //     temp=temp->next;
    // }
    // tail->next = temp;

    tail->next = head->next->next;
}

template<typename T> bool isCycle(ListNode<T> *head){
    ListNode<T>* slow = head;
    ListNode<T>* fast = head;

    while(fast!=nullptr and fast->next!=nullptr){
        fast= fast->next->next;
        slow = slow->next;
    
        if(fast==slow){
            return true;
        }
    }
    return false;
}

template<typename T> void BreakCycle(ListNode<T> *head){
    if(!isCycle(head)){
        cout << "No cycle found" << endl;
        return;
    }

    ListNode<T> *slow = head;
    ListNode<T> *fast = head;
    while(fast!=nullptr and fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;

        if(slow==fast){
            break;
        }
    }

    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    ListNode<T> *tail = fast;
    while(temp!=fast){
        temp = temp->next;
    }
    tail->next = nullptr;
}

template<typename T> bool isPalindrome(ListNode<T> *head){
    if(head==nullptr or head->next==nullptr){
        return true;
    }

    ListNode<T> *mid = midpoint03(head  );
    ListNode<T> *secondHead = mid->next;
    mid->next = nullptr; // break curr linked list into 2 halves

    ReverseLLIteratively(secondHead);

    // second list list will either be of same lenght of 1st or will be smaller

    ListNode<T>* left = head;
    ListNode<T>* right = secondHead;
    bool result = true;
    while(right!=nullptr){
        if(left->val!=right->val){
            result = false;
            break;
        }
        left = left->next;
        right = right->next;
    }
    return result;
}

template<typename T> void RemoveDuplicateFromSorted(ListNode<T> *head){
    while(head!=nullptr and head->next!=nullptr){
        if(head->val == head->next->val){
            ListNode<T> *dup = head->next;
            head->next = dup->next;
            delete dup;
        } else{
            head= head->next;
        }
    }
}

template<typename T>void reOrderList(ListNode<T> *head){
    if(head==nullptr || head->next==nullptr){
        return;
    }
    ListNode<T> *mid = midpoint02(head);
    ListNode<T> *h2 = mid->next;
    mid->next = nullptr;

    ReverseLLIteratively(h2);
    ListNode<T> *h1 = head;

    while(h2!=nullptr){
        ListNode<T> *x = h1->next;
        ListNode<T> *y = h2->next;

        h1->next = h2;
        h2->next = x;
        h1 = x;
        h2 = y;
    }
}