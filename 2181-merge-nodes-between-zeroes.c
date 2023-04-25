/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head){

    // Two pointers:
    // (1) To keep track of current location in linked list.
    // (2) To keep track of tail.

    struct ListNode* tail = head;
    struct ListNode* curr = tail->next;

    // Iterate through all nodes in linked list:
    // (1) If tail->val == 0:
    //      Traverse through all non-zero node
    //      Accumulate the sum;
    //      Skip over the entire subsequence.
    // (2) If curr->next is NULL:
    //      Break off saved linked list by inserting a NULL.
    // (3) If curr->val == 0 (and it's not the last node):
    //      Connect the tail->next to current.
    //      Connect the tail to current.
    while (curr) {
        if (tail->val == 0) {
            while (curr->val != 0) {
                tail->val += curr->val;
                curr = curr->next;
            }
        }

        if (!curr->next) {
            tail->next = NULL;
            break;
        }

        if (curr->val == 0) {
            tail->next = curr;
            tail = curr;
        }
        curr = curr->next;
    }
    return head;
}