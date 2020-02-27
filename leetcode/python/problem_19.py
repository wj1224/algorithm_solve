# Definition for singly-linked list.
# class ListNode:
#	  def __init__(self, x):
#		  self.val = x
#		  self.next = None

class Solution:
	def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
		if head.next is None:
			return None
		list_dict = {}
		
		node = head
		idx = 0
		while node is not None:
			list_dict[idx] = node
			idx += 1
			node = node.next
		N_node = len(list_dict)
		if n == 1:
			list_dict[N_node - 2].next = None
		elif N_node - n == 0:
			head = head.next
		else:
			list_dict[N_node - n - 1].next = list_dict[N_node - n + 1]
		
		return head
