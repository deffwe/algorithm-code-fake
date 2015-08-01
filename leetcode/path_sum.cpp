#include <iostream>
#include <stdlib.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
        	return false;
        }

        if(sum == root->val) {
        	return true;
        }
        hasPathSum(root->left, sum - root->val);
        hasPathSum(root->right, sum - root->val);
    }
};

int main(int argc, char** argv) {
	int sum = 10;
	if(argc > 1) {
		sum = atoi(argv[1]);
	}
	Solution s;

	TreeNode node = new TreeNode(5);
	node.left = new TreeNode(4);
	node.right = new TreeNode(8);

	node.left.left = new TreeNode(11);

	node.right.left = new TreeNode(13);
	node.right.right = new TreeNode(4);

	node.left.left.left = new TreeNode(7);
	node.left.left.right = new TreeNode(2);

	node.right.right.right = new TreeNode(1);

	cout << s.hasPathSum(node, 22) << endl;
	return 0;
}