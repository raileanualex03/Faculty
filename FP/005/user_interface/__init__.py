#! /usr/bin/env python3.8
from Repository.repo_pickle import PickleRepoBooks, PickleRepoClients, PickleRepoRentals
from Repository.repository_file import RepoFileClients, RepoFileBooks, RepoFileRentals
from Service.service import ServiceRentals, ServiceBooks, ServiceClient, UndoController, CascadedOperation
from Domain.domain import Clients, Books, Rentals
from Repository.repo import RepositoryRentals, RepositoryBooks, RepositoryClients
import datetime
from configparser import ConfigParser

class UserInterface(object):
    def __init__(self, service_clients, service_books, service_rentals, undo_controller):
        self._service_clients=service_clients
        self._service_books=service_books
        self._service_rentals=service_rentals
        self._undo_controller = undo_controller

    @staticmethod
    def print():
        print('''The possible commands are:
        0.Exit the application.
        1.Add      (client/book/rental)
        2.Remove   (client/book/rental)
        3.Display  (clients/books/rentals)
        4.Update   (client/book/rental)
        5.Search through all the stuff.
        6.Statistics for books/authors/clients
        7.Undo the last operation
        8.Redo the last undo
              ''')

    # def values_from_files(self):
    #     file_clients = open('/home/alex/Desktop/assignment6-8/Repository/document_clients', 'r')
    #     file_books = open('/home/alex/Desktop/assignment6-8/Repository/document_books', 'r')
    #     file_rentals = open('/home/alex/Desktop/assignment6-8/Repository/document_rentals', 'r')
    #     self._repo_files.add_all_entities(file_clients, file_books, file_rentals)
    #

    def client_existence_by_id(self, client_id):
        list=self._service_clients.get_all()
        for element in list:
            if element.id == client_id:
                return True
        return False

    def book_existence_by_id(self, book_id):
        list=self._service_books.get_all()
        for element in list:
            if element.id == book_id:
                return True
        return False


    def ui_add(self):
        choice=input("Enter the type you want to add (client/book/rental):").strip()
        if choice=='client':
            id=input("Enter the id of the client:")
            name=input("Enter the name of the client:")
            client=Clients(id, name)
            self._service_clients.add(client)
        elif choice=='book':
            id=input("Enter the id of the book:")
            title=input("Enter the title of the book:")
            author=input("Enter the author of the book:")
            book=Books(id, title, author)
            self._service_books.add(book)
        elif choice=='rental':
            id=input('Enter the id of the rental:')
            book_id=input('Enter the id of the book you want to rent:')
            client_id=input('Enter the id of the client that will rent the book:')
            rented_date_year=input('Enter the year of the rental:')
            rented_date_month=input("Enter the month of the rental(1-12):")
            rented_date_day=input("Enter the day of the rental(1-31):")
            rented_date=datetime.datetime(int(rented_date_year), int(rented_date_month), int(rented_date_day))
            returned_date_year = input('Enter the year of the returning::')
            returned_date_month = input("Enter the month of the returning(1-12):")
            returned_date_day = input("Enter the day of the returning(1-31):")
            returned_date=datetime.datetime(int(returned_date_year), int(returned_date_month), int(returned_date_day))
            rental=Rentals(id, book_id, client_id, rented_date, returned_date)
            if self.client_existence_by_id(client_id) is False:
                raise ValueError('Not existing client!')
            if self.book_existence_by_id(book_id) is False:
                raise ValueError('Not existing book!')
            self._service_rentals.add(rental)
        else:
            raise ValueError('Invalid input!')

    def ui_remove(self):
        choice=input('Enter the entity you want to delete(client/book/rental):')
        if choice=='client':
            client_id=input('Enter the client s ID:')
            client = self._service_clients.find_client_by_id(client_id)
            print(client)
            operation = self._service_clients.delete(client)
            self._service_rentals.update_list_after_client_removed(client, operation)

        elif choice=='book':
            book_id=input("Enter the book s ID:")
            book=self._service_books.find_book_by_id(book_id)
            operation = self._service_books.delete(book)
            self._service_rentals.update_list_after_removal_of_book(book, operation)

        elif choice=='rental':
            rental_id=input("Enter the rental s ID:")
            rental=self._service_rentals.find_rental_by_id(rental_id)
            self._service_rentals.delete(rental)
        else:
            raise ValueError('Invalid input!')


    def ui_display(self):
        choice=input("Enter what you want to be displayed (clients/books/rentals):")
        if choice=='clients':
            list=self._service_clients.get_all()
            if len(list)==0:
                print("The list is empty!")
            else:
                for element in list:
                    print(element)
        elif choice=="books":
            list=self._service_books.get_all()
            if len(list)== 0:
                print("The list is empty!")
            else:
                for element in list:
                   print(element)
        elif choice == "rentals":
            list=self._service_rentals.get_rentals()
            if len(list)==0:
                print("The list is empty!")
            else:
                for element in list:
                    print(element)
        else:
            raise ValueError('Invalid input!')

    def ui_update(self):
        choice=input("Enter what you want to update(client/book/rental):")
        if choice=='client':
            id=input("Enter the id of the client you want to update:")
            name=input("Enter his new name:")
            if self.client_existence_by_id(id) is False:
                raise ValueError('No clients with this id!')
            client = Clients(id, 'None')
            self._service_clients.update(client, name)
        elif choice=='rental':
            id=input("Enter the id of the rent you want to update:")
            book_id=input("Enter the new id of the book:")
            client_id=input("Enter the new id of the client:")
            rented_date_year = input('Enter the year of the rental:')
            rented_date_month = input("Enter the month of the rental(1-12):")
            rented_date_day = input("Enter the day of the rental(1-31):")
            rented_date = datetime.datetime(int(rented_date_year), int(rented_date_month), int(rented_date_day))
            returned_date_year = input('Enter the year of the returning:')
            returned_date_month = input("Enter the month of the returning(1-12):")
            returned_date_day = input("Enter the day of the returning(1-31):")
            returned_date = datetime.datetime(int(returned_date_year), int(returned_date_month), int(returned_date_day))
            rental = Rentals(id, book_id, client_id, rented_date, returned_date)
            self._service_rentals.update_rental(rental)
        elif choice=='book':
            id= input("Enter the id of the book you want to update:")
            title= input("Enter the new title of the book:")
            author= input("Enter the new author of the book:")
            book = self._service_books.find_book_by_id(id)
            self._service_books.update(book, title, author)
        else:
            raise ValueError('Invalid input!')

    def ui_search(self):
        pattern=input("Enter your search:")
        books_searched=self._service_books.search_pattern(pattern)
        clients_searched=self._service_clients.search_pattern(pattern)
        rentals_searched=self._service_rentals.search_pattern(pattern)
        search_result=self.combine_lists_of_results(books_searched, clients_searched, rentals_searched)

        if len(search_result)==0:
            raise ValueError("No elements found!")
        else:
            for element in search_result:
                print(element)

    @staticmethod
    def combine_lists_of_results(books_searched, clients_searched, rentals_searched):
        search_result=[]
        for element in books_searched:
            search_result.append(element)
        for element in clients_searched:
            search_result.append(element)
        for element in rentals_searched:
            search_result.append(element)
        return search_result

    def ui_statistics(self):
        choice=input("Enter your choice(clients/book/authors")
        if choice == "books":
            most_rented_books=self._service_rentals.most_rented_books()
            if len(most_rented_books)==0:
                raise ValueError('No books rented found')
            for element in most_rented_books:
                print(self._service_books.find_book_by_id(element[0]), ' rented for {} times'.format(element[1]))
        elif choice == "clients":
            most_active_clients=self._service_rentals.most_active_clients()
            if len(most_active_clients)==0:
                raise ValueError('No clients that rented a book found! ')
            for element in most_active_clients:
                print(self._service_clients.find_client_by_id(element[0]), ' has rented books for {} days'.format(str(element[1])))
        elif choice == 'authors':
            most_wanted_authors=self._service_rentals.most_wanted_authors()
            if len(most_wanted_authors)==0:
                raise ValueError('No rents found')
            for element in most_wanted_authors:
                print('The author {} was rented for {} times'.format(element[0],element[1]))
        else:
            raise ValueError('ERROR !!! Invalid command')

    def undo(self):
      try:
        self._undo_controller.undo()
      except Exception as ex:
          raise ValueError('ERROR: Can not undo!')
    def redo(self):
      try:
        self._undo_controller.redo()
      except Exception as ex:
         raise ValueError('ERROR:Can not redo!')


    def menu(self):
        commands={
            "1": self.ui_add,
            "2": self.ui_remove,
            "3": self.ui_display,
            "4": self.ui_update,
            "5": self.ui_search,
            "6": self.ui_statistics,
            "7": self.undo,
            "8": self.redo
         }
        # self._service_clients.starting_clients()
        # self._service_books.starting_books()
        # self._service_rentals.starting_rentals()
        while True:
            try:
               self.print()
               command=input("Enter your command:")
               if command=='0':
                   print("Thank you for running this application!")
                   exit()
               elif command in commands:
                  commands[command]()
                  # self._repo_pickle.update_all()
                  print('\n >>>The operation was succesfully computed! \n')
               else:
                   raise ValueError('Invalid input!')
            except Exception as ex:
               print(ex)
#
#
# undo_controller = UndoController()
# repo_clients = PickleRepoClients()
# repo_books = PickleRepoBooks()
# repo_rentals = PickleRepoRentals()
# service_clients = ServiceClient(repo_clients, undo_controller)
# service_books = ServiceBooks(repo_books, undo_controller)
# service_rentals = ServiceRentals(repo_rentals, repo_books, repo_clients, undo_controller)
#
# user_interface = UserInterface(service_clients, service_books, service_rentals, undo_controller)
# user_interface.menu()


#
object_parser = ConfigParser()

object_parser.read("settings.properties")
if object_parser.get("settings", "repository") == "memory":
    print("This application gets data from memory")
    undo_controller = UndoController()
    repo_clients = RepositoryClients()
    repo_books = RepositoryBooks()
    repo_rentals = RepositoryRentals(repo_books, repo_clients)
    service_clients = ServiceClient(repo_clients, undo_controller)
    service_books = ServiceBooks(repo_books, undo_controller)
    service_rentals = ServiceRentals(repo_rentals, repo_books, repo_clients, undo_controller)
    user_interface = UserInterface(service_clients, service_books, service_rentals, undo_controller)
    user_interface.menu()



elif object_parser.get("settings", "repository") == "binary":
    print("This application gets data from pickle documents")
    undo_controller = UndoController()
    repo_clients = PickleRepoClients()
    repo_books = PickleRepoBooks()
    repo_rentals = PickleRepoRentals()
    service_clients = ServiceClient(repo_clients, undo_controller)
    service_books = ServiceBooks(repo_books, undo_controller)
    service_rentals = ServiceRentals(repo_rentals, repo_books, repo_clients, undo_controller)
    user_interface = UserInterface(service_clients, service_books, service_rentals, undo_controller)
    user_interface.menu()

elif object_parser.get("settings", "repository") == "text":
    print("This application gets data from file documents")
    undo_controller = UndoController()
    repo_clients = RepoFileClients()
    repo_books = RepoFileBooks()
    repo_rentals = RepoFileRentals()
    service_clients = ServiceClient(repo_clients, undo_controller)
    service_books = ServiceBooks(repo_books, undo_controller)
    service_rentals = ServiceRentals(repo_rentals, repo_books, repo_clients, undo_controller)
    user_interface = UserInterface(service_clients, service_books, service_rentals, undo_controller)
    user_interface.menu()
