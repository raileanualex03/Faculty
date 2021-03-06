class directedGraph:
    def __init__(self):
        self.__vertices = 0
        self.__dictIn = {}
        self.__dictOut = {}
        self.__dictCosts = {}
        self.copy = None

    def createCopyOfGraph(self):
        '''
        this function creates a copy of the graph
        '''
        new_graph = directedGraph()
        new_graph.__vertices = self.__vertices
        new_graph.__dictOut = self.__dictOut
        new_graph.__dictIn = self.__dictIn
        new_graph.__dictCosts = self.__dictCosts
        self.copy = new_graph
        # this function created a graph and saved a copy of the current graph in self.copy

    def makeEmptyGraph(self):
        '''
        this function empties the graph
        '''
        self.__dictCosts = {}
        self.__dictIn = {}
        self.__dictOut = {}

    def getNumberOfVertices(self):
        '''
        :return: this function returns the number of vertices in this directedGraph :)
        '''
        return self.__vertices

    def isVertex(self, vertex):
        '''
        this function checks if the vertex exists in the dictionaryIn
        :param vertex:
        :return: True-> if vertex is in the dictionary
                False -> otherwise
        '''
        if vertex in self.__dictIn.keys():
            return True
        else:
            return False

    def isEdge(self, x, y):
        '''
        this function checks if the edge exists, the edge consisting of x and y
        :param x: the outbounding vertex
        :param y: the inbounding vertex
        :return: True -> if edge is in the dictionary of costs as a key
                False -> otherwise
        '''
        if (x, y) in self.__dictCosts.keys():
            return True
        else:
            return False

    def addVertex(self, vertex):
        '''
        this function will add a vertex in the dictionaries if is okay regarding all the validations
        :param vertex: the number - id of the vertex
        :return: None -> if the vertex was added
                throws Errors -> if the vertex already exists
        '''
        if vertex not in self.__dictIn:
            self.__dictIn[vertex] = []
            self.__dictOut[vertex] = []
            self.__vertices += 1
        else:
            raise ValueError("ERROR: This vertex already exists!")

    def addEdge(self, x, y, cost):
        '''
        this function will add an edge in the dictionary of costs if it is okay regarding all the validations
        :param x: the outbound vertex
        :param y: the inbound vertex
        :param cost: the costs of this edge
        :return: None -> if the edge was added
                ThrowsError -> if the edge is not valid (every vertex must exist and the edge must be unique)
        '''
        # here I check if the vertices exist
        if self.isVertex(x) == False or self.isVertex(y) == False:
            raise ValueError("ERROR: This vertex doesn't exist")

        # here I check if the edge already exists
        if self.isEdge(x, y) == True:
            raise ValueError("ERROR: This edge already exists!")
        else:
            self.__dictIn[y].append(x)
            self.__dictOut[x].append(y)
            self.__dictCosts[(x, y)] = cost

    def removeVertex(self, vertex):
        '''
        this function will remove a vertex from the dictionaries if the vertex exists
        :param vertex: the vertex :)
        :return:None-> if the vertex was removed
                ThrowsError-> if the vertex doesn't exist
        '''
        if self.isVertex(vertex) == False:
            raise ValueError("ERROR: This vertex doesn't exist!")
        for element in self.__dictOut[vertex]:
            self.__dictIn[element].remove(vertex)
            if self.isEdge(vertex, element) == True:
                del self.__dictCosts[(vertex, element)]
            if self.isEdge(element, vertex) == True:
                del self.__dictCosts[(element, vertex)]

        for element in self.__dictIn[vertex]:
            self.__dictOut[element].remove(vertex)
            if self.isEdge(element, vertex) == True:
                del self.__dictCosts[(element, vertex)]

            if self.isEdge(vertex, element) == True:
                del self.__dictCosts[(vertex, element)]

        del self.__dictOut[vertex]
        del self.__dictIn[vertex]
        self.__vertices -= 1

    def removeEdge(self, x, y):
        '''
        this function will remove an edge if it exists :)
        :param x: outbound vertex
        :param y: inbound vertex
        :return: None-> if the edge was removed
                ThrowsError-> if the edge doesn't exist
        '''
        if self.isEdge(x, y) == False:
            raise ValueError("ERROR: This edge doesn't exist!")
        del self.__dictCosts[(x, y)]

    def getCostOfEdge(self, x, y):
        '''
        this function will return the cost of an edge if this edge exists
        :param x: outbound vertex
        :param y: inbound vertex
        :return: the cost if the edge exists
                ThrowsError -> if edge doesn't exist
        '''
        if self.isEdge(x, y) == False:
            raise ValueError("ERROR: This edge doesn't exist!")
        return self.__dictCosts[(x, y)]

    def changeCostOfEdge(self, x, y, newCost):
        '''
        this function will change the cost of an edge
        :param x: outbound vertex
        :param y: inbound vertex
        :param newCost: the new cost
        :return: None
        '''
        if self.isEdge(x, y) == False:
            raise ValueError("ERROR: This edge doesn't exist!")
        del self.__dictCosts[(x, y)]
        self.__dictCosts[(x, y)] = newCost

    def getInDegreeOfVertex(self, y):
        '''
        this function will return the indegree of a vertex
        :param y: the vertex
        :return: the indegree of this vertex
        '''
        if self.isVertex(y) == False:
            raise ValueError("This vertex doesn't exist")
        return len(self.__dictIn[y])

    def getOutDegreeOfVertex(self, x):
        '''
        this function will return the outdegree of a vertex
        :param x: the vertex
        :return: the outdegree of this vertex
        '''
        if self.isVertex(x) == False:
            raise ValueError("This vertex doesn't exist")
        return len(self.__dictOut[x])

    def iterateVertices(self):
        '''
        :return: this function will return a list containing all the vertices
        '''
        list = [element for element in self.__dictIn.keys()]
        return list

    def getInboundVertices(self, x):
        '''
        :return: this function will return a list containing the vertices that are coming to the vertex - x
        '''
        return [element for element in self.__dictIn[x]]

    def getOutboundVertices(self, y):
        '''
        :return: this function will return a list containing the vertices that are leaving from the vertex - y
        '''
        return [element for element in self.__dictOut[y]]

    def getInboundEdges(self, y):
        '''
        :param y: a vertex
        :return:this function will return a list containing the edges that are coming to the vertex - y
         '''
        return [(y, element) for element in self.__dictIn[y]]

    def getOutboundEdges(self, x):
        '''
        :param x: a vertex
        :return: this function will return a list containing the edges that are leaving frmo the vertex - x
        '''
        return [(element, x) for element in self.__dictOut[x]]

    def getNumberOfEdges(self):
        '''
        :return: this function will return the number of edges
        '''
        return len(self.__dictCosts.keys())

    def getCosts(self):
        return self.__dictCosts

    def parseInboundEdgesOfVertex(self, vertex):
        '''
        this function will return a copy of a list containing all the inbound edges
        :param vertex:  a vertex
        :return: the copy of a list
        '''
        if self.isVertex(vertex) == False:
            raise ValueError("This vertex doesn't exist")
        list = []
        for element in self.__dictIn[vertex]:
            list.append((element, vertex))
        return list

    def getIsolatedVertices(self):
        '''
        this function will return a list containing all the isolated vertices
        '''
        list = []
        for element in self.__dictOut:
            if len(self.__dictIn[element]) == 0 and len(self.__dictOut[element]) == 0:
                list.append(element)
        return list

    def parseOutboundEdgesOfVertex(self, vertex):
        '''
        this function will return a copy of a list containing all the outbound edges
        :param vertex: a vertex
        :return: the copy of a list
        '''
        if self.isVertex(vertex) == False:
            raise ValueError("This vertex doesn't exist")
        list = []
        for element in self.__dictOut[vertex]:
            list.append((vertex, element))
        return list

    def reverseBFS(self, x, y):
        if self.isVertex(y) == False or self.isVertex(x) == False:
            raise ValueError("This vertex doesn't exist")
        # Mark all the vertices as not visited
        visited = [False] * (self.getNumberOfVertices())

        # Create a queue for BFS
        queue = []

        # Mark the source node as visited and enqueue it
        queue.append(y)
        visited = []
        visited.append(y)
        prev = dict()

        while queue:
            # n will take the first value put in queue
            n = queue.pop(0)

            if n == x:
                # if we found the desired Vertex, we will return *prev* dictionary
                return prev

            # go through every vertex that comes into n
            for i in self.__dictIn[n]:
                if i not in visited:
                    queue.append(i)
                    visited.append(i)
                    prev[i] = n

        # If BFS is complete without visited x
        return False

    def getPath(self, x, y):
        prev = self.reverseBFS(x, y)
        if (prev == False):
            raise ValueError("No path found!")
        pathEdges = []
        number = x
        while(number != y):
            pathEdges.append((number, prev[number]))
            number = prev[number]
        return pathEdges

    def __str__(self):
        return str("Directed graph: ") + str(self.__dictCosts)
