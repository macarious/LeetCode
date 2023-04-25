/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head){


    // Divide-and-conquer approach such as merge sort.
    // Split the linked-list into small subproblems (halves) recursively.
    // We merge them back into one linked list.

    if (!head) {
        return NULL;
    }

    if (!head->next) {
        return head;
    }

    // Find mid point of linked list, use slow and fast pointer.
    // Fast pointer to traverse at twice the rate of the slow pointer.
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* mid = slow->next;
    slow->next = NULL;

    // Write a merge function to merge two linked lists.
    // Take two linked lists as parameters, and return a merged/sorted linked list.
    struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
        // Create a dummy node to store the sorted/merged list.
        struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* tail = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (!l1) {
            tail->next = l2;
        } else {
            tail->next = l1;
        }

        struct ListNode* sorted_list = dummy->next;
        free(dummy);
        return sorted_list;
    }

    // Divide problem into halves, and recursively call sortList on 2 subproblems.
    // Merge.
    return merge(sortList(head), sortList(mid));
}