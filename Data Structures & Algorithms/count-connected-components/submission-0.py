class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = [i for i in range(n)]
        size = [1] * n

        def find(node):
            if parent[node] != node:
                parent[node] = find(parent[node])
            return parent[node]

        def union(node1, node2):
            node1, node2 = find(node1), find(node2)

            if node1 == node2:
                return 0

            if size[node1] > size[node2]:
                parent[node2] = node1
                size[node1] += size[node2]
            else:
                parent[node1] = node2
                size[node2] += size[node1]
            return 1
        
        res = n
        for n1, n2 in edges:
            res -= union(n1, n2)
        return res