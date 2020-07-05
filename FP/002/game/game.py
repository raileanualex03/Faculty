from domain.sequence import Sequence
from repository.repository_winners import Winner


class Game:
    def __init__(self, player):
        self.__player = player

    def main(self):
        can_undo = False
        while True:
            self.__player.show_board()
            print("""
The commands are:
           << swap <w><l> <w><l>
           << undo last operation
                            """)
            command = input(">>")

            if "swap" in command :
                choice = command.split()
                position1 = choice[1]
                position2 = choice[2]
                last_sequence = self.__player.get_board()
                self.__player.move(position1, position2)
                can_undo = True
            if "undo" in command:
                if can_undo == True:
                    self.__player.change_sequence(last_sequence)
                    can_undo = False
                else:
                    print("ERROR: Can't be done")

    def undo(self, sequence):
        self.__player.change_sequence(sequence)

class Player:
    def __init__(self, sequence, name, repo):
        self.__sequence = sequence
        self.__score = self.__sequence.get_length()
        self.name = name
        self.repo_winners = repo

    def move(self, position1, position2):
        self.__sequence.show_board()
        first_letter = ''
        second_letter = ''
        index_word = 0
        index_letter = 0
        for element in self.__sequence.get_representation():
            if index_letter == int(position1[1]) and index_word == int(position1[0]):
                first_letter = element
            if index_letter == int(position2[1]) and index_word == int(position2[0]):
                second_letter = element
            if element == ' ':
                index_word += 1
                index_letter = -1
            index_letter += 1

        index_word = 0
        index_letter = 0
        sequence = self.__sequence.get_representation()
        nr = 0
        for element in sequence:
            if index_letter == int(position1[1]) and index_word == int(position1[0]):
               sequence[nr] = second_letter
            if index_letter == int(position2[1]) and index_word == int(position2[0]):
                sequence[nr] = first_letter
            if element == ' ':
                index_letter = -1
                index_word += 1
            index_letter += 1
            nr += 1
        self.__sequence.change_representation(sequence)
        if self.won_game() == True:
            self.show_board()
            print("CONGRATS! Your score is :{}".format(self.__score))

            exit()
        self.__score -= 1
        print("Your score is {}".format(self.__score))
        return sequence

    def won_game(self):
        self.repo_winners.add_winner(Winner(self.name, self.__score))
        return self.__sequence.won_game()

    def show_board(self):
        return self.__sequence.show_board()

    def get_max_length(self):
        index_word = 0
        for element in self.__sequence.get_sequence():
            if element == ' ':
                index_word += 1
        return index_word

    def change_sequence(self, sequence):
        self.__sequence.change_representation(sequence)

    def get_board(self):
        return self.__sequence.get_representation()
# class Player:
#     def __init__(self, sequence):
#         self.__sequence = sequence
#         self.__score = self.__sequence.get_length()
#
#     def move(self, position1, position2):
#         self.__sequence.show_board()
#         first_letter = ''
#         second_letter = ''
#         index_word = 0
#         index_letter = 0
#         for element in self.__sequence.get_representation():
#             if index_letter == int(position1[1]) and index_word == int(position1[0]):
#                 first_letter = element
#             if index_letter == int(position2[1]) and index_word == int(position2[0]):
#                 second_letter = element
#             if element == ' ':
#                 index_word += 1
#                 index_letter = -1
#             index_letter += 1
#
#         index_word = 0
#         index_letter = 0
#         sequence = self.__sequence.get_representation()
#         nr = 0
#         for element in sequence:
#             if index_letter == int(position1[1]) and index_word == int(position1[0]):
#                sequence[nr] = second_letter
#             if index_letter == int(position2[1]) and index_word == int(position2[0]):
#                 sequence[nr] = first_letter
#             if element == ' ':
#                 index_letter = -1
#                 index_word += 1
#             index_letter += 1
#             nr += 1
#         self.__sequence.change_representation(sequence)
#
#         if self.won_game() == True:
#             print("You won")
#             exit()
#         self.__score -= 1
#         print("SCORE: {}".format(self.__score))
#         return sequence
#
#     def won_game(self):
#         return self.__sequence.won_game()
#
#     def show_board(self):
#         return self.__sequence.show_board()
#
#     def get_max_length(self):
#         index_word = 0
#         for element in self.__sequence.get_sequence():
#             if element == ' ':
#                 index_word += 1
#         return index_word
