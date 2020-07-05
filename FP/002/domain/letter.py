
class Letter:
    def __init__(self, letter, representation = '0'):
        self.__letter = letter
        self.__representation = representation

    @property
    def letter(self):
        return self.__letter

    @property
    def representation(self):
        return self.__representation

    def change_representation(self, new_representation):
        self.__representation = new_representation

    def check(self):
        return self.__letter == self.__representation

    def __str__(self):
        return "The letter is: " + str(self.__letter) + " and its representation is: " + str(self.representation)

