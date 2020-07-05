class Iterable:
    def __init__(self, content):
        self._content = content
        self._index = 0
        self._items = list(content)

    def __iter__(self):
        return self

    def __next__(self):
        self._index += 1
        if self._index >= len(self._items):
            raise StopIteration
        return self._items[self._index]

    def __len__(self):
        return len(self._items)

    def __getitem__(self, key):
        return self._items[key]

    def __setitem__(self, key, item):
        self._items[key] = item

    def __delitem__(self, key):
        del (self._items[key])

    def __eq__(self, lst):
        return self._items == lst

    def __str__(self):
        return str(self._items)

    def shell_sort(self, compare_function):
        gap = int(len(self._items) // 2)
        while gap > 0:
            for index in range(gap, len(self._items)):
                elem = self._items[index]
                second_index = index
                while second_index >= gap and compare_function(self._items[second_index - gap], elem) != True:
                    self._items[second_index] = self._items[second_index - gap]
                    second_index -= gap
                self._items[second_index] = elem
            gap = int(gap // 2)

    def filter(self, acceptance_function):

        for i in range(len(self._items) - 1, -1, -1):
            if acceptance_function(self._items[i]) != True:
                self._items.remove(self._items[i])
        return self._items
