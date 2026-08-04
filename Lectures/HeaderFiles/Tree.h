#include "TreeNode.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

TreeNode<int> *BuildTree() {
  int x;
  cin >> x;

  if (x == -1) {
    return nullptr;
  }

  TreeNode<int> *n = new TreeNode<int>(x);
  n->left = BuildTree();
  n->right = BuildTree();

  return n;
}

void Preorder(TreeNode<int> *root) {
  if (root == nullptr) {
    return;
  }

  cout << root->val << " ";
  Preorder(root->left);
  Preorder(root->right);
}

void Inorder(TreeNode<int> *root) {
  if (root == nullptr) {
    return;
  }

  Inorder(root->left);
  cout << root->val << " ";
  Inorder(root->right);
}

void Postorder(TreeNode<int> *root) { 
  if (root == nullptr) {
    return;
  }

  Postorder(root->left);
  Postorder(root->right);

  cout << root->val << " ";
}

int CountofNodes(TreeNode<int> *root) {
  if (root == nullptr) {
    return 0;
  }

  int LSN = CountofNodes(root->left);
  int RSN = CountofNodes(root->right);

  int ans = 1 + LSN + RSN;
  return ans;
}

int SumofNodes(TreeNode<int> *root) {
  if (root == nullptr) {
    return 0;
  }

  int LSS = SumofNodes(root->left);
  int RSS = SumofNodes(root->right);

  int ans = root->val + LSS + RSS;
  return ans;
} 

int Height(TreeNode<int> *root) {
  if (root == nullptr) {
    return 0;
  }

  int LSH = Height(root->left);
  int RSH = Height(root->right);

  int ans = 1 + max(LSH, RSH);
  return ans;
}

// Computations :
// You are going to every node : Total Number of NOdes : n
// After going to every node :
// 1. You call in left subtree to find the diameter:
// 2. You call in the right subtree to find the diameter:
// 3. Left Subtree ki height nikalta hu and right subtree ki height nikalta hu:
// Mujhe height of a tree nikalne nikalme kitna time lagega. (~n)
//
// ~n*n
// Post Order Traversal:
int Diameter(TreeNode<int> *root) {

  if (root == nullptr) {
    return 0;
  }
  // Current Node ke respect aap diameter nikalo left subtree me.
  int Op1 = Diameter(root->left);

  // Current Node ke respect aap diameter nikalo right subtree me.
  int Op2 = Diameter(root->right);

  // Current Node ke respect me aap bolo diameter passes through
  //  the root node:
  int Op3 = Height(root->left) + Height(root->right);

  return max({Op1, Op2, Op3});
}

// From this function we are computing the height (ans simultaenoussly build dimater) only and
//  we are saying that since the diameter will pass through the
//  root node for one of the nodes, we are just computing option 3 for every
//  node and building height throught height function:
// Computations :  ~n :
int diameter = 0;
int HeightDiameter(TreeNode<int> *root) {
  if (root == nullptr) {
    return 0;
  }

  int LSH = HeightDiameter(root->left);
  int RSH = HeightDiameter(root->right);

  // Current node ke respect me option 3 nikalna hain and
  //  usko maximum se update karna hain: Ye contribution rahega mera
  // diameter me.

  int Op3 = LSH + RSH;
  diameter = max(diameter, Op3);

  // We are computing the height of the tree:
  return 1 + max(LSH, RSH);
}

class Pair {
public:
  int diameter;
  int height;

  Pair() {
    diameter = 0;
    height = 0;
  }
};
// Computations : ~n:
Pair Diamter03(TreeNode<int> *root) {
  Pair p;
  if (root == nullptr) {
    p.height = 0;
    p.diameter = 0;
    return p;
  }

  Pair LSI = Diamter03(root->left);
  Pair RSI = Diamter03(root->right);

  // Build the height and diameter simultaneously:
  p.height = 1 + max(LSI.height, RSI.height);

  int Op1 = LSI.diameter;
  int Op2 = RSI.diameter;
  int Op3 = LSI.height + RSI.height;

  p.diameter = max({Op1, Op2, Op3});

  return p;
}

pair<int, bool> IsHeightBalanced(TreeNode<int> *root) {
  pair<int, bool> p;
  if (root == nullptr) {
    p.first = 0; 
    p.second = 1; // Khali node hamesha height balanced hota hain.
    return p;
  }

  pair<int, bool> LSI = IsHeightBalanced(root->left);
  pair<int, bool> RSI = IsHeightBalanced(root->right);

  // Build the height first:
  p.first = 1 + max(LSI.first, RSI.first);

  // Check if the tree till the current node is height balanced or not:
  bool Op1 = LSI.second;
  bool Op2 = RSI.second;
  bool Op3 = 0;

  // Check if the current node is height balanced or not?
  if (abs(LSI.first - RSI.first) <= 1) {
    Op3 = 1;
  } else {
    Op3 = 0;
  }

  // How I can say ki mera tree till this point is height balanced or not?
  if (Op1 == 1 and Op2 == 1 and Op3 == 1) {
    p.second = 1;
  } else {
    p.second = 0;
  }

  return p;
}

// Mirror Image of this Tree:
void Mirror(TreeNode<int> *root) {
  if (root == nullptr) {
    return;
  }

  Mirror(root->left);
  Mirror(root->right);
  swap(root->left, root->right);
}

// Left View of the Tree:
void LeftView(TreeNode<int> *root, int level, int &maxlevel) {
  if (root == nullptr) {
    return;
  }

  if (maxlevel < level) {
    cout << root->val << " ";
    maxlevel = level;
  }

  LeftView(root->left, level + 1, maxlevel);
  LeftView(root->right, level + 1, maxlevel);
}

// Right View of the Tree:
void RightView(TreeNode<int> *root, int level, int &maxlevel) { 
  if (root == nullptr) {
    return;
  }

  if (maxlevel < level) {
    cout << root->val << " ";
    maxlevel = level;
  }

  RightView(root->right, level + 1, maxlevel);
  RightView(root->left, level + 1, maxlevel);
}

// for binary tree only not bianry search tree
TreeNode<int> *BuildFromArray(vector<int> &a, int s, int e) {
  if (s > e) {
    return nullptr;
  }

  int mid = (s + e) / 2;
  TreeNode<int> *r = new TreeNode<int>(a[mid]);
  r->left = BuildFromArray(a, s, mid - 1);
  r->right = BuildFromArray(a, mid + 1, e);

  return r;
}


// Index is for traversal over the preorder vector
//  s and e are for the inorder range or they tell us that in the given subtree
//  which range of nodes we can attach:
TreeNode<int> *BuildTreeFromPreAndIn(vector<int> &pre, vector<int> &in, int s, int e, int &index) {
  if (s > e) {
    return nullptr;
  }

  TreeNode<int> *r = new TreeNode<int>(pre[index]);
  // Current range of elements this r can have is from s to e.

  // First Build the Left side of the tree why? because we are traversing over
  // the preorder vector through index variable.
  // Mujhe ye to pata hain ki r ke left aur right me kya nodes jaayenge but
  // abhi ye nahi pata ki konse node left me jaayenge and konse node right
  // me jaayenge, ye cheez kaise pata karu?

  // Idea : Aap current r/pre[index] ko inorder vector me dhundo and jo jo nodes
  //  left me hain is pre[index] ke vo left side me jaayenge r ke and jo jo
  //  node right me hain vo right side me jaayenge r ke.

  // Important Point to note : r ke left me s index se lekar pre[index] vala
  // index in inorder tak element jaayenge r ke left me and similarly pre[index]
  // vala index se lekar e index tak jaayenge r ke right me.

  int target_index = -1;
  for (int j = s; j <= e; j++) {
    if (in[j] == pre[index]) {
      target_index = j;
      break;
    }
  }

  index++; // Preorder ka index agli recursion call ke liye ++ kardo.

  r->left = BuildTreeFromPreAndIn(pre, in, s, target_index - 1, index);
  r->right = BuildTreeFromPreAndIn(pre, in, target_index + 1, e, index);

  return r;
}

TreeNode<int> *BuildLevelOrderusingRecursion(vector<int> &a, int index) {

  if (index >= a.size() or a[index] == -1) {
    return nullptr;
  }

  TreeNode<int> *root = new TreeNode<int>(a[index]);
  root->left = BuildLevelOrderusingRecursion(a, 2 * index + 1);
  root->right = BuildLevelOrderusingRecursion(a, 2 * index + 2);

  return root;
}

// Computations : ~n  : Extra Space : Stack : height of the tree
void InorderIterative(TreeNode<int> *root) {
  stack<TreeNode<int> *> st;
  TreeNode<int> *current = root;

  // Initially Current is 7 and ye sabse pehla node hai  and stack khali
  //  hain:

  while (current != nullptr or !st.empty()) { // and

    // Go to the leftmost branch and visit every node.
    while (current != nullptr) {
      st.push(current);
      current = current->left;
    }

    // Current is Nullptr here: so we pop the element and continue the
    // process:
    current = st.top();
    st.pop();
    // You are at root : print this node:
    cout << current->val << " ";

    // Move to the right of this node: Right Subtree par jao:
    current = current->right;
  }
}
// Morris Traversal : Time : ~n and space constant:

void PrintKthLevel(TreeNode<int> *root, int k) {
  if (root == nullptr) {
    return;
  }

  if (k == 0) {
    cout << root->val << " ";
    return;
  }

  // If I am standing here:
  PrintKthLevel(root->left, k - 1);
  PrintKthLevel(root->right, k - 1);
}

// Computations : h*n
void PrintAllLevel(TreeNode<int> *root) {
  if (root == nullptr) {
    return;
  }
  // How many levels are there in a tree :
  int HeightofTree = Height(root);

  // Height is calculated on 1 basedand we are currently
  //  calculating level by zero based :

  for (int i = 0; i < HeightofTree; i++) {
    PrintKthLevel(root, i);
    cout << endl;
  }
}

void bfs(TreeNode<int> *root) {
  if (root == nullptr) {
    return;
  }
  queue<TreeNode<int> *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode<int> *f = q.front();
    q.pop();

    cout << f->val << " ";
    if (f->left != nullptr) {
      q.push(f->left);
    }
    if (f->right != nullptr) {
      q.push(f->right);
    }
  }
}

void bfs02(TreeNode<int> *root) {
  if (root == nullptr) {
    return;
  }
  queue<TreeNode<int> *> q;
  q.push(root);
  q.push(nullptr); // One level is finished and we insert a blocker.

  while (!q.empty()) {
    TreeNode<int> *f = q.front();
    q.pop();
    if (f == nullptr) {
      if (!q.empty()) {
        q.push(nullptr);
      }
      cout << endl;
    } else {

      cout << f->val << " ";
      if (f->left != nullptr) {
        q.push(f->left);
      }
      if (f->right != nullptr) {
        q.push(f->right);
      }
    }
  }
}

vector<vector<int>> bfs03(TreeNode<int> *root) {
  // This vector of vector will store all the nodes ki value:
  vector<vector<int>> ans;  

  // This vector will store the current level nodes ki value.
  vector<int> current;

  if (root == nullptr) {
    return ans;
  }

  queue<TreeNode<int> *> q;
  q.push(root);
  q.push(nullptr); // One level is finished and we insert a blocker.

  while (!q.empty()) {
    TreeNode<int> *f = q.front();
    q.pop();
    if (f == nullptr) {
      // Previous Level is finished.
      // Previous level ke saare nodes the vo humne current vector me daal diya
      // hain.
      ans.push_back(current);
      current.clear();

      if (!q.empty()) {
        q.push(nullptr);
      }
    } else {

      current.push_back(f->val);

      if (f->left != nullptr) {
        q.push(f->left);
      }
      if (f->right != nullptr) {
        q.push(f->right);
      }
    }
  }

  return ans;
}

TreeNode<int> *BuildFrombfsIteratively(vector<int> &a) {
  if (a.empty() == 1) {
    return nullptr;
  }
  int i = 1; // This is to iterate over the original array.
  TreeNode<int> *root = new TreeNode<int>(a[0]);
  queue<TreeNode<int> *> q;
  q.push(root);

  while (i < a.size() and !q.empty()) {
    TreeNode<int> *f = q.front();
    q.pop();

    // Mujhe is f ke left and right side nodes ko insert
    //  karna hain.

    // This is for left subtree of f.
    if (a[i] != -1) {
      f->left = new TreeNode<int>(a[i]);
      q.push(f->left);
    }

    i++;
    // This is for right subtree of f.
    if (i < a.size() and a[i] != -1) {
      f->right = new TreeNode<int>(a[i]);
      q.push(f->right);
    }

    i++;
  }

  return root;
} 

// You are going to every node and left subtree par call, right subtree par call
// and max.
//  ~n

TreeNode<int> *InsertInBst(TreeNode<int> *root, int value) {

  if (root == nullptr) {
    // TreeNode<int> *NewNode = new TreeNode<int>(value);
    // return NewNode;
    return new TreeNode<int>(value);
  }

  if (root->val < value) {
    root->right = InsertInBst(root->right, value);
  } else {
    root->left = InsertInBst(root->left, value);
  }

  return root;
}

TreeNode<int> *BuildBst(vector<int> &values) {
  TreeNode<int> *root = nullptr;

  for (int x : values) {
    root = InsertInBst(root, x);
  }
  return root;
}

bool SearchInBst(TreeNode<int> *root, int key) {
  if (root == nullptr) {
    return false;
  }

  if (root->val == key) {
    return true;
  }

  if (root->val < key) {
    return SearchInBst(root->right, key);
  } else {
    return SearchInBst(root->left, key);
  }
}

TreeNode<int> *FindMin(TreeNode<int> *root) {

  while (root->left != nullptr) {
    root = root->left;
  }

  // Jis node par aap abhi khade ho vahi minimum hain as hum bst me hain.
  return root;
}

TreeNode<int> *DeleteInBst(TreeNode<int> *root, int target) {
  if (root == nullptr) {
    return nullptr;
  }

  // Search for this root:
  if (root->val > target) {
    root->left = DeleteInBst(root->left, target);
  } else if (target > root->val) {
    root->right = DeleteInBst(root->right, target);
  } else {
    // You have found the element :
    // Case 01 : Leaf Node :
    if (root->left == nullptr and root->right == nullptr) {
      delete root;
      return nullptr;
    }

    // Case 02  : One Child is there of this current node which you want to
    // delete.
    if (root->left == nullptr) {
      // Right Child exists:
      TreeNode<int> *temp = root->right;
      delete root;

      return temp;
    }

    if (root->right == nullptr) {
      // Left Child exists:
      TreeNode<int> *temp = root->left;
      delete root;

      return temp;
    }

    // Case 03 : There are two child of this current node which you want to
    // delete.
    TreeNode<int> *InorderSuccessor = FindMin(root->right);
    root->val = InorderSuccessor->val;
    root->right = DeleteInBst(root->right, InorderSuccessor->val);
  }

  return root;
}

int kthSmallest(TreeNode<int> *root, int &k) {} // reverse inorder counting

// check if current tree is BST or not - (inorder = check sorted or not)

// print leaf nodes in bst

// print left/right boundary bst or bt


TreeNode<int> *lowestCommonAncestor(TreeNode<int> *root, TreeNode<int> *p,  TreeNode<int> *q) { 

  if (root == nullptr) {
    return nullptr;
  }

  if (root->val == p->val or root->val == q->val) {
    // I will not go below this level saying ki mera potential lca root hi hain.
    return root;
  }

  TreeNode<int> *leftlca = lowestCommonAncestor(root->left, p, q);
  TreeNode<int> *rightlca = lowestCommonAncestor(root->right, p, q);

  // Current root ka lca calculate hoga:
  if (leftlca != nullptr and rightlca != nullptr) {
    return root;
  }

  if (leftlca == nullptr and rightlca != nullptr) {
    return rightlca;
  } else {
    return leftlca;
  }
}

// Homework :
// STL : Associative Containers and Trees Part 02 : Trees with STL:
// Trees Part 03 : Dp on Trees:

vector<int> MorrisInorder(TreeNode<int>* root){
  vector<int>inorder;
  TreeNode<int>* curr = root;
  while(curr!=nullptr){
    if(curr->left == nullptr){
      inorder.push_back(curr->val);
      curr = curr->right;
    } else{
      TreeNode<int>* prev = curr->left;
      while(prev->right && prev->right!=curr){
        prev = prev->right;
      }
      if(prev->right==nullptr){
        prev->right= curr;
        curr = curr->left;
      } else{
        prev->right = nullptr;
        inorder.push_back(curr->val);
        curr= curr->right;
      }
    }
  }
  return inorder;
}

vector<int> MorrisPreorder(TreeNode<int>* root){
  vector<int>inorder;
  TreeNode<int>* curr = root;
  while(curr!=nullptr){
    if(curr->left == nullptr){
      inorder.push_back(curr->val);
      curr = curr->right;
    } else{
      TreeNode<int>* prev = curr->left;
      while(prev->right && prev->right!=curr){
        prev = prev->right;
      }
      if(prev->right==nullptr){
        prev->right= curr;
        inorder.push_back(curr->val);
        curr = curr->left;
      } else{
        prev->right = nullptr;
        inorder.push_back(curr->val);
        curr= curr->right;
      }
    }
  }
  return inorder;
}

