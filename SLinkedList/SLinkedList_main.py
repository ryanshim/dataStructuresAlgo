# Test Python implementation of a singly linked list
import unittest
from SLinkedList import SLinkedList

class TestSLinkedListMethods(unittest.TestCase):
    def test_empty(self):
        x = SLinkedList()
        self.assertEqual(x.empty(), True)

    def test_insert(self):
        x = SLinkedList()
        x.push_back(10)
        x.push_back(20)
        x.push_back(30)
        self.assertEqual(x.front(), 10)
        self.assertEqual(x.back(), 30)

    def test_find(self):
        x = SLinkedList()
        x.push_back(10)
        x.push_back(20)
        x.push_back(30)
        self.assertEqual(x.find(30).value, 30)

if __name__ == '__main__':
    unittest.main()
