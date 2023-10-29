from binarySearchTree import binarySearchTree
from RedBlackTree import RedBlackTree
from random import randint

def main():
    T = RedBlackTree()

    for i in range(10):
        T.insert(i)
    
    T.print()

if __name__ == '__main__':
    main()