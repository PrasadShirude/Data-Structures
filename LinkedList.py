class node:
	def __init__(self,data):
		self.data=data
		self.next=None
class Queue:
	def __init__(self):
		print("Inside Constructor")
		self.head=None
		self.iSize=0

	def enQueue(self,iNo):
		newn=node(iNo)
		temp=self.head
		if self.head==None:
			self.head=newn
		else:
			while temp.next!=None:
				temp=temp.next
			temp.next=newn
		self.iSize=self.iSize+1

	def deQueue(self):
		temp=None
		iRet=None

		if self.head==None:
			print("The Queue is empty")
			return iRet
		else:
			self.iSize=self.iSize-1
			temp=self.head
			self.head=self.head.next
			iRet=temp.data
			del temp
		return iRet
			
	def display(self):
		if self.head==None:
			print("The Queue is empty")
		else:
			temp=self.head
			while temp!=None:
				print(temp.data,end=" ")
				temp=temp.next

	def count(self):

		if self.head==None:
			print("The Queue is empty")
		else:
			return self.iSize

	def __del__(self):
		print("Inside Destructor")
		temp=None
		while self.head!=None:
			temp=self.head
			self.head=self.head.next
			del temp
