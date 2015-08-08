// Definition for a binary tree node.
#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) {
            return 1;
        } 

        int leftMin = INT_MAX;
        if(root->left != NULL) {
            leftMin = minDepth(root->left) + 1;
        }
        int rightMin = INT_MAX;
        if(root->right != NULL) {
            rightMin = minDepth(root->right) + 1; 
        }

        return leftMin<rightMin ? leftMin : rightMin;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode *node = new TreeNode(5);
	node->left = new TreeNode(4);
	node->right = new TreeNode(8);

	node->left->left = new TreeNode(11);

	// node->right->left = new TreeNode(13);
	// node->right->right = new TreeNode(4);

	// node->left->left->left = new TreeNode(7);
	// node->left->left->right = new TreeNode(2);

	// node->right->right->right = new TreeNode(1);

	Solution s;
	cout << s.minDepth(node) << endl;
	return 0;
}
