import tkinter as tkinter

from TrainGame.Repository.repo_files import RepositoryFiles
from TrainGame.Service.service import ServiceSentences


def page_input():
    tk = tkinter.Tk()
    repo = RepositoryFiles()
    service = ServiceSentences(repo)
    input_page = InputPage(tk, service)
    input_page.create_text()
    input_page.create_input()
    input_page.create_add_button()
    tk.mainloop()

class InputPage:
    def __init__(self, tk, service):
        self.tk = tk
        self.service = service
    def create_text(self):
        self.label = tkinter.Label(self.tk, text = "Here you can add your new sentence")
        self.label.pack(side = "top")

    def create_input(self):
        self.input = tkinter.Entry(self.tk)
        self.input.pack(side = "top")

    def create_add_button(self):
        self.button = tkinter.Button(self.tk, text = "ADD THIS SENTENCE", command = self.add_sentence)
        self.button.pack(side = "top")

    def add_sentence(self):
        self.service.add_sentence(self.input.get())
        self.tk.destroy()
        from TrainGame.GUI.main_page import start

        start()

