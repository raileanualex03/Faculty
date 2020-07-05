import random


class Computer:
    def __init__(self, board):
        self.__board = board

    def put_three_cruisers(self, number):
        for i in range(number):
            list = ['*', 'E', 'B']
            interval = range(0, 8)
            line = random.choice(interval)
            column = random.choice(interval)
            while self.__board.secret_board()[line][column] in list:
                line = random.choice(interval)
                column = random.choice(interval)
            self.__board.secret_change_value(line, column, 'B')

    def relocate_remaining_cruisers(self, cruisers_left):
        pass
