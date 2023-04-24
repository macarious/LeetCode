
  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode next;
  };
 
struct ListNode sortList(struct ListNode head){

    if (!head  !head-next) {
        return head;
    }

    struct ListNode slow = head;
    struct ListNode fast = head-next;

     Find the mid point to divide the linked list into halves.
    while (fast && fast-next) {
        slow = slow-next;
        fast = fast-next-next;
    }

    struct ListNode mid = slow-next;
    slow-next = NULL;

     Merge two lists.
    struct ListNode merge(struct ListNode list1, struct ListNode list2) {
        
         Create pointers to the head and tail of the merged linked list.
        struct ListNode dummy = (struct ListNode)malloc(sizeof(struct ListNode));
        struct ListNode tail = dummy;

        while (list1 && list2) {
            if(list1-val  list2-val) {
                tail-next = list1;
                list1 = list1-next;
            } else {
                tail-next = list2;
                list2 = list2-next;
            }
            tail = tail-next;
        }

        if (!list1) {
            tail-next = list2;
        } else {
            tail-next = list1;
        }

        return dummy-next;
    }

     Sort the two halves recursively.
    return merge(sortList(head), sortList(mid));
}