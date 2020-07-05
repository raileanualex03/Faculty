from user_interface import *
from Service.undo_redo import *


undo_controller=UndoController()
repo_clients=RepositoryClients()
repo_books=RepositoryBooks()
repo_rentals=RepositoryRentals()
service_clients=ServiceClient(repo_clients, undo_controller)
service_books=ServiceBooks(repo_books, undo_controller)
service_rentals=ServiceRentals(repo_rentals, repo_books, repo_rentals, undo_controller)
user_interface=UserInterface(service_clients, service_books, service_rentals)
user_interface.menu()