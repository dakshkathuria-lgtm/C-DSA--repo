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

void dfs(TreeNode* root, int col , int level, multimap<pair<int, int>, int>&mp){
    if(root==nullptr){
        return;
    }

    mp.insert({{col, level}, root->val});
    dfs(root->left, col-1, level+1, mp);
    dfs(root->right, col+1, level+1, mp);
}

vector<int>TopViewOfTreeUsingMultiMap(TreeNode* root){
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }

    multimap<pair<int, int>, int> mp;
    dfs(root, 0, 0, mp);

    int FirstVisit = INT_MIN;
    for(multimap<pair<int, int>, int>::iterator x=mp.begin();x!=mp.end();x++){
        int CurrentCol = (*x).first.first;
        int level = x->first.second;
        int val = x->second;
        if(CurrentCol!=FirstVisit){
            ans.push_back(val);
            FirstVisit = CurrentCol;
        }
    }   
    return ans;
}

int main(){

    TreeNode* root = BuildTree();
    bfs(root);
    cout << "-----------------------------" << endl;
    vector<int> ans = TopViewOfTreeUsingMultiMap(root);
    for(int x:ans){
        cout << x << " "; 
    }
    cout << endl << "-------------------------" << endl;
    return 0;
}