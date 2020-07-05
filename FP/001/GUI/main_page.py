import tkinter as tkinter
from tkinter.constants import *
class MainPage:
    def __init__(self, tk):
        self.tk = tk

    def create_title(self):
        self.frame = tkinter.Frame(self.tk, relief = RIDGE, borderwidth = 150)
        self.frame.pack(fill =BOTH, expand = 1)

    def create_text(self):
        self.label = tkinter.Label(self.tk, text = "Welcome to HANGMAN")
        self.label.pack(fill = X, expand = 1, side = TOP)

    def create_add_button(self):
        self.button_add = tkinter.Button(self.frame, text = "Add a sentence", command = self.page_input)
        self.button_add.pack(side = BOTTOM)

    def create_start_game(self):
        self.button_start = tkinter.Button(self.frame, text = "Start the game", command = self.page_game)
        self.button_start.pack(side = BOTTOM)

    def page_game(self):
        from TrainGame.GUI.game_page import game_page as game
        self.tk.destroy()
        game()

    def page_input(self):
        from TrainGame.GUI.input_page import page_input as input
        self.tk.destroy()
        input()



def start():
    tk = tkinter.Tk()
    main_page = MainPage(tk)
    main_page.create_text()
    main_page.create_title()
    main_page.create_add_button()
    main_page.create_start_game()
    tk.mainloop()
start()
