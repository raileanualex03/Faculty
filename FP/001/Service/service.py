import random


class ServiceSentences:
    def __init__(self, repo):
      self.__repository = repo
      self.__repository.get_sentences_from_file()


    def add_sentence(self, sentence):
        self.__repository.add_sentence(sentence)

    def get_random_sentence(self):
        # this function will return one of the sentences random from the list of sentences
        list = self.__repository.get_all_sentences()
        sentence = random.choice(list)
        #todo: validation
        while sentence[:(-2)] == str('\n') :
            sentence = random.choice(list)
        return sentence

