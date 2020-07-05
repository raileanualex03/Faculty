import random


class RepositorySequences:
    def __init__(self):
        self.__sequences = []

    def get_sequences(self):
        return self.__sequences

    def get_random_sequence(self):
        return random.choice(self.__sequences)

    def add_sequence(self, sequence):
        if sequence == ' ' or sequence in self.__sequences or sequence == '\n':
            raise ValueError("Invalid sequence")
        self.__sequences.append(sequence)
        self.save_sequences_to_file()

    def get_sequences_from_file(self):
        file = open('C:\MyFiles\ScrableGame\domain\sequences', 'r')
        for line in file:
            element = line.split(';')
            try:
                for words in element:
                    self.add_sequence(str(words))
            except:
                continue
        file.close()

    def save_sequences_to_file(self):
        file = open('C:\MyFiles\ScrableGame\domain\sequences', 'w')
        for element in self.__sequences:
            file.write(element)
            file.write(';')
