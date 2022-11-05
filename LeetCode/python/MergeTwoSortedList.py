# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        if list1!=None and list2!=None:
            if list1.val <= list2.val :
                head.val = list1.val
                head.next = None
                list1 = list1.next
            else:
                head.val = list2.val
                head.next = None
                list2 = list2.next
        it = head
        while list1!=None and list2!=None:
            if list1.val <= list2.val :
                it.next.val = list1.val
                list1 = list1.next
                it = it.next
            else:
                it.next.val = list2.val
                list1 = list1.next
                it = it.next

        if list1!=None:
            while list1!=None:
                it.next.val = list1.val
                list1 = list1.next
                it = it.next
        if list1!=None:
            while list2!=None:
                it.next.val = list2.val
                list1 = list2.next
                it = it.next

        return head
