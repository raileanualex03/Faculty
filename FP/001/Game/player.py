class Player:
    def __init__(self, sentence):
        self.__sentence = sentence
        self.__errors = 0

    def move(self, letter):
         ok = self.__sentence.change_value(letter)
         if self.won_game() == True:
             print("You won. Congrats!")
             exit()

         if ok == 1:
            self.__errors += 1
            if self.finished_game() == True:
                raise ValueError("You lost !")

            else:
                list = ['H', 'A', 'N', 'G', 'M', 'A', 'N']
                print(">> Be careful ! ")
                print(''.join(list[-self.__errors:]))
                print("You got {} mistakes left ! ".format(7-self.__errors))
                print("\nThis is the board: ")

    def finished_game(self):
        if self.__errors == 7:
            return True
        return False

    def won_game(self):
        if self.__sentence.check_board() == True:
            return True
        return False

    def get_errors(self):
        return self.__errors



