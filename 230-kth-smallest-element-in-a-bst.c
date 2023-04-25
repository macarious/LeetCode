/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k) {

    // Smallest element is all the way to the leftmost node (with no left child).
    // Parent containing the "leftmost" child will has the next least value.
    // The right subtree will contain the next least value.
    // left subtree -> root -> right subtree (in-order DFS).

    // To keep track of how nodes we have visited.
    int counter = 0;

    // Traverse (in-order) recursively until counter == k.
    // Base case -- node is NULL.
    // (1) Traverese all the way to the left. Check objective.
    // (2) Increment counter by 1. Check objective. (return node).
    // (3) Traverse right subtree recursively.
    struct TreeNode* traverse(struct TreeNode* node) {
        if (!node) {
            return NULL;
        }

        struct TreeNode* left = traverse(node->left);
        
        if (counter == k) {
            return left;
        }
        
        counter++;

        if (counter == k) {
            return node;
        }

        return traverse(node->right);
    }

    return traverse(root)->val;
}