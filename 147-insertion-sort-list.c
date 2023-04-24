/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head){

    struct ListNode* current = head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    // Iterate through the linked list.
    while (current && current->next) {

        // Check if the current node is greater than the next node.
        if (current->val > current->next->val) {
            struct ListNode* previous = dummy;
            struct ListNode* temp = current->next;

            // Iterate through the linked list to find the correct position.
            while (previous->next->val < temp->val) {
                previous = previous->next;
            }
            current->next = temp->next;
            temp->next = previous->next;
            previous->next = temp;
        } else {
            current = current->next;
        }
    }
    return dummy->next;
}