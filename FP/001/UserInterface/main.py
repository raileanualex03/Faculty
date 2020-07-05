from TrainGame.Game.game import Game
from TrainGame.Repository.repo_files import RepositoryFiles
from TrainGame.Service.service import ServiceSentences


class User_Interface:
    def __init__(self, service):
        self.__service = service

    def add_sentence(self):
        sentence = input("Enter the sentence: ")
        self.__service.add_sentence(sentence)

    def game(self):
        game = Game(service)
        game.main()

    def main(self):
        commands = {
            "1":self.add_sentence,
            "2":self.game,

        }
        while True:
                print("""
                --------The menu----------
                1.Add a sentence
                2.Start the game
                """)
                choice = input("Enter your choice: ")
                commands[choice]()

repo = RepositoryFiles()
service = ServiceSentences(repo)
ui = User_Interface(service)
ui.main()