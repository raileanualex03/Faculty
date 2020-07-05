from createRandomGraph import createRandom
from directedGraph import directedGraph
from getDataFromFile import getData, writeData


class UI:
    def __init__(self, graph):
        self.graph = graph

    def ui_change_cost(self):
        x = int(input(">>"))
        y = int(input(">>"))
        print( self.graph.getCostOfEdge(x, y))
        cost = int(input("Enter new cost: "))
        self.graph.changeCostOfEdge(x, y, cost)

    def ui_dOut_for_key(self):
        x = int(input(">>"))
        print("These is the number of vertices leaving from vertex {} :".format(x))
        print(self.graph.getOutDegreeOfVertex(x))

    def ui_dIn_for_key(self):
        x = int(input(">>"))
        print("These are the keys of the vertices coming to vertex {}:".format(x))
        print(self.graph.getInDegreeOfVertex(x))

    def ui_is_edge(self):
        x = int(input(">>"))
        y = int(input(">>"))
        print(self.graph.isEdge(x, y))

    def ui_add_edge(self):
        x = int(input(">>"))
        y = int(input(">>"))
        cost = int(input(">>"))
        self.graph.addEdge(x, y, cost)


    def ui_is_vertex(self):
        x = int(input(">>"))
        print(self.graph.isVertex(x))

    def ui_remove_edge(self):
        x = int(input(">>"))
        y = int(input(">>"))
        self.graph.removeEdge(x, y)


    def ui_remove_vertex(self):
        print("ATTENTION: This vertex will no longer exist and every other vertex will stay the same !")
        x = int(input(">>"))
        self.graph.removeVertex(x)

    def ui_add_vertex(self):
        x = int(input(">>"))
        self.graph.addVertex(x)

    def ui_get_all_vertices(self):
        print("These is the number of vertices: {}".format(self.graph.getNumberOfVertices()))


    def ui_outdegree(self):
        x = int(input(">>"))
        print("These is the number of vertices leaving from vertex {} :".format(x))
        print(self.graph.getOutDegreeOfVertex(x))

    def ui_indegree(self):
        x = int(input(">>"))
        print("These are the keys of the vertices coming to vertex {}:".format(x))
        print(self.graph.getInDegreeOfVertex(x))

    def ui_showVertices(self):
        print(self.graph.iterateVertices())

    def ui_parse_outbound_edges(self):
        x = int(input(">>"))
        for element in self.graph.parseOutboundEdgesOfVertex(x):
            print(element)

    def ui_parse_inbound_edges(self):
        x = int(input(">>"))
        for element in self.graph.parseInboundEdgesOfVertex(x):
            print(element)

    def ui_change_graphs(self):
        # TODO: -> this
        print("You just created a copy of this function !")
        self.graph.createCopyOfGraph()
        print(self.graph)
        print(self.graph.copy)

        print("You just changed the graphs between them ")
        self.graph, self.graph.copy = self.graph.copy, self.graph

        print(self.graph)
        print(self.graph.copy)

    def ui_check_path(self):
        x = int(input(">>"))
        y = int(input(">>"))
        path = self.graph.getPath(x, y)
        print("This is the path:", end=" ")
        for element in path:
            print(element, end=" ")
        print("\n The length of the path is: {}".format(len(path)))

    def ui_show_isolated_vertices(self):
        print(self.graph.getIsolatedVertices())

    @staticmethod
    def show_menu():
        print("""   
                    q: Quit and save to 'output.txt'
                    1: Check edge,
                    2: Add edge,
                    3: Check vertex,
                    4: Remove edge,
                    5: Remove vertex,
                    6: Add vertex,
                    7: Change the cost of an edge,
                    8: Show the number of vertices,
                    9: Show the inbound degree of a vertex,
                   10: Show the outbound degree of a vertex,
                   11: Show the vertices,
                   12: Show inbound edges of vertex,
                   13: Show outbound edges of vertex.
                   15: Show path between two vertices.
                   16: Show isolated vertices.
                   
                """)

    def menu(self):
        commands = {
            1: self.ui_is_edge,
            2: self.ui_add_edge,
            3: self.ui_is_vertex,
            4: self.ui_remove_edge,
            5: self.ui_remove_vertex,
            6: self.ui_add_vertex,
            7: self.ui_change_cost,
            8: self.ui_get_all_vertices,
            9: self.ui_indegree,
            10: self.ui_outdegree,
            11: self.ui_showVertices,
            12: self.ui_parse_inbound_edges,
            13: self.ui_parse_outbound_edges,
            14: self.ui_change_graphs,
            15: self.ui_check_path,
            16: self.ui_show_isolated_vertices,
            'q': quit,

        }
        while True:
            try:
                self.show_menu()
                command = input("Enter your command: ")
                if command == "q":
                    writeData("random_graph2.txt", self.graph)
                    quit()
                if int(command) not in commands:
                    raise ValueError("Invalid command")
                command = int(command)
                commands[command]()

            except Exception as e:
                print(e)
