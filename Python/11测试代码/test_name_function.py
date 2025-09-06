import unittest

from name_function import get_formatted_name
class NamesTestCase(unittest.TestCase):
    def test_first_last_name(self):
        fomatted_name = get_formatted_name('wang', 'zixiang')
        self.assertEqual(fomatted_name, 'Wang Zixiang')

    def test_first_last_middle(self):
        fomatted_name = get_formatted_name('wang', 'xiang', 'zi')
        self.assertEqual(fomatted_name, 'Wang Zi Xiang')

if __name__ == '__main__':
    unittest.main()