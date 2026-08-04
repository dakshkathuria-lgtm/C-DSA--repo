#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
#define int long long

template<typename T> class Node{
    public:
        // Data
        string key;
        T value;

        // next block ka adress for separate chain method
        Node<T> *next;

        // defualt constructor
        Node(){
            next = nullptr;
        }

        // paramterised consturctor
        Node(string s, int v){
            key = s;
            value = v;
        }

        // destructor
        ~Node(){
            if(next!=nullptr){
                delete next;
            }
        }
};

// HashTable: to store all the data

template<typename T> class HashTable{

    Node<T>**table; // building in dynamic memory so that i can resize the table when rehashing is being performed
    int ts; // we need this for rehashing
    int cs; // we need this for rehashing

    // Hashfunction:
    int HashFunction(string key){
        int p = 1;
        int ans = 0; // represets my hash index where i am going to store this data in hash table

        for(int i =0;i<key.length();i++){
            ans += (((key[i]%ts) * (p % ts)) %ts);
            p = (((p % ts) * 5) % ts);

        }
        return (ans % ts);
    }

    void Rehashing(){
        // double the table size and isnert all the previous data of the tavle into new table

        Node<T> **Oldtable = table;
        int OldTableSize = ts;

        table = new Node<T> *[ts*2];
        ts = 2*ts;
        // initiliase every block of this new tbale with nullptr
        for(int i =0;i<ts;i++){
            table[i] = nullptr;
        }

        // now i have to move all content of previous table into new table

        cs = 0;
        for(int i =0;i<OldTableSize;i++){
            // current index is i; i : this index i will store the head of the linked list at this i
            Node<T> *head = Oldtable[i];
            while(head!=nullptr){
                insert(head->key, head->value);
                head = head->next;
            }
        }

        delete [] Oldtable;
    }

    public:

    // constructor for hashtable
    HashTable(int size = 10){
        ts = size;
        cs = 0;
        table = new Node<T> *[size];

        // initially all values of this tbale should be null
        for(int i =0; i<ts;i++){
            table[i] = nullptr;
        }
    }
    

    // insertion in this hashmap/hashtable
    void insert(string k, int v){
        int HashIndex = HashFunction(k);
        // will create a node of this data k, v and then will insert it in hash index using insert at head of linked list

        // initialsied using ocnstructor
        Node<T> *h = new Node<T> (k,v);
        cs++;

        // insert at head of linked list at index Hashindex of the Hashtable
        h->next = table[HashIndex];
        table[HashIndex] = h;

        // rehashing concept
        // if the data being stored is gretaer than 70% of the size of hash tbale we do rehashing
        // and in rehashing we double the size of table and assing new idncies to the data

        if((cs/ts*1.0)>7.0){
            Rehashing();
        }
    }

    Node<T> *search(T s){
        int HashIndex = HashFunction(s);
        // iterate over this linked list at index hashindex
        Node<T> * head = table[HashIndex];
        while(head!=nullptr){
            if(head->key==s){
                return head;
            }
            head = head->next;
        }
        // mujhe element nhi mila
        return nullptr;
    }

    void print(){
        for(int i =0;i<ts;i++){
            cout << i << " : ";
            Node<T> * head = table[i];
            while(head!=nullptr){
                cout << head->key << "---->" << head->value << "--->";
                head = head->next;
            }
            cout << "NULL" << endl;
        }
    }

};
