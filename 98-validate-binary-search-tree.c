/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root){

    bool isValidBSTBounds(struct TreeNode* root, int* min, int* max) {
        if (root == NULL) {
            return true;
        }

        // Check if the root node is between min and max values.
        if ((min != NULL && root->val <= *min) || (max != NULL && root->val >= *max)) {
            return false;
        }

        return isValidBSTBounds(root->left, min, &root->val) && isValidBSTBounds(root->right, &root->val, max);
    }

    // Recursively call the helper function to check the entire tree.
    return isValidBSTBounds(root, NULL, NULL);
}