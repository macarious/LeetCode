/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

    if (listsSize == 0) {
        return NULL;
    }

    if (listsSize == 1) {
        return lists[0];
    }

    // Divide and conquer approach.
    // Divide the k-number of lists into smaller subproblems (divide in halves).
    // Merge them back together using merge sort.

    // Find the midpoint.
    int m = listsSize / 2;

    // Merge two linked lists (l1, l2).
    struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
        // Dummy pointer to store the merged list.
        // Tail pointer to store the end of the merged list.
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

        struct ListNode* mergedList = dummy->next;
        free(dummy);
        return mergedList;
    }

    return merge(mergeKLists(lists, m), mergeKLists(lists + m, listsSize - m));
}