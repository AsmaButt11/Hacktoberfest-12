# Name: Burhan Haroon
# Username: ex-sherlock
# Description: It provides depth first search for a goal node in a graph.

# Implementing graph using python dictionary
graph = {
    'a': ['b', 'f', 'd', 'e'],
    'b': ['k', 'j'],
    'k': ['n', 'm'],
    'n': None,
    'm': None,
    'j': None,
    'f': None,
    'd': ['g'],
    'g': None,
    'e': ['c', 'h', 'i'],
    'c': None,
    'h': None,
    'i': ['l', 'z'],
    'l': None,
    'z': None
}

allNodes = list(graph.keys())  # Getting all nodes into an array
stack = ['a']  # Starting node/point for the graph

goalNode = str(input("What's the goal node: "))
if goalNode in allNodes:
    while(len(stack) != 0):
        elem = (stack.pop())
        if elem == goalNode:
            print("Goal node found: ", elem)
            break
        else:
            if graph[elem] == None:  # Checking if a node doesnt have left or right child
                continue
            else:
                length = graph[elem].__len__()
                for x in range(length, 0, -1):  # loop to push right to left child in stack
                    stack.append(graph[elem][x-1])
else:
    print("The node dosn't exiest in graph")
