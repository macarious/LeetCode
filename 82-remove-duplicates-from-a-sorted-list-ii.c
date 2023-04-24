/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){

    // Edge case where list has a size of 0 or 1.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Keep track of the current node.
    struct ListNode* current = head;

    // Keep track of previous node.
    struct ListNode* previous = NULL;

    // Iterate through the linked-list.
    while (current != NULL) {
        // Check if current node is unique by comparing with next node.
        if (current->next != NULL && current->val == current->next->val) {
            // Move current node to the last duplicate node.
            while (current->next != NULL && current->val == current->next->val) {
                current = current->next;
            }

            // Remove all duplicate values by updating our pointers.
            // (1) If first node is a duplicate, reassign the head.
            // (2) Otherwise, append unique node to head.
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
        } else {
            // Update previous pointer.
            previous = current;
        }
        current = current->next;
    }
    return head;
}