def is_bipartite(graph, start):
    color = {}
    color[start] = 0
    stack = [start]
    
    while stack:
        node = stack.pop()
        for neighbor in graph[node]:
            if neighbor not in color:
                color[neighbor] = 1 - color[node]
                stack.append(neighbor)
            elif color[neighbor] == color[node]:
                return False
    return True
