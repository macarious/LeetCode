/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head){

    // Iterate through the linked list.
    // Insert current node as needed (current node > next node)
    //      insert next node by comparing each node from the beginning.

    struct ListNode* curr = head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    while (curr && curr->next) {

        if (curr->val > curr->next->val) {
            struct ListNode* temp = curr->next;
            struct ListNode* target = dummy;

            while (temp->val > target->next->val) {
                target = target->next;
            }
            curr->next = temp->next;
            temp->next = target->next;
            target->next = temp;

        } else {
            curr = curr->next;
        }
    }
    struct ListNode* result = dummy->next;
    free(dummy);

    return result;

}