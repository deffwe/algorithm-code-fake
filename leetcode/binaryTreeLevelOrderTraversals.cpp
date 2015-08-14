#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<int> rowNodes;
        vector<vector<int> > colNodes;
        queue<TreeNode*> q;
        vector<TreeNode*> vec;

        if(root != NULL) {
            rowNodes.push_back(root->val);
            colNodes.push_back(rowNodes);
        }

        q.push(root);
        while(q.size()>0) {
            TreeNode* p = q.front();
            q.pop(); 
            vec.push_back(p);
            if(p == NULL) {
                continue;
            }
            q.push(p->left);
            q.push(p->right);
        }

        int j=0, step =2;
        /*for(vector<TreeNode*>::iterator it=vec.begin(); it!=vec.end(); ++it) {
            if(*it!=NULL){
            cout << (*it)->val << " ";}
            else 
            cout << 0 << " ";
        }*/

        for(int i=1; i<vec.size(); i=j) {
            rowNodes.clear();

            int count = 0;
            for(j=i; j<i+step && j<vec.size(); ++j) {
                if(vec[j]) {
                    rowNodes.push_back(vec[j]->val);
                    count += 2;
                }
            } 
            step = count;
            if(rowNodes.size() > 0) {
                colNodes.push_back(rowNodes);
            }
        }

        reverse(colNodes.begin(), colNodes.end());
        return colNodes;
    }
};

int main() {
    TreeNode *node = new TreeNode(5);
    node->left = new TreeNode(4);
    node->right = new TreeNode(8);

    node->left->left = new TreeNode(11);

    node->right->left = new TreeNode(13);
    node->right->right = new TreeNode(4);

    node->left->left->left = new TreeNode(7);
    node->left->left->right = new TreeNode(2);

    node->right->right->right = new TreeNode(1);

    Solution s;
    vector<vector<int> > res = s.levelOrderBottom(node);
    for(vector<vector<int> >::iterator it=res.begin(); it != res.end(); ++it) {
        for(vector<int>::iterator jt=(*it).begin(); jt != (*it).end(); ++jt) {
            cout << *jt << " ";
        }
        cout << "\n";
    }
    return 0;
}
