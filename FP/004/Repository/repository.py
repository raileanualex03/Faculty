


class RepositoryReservations:
    def __init__(self):
        self.__reservations = []


    def add_reservation(self, reservation):
        #todo: check if valid
        self.__reservations.append(reservation)

    def delete_reservation(self, reservation):
        self.__reservations.remove(reservation)

    def search_by_id(self, id):
        for element in self.__reservations:
            if element.id == id:
                return element
        raise ValueError("None")

    def search_by_name(self, name):
        for element in self.__reservations:
            if element.name == name:
                return element
        raise ValueError("None")

    def get_all(self):
        return self.__reservations

class RepositoryRooms:
    def __init__(self):
        self.__rooms = []

    def add_room(self, room):
        #todo: validate
        self.__rooms.append(room)

    def delete_room(self, room):
        self.__rooms.remove(room)

    def search_by_size(self, size):
        list = []
        for element in self.__rooms:
            if element.size == size:
                list.append(element)
        return list

    def search_by_number(self, number):
        for element in self.__rooms:
            if element.number == number:
                return element

    def get_all(self):
        return self.__rooms

    def get_family_rooms(self):
        list = []
        for element in self.__rooms:
            if element.get_type() == 'family':
                list.append(element)
        return list

    def get_double_rooms(self):
        list = []
        for element in self.__rooms:
            if element.get_type == 'double':
                list.append(element)
        return list

    def get_single_rooms(self):
        list = []
        for element in self.__rooms:
            if element.get_type == 'single':
                list.append(element)
        return list



