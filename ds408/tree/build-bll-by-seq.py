
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def addleft(self, node: Node):
        self.left = node 

    def addright(self, node: Node):
        self.right = node

    def grow(self, preseq, midseq):
        rootid_in_mid = find(midseq, self.data)
        newnode = Node(preseq[0])
        if rootid_in_mid != 0:
            newnode.left = self.grow(preseq[1:], midseq)
          
    def __eq__(self, data):
        return self.data == data

    

def to_left_right(preseq, midseq):
    subroot = preseq[0]
     


def build_from_seq(preseq, midseq):
    root = Node(preseq[0]) 
    pres = preseq.copy()
    mids = midseq.copy()
    root.grow(pres, mids)
    return 

def main():
    pre_seq = [1, 2, 3, 4, 5, 6, 7]
    mid_seq = [3,2,4,1,5,6,7]
    

