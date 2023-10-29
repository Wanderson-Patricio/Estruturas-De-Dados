from binarySearchTree import binarySearchTree
from node import *

class RedBlackTree(binarySearchTree):
     
    def __init__(self) -> None:
        """Inicialização de uma árvore Rubro-Negra"""
        super().__init__()
        
    def insert(self, value) -> bool:
        inserted = super().insert(value)
        # não foi inserido
        if not inserted:
            return False
        # q é o nó que foi inserido
        q = self.search(value)
        # foi o primeiro inserido e é a raiz
        if q == self.root:
            q.color = 'black' #A raíz é negra
            return True
        # v é o pai de q
        v = q.parent
        
        def change(v: node) -> None:
            if v.parent is None:
                return
            w = v.parent
            t = w.right if v.isLeftChildren() else w.left
            if v.color == 'red' and t.color == 'red':
                v.color = 'black'
                t.color = 'black'
                w.color = 'red'
                if w.parent is not None and w.parent.color == 'red':
                    w.color = 'black'
                    w.parent.color = 'black'
        
        match v.color:
            case 'black':
                pass
            
            case 'red':
                if v == self.root:
                    v.color = 'black'
                else:
                    # w é o pai de v, avô de q, e t é o irmão de v
                    w = v.parent
                    t = w.right if v.isLeftChildren() else w.left
                    
                    match t.color:
                        case 'red':
                            ## Troca de cores de pai, avô e tio
                            change(v)
                            pass
                            
                        case 'black':
                            if q.isLeftChildren() and v.isLeftChildren():
                                isWRoot = w == self.root
                                w.rightRotation()
                                
                                v.color = 'black'
                                w.color = 'red'
                                if isWRoot:
                                    self.root = v
                                    
                                
                            elif not q.isLeftChildren() and v.isLeftChildren():
                                isWRoot = w == self.root
                                w.doubleRightRotation()
                                q.color = 'black'
                                w.color = 'red'
                                if isWRoot:
                                    self.root = v
                                
                            elif not q.isLeftChildren() and not v.isLeftChildren():
                                isWRoot = w == self.root
                                w.leftRotation()
                                v.color = 'black'
                                w.color = 'red'
                                if isWRoot:
                                    self.root = v
                                
                            else:
                                isWRoot = w == self.root
                                w.doubleLeftRotation()
                                q.color = 'black'
                                w.color = 'red'
                                if isWRoot:
                                    self.root = v
                                
                            pass
                        
        return True