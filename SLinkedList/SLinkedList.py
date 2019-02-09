# Python implementation of a singly linked list
#
class Node:
    def __init__(self, value=None, nxt=None):
        self.value = value 
        self.next = nxt 

class SLinkedList:
    def __init__(self):
        self.n = 0
        self.head = None

    def empty(self):
        return (self.n == 0)

    def front(self):
        return self.head.value

    def back(self):
        node = self.head
        while node.next is not None:
            node = node.next
        return node.value

    def find(self, search_val):
        node = self.head
        while node is not None:
            if node.value == search_val:
                return node
            node = node.next
        return None 

    def insert(self, value, index):
        if self.n == 0:
            self.head = Node(value)
        else:
            prev = self.head
            count = 0
            while count < index:
                prev = prev.next
                count += 1
            temp = Node(value, prev.next)
            prev.next = temp

    def push_back(self, value):
        if self.n == 0:
            self.head = Node(value)
        else:
            node = self.head
            while node.next:
                node = node.next
            temp = Node(value)
            node.next = temp
        self.n += 1

    def display(self):
        node = self.head
        print('[', end='')
        while node.next is not None:
            print(node.value, end=' --> ')
            node = node.next
        print(node.value, end=']\n')
