import random

from computer.computer import Computer
from domain.domain import Board


class Player:
    def __init__(self, board, computer):
        self.__board = board
        self.__computer = computer

    def start_Endeavour(self):
        interval = range(0, 8)
        line = random.choice(interval)
        column = random.choice(interval)
        while self.__board.validate_star(line, column, '*') == False:
            line = random.choice(interval)
            column = random.choice(interval)
        self.__board.change_value(line, column, 'E')

    def move_Endeavour(self, place):
        dict = {"A": 0,
                "B": 1,
                "C": 2,
                "D": 3,
                "E": 4,
                "F": 5,
                "G": 6,
                "H": 7,
                }
        if place[0] not in dict:
            raise ValueError("Invalid location!")
        line = dict[place[0]]
        if int(place[1]) < 1 or int(place[1]) > 8:
            raise ValueError("Invalid location number!")
        column = int(place[1]) - 1
        secret_board = self.__board.secret_board()
        #validate place
        if secret_board[line][column] == 'x' or secret_board[line][column] == 'o' or secret_board[line][column] == "*":
            raise ValueError("Invalid place!")

        list = self.__board.find_Endeavours_position()
        if secret_board[line][column]:
            self.lose()
        last_line = list[0]
        last_column = list[1]
        line_range = [last_line-1, last_line, last_line+1]
        column_range = [last_column-1, last_column, last_column+1]
        if line not in line_range:
            raise ValueError("Invalid place")
        if column not in column_range:
            raise ValueError("Invalid place")

        #restore last place
        self.__board.change_value(list[0], list[1], " ")

        #make move
        self.__board.change_value(line, column, "E")

    def fire(self, place):
        dict = {"A": 0,
                "B": 1,
                "C": 2,
                "D": 3,
                "E": 4,
                "F": 5,
                "G": 6,
                "H": 7,
                }
        print(place[0])
        if place[0] not in dict:
            raise ValueError("Invalid location")
        line = dict[place[0]]
        if int(place[1]) not in range(1, 9):
            raise ValueError("Invalid location")
        column = int(place[1]) - 1
        list = self.__board.find_Endeavours_position()
        line_range = [list[0]-1, list[0], list[0]+1]
        column_range = [list[1]-1, list[1], list[1]+1]
        if line not in line_range:
            raise ValueError("Invalid line")
        if column not in column_range:
            raise ValueError("Invalid column")
        #todo: check if it were a hit
        secret_board = self.__board.secret_board()
        if secret_board[line][column] == "B":
            #change value of the cell
            self.__board.change_value(line, column, "x")
            #restore the remaining cells
            cruisers = self.__board.cruisers_left()
            if len(cruisers) == 0:
                self.won_game()
            print(cruisers)
            print(len(cruisers))
            for element in cruisers:
                self.__board.change_value(element[0], element[1], ' ')
            self.__computer.put_three_cruisers(len(cruisers))
        else:
            self.__board.change_value(line, column, 'o')

    def won_game(self):
        print("CONGRATS! You won")
        exit()

    def lose(self):
        print("YOU LOST! You just moved where a BATTLESHIP was")
        exit()
