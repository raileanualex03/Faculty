import tkinter as tk

from Domain.domain import Sentence
from Game.player import Player
from Repository.repo_files import RepositoryFiles
from Service.service import ServiceSentences

repository = RepositoryFiles()
service = ServiceSentences(repository)
string = service.get_random_sentence()
sentence = Sentence(string)
player = Player(sentence)

def game_page():
    tki = tk.Tk()
    page = GamePage(tki, player, sentence)
    page.create_title()
    page.create_board()
    page.create_button()
    page.create_input()
    tki.mainloop()

class GamePage:
    def __init__(self, tk, player, sentence):
        # i ll have the photo up
        # the text will be in the center
        # the input will be down
        self.tk = tk
        self.player = player
        self.sentence = sentence

    def create_title(self):
        list = ["H", "A", "N", "G", "M", "A", "N"]
        self.title = tk.Label(self.tk, text = "{} .".format(''.join(list[:(self.player.get_errors())])))
        self.title.pack(expand = 1, side = "top")

    def create_board(self):
        self.board = tk.Label(self.tk, text = "{}".format(self.get_board()))
        self.board.pack(side = "top")

    def get_board(self):
        board = self.sentence.get_board()
        string = ''
        for element in board:
            string = string + str(element)
            string += ' '
        return string

    def create_input(self):
        self.input = tk.Entry(self.tk)
        self.input.pack(side = "bottom")

    def create_button(self):
        self.button = tk.Button(self.tk, text = "Try this letter!", command = self.move)
        self.button.pack(side = "bottom")

    def move(self):
        try:
            self.player.move(self.input.get())
            self.tk.destroy()
            game_page()
        except Exception as ex:
            self.error_page(ex)

    def error_page(self, ex ):
        tk2 = tk.Tk()
        label = tk.Label(tk2, text = "{}".format(ex))
        label.pack(side = "top")
        button = tk.Button(tk2, text = "OK", command = tk2.destroy)
        button.pack(side = "top")


game_page()