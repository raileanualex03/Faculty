import random

from Domain.domain import Reservations


class Service:
    def __init__(self, repository_reservations , repository_rooms):
        self.__repository_reservations = repository_reservations
        self.__repository_rooms = repository_rooms

    def add_reservation(self, name, room_type, guests, date1, date2, room_number):
        reservation = Reservations( name, room_type, guests, date1, date2, room_number)
        good_reservation = self.check_room_for_reservation(reservation)
        good_reservation.change_room_number(self.get_random_number())
        self.__repository_reservations.add_reservation(good_reservation)

    def add_room(self, room):
        #todo: validate
        self.__repository_rooms.add_room(room)

    def delete_reservation(self, reservation_name):
        reservation = self.__repository_reservations.search_by_name(reservation_name)
        self.__repository_reservations.delete(reservation)

    def validate_reservation(self, reservation):
        #validate type
        type = reservation.room_type
        if type == "family":
            if int(reservation.guests) > 4:
                raise ValueError("Too many guests for this room")
            if int(reservation.guests) < 1:
                raise ValueError("Invalid zero guests")
        elif type == "double":
            if int(reservation.guests) > 2:
                raise ValueError("Too many guests for this room")
            if int(reservation.guests) < 1:
                raise ValueError("Invalid zero guests")
        elif type == "single":
            if int(reservation.guests) > 1:
                raise ValueError("Too many guests for this room")
            if int(reservation.guests) < 1:
                raise ValueError("invalid zero guests")
        list = ['single', 'double', 'family']
        if type not in list:
                    raise ValueError("Not available rooms in this period")

        #validate dates
        date1 = reservation.date1
        date_split = date1.split('/')
        date2 = reservation.date2
        date_split2 = date2.split('/')
        if int(date_split[0]) < 1 or int(date_split[0]) > 31 or int(date_split[1]) < 1 or int(date_split[1]) > 12:
            raise ValueError("Invalid date")
        if int(date_split2[0]) < 1 or int(date_split2[0]) > 31 or int(date_split2[1]) < 1 or int(date_split2[1]) > 12:
            raise ValueError("Invalid date")
        if int(date_split[1]) > int(date_split2[1]):
            raise ValueError("Invalid month")
        if int(date_split[0]) > int(date_split2[0]):
            raise ValueError("Invalid day")

        #validate name
        if reservation.room_name == ' ' or reservation.room_name == '':
            raise ValueError("Invalid name")

        #validate room
        for element in self.__repository_reservations.get_all():
            if element.room_number == reservation.room_number:
                date1_reservation = element.date1.split('/')
                date2_reservation = element.date2.split('/')
                if int(date1_reservation[1]) == int(date2[1]):
                    if int(date1_reservation[0]) <= int(date2[0]) and int(date2_reservation[0] >= int(date2[0])):
                        return False
                if int(date2_reservation[1] > int(date1[1])):
                    return False
        return True

    def check_room_for_reservation(self, reservation):
        type = reservation.room_type
        if type == "family":
            list = self.__repository_rooms.get_family_rooms()
            for element in list:
                reservation.change_room_number(element.number)
                check = self.validate_reservation(reservation)
                if check == True:
                    return reservation
        elif type == "double":
                list = self.__repository_rooms.get_double_rooms()
                for element in list:
                    reservation.change_room_number(element.number)
                    if self.check_room_for_reservation(reservation) == True:
                        return reservation
        elif type == "single":
                list = self.__repository_rooms.get_single_rooms()
                for element in list:
                    reservation.change_room_number(element.number)
                    if self.check_room_for_reservation(reservation) == True:
                        return reservation


    def get_random_number(self):
        number = range(1000, 9999)
        return random.choice(number)

    def get_all_rooms(self):
        return self.__repository_rooms.get_all()

    def get_all_reservations(self):
        return self.__repository_reservations.get_all()


