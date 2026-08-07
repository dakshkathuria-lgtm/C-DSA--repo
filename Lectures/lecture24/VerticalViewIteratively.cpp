#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include<map>
#include<set>
#include<climits>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left; // apne hi jaise ek aur ka adrress sotre kar rhe honge
        TreeNode *right;

        TreeNode(){
            left = nullptr;
            right = nullptr;
        }

        TreeNode(int x){
            val = x;
            left = nullptr;
            right = nullptr;
        }

        ~TreeNode(){}
};

TreeNode *BuildTree() {
  int x;
  cin >> x;

  if (x == -1) {
    return nullptr;
  }

  TreeNode *n = new TreeNode(x);
  n->left = BuildTree();
  n->right = BuildTree();

  return n;
}

void bfs(TreeNode* root){
    if(root==nullptr){
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* f = q.front();
        q.pop();
        if(f==nullptr){
            if(!q.empty()){
                q.push(nullptr);
            }
            cout << endl;
        } else{
            cout << f->val << " ";
            if(f->left!=nullptr){
                q.push(f->left);
            }
            if(f->right!=nullptr){
                q.push(f->right);
            }
        }
    }
}

vector<int>VerticalViewOfTreeIteratively(TreeNode* root){
    vector<int> ans;
    
    queue<pair<TreeNode*, pair<int, int>>> q;
    // queue<Node,pair<col,level>>>q;

    map<int, map<int, multiset<int>>> mp;
    // map<col, multiset<pair<level, value>>> mp1;

    q.push({root, {0,0}});

    while(!q.empty()){
        auto f = q.front();
        q.pop();

        int CurrentCol = f.second.first;
        int CurrentLevel = f.second.second;
        TreeNode *CurrentNode = f.first;

        mp[CurrentCol][CurrentLevel].insert({CurrentNode->val});

        // insert its children
        if(CurrentNode->left!=nullptr){
            q.push({CurrentNode->left, {CurrentCol-1, CurrentLevel+1}});
        }

        if(CurrentNode->right!=nullptr){
            q.push({CurrentNode->right, {CurrentCol+1, CurrentLevel+1}});
        }
    }

    // build ans vector
    for(pair<int, map<int, multiset<int>>> x: mp){
        int CurrentCol = x.first;
        map<int, multiset<int>> Data = x.second;
        for(pair<int, multiset<int>> y : x.second){
            int CurrentLevel = y.first;
            multiset<int> nodes = y.second;
            for(int z : y.second){
                ans.push_back(z);
            }
        }
    }
    return ans;
}

int main(){

    TreeNode* root = BuildTree();
    bfs(root);
    cout << "-----------------------------" << endl;
    vector<int> ans = VerticalViewOfTreeIteratively(root);
    for(int x:ans){
        cout << x << " "; 
    }
    cout << endl << "-------------------------" << endl;
    return 0;
}