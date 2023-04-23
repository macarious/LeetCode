/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    // Divide and conquer.

    // Base Case 1: no lists are left.
    if (listsSize == 0) {
        return NULL;
    }

    // Base Case 2: 1 list left.
    if (listsSize == 1 ){
        return lists[0];
    }

    // Split k number of lists in half.
    // Merge them recursively when we have more than two lists.
    int mid = listsSize / 2;
    struct ListNode* leftList = mergeKLists(lists, mid);
    struct ListNode* rightList = mergeKLists(lists + mid, listsSize - mid);

    // When we have two lists, we merge the elements.
    struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        // Keep track of the new sorted linked list.
        struct ListNode dummyNode;
        dummyNode.next = NULL;
        struct ListNode* tail = &dummyNode;

        while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
        }

        if (list1 == NULL) {
            tail->next = list2;
        } else {
            tail->next = list1;
        }
        return dummyNode.next;
    }

    return mergeTwoLists(leftList, rightList);
}