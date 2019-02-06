# Python implementation of a singly linked list
#
class Node:
    def __init__(self, value=None, nxt=None):
        self.value = value 
        self.next = nxt 

    def get_value(self):
        return self.value

    def get_next(self):
        return self.next

class SLinkedList:
    def __init__(self):
        self.linked_list = []

    def front(self):
        return self.linked_list[0].get_value()

    def back(self):
        return self.linked_list[len(self.linked_list)-1].get_value() 

    def push_back(self, value):
        obj = Node(value, None)
        self.linked_list.append(obj)

    def display(self):
        print('[', end='')
        for i in range(len(self.linked_list)-1):
            print(self.linked_list[i].get_value(), end=', ')
        print(self.linked_list[len(self.linked_list)-1].get_value(), end=']\n')

if __name__ == '__main__':
    foo = SLinkedList()
    for i in range(5):
        foo.push_back(i)

    foo.display() 

