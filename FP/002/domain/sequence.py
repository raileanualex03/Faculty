from random import shuffle

from domain.letter import Letter


class Sequence:
    def __init__(self, sequence):
        self.__board = []
        for element in sequence:
            if element == '\n':
                pass
            elif element != ' ':
                self.__board.append(Letter(element))
            else:
                self.__board.append(Letter(element, representation= ' '))

    def show_board(self):
        print(''.join(self.get_representation()))

    def get_sequence(self):
        list = []
        for element in self.__board:
            list.append(element.letter)
        return list

    def get_representation(self):
        list = []
        for element in self.__board:
            list.append(element.representation)
        return list


    def random_representation(self):
        letters_to_shuffle = []
        all_the_letters = self.get_sequence()
        new_letters = []
        index_letter = 0
        for index in range(len(all_the_letters)-1):
            if all_the_letters[index] == ' ' or all_the_letters[index+1] == ' ':
                new_letters.append(all_the_letters[index])
                index_letter = -1
            elif index_letter == 0:
                new_letters.append(all_the_letters[index])
            elif index_letter != 0:
                new_letters.append('0')
                letters_to_shuffle.append(all_the_letters[index])
            else:
                new_letters.append(all_the_letters[index])
            index_letter += 1
        new_letters.append(all_the_letters[len(all_the_letters)-1])

        # for element in all_the_letters:
        #     try:
        #         if element[index+1] == ' ':
        #             new_letters.append(element)
        #     except:
        #          pass
        #          new_letters.append(all_the_letters[index])
        #
        #
        #     if  element == ' ':
        #         index_word = -1
        #         new_letters.append(element)
        #     elif index_word != 0:
        #         letters_to_shuffle.append(element)
        #         new_letters.append('0')
        #     else:
        #         new_letters.append(element)
        #     index += 1
        #     index_word += 1
        shuffle(letters_to_shuffle)
        #
        number = 0

        list = []
        for element in new_letters:
            if element == '0':
                list.append(letters_to_shuffle[number])
                number += 1
            else:
                list.append(element)
        self.change_representation(list)

    def change_representation(self, list):
        index = 0
        for element in list:
            self.__board[index].change_representation(list[index])
            index += 1

    def lists_of_representations(self):
        word = ''
        words = []
        for element in self.get_representation():
            if element != ' ':
                word += element
            else:
                words.append(word)
                word = ''
        words.append(word)
        return words


    def change_representations_from_a_list(self, list):
        index = 0
        for element in list:
            for element2 in element:
                index += 1
                if self.__board[index].letter != ' ':
                    self.__board[index].change_representation(element2)
                else:
                    pass

    def interchange_values(self, position1, position2):
        # position = 00 (%s%s)
        # I ll take each position as a string
        words = self.lists_of_representations()
        aux1, aux2 = self.swap(words[int(position1[0])][int(position1[1])], words[int(position2[0])][int(position2[1])])
        new_words = self.assign_string(words, position1, aux1)
        new_words2 = self.assign_string(new_words, position2, aux2)
        self.change_representations_from_a_list(new_words2)

    def assign_string(self, list, position, value):
        new_list = []
        for index_word in range(len(list)):
            if int(position[0]) != index_word:
                    new_list.append(list[index_word])
            else:
                word = ''
                for index_letter in range(len(list[index_word])):
                    if int(position[1]) == index_letter:
                        word += value
                    else:
                        word += list[index_word][index_letter]
                new_list.append(word)
        return new_list

    def swap(self, string_one, string_two):
            return string_two, string_one


        # words[int(position2[0])][int(position2[1])] = aux
        # self.change_representations_from_a_list(words)

    def won_game(self):
        for element in self.__board:
            if element.check() != True:
                return False
        return True

    def get_length(self):
        index_letter = 0
        for element in self.get_sequence():
            if element != ' ':
                index_letter += 1
        return index_letter




