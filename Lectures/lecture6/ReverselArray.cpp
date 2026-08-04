#include<iostream>

int main(){

    int n ;
    std::cin >> n;
    int a[n];

    for(int i =0;i<n;i++){
        std::cin >> a[i];
    }

    for(int i =0;i<n;i++){
        std::cout << a[i];
    }

    std:: cout << std::endl;

    int b[n];
    for(int i =0;i<n;i++){
        b[i]=a[n-1-i];
    }

    for(int i =0;i<n;i++){
        std::cout << b[i];
    }

    return 0;
}