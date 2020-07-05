class Letter:
    def __init__(self, letter):
        self.__letter = letter
        self.__representation = '0'

    def initial_representation(self):
        if self.__letter != ' ':
            self.__representation = '_'
        else:
            self.__representation = ' '

    @property
    def letter(self):
        return self.__letter

    @property
    def representation(self):
        return self.__representation

    def change_representation(self):
        self.__representation = self.__letter

class Sentence:
    def __init__(self, sentence):
        self.__sentence = []
        for element in sentence:
            if (element >= 'a' and element <= 'z') or (element >= 'A' and element <= 'Z') or element == ' ':
               letter = Letter(element)
               letter.initial_representation()
               self.__sentence.append(letter)

    def get_board(self):
        return  [element.representation for element in self.__sentence]

    def get_sentence(self):
        return  [element.letter for element in self.__sentence]

    def show_board(self):
        print(' '.join(self.get_board()))

    def show_sentence(self):
        print(' '.join(self.get_sentence()))

    def change_value(self, value):
        ok = 1
        for element in self.__sentence:
            if element.letter.lower() == value.lower():
                element.change_representation()
                ok = 0
        return ok
        # you can check if it the operation were done

    def check_board(self):
        for element in self.get_board():
            print(element)
            if element == '_':
                return False
        return True


