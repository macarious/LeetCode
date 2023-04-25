/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root){

    // Check each node if it is a:
    // (1) Left child, value must be less than parent node.
    // (2) Right child, value must be greater than parent node.

    // Function to check if node is within upper- and lower-bounds.
    bool isValidSubTree(struct TreeNode* node, int* lower, int* upper) {
        if (!node) {
            return true;
        }

        if ((lower != NULL && node->val <= *lower)
            || (upper != NULL && node->val >= *upper)) {
            return false;
        }

        return isValidSubTree(node->left, lower, &node->val)
            && isValidSubTree(node->right, &node->val, upper);
    }

    return isValidSubTree(root, NULL, NULL);

}