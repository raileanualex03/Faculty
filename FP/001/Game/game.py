from TrainGame.Domain.domain import Sentence
from TrainGame.Game.player import Player


class Game:
    def __init__(self, service):
        self.__service = service

    def get_random_sentence(self):
        list = self.__service.get_random_sentence()
        return list

    def main(self):
        string = self.get_random_sentence()
        sentence = Sentence(string)
        sentence.show_sentence()
        player = Player(sentence)
        while True:
            sentence.show_board()
            letter = input("Enter the letter: ")
            player.move(letter)

