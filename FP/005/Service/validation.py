from Domain.domain import Clients
from Errors import RepoError


class Validate(object):
    def check_client(self, client):
        id = str(client.id)
        name = str(client.name)
        if len(id)==0 or len(name)==0:
            return False
        for letter in id:
            if letter <'0' or letter >'9' or letter==' ' or letter == str('13'):
                return False
        for letter in name:
            if (letter<'A' or letter >'z') and letter !=' ':
                return False
        return True

    def check_book(self, book):
        id=str(book.id)
        title=str(book.title)
        author=str(book.author)
        if len(id)==0 or len(title)==0 or len(author)==0:
            return False
        for letter in id:
            if letter <'0' or letter >'9' or letter==' ':
                return False
        for letter in title:
            if (letter<'A' or letter >'z') and letter !=' ' and letter!='.':
                return False
        for letter in author:
            if (letter<'A' or letter >'z') and letter !=' ' and letter!='.':
                return False
        return True







