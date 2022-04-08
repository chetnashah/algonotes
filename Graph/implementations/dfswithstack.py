
graph = { 
    "a": ["b", "c"],
    "b": ["d"],
    "c": ["e"],
    "d": ["f"],
    "e": [],
    "f": []
};

def dfsWithStack(graph):
    stack = []
    visited = {} # this could also have been an array or a set
    stack.append("a") # starting source is first vertex

    while(len(stack) > 0):
        u = stack.pop() # popping is when the visiting/exploring happens
        visited[u] = True
        print("visited : ", u)
        for v in graph[u]:
            if ((v in visited) == False):
                stack.append(v)

dfsWithStack(graph)
