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


vector<int>TopViewOfTreeIteratively(TreeNode* root){
    vector<int> ans;
    queue<pair<TreeNode*, int>>q;
    map<int, int> mp;

    q.push({root,0});
    
    while(!q.empty()){
        pair<TreeNode* , int> f =q.front();
        q.pop();

        TreeNode* newNode = f.first;
        int CurrentCol = f.second;

        if(mp.count(CurrentCol)==0){
            mp[CurrentCol] = newNode->val;
        }

        // insert its children
        if(newNode->left!=nullptr){
            q.push({newNode->left, CurrentCol-1});
        }

        if(newNode->right!=nullptr){
            q.push({newNode->right, CurrentCol+1});
        }
    }

    for(pair<int, int> x:mp){
        ans.push_back(x.second);
    }
    return ans;
}

int main(){

    TreeNode* root = BuildTree();
    bfs(root);
    cout << "-----------------------------" << endl;
    vector<int> ans = TopViewOfTreeIteratively(root);
    for(int x:ans){
        cout << x << " "; 
    }
    cout << endl << "-------------------------" << endl;
    return 0;
}