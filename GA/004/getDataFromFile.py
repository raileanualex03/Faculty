from directedGraph import directedGraph


def getData(file_name):
    file = open(file_name)
    graph = directedGraph()
    first_line = file.readline()
    element = first_line.split()
    number_of_vertices = int(element[0])
    number_of_edges = int(element[1])
    for index in range(number_of_edges):
        line = file.readline()
        element = line.split()
        x = int(element[0])
        y = int(element[1])
        cost = int(element[2])
        try:
            graph.addVertex(x)
        except:
            pass
        try:
            graph.addVertex(y)
        except:
            pass
        try:
            graph.addEdge(x, y, cost)
        except:
            pass
    ok=0
    while(graph.getNumberOfVertices() < number_of_vertices and ok == 1):
        line = file.readline()
        element = line.split()
        try:
            graph.addVertex(int(element[0]))
        except:
            pass
    return graph

def writeData(file_name, graph, variable):
    file = open(file_name, 'w')
    if variable == True:

        file.write(str(graph.getNumberOfVertices()) + ' ' + str(graph.getNumberOfEdges()) + '\n')
        costs = graph.getCosts()
        for element in graph.getCosts().keys():
            file.write(str(element[0]) + ' ' + str(element[1]) + ' ' + str(costs[element]) + '\n')

        isolatedVertices = graph.getIsolatedVertices()
        for element in isolatedVertices:
            file.write(str(element) + '\n')
    else:
        file.write("Too many edges!")
    file.close()