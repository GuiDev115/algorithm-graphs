def DFS(graph, node, visited):
    stack = [(node, 0)]
    max_distance = 0
    farthest_node = node
    while stack:
        node, distance = stack.pop()
        if distance > max_distance:
            max_distance = distance
            farthest_node = node
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                stack.append((neighbor, distance + 1))
    return farthest_node, max_distance

def find_diameter(graph):
    # Escolha um nó arbitrário para iniciar a DFS
    arbitrary_node = list(graph.keys())[0]
    
    # Execute a DFS a partir do nó arbitrário para encontrar o nó mais distante
    farthest_node, _ = DFS(graph, arbitrary_node, set())
    
    # Execute a DFS novamente a partir do nó mais distante para encontrar o diâmetro
    _, diameter = DFS(graph, farthest_node, set())
    
    return diameter
