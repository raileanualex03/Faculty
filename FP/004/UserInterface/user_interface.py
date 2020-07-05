from Domain.domain import Room
from Repository.repository import RepositoryRooms, RepositoryReservations
from Service.service import Service

repo_rooms = RepositoryRooms()
repo_reservations = RepositoryReservations()
service = Service(repo_reservations, repo_rooms)
room = Room(1, 4)
service.add_room(room)
try:
    service.add_reservation("Popescu", "family", 4, "11/02", "15/04", 0)
    service.add_reservation("Popescu", "family", 4, "11/05", "15/06", 0)
except Exception as ex:
    print(ex)
print('\n'.join(str(element)for element in service.get_all_reservations()))

