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

void dfs(TreeNode* root, int col , int level, map<pair<int, int>, vector<int>>&mp){
    if(root==nullptr){
        return;
    }

    mp[{col, level}].push_back(root->val);
    dfs(root->left, col-1, level+1, mp);
    dfs(root->right, col+1, level+1, mp);
}

vector<int>BottomViewOfTreeUsingMap(TreeNode* root){
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }

    map<pair<int, int>, vector<int>> mp;
    dfs(root, 0, 0, mp);

    map <int, int> ln;

    for(pair<pair<int, int>, vector<int>> x:mp){
        int col = x.first.first;
        ln[col] = x.second.back();
    }   
    
    for(pair<int, int> x:ln){
        ans.push_back(x.second);
    }

    return ans;

}

int main(){

    TreeNode* root = BuildTree();
    bfs(root);
    cout << "-----------------------------" << endl;
    vector<int> ans = BottomViewOfTreeUsingMap(root);
    for(int x:ans){
        cout << x << " "; 
    }
    cout << endl << "-------------------------" << endl;
    return 0;
}