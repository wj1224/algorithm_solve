# Definition for singly-linked list.
# class ListNode:
#	  def __init__(self, x):
#		  self.val = x
#		  self.next = None

class Solution:
	def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
		cur_l1 = l1
		cur_l2 = l2
		a = []
		b = []

		while True:
			a.append(cur_l1.val)
			cur_l1 = cur_l1.next
			if cur_l1 is None:
				break
			elif cur_l1.next is None:
				a.append(cur_l1.val)
				break
		
		while True:
			b.append(cur_l2.val)
			cur_l2 = cur_l2.next
			if cur_l2 is None:
				break
			elif cur_l2.next is None:
				b.append(cur_l2.val)
				break
		
		a.reverse()
		b.reverse()
		
		sum_ab = str(int(''.join(map(str, a))) + int(''.join(map(str, b))))
		sum_ab = sum_ab[::-1]

		l3 = ListNode(sum_ab[0])
		temp = l3
		for i in range(1, len(sum_ab)):
			temp.next = ListNode(sum_ab[i])
			temp = temp.next
			
		return l3
