class node:
    
    def __init__(self, data) -> None:
        """Inicialização de um nó"""
        self.data = data
        self.left : node = None
        self.right : node = None
        self.parent : node = None
        self.height : int = 0
        self.leftHeight : int = 0
        self.rightHeight : int = 0
        
    def __eq__(self, __value: object) -> bool:
        """Verifica se um nó é igual a outro"""
        if isinstance(__value, node):
            if self.data == __value.data:
                return True

            return False
        
        return False
    
    def __str__(self) -> str:
        """Retorna as informações do nó"""
        result = f'{self.data}'
        if not self.isLeaf():
            result += ' - childrens: '
            if self.left != None:
                result += f'left - {self.left.data} '
            if self.right != None:
                result += f'right - {self.right.data} '
        
        return result
    
    def printOrder(self) -> None:
        print(self)
        
        if self.left != None:
            self.left.printOrder()
        if self.right != None:
            self.right.printOrder()
    
    def isLeaf(self) -> bool:
        """Retorna se o nó atual é uma folha"""
        return self.left == None and self.right == None
    
    def isLeftChildren(self) -> bool:
        """Verifica se o nó é o filho esquerdo do seu pai"""
        if self.parent != None and self.parent.left == self:
            return True
        
        return False
    
    def search(self, value):
        """Busca por um valor em um nó"""
        if self.data == value: return self

        if self.data > value: 
            if self.left != None:
                return self.left.search(value)
            else:
                return None
            
        else:
            if self.right != None:
                return self.right.search(value)
            else:
                return None
    
    def updateHeight(self) -> None:
        """Atualiza o valor da altura do nó"""
        left = 0 if self.left == None else self.left.height
        right = 0 if self.right == None else self.right.height
        
        def max(a, b):
            return a if a > b else b
        
        self.leftHeight = left
        self.rightHeight = right
        self.height = max(left, right) + 1
        
    def inOrderUpdateHeight(self) -> None:
        """Atualiza as alturas de todos os nós a partir de self"""
        if self.left != None:
            self.left.inOrderUpdateHeight()
        if self.right != None:
            self.right.inOrderUpdateHeight()
            
        self.updateHeight()
            
    def insert(self, value) -> None:
        """Insere um nóvo nó na subárvore gerada a partir de v"""
        
        if self.data > value:
            if self.left == None:
                
                self.left = node(value)
                self.left.parent = self
                
            else:
                self.left.insert(value)
                
        else:
            if self.right == None:
                
                self.right = node(value)
                self.right.parent = self
                
            else:
                self.right.insert(value)
          
    def findSucessor(self):
        """Retorna o sucessor do nó atual na sua subárvore direita"""
        aux = self.right
        while aux.left != None:
            aux = aux.left
            
        return aux
          