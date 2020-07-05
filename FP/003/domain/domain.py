import random


class Cell:
    def __init__(self, line, column, value=' ', secret=' '):
        self.__line = line
        self.__column = column
        self.__value = value
        self.__secret = secret

    @property
    def line(self):
        return self.__line

    @property
    def column(self):
        return self.__column

    @property
    def value(self):
        return self.__value

    def change_value(self, new_value):
        self.__value = new_value
        self.__secret = new_value

    def change_secret(self, new_value):
        self.__secret = new_value

    @property
    def secret(self):
        return self.__secret


class Board:
    def __init__(self, lines, columns):
        self.__lines = lines
        self.__columns = columns
        self.__board = [[Cell(i, j) for j in range(self.__columns)] for i in range(self.__lines)]

    @property
    def lines(self):
        return self.__lines

    @property
    def columns(self):
        return self.__columns

    def get_board_values(self):
       return  [[self.__board[i][j].value for j in range(self.__columns)] for i in range(self.__lines)]

    def show_board(self):
        dict = {1: "A",
                2: "B",
                3: "C",
                4: "D",
                5: "E",
                6: "F",
                7: "G",
                8: "H",
                }

        print('+---+---+---+---+---+---+---+---+---+')
        print('|', ' | '.join(str(index) for index in range(9)), '|')
        index = 0
        for element in self.find_final_board():
            index += 1
            print('+---+---+---+---+---+---+---+---+---+')
            print('|', dict[index], '|', ' | '.join(str(i) for i in element), '|')
        print('+---+---+---+---+---+---+---+---+---+')

    def find_final_board(self):
        for line2 in self.__board:
            for element in line2:
               if element.secret == "E":
                   line = element.line
                   column = element.column

        line_list = [line-1, line, line+1]
        column_list = [column-1, column, column+1]
        board = self.secret_board()
        new_board = []
        for i in line_list:
            for j in column_list:
                try:
                    if board[i][j] == "B":
                        new_board.append([i, j])
                except:
                    continue
        final_board = self.get_board_values()
        for element in new_board:
            final_board[element[0]][element[1]] = "B"
        return final_board

    def get_column(self, column):
        list = []
        for line in self.__board:
            for element in line:
                if element.column == column:
                    list.append(element.value)
        return list

    def find_Endeavours_position(self):
        for line in self.__board:
            for element in line:
                if element.value == "E":
                    return [element.line, element.column]

    def get_line(self, line):
        list = []
        for line2 in self.__board:
            for element in line2:
                if element.line == line:
                    list.append(element.value)
        return list

    def change_value(self, line, column, new_value):
        self.__board[line][column].change_value(new_value)

    def get_positive_diagonals(self):
        board_values = self.get_board_values()
        diagonals = []
        for i in range(self.lines):
            diagonal = []
            aux = i
            for j in range(0, self.columns):
                    diagonal.append(board_values[aux][j])
                    aux -=1
            diagonals.append(diagonal[:(i+1)])
        return diagonals

    def get_negative_slopes(self):
        board_values = self.get_board_values()
        diagonals = []
        for i in range(self.lines-1, -1, -1):
            diagonal = []
            aux = i
            for j in range(self.columns-1, -1, -1):
                diagonal.append(board_values[aux][j])
                aux -= 1
            diagonals.append(diagonal[:(i+1)])
        return diagonals

    def check_if_two_consecutives_values_are_in_a_list(self, list, value):
        for i in range(len(list)-1):
            if list[i] == list[i+1] == value:
                return False
        return True

    def get_random_10stars(self):
        for i in range(10):
            interval = range(0, 8)
            line = random.choice(interval)
            column = random.choice(interval)
            #todo: validate star
            while self.validate_star(line, column, '*') == False:
                line = random.choice(interval)
                column = random.choice(interval)
            self.change_value(line, column, '*')

    def validate_star(self, line, column, value):
            if value == "B" or value == "E":
                board_values = self.secret_board()
            else:
                board_values = self.get_board_values()
            try:
                if board_values[line-1][column] == value:
                    return False
            except:
                pass
            try:
                if board_values[line-1][column-1] == value:
                     return False
            except:
                pass

            try:
                if board_values[line][column-1] == value:
                    return False
            except:
                pass
            try:
                if board_values[line+1][column] == value:
                    return False
            except:
                pass
            try:
                if board_values[line+1][column+1] == value:
                    return False
            except:
                pass
            try:
                if board_values[line][column+1] == value:
                    return False
            except:
                pass
            try:
                if board_values[line-1][column+1] == value:
                    return False
            except:
                pass
            try:
                if board_values[line+1][column-1] == value:
                    return False
            except:
               pass
            try:
                if board_values[line][column] == value:
                    return False
            except:
                pass
            return True

    def secret_board(self):
        final_list = []
        for line in self.__board:
            list = []
            for element in line:
                list.append(element.secret)
            final_list.append(list)
        return final_list

    def secret_change_value(self, line, column, value):
        self.__board[line][column].change_secret(value)

    def cheat(self):
        dict = {1: "A",
                2: "B",
                3: "C",
                4: "D",
                5: "E",
                6: "F",
                7: "G",
                8: "H",
                }

        print('+---+---+---+---+---+---+---+---+---+')
        print('|', ' | '.join(str(index) for index in range(9)), '|')
        index = 0
        for element in self.secret_board():
            index += 1
            print('+---+---+---+---+---+---+---+---+---+')
            print('|', dict[index], '|', ' | '.join(str(i) for i in element), '|')
        print('+---+---+---+---+---+---+---+---+---+')

    def cruisers_left(self):
        final_list = []
        for line in self.__board:
            for element in line:
                if element.secret == "B":
                    final_list.append([element.line, element.column])
        return final_list

    def change_boards(self, list):
        line = 0
        column = 0
        for element in list[:(len(list)-1)]:
            #because the last element is going to be '\n'
            if line == 8:
                line = 0
            if column == 8:
                column = 0
                line += 1
            if element != "B":
                self.change_value(line, column, element)
            else:
                self.secret_change_value(line, column, element)
            column += 1
    #
    # def show_if_cruisers_are_close_enough(self, line, column):
    #     secret_board = self.secret_board()
    #     if secret_board[line][column-1] == "B":




