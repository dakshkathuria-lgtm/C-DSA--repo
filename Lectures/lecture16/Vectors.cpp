#include<iostream>
#include<vector>
using namespace std;

int Solve(int a[], int n){
    int sum = 0;
    for(int i =0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

int Solve02(int a[], int n){
    int sum = 0;
    for(int i =0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

int Solve03(vector<int> &a){
    int size = a.size();
    int capacity = a.capacity();

    int sum = 0;
    // for(int i =0;i<n;i++){
    //     sum+=a[i];
    // }

    for(auto x :a);
    return sum;
}

vector<int> Solve04(vector<int> &a){
    int size = a.size();
    int capacity = a.capacity();
    vector<int> ans{};
    
    int sum = 0;
    // for(int i =0;i<n;i++){
    //     sum+=a[i];
    // }

    for(auto x :a);
    return {};
}

int main(){

    int a[5];
    int b [5]{3, 2, 1, 3};
    int c[5]{3, 2, 1, 3, 5};

    // DYNAMIC ARRAYS
    int *d = new int[5];
    int *e = new int[5]{3, 2, 13};
    int *f = new int[5]{3, 2, 1, 3, 5}; 
    
    delete[] f; // to avoid memory leak

    f = new int[10]{3, 2, 1, 3, 4, 5, 5, 1};

    int n = sizeof(c); // 4* number of elements
    int n1 = sizeof(c)/sizeof(int) ; // actual size;
    int ans = Solve(c, n1); // c passed by refernce and n1 passed by value

    // Do not take size for dynamic array like this as sizes can be changed
    // int n2 = sizeof(f)/sizeof(int);


    int ans02 = Solve02(f, 8);

    cout << ans << " " << ans02 << endl;



    // for each loop

    auto x{90}; // kkeywrod that will be replced with the type the current variable is of


    // for each loop can only be applied on a container data type / structre and used to fetch all only not modify all

    for(int x: c){  // for every element of c x kaisa hai
        x= x+1;
        cout << x << " ";      // sirf change hota 1 baari
    }
    cout << endl;

    for(int x:c){
        cout << x << " ";       // remains same
    }


    vector<int> v;

    vector<int> v1(5); // vector made from dynamic array whose capacity is 5 and will be 2*5 when full

    vector<int> v2(7,5); // capacity is 7 and each element is initialsed with value 5

    vector<int> v3{3, 2, 1, 3,4,5}; // size 6 nad double its size when a new element is inserted here



    int z;
    cin >> z;
    vector<int> y;
    for(int i =0;i<z;i++){
        cin >> y[i]; // u can't take input in a vector like this if u have not speicified its size
    }

    for(int i =0;i<z;i++){
        int x;
        cin >> x;
        y.push_back(x);
    }

    vector<int> q(n);
    for(int i =0;i<z;i++){
        cin >> q[i];
    } // if size is given do not take input using push_back as it will put the element to the end

    q = y; // as type same

    int ans03 = Solve03(q);

    cout << ans03 << endl;



    return 0;
}