# Test Python version of a fixed vector.
import unittest
from FixedVector import FixedVector

class TestFixedVectorMethods(unittest.TestCase):
    def test_set(self):
        foo = FixedVector(5)
        for i in range(foo.get_length()):
            foo.set(i, i*10)

    def test_get_length(self):
        foo = FixedVector(5)
        self.assertEqual(foo.get_length(), 5)

    def test_empty(self):
        foo = FixedVector(5)
        self.assertEqual(foo.empty(), True)
        foo.set(2, 20)
        self.assertEqual(foo.empty(), False)

    def test_get(self):
        foo = FixedVector(5)
        foo.set(3, 30)
        self.assertEqual(foo.get(3), 30)

    @unittest.expectedFailure
    def test_set_failure(self):
        foo = FixedVector(5)
        self.assertEqual(foo.set(-1, 10), None)

if __name__ == '__main__':
    unittest.main()
