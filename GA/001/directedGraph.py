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

    def WarshallAlgorithm(self):
        dist = []
        next = []
        # initiating the dist matrix
        for i in range(self.getNumberOfVertices()+1):
            currentList = []
            for j in range(self.getNumberOfVertices()+1):
                currentList.append(100000) # infinity
            dist.append(currentList)

        # initiating the next matrix
        for i in range(self.getNumberOfVertices()+1):
            currentList = []
            for j in range(self.getNumberOfVertices()+1):
                currentList.append(0)
            next.append(currentList)

        # putting in the values of the corresponding edges in the matrix
        for edge in self.__dictCosts:
            dist[edge[0]][edge[1]] = self.__dictCosts[edge]
            next[edge[0]][edge[1]] = edge[1]

        for i in self.__dictIn:
            dist[i][i] = 0
            next[i][i] = i

        file = open("lab3.txt", "w")      # in order to put every matrix in the file
        for k in range(self.getNumberOfVertices()+1):
            for i in range(self.getNumberOfVertices()+1):
                for j in range(self.getNumberOfVertices()+1):
                    # here we check every possible combination
                    if(dist[i][j] > dist[i][k] + dist[k][j]):
                        dist[i][j] = dist[i][k] + dist[k][j]
                        next[i][j] = next[i][k]

                    # using this to put the matrix in the file
            for line in dist:
                for element in line:
                       file.write(str(element) + ' , ')
                file.write("\n")
            file.write("Next step...\n")
        # then we return the two matrices: dist and next.
        return dist, next

    def getPath(self, x,  y):
        if (self.isVertex(x) == False or self.isVertex(y) == False):
            raise ValueError("No vertex found!")
        if self.isEdge(x, y):
            return [x, y], self.getCostOfEdge(x, y)
        dist, next = self.WarshallAlgorithm()
        if next[x][y] == 0:
            return [], []
        path = [x]
        while x != y:
            # while we haven't reached the last element, we go to the next one using the next matrix.
            x = next[x][y]
            # then we append the current element to the path list such that we can keep track
            path.append(x)
        # here we find the cost.
        cost = 0
        for i in range(len(path) - 1):
            # we go through every element of the path and get the cost needed of that specific edge
            # consisting of current element and the next one of the list
            cost += self.getCostOfEdge(path[i], path[i+1])
        return path, cost


    def KruskalAlgorithm(self):
        # putting each edge in a list as [firstVertex, secondVertex, costOfEdge]
        edgesSorted=[]
        for key in self.__dictCosts:
            edgesSorted.append([key[0], key[1], self.__dictCosts[key]])

        # sorting the list increasing by each cost of the edge
        edgesSorted = sorted(edgesSorted, key=lambda x: x[2])

        # in edges I ll keep only the edges wanted.
        edges = []

        for edge in edgesSorted:
            edges.append(edge)
            if self.isCyclic(edges) != False:
                edges.pop(len(edges)-1)

        # here we check if we actually have a good path
        visited = [False]*self.__vertices
        for element in edges:
            if visited[element[0]] == False:
                visited[element[0]] = True
            if visited[element[1]] == False:
                visited[element[1]] = True
        for element in visited:
            if element == False:
                print("bad input :)")
                return False

        return edges


    def isCyclicUtil(self, edges,  v, visited, parent):

        # Mark the current node as visited
        visited[v] = True

        # Recur for all the vertices adjacent to this vertex
        newList = []
        for element in edges:
            if element[0] == v:
                newList.append(element[1])
            if element[1] == v:
                newList.append(element[0])

        # newList = list of adjacent vertices with vertex
        for i in newList:
            # If the vertex is not visited then recurse on it
            if visited[i] == False:
                if (self.isCyclicUtil(edges, i, visited, v)):
                    return True
            # If an adjacent vertex is visited and not parent of current vertex,
            # then there is a cycle
            elif parent != i:
                return True
        return False

    def isCyclic(self, edges):
        # edges = a list containing all the edges in format [firstVertex, secondVertex, cost]
        visited = [False] * self.__vertices
        for i in range(self.__vertices):
            if visited[i] == False:
                if self.isCyclicUtil(edges, i, visited, -1):
                    return True
        return False

    def showCycle(self):
        edgesSorted = []
        for key in self.__dictCosts:
            edgesSorted.append([key[0], key[1], self.__dictCosts[key]])
        return self.isCyclic(edgesSorted)


    def canGo(self, v, pos, path):
        # this method will check if it is safe to go from last element of the path and the next vertex
        # by safe I mean either it is an edge between them
        # and check if it is not already in the path
        if self.isEdge(path[pos-1], v) == False or self.isEdge(v, path[pos-1]):
            return False
        # if we have an edge we check if this vertex isn't already in the path
        for vertex in path:
            if vertex == v:
                # if the vertex already is in the path then we return False
                return False

        return True

    def hamiltonianCycleUtil(self, path, pos):
        # here we check if we reached a cycle
        if pos == self.__vertices:
            if self.isEdge(path[pos-1], path[0]) or self.isEdge(path[0], path[pos-1]) == True:
                return True
            else:
                return False
        # ------
        # here we iterate through the remaining set of vertices
        for vertex in range(1, self.__vertices):
            # we check if we can go on this vertex
            if self.canGo(vertex, pos, path) == True:
                path[pos] = vertex
                # if we can go then we put the vertex in that position and we call recursively  this function on this vertex and next position
                if self.hamiltonianCycleUtil(path, pos+1)== True:
                    return True
                path[pos] = -1
        return False

    def hamCycle(self):
        path = [-1] * self.__vertices

        path[0] = 0
        if self.hamiltonianCycleUtil(path, 1)== False:
            print("No solution found!")
            return False
        print(path)
        return True 


    def __str__(self):
        return str("Directed graph: ") + str(self.__dictCosts)
