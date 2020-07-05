


class Room:
    def __init__(self, number, size):
        self.__number = number
        self.__size = size

    @property
    def number(self):
        return self.__number

    @property
    def size(self):
        return self.__size

    def get_type(self):
        if self.size == 1:
            return "single"
        if self.size == 2:
            return "double"
        if self.size == 4:
            return "family"

    def __str__(self):
        return "The room's number is " + str(self.number) + " and its type is " + str(self.get_type())


class Reservations:
    def __init__(self, room_name, room_type, guests, date1, date2, room_number):
        self.__id = 0
        self.room_name = room_name
        self.room_type = room_type
        self.guests = guests
        self.date1 = date1
        self.date2 = date2
        self.room_number = room_number

    @property
    def id(self):
        return self.__id

    def change_room_number(self, new_number):
        self.room_number = new_number

    def change_id(self, id):
        self.__id = id

    def __str__(self):
        return "Room: " + str(self.room_number) + ' //name: ' + str(self.room_name) + '// type: ' + str(self.room_type) + ' // {} guests'.format(str(self.guests))


