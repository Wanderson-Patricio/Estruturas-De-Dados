from node import node

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
            self.root = node(value)
            self.root.parent = None
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
        
        parent = nodeToRemove.parent
        
        if nodeToRemove.isLeaf():
            if nodeToRemove.isLeftChildren():
                parent.left = None
            else:
                parent.right = None
                
        elif nodeToRemove.left != None and nodeToRemove.right != None:
            # Node has two children
	        # Find the in-order successor (smallest value in the right subtree)
            sucessor = nodeToRemove.findSucessor()
            sucessorValue = sucessor.data
            
            #Remove the successor node, which is guaranteed to have 0 or 1 child
            self.remove(sucessorValue)
            nodeToRemove.data = sucessorValue
            
        else:
            #Node has only one child
            child = nodeToRemove.left if nodeToRemove.left != None else nodeToRemove.right
            
            if nodeToRemove.isLeftChildren():
                parent.left = child
                child.parent = parent
            else:
                parent.right = child
                child.parent = parent
                
        self.root.inOrderUpdateHeight()
        return True