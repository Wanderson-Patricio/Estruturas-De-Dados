class node:
    ##############################################
    # INICIALIZAÇÃO
    def __init__(self, data, isExternal : bool) -> None:
        """Inicialização de um nó"""
        self.data = data
        self.left : node = None
        self.right : node = None
        self.parent : node = None
        self.height : int = 0
        self.leftHeight : int = 0
        self.rightHeight : int = 0
        self.color : str = 'red'
        self.isExternal = isExternal
        
        

    ##############################################
    #IGUALDADA
    def __eq__(self, __value: object) -> bool:
        """Verifica se um nó é igual a outro"""
        if isinstance(__value, node):
            if self.data == __value.data:
                return True

            return False
        
        return False
    
    ##############################################
    #STRING
    def __str__(self) -> str:
        """Retorna as informações do nó"""
        result = f'{self.data} - cor: {self.color}'
        if not self.isLeaf():
            result += ' - childrens: '
            if not self.left.isExternal:
                result += f'left - {self.left.data} ;'
            else:
                result += f'left - ext '
            if not self.right.isExternal:
                result += f'right - {self.right.data} '
            else:
                result += f'right - ext '
        else:
            result += ' => left - ext ;right - ext '
        
        return result
    
    ##############################################
    #IMPRESSÃO
    def printOrder(self) -> None:
        print(self)
        
        if not self.left.isExternal:
            self.left.printOrder()
        if not self.right.isExternal:
            self.right.printOrder()
    
    ##############################################

    def isLeaf(self) -> bool:
        """Retorna se o nó atual é uma folha"""
        return self.left.isExternal and self.right.isExternal
    
    ##############################################

    def isLeftChildren(self) -> bool:
        """Verifica se o nó é o filho esquerdo do seu pai"""
        if self.parent != None and self.parent.left == self:
            return True
        
        return False
    
    ##############################################

    def search(self, value):
        """Busca por um valor em um nó"""
        if self == None: return None
        if self.data == value: return self

        if self.data > value: 
            if not self.left.isExternal:
                return self.left.search(value)
            else:
                return None
            
        else:
            if not self.right.isExternal:
                return self.right.search(value)
            else:
                return None
    
    ##############################################

    def updateHeight(self) -> None:
        """Atualiza o valor da altura do nó"""
        left = 0 if self.left.isExternal else self.left.height
        right = 0 if self.right.isExternal else self.right.height
        
        def max(a, b):
            return a if a > b else b
        
        self.leftHeight = left
        self.rightHeight = right
        self.height = max(left, right) + 1

    ##############################################

    def inOrderUpdateHeight(self) -> None:
        """Atualiza as alturas de todos os nós a partir de self"""
        if not self.left.isExternal:
            self.left.inOrderUpdateHeight()
        if not self.right.isExternal:
            self.right.inOrderUpdateHeight()
            
        self.updateHeight()

    ##############################################

    def insert(self, value) -> None:
        """Insere um nóvo nó na subárvore gerada a partir de v"""
        
        if self.data > value:
            if self.left.isExternal:
                
                self.left = node(value, False)
                self.left.parent = self
                self.left.left = externalNode()
                self.left.right = externalNode()
                
            else:
                self.left.insert(value)
                
        else:
            if self.right.isExternal:
                
                self.right = node(value, False)
                self.right.parent = self
                self.right.left = externalNode()
                self.right.right = externalNode()
                
            else:
                self.right.insert(value)

    ##############################################

    def findSucessor(self):
        """Retorna o sucessor do nó atual na sua subárvore direita"""
        aux = self.right
        while not aux.left.isExternal:
            aux = aux.left
            
        return aux
    
    #################################################################################
    ## Propriedades das árvores AVL e Rubro-Negras
    #################################################################################      
    
    def balanceFactor(self) -> int:
        """Fator de balanceamento da AVL"""
        return self.leftHeight - self.rightHeight
    
    def rightRotation(self) -> None:
        """Rotação simples a Direita"""
        u = self.left
        t2 = u.right
        w = self.parent
        
        if self.parent != None:
            w.left = u
        
        u.right = self
        u.parent = w
        self.left = t2
        self.parent = u
        t2.parent = self
        
        
        
    def doubleRightRotation(self) -> None:
        """Rotação dupla a Direita"""
        u = self.right
        w = self.parent
        t2 = u.left
        t3 = u.right
        p = w.parent
        
        if p is not None:
            p.left = u
        
        u.parent = p
        u.right = w
        w.parent = u
        u.left = self
        self.parent = u
        self.right = t2
        t2.parent = self
        w.left = t3
        t3.parent = w
        
    def leftRotation(self) -> None:
        """Rotação simples a Esquerda"""
        u = self.right
        t2 = u.left
        w = self.parent
        
        if w is not None:
            w.right = u
        
        u.parent = w
        u.left = self
        self.parent = u
        self.right = t2
        t2.parent = self
            
    def doubleLeftRotation(self) -> None:
        """Rotação dupla a Esquerda"""
        u = self.left
        w = self.parent
        t2 = u.left
        t3 = u.right
        p = w.parent
        
        if p is not None:
            p.right = u

        u.parent = p        
        u.left = w
        w.parent = u
        u.right = self
        self.parent = u
        self.left = t3
        t3.parent = self
        w.right = t2
        t2.parent = w
        

        
        
##################################################################################
# Nó Externo
##################################################################################
        
class externalNode(node):
    def __init__(self) -> None:
        """Inicialização de um nó externo.
        Sempre inicializado como um nó negro, e sem carregar informação.
        """
        super().__init__(0, True)
        self.color = 'black'