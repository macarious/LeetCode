/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    // If the listSize is 0.
    if (listsSize == 0) {
        return NULL;
    }

    // If the listSize is 1.
    if (listsSize == 1) {
        return lists[0];
    }

    // Function that merges two sorted lists.
    struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }

        if (list2 == NULL) {
            return list1;
        }
        
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list2->next, list1); 
            return list2;
        }
    }

    int mid = listsSize / 2;

    // Merge left half with right half.
    struct ListNode* leftLists = mergeKLists(lists, mid);
    struct ListNode* rightLists = mergeKLists(lists + mid, listsSize - mid);
    return mergeTwoLists(leftLists, rightLists);

}