import random


def createRandom(initialGraph, vertices, edges):
    '''
    this function will create a graph that will contain a specified number of vertices and edges :)
    :param initialGraph: the empty graph
    :param vertices: the number of vertices
    :param edges: the number of edges
    :return: the graph containing vertices and edges :)
    '''



    if (edges > vertices*vertices):
        print("Couldn't be done! Too many edges requested.")
        print("The application will continue with an empty graph :)")
        return initialGraph
        # Now there are going to be the vertices from 0 to vertices-1 included

    for index in range(0, vertices):
            initialGraph.addVertex(index)
    counter = 0
    costRange = range(1, 20)
    verticesRange = range(0, vertices)
    firstVertex = int(random.choice(verticesRange))
    secondVertex = int(random.choice(verticesRange))
    cost = int(random.choice(costRange))

    while counter < edges:
        if initialGraph.isEdge(firstVertex, secondVertex) == False:
            initialGraph.addEdge(firstVertex, secondVertex, cost)
            counter += 1
        else:
            firstVertex = random.choice(verticesRange)
            secondVertex = random.choice(verticesRange)
            cost = random.choice(costRange)


    return initialGraph
