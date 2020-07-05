class Books:
    def __init__(self, book_id, title, author):
        self._book_id=book_id
        self._title=title
        self._author=author

    @property
    def id(self):
        return self._book_id

    @property
    def title(self):
        return self._title

    @property
    def author(self):
        return self._author

    def set_title(self, new_title):
        self._title=new_title

    def set_author(self, new_author):
        self._author=new_author

    def __str__(self):
        return str(self.id)+'-> "'+ str(self.title)+'" by '+str(self.author)

class Clients:
    def __init__(self, client_id, name):
        self._client_id=client_id
        self._name=name

    @property
    def id(self):
        return self._client_id

    @property
    def name(self):
        return self._name

    def set_name(self, new_name):
        self._name=new_name

    def __str__(self):
        return str(self.id)+'-> '+str(self.name)

class Rentals:
    def __init__(self, rental_id, book_id, client_id, rented_date, returned_date):
        self._rental_id = rental_id
        self._book_id =  book_id
        self._client_id = client_id
        self._rented_date = rented_date
        self._returned_date = returned_date

    @property
    def rental_id(self):
        return self._rental_id

    @property
    def book_id(self):
        return self._book_id

    @property
    def client_id(self):
        return self._client_id

    @property
    def rented_date(self):
        return self._rented_date

    @property
    def returned_date(self):
        return self._returned_date

    def set_book_id(self, new_book_id):
        self._book_id=new_book_id

    def set_client_id(self, new_client_id):
        self._client_id=new_client_id

    def set_returned_date(self, new_returning_date):
        self._returned_date=new_returning_date

    def set_rented_date(self, new_renting_date):
        self._rented_date=new_renting_date

    def __str__(self):
        return 'ID:'+str(self.rental_id)+' The book s ID is: '+str(self.book_id)+' The client s ID is:'+str(self.client_id)+' The rented date is:'+str(self.rented_date)+' The returned date will be:'+str(self.returned_date)