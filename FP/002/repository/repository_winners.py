
class Winner:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def __str__(self):
        return str(self.score) + ' Name: ' + str(self.name)



class RepositoryWinners:
    def __init__(self):
        self.winners = []

    def add_winner(self, winner):
        self.winners.append(winner)
        self.save_sequences_to_file()

    def get_winners_from_file(self):
            file = open("C:\MyFiles\ScrableGame\winners", 'r')
            for element in file:
                    print(element)
                    variable = element.split(';')
                    for element2 in variable:
                         line = element2.split()
                         if line != []:
                            print(line)
                            name = line[0]
                            score = line[1]
                            self.add_winner(Winner(name, score))

            file.close()

    def save_sequences_to_file(self):
            file = open("C:\MyFiles\ScrableGame\winners", 'w')
            for element in self.winners:
                file.write(str(element.name))
                file.write(' ')
                file.write(str(element.score))
                file.write(';')
            file.close()

    def sort_winners(self):
        self.winners = sorted(self.winners, key=lambda x: int(x.score), reverse=True)

    def get_winners(self):
        self.sort_winners()
        list = [element for element in self.winners]

        return list