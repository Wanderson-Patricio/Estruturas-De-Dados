from node import *

class binarySearchTree:
    
    def __init__(self) -> None:
        """Cria uma árvore vazia"""
        self.root : node = None
    
    def print(self):
        """Imprime todos os nós da árvore"""
        self.root.printOrder()
        
    def search(self, value) -> node:
        """Busca por um valor na árvore"""
        return self.root.search(value)
    
    def insert(self, value) -> bool:
        """Inserção de um novo nó na árvore. Retorna também se houve sucesso na inserção"""
        if self.root == None:
            self.root = node(value, False)
            self.root.parent = None
            self.root.left = externalNode()
            self.root.right = externalNode()
        else:
            if self.search(value) != None: 
                return False
            
            self.root.insert(value)
            
        self.root.inOrderUpdateHeight()
        return True
    
    def remove(self, value) -> bool:
        """Inserção de um nó da árvore. Retorna também se houve sucesso na remoção"""
        nodeToRemove = self.search(value)
        
        if nodeToRemove == None: return False
        
        if nodeToRemove == self.root:
            if nodeToRemove.isLeaf():
                self.root = None
            elif nodeToRemove.left.isExternal and not nodeToRemove.right.isExternal:
                self.root = nodeToRemove.right
            elif not nodeToRemove.left.isExternal and nodeToRemove.right.isExternal:
                self.root = nodeToRemove.left
            else:
                nodeToRemove.left.right = nodeToRemove.right
                self.root = nodeToRemove.left
                
            return True
        
        ## if nodeToRemove isn't the root, then it has a parent
        
        parent = nodeToRemove.parent
        
        if nodeToRemove.isLeaf():
            if nodeToRemove.isLeftChildren():
                parent.left = externalNode()
            else:
                parent.right = externalNode()
                
        elif not nodeToRemove.left.isExternal and not nodeToRemove.right.isExternal:
            # Node has two children
	        # Find the in-order successor (smallest value in the right subtree)
            sucessor = nodeToRemove.findSucessor()
            sucessorValue = sucessor.data
            
            #Remove the successor node, which is guaranteed to have 0 or 1 child
            self.remove(sucessorValue)
            nodeToRemove.data = sucessorValue
            
        else:
            #Node has only one child
            child = nodeToRemove.left if not nodeToRemove.left.isExternal else nodeToRemove.right
            
            if nodeToRemove.isLeftChildren():
                parent.left = child
                child.parent = parent
            else:
                parent.right = child
                child.parent = parent
                
        self.root.inOrderUpdateHeight()
        return True