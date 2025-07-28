// Online C++ compiler to run C++ program online
#include<iostream> 
#include<vector> 
#include<queue> 

using namespace std; 

struct TreeNode{
public: 
      int val; 
      TreeNode* left; 
      TreeNode* right; 
      TreeNode(): val(0), left(nullptr), right(nullptr){}
      TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
      TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
};
class Solution{
public: 
      vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> res; 
        if(root==nullptr) return res; 
        queue<TreeNode*> q; 
        bool leftToRight = true; 
        q.push(root); 
        while(!q.empty()){
          int sz= q.size(); 
          vector<int> level(sz); 
          for(int i=0; i<sz; ++i){
            TreeNode* node= q.front(); 
            q.pop(); 
            int index = leftToRight? i : sz-i-i; 
            level[index] = node->val; 
            if(node->left) q.push(node->left); 
            if(node->right) q.push(node->right); 
          }
          res.push_back(level); 
          leftToRight = !leftToRight; 
        }
        return res; 
      }
};
int main(){
  TreeNode* root = new TreeNode(1); 
  root->left = new TreeNode(2); 
  root->right = new TreeNode(3); 
  root->left->left = new TreeNode(4); 
  root->left->right = new TreeNode(5); 
  root->right->left = new TreeNode(6); 
  root->right->right = new TreeNode(7); 
  Solution sol; 
  vector<vector<int>> res = sol.zigzagLevelOrder(root); 
  for(auto v:res){
    cout << "[" ; 
    for(int n:v){
      cout << n << "," ; 
    }
    cout << "]" ; 
  }
  cout << endl; 
  return 0; 
}
