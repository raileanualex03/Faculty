from createRandomGraph import createRandom
from directedGraph import directedGraph
from getDataFromFile import getData
from userInterface import UI

print("If you want to get the input from the file press W ")
print("If you want to get a random graph press R")
command = input("Enter your choice: ")
if command.lower() == 'w':
    print("\n        This application gets data from 'input.txt'.")
    graph = getData('input.txt')
else:
    print("              This application gets a random graph.")
    graph = directedGraph()
    x = int(input("Enter the number of vertices: "))
    y = int(input("Enter the number of edges: "))
    graph = createRandom(graph, x, y)
ui = UI(graph)
ui.menu()