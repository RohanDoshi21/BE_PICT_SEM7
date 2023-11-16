import heapq

class Node:
    def __init__(self, val, symbol) -> None:
        self.val = val
        self.symbol = symbol
        self.huffman = ''
        self.l = None
        self.r = None

    def __lt__(self, next):
        return self.val < next.val

nodes = []
char = ['a', 'b', 'c', 'd', 'e']
freq = [100, 12, 24, 105, 38]

for i in range(len(char)):
    heapq.heappush(nodes, Node(freq[i], char[i]))

while len(nodes) > 1:
    left = heapq.heappop(nodes)
    right = heapq.heappop(nodes)
    left.huffman = '0'
    right.huffman = '1'

    newNode = Node(left.val + right.val, left.symbol + right.symbol)
    newNode.l = left
    newNode.r = right
    heapq.heappush(nodes, newNode)

def printNodes(node, val=''):
    newVal = val + node.huffman

    if node.l:
        printNodes(node.l, newVal)

    if node.r:
        printNodes(node.r, newVal)

    if not node.l and not node.r:
        print(f"{node.symbol} -> {newVal}")

printNodes(nodes[0])