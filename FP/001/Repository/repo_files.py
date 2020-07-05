

'''
I ll create a list full of sentences read from the file or from the keyboard
'''
class RepositoryFiles:
    def __init__(self):
         self.__sentences = []

    def add_sentence(self, sentence):
        self.__sentences.append(sentence)
        self.save_sentence_to_file(sentence)

    def get_sentences_from_file(self):
        file = open("C:\MyFiles\TrainGame\Repository\sentences", "r")
        for line in file:
            self.__sentences.append(line)
        file.close()

    def save_sentence_to_file(self, element):
        file = open("C:\MyFiles\TrainGame\Repository\sentences", 'w')
        for element in self.get_all_sentences():
            file.write(element)
            file.write('\n')

    def get_all_sentences(self):
        return self.__sentences
