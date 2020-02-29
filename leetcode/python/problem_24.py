# Definition for singly-linked list.
# class ListNode:
#	  def __init__(self, x):
#		  self.val = x
#		  self.next = None

class Solution:
	def swapPairs(self, head: ListNode) -> ListNode:
		cur_node = head
		idx = 0
		
		while cur_node is not None:
			next_node = cur_node.next
			if idx % 2 == 0:
				temp = cur_node
				if cur_node.next is None:
					pass
				elif cur_node.next.next is not None:
					if cur_node.next.next.next is not None:
						cur_node.next = cur_node.next.next.next
					else:
						cur_node.next = cur_node.next.next
				else:
					cur_node.next = None
			else:
				cur_node.next = temp
			if idx == 1:
				head = cur_node
			cur_node = next_node
			idx += 1
			
		return head
