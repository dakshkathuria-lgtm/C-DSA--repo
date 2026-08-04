#include<iostream>
#include<climits>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class Encrypter {
public:
    map<char, string> mp;
    vector<string> d;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        // create mapping of key value pair
        for(int i =0;i<keys.size();i++){
            mp[keys[i]] = values[i];
        }
        d = dictionary;
    }
    
    string encrypt(string word1) {
       string ans = {""};
       for(int i =0;i<word1.size();i++){
        if(mp.count(word1[i])==0){
            return "";  
        }
        ans = ans + mp[word1[i]];
       } 
       return ans;
    }
    
    int decrypt(string word2) {
        int ans = 0;
        for(string x:d){
            string l = encrypt(x);
            if(l==word2){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<char> key{'a', 'b', 'c', 'd'};
    vector<string> values{"ei", "zf", "ei", "am"};
    vector<string> dictionary {"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"};

    Encrypter e(key, values, dictionary);
    cout << e.encrypt("abcd") << endl;
    cout << e.decrypt("eizfeiam") << endl;
    return 0;
}