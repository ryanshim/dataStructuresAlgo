# Test Python implementation of a singly linked list
import unittest
from SLinkedList import SLinkedList

class TestSLinkedListMethods(unittest.TestCase):
    def  __init__(self, *args, **kwargs):
        super(TestSLinkedListMethods, self).__init__(*args, **kwargs)
        self.x = SLinkedList()

    def test_empty(self):
        self.assertEqual(self.x.empty(), True)

    def test_push_back(self):
        self.x.push_back(10)
        self.x.push_back(20)
        self.x.push_back(30)

    def test_front_back(self):
        self.x.push_back(10)
        self.x.push_back(20)
        self.x.push_back(30)
        self.assertEqual(self.x.front(), 10)
        self.assertEqual(self.x.back(), 30)

    def test_insert(self):
        self.x.push_back(10)
        self.x.push_back(20)
        self.x.push_back(30)
        self.assertEqual(self.x.front(), 10)
        self.assertEqual(self.x.back(), 30)

    def test_find(self):
        self.x.push_back(10)
        self.x.push_back(20)
        self.x.push_back(30)
        self.assertEqual(self.x.find(30).value, 30)

if __name__ == '__main__':
    unittest.main()
