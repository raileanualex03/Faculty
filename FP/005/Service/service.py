import datetime
import random
from Domain.domain import Clients, Books, Rentals
from Errors import ServiceError
from Service.validation import Validate
from Service.undo_redo import *


class ServiceClient(object):
    def __init__(self, repository_clients, undo_controller):
        # this function creates a ServiceClient object
        # input: repo_clients-repository object, validation_clients=valid_client object
        self._list_clients = repository_clients
        self._undo_controller = undo_controller

    def client_existence_by_id(self, client_id):
        list = self.get_all()
        for element in list:
            if element.id == client_id:
                return True
        return False



    def add(self, client):
        # this function will get a client and add it to the list of clients
        if Validate.check_client(self, client) is False:
            raise ServiceError('Invalid input!')
        self._list_clients.add(client)
        undo = FunctionCall(self._list_clients.delete, client)
        redo = FunctionCall(self._list_clients.add, client)
        op = Operation(undo, redo)
        self._undo_controller.recordOperation(op)

    def get_all(self):
        return self._list_clients.get_all()

    def delete(self, client, var=True):
        if Validate.check_client(self, client) is False:
            raise ServiceError('Invalid input!')
        self._list_clients.delete(client)
        if var == True :
            undo = FunctionCall(self._list_clients.add, client)
            redo = FunctionCall(self._list_clients.delete, client)
            op = Operation(undo, redo)
            return op

    def search(self, client):
        if Validate.check_client(self, client) is False:
            raise ServiceError('Invalid input!')
        return self._list_clients.search(client)

    def update(self, client, new_name):
        if Validate.check_client(self, client) is False:
            raise ServiceError('Invalid input!')
        client = self.find_client_by_id(client.id)
        old_name = client.name
        client.set_name(new_name)
        self._list_clients.update(client)
        undo = FunctionCall(self.update, client, old_name)
        redo = FunctionCall(self.update, client, new_name)
        op = Operation(undo, redo)
        self._undo_controller.recordOperation(op)

    def find_client_by_id(self, client_id):
        list = self.get_all()
        for element in list:
            if element.id == client_id:
                return element
        raise ServiceError('No element found!')

    def search_pattern(self, pattern):
        clients_searched = []
        pattern = str(pattern).lower()
        for element in self._list_clients.get_all():
            if pattern in str(element.id) or pattern in str(element.name).lower():
                clients_searched.append(element)
        return clients_searched


class ServiceBooks(object):
    def __init__(self, repository_books, undo_controller):
        # this function creates a ServiceBooks object
        self._list_books = repository_books
        self._undo_controller = undo_controller

    def book_existence_by_id(self, book_id):
        list = self.get_all()
        for element in list:
            if element.id == book_id:
                return True
        return False


    def add(self, book):
        if Validate.check_book(None, book) is False:
            raise ServiceError('Invalid input!')
        self._list_books.add(book)
        undo = FunctionCall(self._list_books.delete, book)
        redo = FunctionCall(self._list_books.add, book)
        op = Operation(undo, redo)
        self._undo_controller.recordOperation(op)

    def get_all(self):
        return self._list_books.get_all()

    def delete(self, book, variable = True):
        # this function deletes an object from the list
        if Validate.check_book(None, book) is False:
            raise ServiceError('Invalid input!')
        if variable == True:
           self._list_books.delete(book)
           undo = FunctionCall(self.add, book)
           redo = FunctionCall(self.delete, book)
           operation = Operation(undo, redo)
           return operation

    def search(self, book):
        # this function returns the object if it is in the list
        if Validate.check_book(None, book) is False:
            raise ServiceError('Invalid input!')
        return self._list_books.search(book)

    def update(self, book, book_title, book_author):
        book = self.find_book_by_id(book.id)

        old_title = book.title
        old_author = book.author
        book.set_title(book_title)
        book.set_author(book_author)
        self._list_books.update(book)
        undo = FunctionCall(self.update, book, old_title, old_author)
        redo = FunctionCall(self.update, book, book_title, book_author)
        operation = Operation(undo, redo)
        self._undo_controller.recordOperation(operation)

    def find_book_by_id(self, book_id):
        list = self._list_books.get_all()
        for element in list:
            if str(element.id) == str(book_id):
                return element
        raise ServiceError('No element found!')

    def search_pattern(self, pattern):
        books_searched = []
        pattern = pattern.lower()
        for element in self._list_books.get_all():
            if pattern in str(element.id) or pattern in str(element.title.lower()) or pattern in str(
                    element.author.lower()):
                books_searched.append(element)
        return books_searched




class ServiceRentals(object):
    def __init__(self, repository_rentals, repository_books, repository_clients, undo_controller):
        self._list_rentals = repository_rentals
        self._list_books = repository_books
        self._list_clients = repository_clients
        self._undo_controller = undo_controller

    def add(self, rental):
        if self.available_book(rental) is False:
            raise ServiceError('SERVICE ERROR: Not available book!')
        if self.available_client(rental) is False:
            raise ServiceError('SERVICE ERROR: Not available client')
        self._list_rentals.add(rental)
        undo = FunctionCall(self.delete, rental)
        redo = FunctionCall(self.add, rental)
        op = Operation(undo, redo)
        self._undo_controller.recordOperation(op)

    def get_rentals(self):
        return self._list_rentals.get_all()

    def delete(self, rental):
        self._list_rentals.delete(rental)
        undo = FunctionCall(self.add, rental)
        redo = FunctionCall(self.delete, rental)
        operation = Operation(undo, redo)
        self._undo_controller.recordOperation(operation)

    def find_rental_by_id(self, rental_id):
        list = self.get_rentals()
        for element in list:
            if element.rental_id == rental_id:
                return element
        raise ServiceError('No elements found!')

    def rental_duration(self, rental):
        # this function will return how many days a book was rented
        return rental.returned_date - rental.rented_date

    def available_book(self, rental):
        # this function will search for a book in the list of rentals and if it finds it and
        for element in self._list_rentals.get_all():
            if element.book_id == rental.book_id and element.returned_date > rental.rented_date:
                return False
        return True

    def available_client(self, rental):
        for element in self._list_rentals.get_all():
            if element.client_id == rental.client_id and element.returned_date > rental.rented_date:
                return False
        return True

    def update_rental(self, rental):
        old_rental=self.find_rental_by_id(rental.rental_id)
        self._list_rentals.update(rental)
        undo = FunctionCall(self.update_rental, old_rental)
        redo = FunctionCall(self.update_rental, rental)

        op = Operation(undo, redo)
        self._undo_controller.recordOperation(op)

    def search_pattern(self, pattern):
        rentals_searched = []
        pattern = str(pattern).lower()
        for element in self._list_rentals.get_all():
            if pattern in str(element.rental_id) or pattern in str(element.book_id) or pattern in str(
                    element.client_id) or pattern in str(element.rented_date) or pattern in str(element.returned_date):
                rentals_searched.append(element)
        return rentals_searched

    def how_many_times_was_rented_a_book(self,
                                         book_id):  # this function gets a book by its id and checks how many times it was rented
        counter = 0
        for element in self._list_rentals.get_all():
            if element.book_id == book_id:
                counter += 1
        return counter

    def most_rented_books(self):
        list_of_rented_books = []
        for element in self._list_rentals.get_all():
            book = [element.book_id, self.how_many_times_was_rented_a_book(
                element.book_id)]  # this function will go through every element of the rental

            list_of_rented_books.append(
                book)  # will add a list consisting of books id and how many times was the book rented in list_of_rented_books
        list_of_rented_books = self.get_only_unique_values_of_a_list(
            list_of_rented_books)  # here it will get unique elements
        list_of_rented_books = sorted(list_of_rented_books, key=lambda x: x[1],
                                      reverse=True)  # here we use a lambda function to sort the list by second parameter of every element of the list, reversed
        return list_of_rented_books

    def get_only_unique_values_of_a_list(self, list):
        final_list = []
        for element in list:
            if element not in final_list:  # this function will just return another list with the uniques elements of the first list
                final_list.append(element)
        return final_list

    def most_active_clients(self):
        list_of_active_clients = []
        for element in self._list_rentals.get_all():
            client = [element.client_id, self.how_many_days_rented_by_client(
                element.client_id)]  # this function will add in list_of_active_clients the id of the client days as another list
            list_of_active_clients.append(client)
        list_of_active_clients = self.get_only_unique_values_of_a_list(list_of_active_clients)  # here we will get just unique elements
        list_of_active_clients = sorted(list_of_active_clients, key=lambda x: x[1],
                                        reverse=True)  # here we sort with a lambda function by second parameter of every list(which is the number of days, as we said previously)
        return list_of_active_clients

    def how_many_days_rented_by_client(self, client_id):
        days = 0
        for element in self._list_rentals.get_all():  # this function will go in every rental and check if a certain client is in the list of rentals and add in days how many days he used the book, then returnes the number of dayss
            if element.client_id == client_id:
                days += self.rental_duration(element).days
        return days

    def find_author_by_id_of_book(self, book_id):
        for element in self._list_books.get_all():
            if element.id == book_id:
                return element.author

    def most_wanted_authors(self):
        '''this function will store in list_of_authors_and_counters the name of every author and how many times it was found through the rentals list
           every time we find the same author we will increase the counter(which is the second parameter of every list)
        '''
        list_of_authors_and_counters = []
        for element in self._list_rentals.get_all():  # we will take every rent and find the author of the book, then put it into the list_of_authors_and_counter or increase the counter
            author = self.find_author_by_id_of_book(
                element.book_id)  # here we will use find author to find the author of the book using just the id of the book found in the list of rentals
            object = [author, 1]
            for every_element in list_of_authors_and_counters:
                if every_element[0] == object[0]:  # here we check if the authors are the same
                    every_element[1] += 1
                    # if so, then we will increase the counter
            else:
                list_of_authors_and_counters.append(object)  # else we append it to the list

        list_of_authors = []
        for element in list_of_authors_and_counters:
            if element[0] not in list_of_authors:
                list_of_authors.append(element[0])
        new_list_of_all = []
        for element in list_of_authors_and_counters:
            if element[0] in list_of_authors:
                new_list_of_all.append(element)
                list_of_authors.remove(element[0])
        new_list_of_all = sorted(new_list_of_all, key=lambda x: x[1], reverse=True)
        return new_list_of_all



    def get_all_rentals_of_a_client(self, client):
        rented_books_by_client=[]
        for element in self.get_rentals():
            if element.client_id == client.id:
                rented_books_by_client.append(element)
        return rented_books_by_client

    def get_all_rentals_of_a_book(self, book):
        rented_books=[]
        for element in self.get_rentals():
            if element.book_id == book.id:
                rented_books.append(element)
        return rented_books

    def update_list_after_removal_of_book(self, book, operation):

        rents=self.get_all_rentals_of_a_book(book)
        list_of_operations=[]
        for element in self.get_rentals():
                if book.id == element.book_id:
                    self.delete(element)
                    undo = FunctionCall(self.add, element)
                    redo = FunctionCall(self.delete, element)
                    op = Operation(undo, redo)
                    list_of_operations.append(op)
        list_of_operations.append(operation)
        final_operation = CascadedOperation(list_of_operations)
        self._undo_controller.recordOperation(final_operation)



    def update_list_after_client_removed(self, client, operation):

        '''
        Updates the list of rentals after a client is removed
        '''
        list_of_operations = []
        for element in self.get_rentals():
                if client.id == element.client_id:
                    self.delete(element)
                    undo = FunctionCall(self.add, element)
                    redo = FunctionCall(self.delete, element)
                    op = Operation(undo, redo)
                    list_of_operations.append(op)
        list_of_operations.append(operation)
        final_operation = CascadedOperation(list_of_operations)
        self._undo_controller.recordOperation(final_operation)

