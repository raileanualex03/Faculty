import unittest

from Domain.domain import Room, Reservations


class TestRoom(unittest.TestCase):
    def test_number__GoodInput__CreatesEntity(self):
        room = Room(1, 2)
        self.assertAlmostEqual(room.number, 1)

    def test_size__GoodInput__CreatesEntity(self):
        room = Room(1, 2)
        self.assertAlmostEqual(room.size, 2)

    def test_type__GoodInput__ReturnsType_double(self):
        room = Room(1, 2)
        self.assertAlmostEqual(room.get_type(), "double")

    def test_type__GoodInput__ReturnsType_single(self):
        room = Room(1, 1)
        self.assertAlmostEqual(room.get_type(), "single")

    def test_type_GoodInput__ReturnsType_family(self):
        room = Room(1, 4)
        self.assertAlmostEqual(room.get_type(), "family")

    # def test__str__GoodInput__ShowsRoom(self):
    #     room = Room(1, 4)
    #     str(room)
    #     print(room)
    #     self.assertAlmostEqual(str(room), "The room's number is 1 and its type is family")
    #
    # def test_created__GoodInput__CreatesRoom(self):
    #
    #     self.assertAlmostEqual()



class TestReservations(unittest.TestCase):
    def test_reservation__GoodInput__GetsGuests(self):
        reservation = Reservations(1234, "family", 4, '11 02', '15 02')
        self.assertAlmostEqual(reservation.guests, 4)

    def test_reservation__GoodInput__GetsID(self):
        reservation = Reservations(1234, "family", 4, '11 02', '15 02')
        self.assertAlmostEqual(reservation.id, 1234)

    def test_reservation__GoodInput__GetsType(self):
        reservation = Reservations(1234, "family", 4, '11 02', '15 02')
        self.assertAlmostEqual(reservation.room_type, "family")

    def test_reservation__GoodInput__GetsDate1(self):
        reservation = Reservations(1234, "family", 4, '11 02', '15 02')
        self.assertAlmostEqual(reservation.date1, "11 02")

    def test_reservation__GoodInput__GetsDate2(self):
        reservation = Reservations(1234, "family", 4, '11 02', '15 02')
        self.assertAlmostEqual(reservation.date2, "15 02")


if __name__ == '__main__':
    unittest.main()
