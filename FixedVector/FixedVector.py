# Fixed vector class implementation in Python.
# 
class FixedVector:
    def __init__(self, length, fv_origin=None):
        self.length = length
        self.num_elts = 0
        if fv_origin is None:
            self.fixed_vector = [None for i in range(self.length)]
        else:
            self.num_elts = fv_origin.get_num_elts()
            self.fixed_vector = self.copy(fv_origin)

    def copy(self, original):
        return [x for x in original]

    def get_length(self):
        return len(self.fixed_vector)

    def get_num_elts(self):
        return self.num_elts

    def empty(self):
        return (self.get_num_elts() == 0)

    def get(self, index):
        if index > self.length-1 or index < 0:
            raise OverflowError
        return self.fixed_vector[index]

    def set(self, index, value):
        if index > self.length-1 or index < 0:
            raise OverflowError
        self.fixed_vector[index] = value
        self.num_elts += 1

    def display(self):
        print([x for x in self.fixed_vector])

    def __getitem__(self, index):
        return self.fixed_vector[index]
