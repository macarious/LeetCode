/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){

    if (!head || !head->next) {
        return head;
    }

    // Iterate through the linked list.
    // Pointer -- curr, to keep track of the current location.
    // Pointer -- prev, to keep track of nodes before curr for removal.

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr) {
        if (curr->next && curr->val == curr->next->val) {
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            } // curr is at last node of the subsequence.

            if (!prev) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
        } else {
            prev = curr;
        }
        curr = curr->next;
    }

    return head;

}