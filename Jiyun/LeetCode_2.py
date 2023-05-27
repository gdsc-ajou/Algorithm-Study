# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        head = tail = ListNode()
        while l1 and l2:
            carry, num = divmod(l1.val + l2.val + carry, 10)
            tail.next = ListNode(num)
            tail = tail.next

            l1, l2 = l1.next, l2.next

        if l2:
            l1 = l2

        while l1:
            carry, num = divmod(l1.val + carry, 10)
            tail.next = ListNode(num)
            tail = tail.next

            l1 = l1.next
        
        if carry:
            tail.next = ListNode(carry)

        return head.next
        
