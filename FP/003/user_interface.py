from computer.computer import Computer
from domain.domain import Board
from player.player import Player

print("""
__________________Stellar Journey - game_______________""")
class UserInterface:
    def __init__(self, board, computer, player):
        self.__board = board
        self.__computer = computer
        self.__player = player

    def save(self, name):
        file = open("C:\MyFiles\FMI\First Semester\FP\FinalExamGames\Game\saves", "a")
        # i ll save the secret board
        board = self.__board.secret_board()
        file.write(name)
        file.write(';')
        for line in board:
            for element in line:
                file.write(str(element))
        file.write('\n')
        file.close()
        print("You will be able to use the saving by typing its name in the future")
        exit()

    def load_existing_game(self):
        file = open("C:\MyFiles\FMI\First Semester\FP\FinalExamGames\Game\saves", "r")
        print("These are the options: ")
        for line in file:
            element = line.split(';')
            print('->', element[0])
        file.close()
        file = open("C:\MyFiles\FMI\First Semester\FP\FinalExamGames\Game\saves", "r")

        choice = input("Enter the name of the saving:")
        command = choice.split()
        for line in file:
            element = line.split(';')
            if element[0] == command[0]:
                self.__board.change_boards(element[1])
                self.__board.show_board()
        self.start_loading()

    def menu(self):
        commands = {
            "LOAD": self.load_existing_game,
            "START": self.run,
        }
        print("""
            Type LOAD to choose from an existing game
            Type START to start the game
        """)
        choice = input("Enter your command: ")
        if choice not in commands:
            raise ValueError("Invalid choice")
        commands[choice]()

    def run(self):
        print("""    Your rocket is represented by E-> the Endeavour
            Enemies are represented by B -> Battle cruisers
            The obstacles are represented by * 

            ATTENTION: You can only move or shoot one cell away from your current position!

            The available commands are:
                move <coordinate1><coordinate2> -> Move your rocket in that cell
                fire <coordinate1><coordinate2> -> You can shoot there, if hit, the enemy dies
                cheat                           -> You can see the place where the enemies are
        """)
        self.__board.get_random_10stars()
        self.__player.start_Endeavour()
        self.__computer.put_three_cruisers(3)
        self.__board.show_board()
        while True:
            command = input(">>")
            try:
                if command == "cheat":
                    self.__board.cheat()
                elif "move" in command:
                    choice = command.split()
                    self.__player.move_Endeavour(choice[1])
                    self.__board.show_board()
                elif "fire" in command:
                    choice = command.split()
                    self.__player.fire(choice[1])
                    self.__board.show_board()
                elif "exit" in command:
                    name = input("Enter the name of the save: ")
                    self.save(name)
                elif "load" in command:
                    self.load_existing_game()
                else:
                    raise ValueError("Invalid command")
            except Exception as ex:
                print(ex)

    def start_loading(self):

        print("""
            Your rocket is represented by E-> the Endeavour
            Enemies are represented by B -> Battle cruisers
            The obstacles are represented by * 

            ATTENTION: You can only move one cell away from your current position!

            The available commands are:
                move <coordinate1><coordinate2> -> Move your rocket in that cell
                fire <coordinate1><coordinate2> -> You can shoot there, if hit, the enemy dies
                cheat                           -> You can see the place where the enemies are
        """)
        while True:
            command = input(">>")
            try:
                if command == "cheat":
                    self.__board.cheat()
                elif "move" in command:
                    choice = command.split()
                    self.__player.move_Endeavour(choice[1])
                    self.__board.show_board()
                elif "fire" in command:
                    choice = command.split()
                    self.__player.fire(choice[1])
                    self.__board.show_board()
                elif "exit" in command:
                    name = input("Enter the name of the save: ")
                    self.save(name)
                elif "load" in command:
                    self.load_existing_game()
                else:
                    raise ValueError("Invalid command")
            except Exception as ex:
                print(ex)


board = Board(8, 8)
computer = Computer(board)
player = Player(board, computer)
ui = UserInterface(board, computer, player)
ui.menu()
