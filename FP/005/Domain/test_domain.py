import unittest
from Domain.domain import Clients, Books, Rentals


class TestClients(unittest.TestCase):
       def test_name__GoodInput__ReturnsValue(self):
           test=Clients('1', 'Alex')
           self.assertEqual(test.name, 'Alex')

       def test_id__GoodInput__ReturnsValue(self):
           test=Clients('1', 'Alex')
           self.assertEqual(test.id, '1')

       def test_set_name__GoodInput__ReturnsValue(self):
           test=Clients(1, 'Alex')
           test.set_name('l')
           self.assertEqual(test.name, 'l')

       def test__str__GoodInput__CreatesFine(self):
           test=Clients('1', 'Bau')
           self.assertTrue(test.__str__,'1 --> Bau')

class TestBooks(unittest.TestCase):
    def  test_id_GoodInput__ReturnsValue(self):
        test=Books('1','The book', 'the author')
        self.assertEqual(test.id, '1')

    def test_title_GoodInput__ReturnsValue(self):
        test=Books('1','The book', 'the author')
        self.assertEqual(test.title, 'The book')

    def test_author__GoodInput__ReturnsValue(self):
        test=Books('1','The book', 'the author')
        self.assertEqual(test.author, 'the author')

    def test_set_title_GoodInput_ChangesTitle(self):
        test=Books('1', 'The book', 'the author')
        test.set_title('bau')
        self.assertEqual(test.title, 'bau')

    def test_set_author__GoodInput__ChangesAuthor(self):
        test=Books('1', 'the book', 'the author')
        test.set_author('author')
        self.assertEqual(test.author, 'author')

    def test__str__GoodInput__PrintsFine(self):
        test= Books('1', 'The book', 'The author')
        self.assertTrue(test.__str__, '1-> "The book" by The author')



class TestRentals(unittest.TestCase):
    def test_rental_id__GoodInput__ReturnsValue(self):
        test=Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        self.assertEqual(test.rental_id, '1')

    def test_book_id__GoodInput__ReturnsValue(self):
        test = Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        self.assertEqual(test.book_id, '1')

    def test_client_id__GoodInput__ReturnsValue(self):
        test = Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        self.assertEqual(test.client_id, '1')

    def test_return_date__GoodInput__ReturnsValue(self):
        test = Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        self.assertEqual(test.returned_date, '7/2/2010')

    def test_rent_date__GoodInput__ReturnsValue(self):
        test = Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        self.assertEqual(test.rented_date, '1/2/2010')

    def test_set_book_id__GoodInput__ChangesID(self):
        test = Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        test.set_book_id('2')
        self.assertEqual(test.book_id, '2')

    def test_set_client_id__GoodInput__ChangesID(self):
        test = Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        test.set_client_id('2')
        self.assertEqual(test.client_id, '2')
    def test_set_returned_date__GoodInput__ChangesReturningDate(self):
        test = Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        test.set_returned_date('2/3/2011')
        self.assertEqual(test.returned_date, '2/3/2011')

    def test_set_rented_date__GoodInput__ChangesRentingDate(self):
        test = Rentals('1', '1', '1', '1/2/2010', '7/2/2010')
        test.set_rented_date('1/1/2010')
        self.assertEqual(test.rented_date, '1/1/2010')

    def test__str__GoodInput__PrintsFine(self):
        test=Rentals('1', '1' ,'1', '1/1/2010', '2/2/2010')
        self.assertTrue(test.__str__, 'ID: 1 The book s ID is 1 The client s ID is 1 The rented date is 1/1/2010 The returned date is 2/2/2010')




if __name__ == '__main__':
    unittest.main()
