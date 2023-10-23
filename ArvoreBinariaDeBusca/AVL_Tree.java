package classes;

public class AVL_Tree extends BinarySearchTree{
	
	private int balanceFactor(BinaryNode node) {
        return node.getLeftHeight() - node.getRightHeight();
    }
	
	private void rightRotation(BinaryNode p) {
		BinaryNode u = p.getLeft();
		BinaryNode t2 = u.getRight();
		
		u.setRight(p);
		p.setLeft(t2);
	}
	
	private void doubleRightRotation(BinaryNode p) {
		BinaryNode u = p.getRight(), w = p.getParent();
		BinaryNode t2 = u.getLeft(), t3 = u.getRight();
		
		u.setRight(w);
		u.setLeft(p);
		p.setRight(t2);
		w.setLeft(t3);
	}
	
	private void leftRotation(BinaryNode p) {
		BinaryNode u = p.getRight(), t2 = u.getLeft();
		
		u.setLeft(p);
		p.setRight(t2);
	}
	
	private void doubleLeftRotation(BinaryNode p) {
		BinaryNode u = p.getLeft(), w = p.getParent();
		BinaryNode t2 = u.getLeft(), t3 = u.getRight();
		
		u.setLeft(w);
		w.setRight(t2);
		p.setLeft(t3);
	}
	
	private void rebalance(BinaryNode node) {
        if (node == null) {
            return;
        }
        
        updateHeight(node); // Update the height of the current node

        int balanceFactor = balanceFactor(node);

        // Perform rotations to balance the tree
        if (balanceFactor > 1) {
            if (balanceFactor(node.getLeft()) >= 0) {
                // Left-Left case
                rightRotation(node);
            } else {
                // Left-Right case
                doubleRightRotation(node);
            }
        } else if (balanceFactor < -1) {
            if (balanceFactor(node.getRight()) <= 0) {
                // Right-Right case
                leftRotation(node);
            } else {
                // Right-Left case
                doubleLeftRotation(node);
            }
        }

        // Recursively rebalance the parent nodes
        if (node.getParent() != null) {
            rebalance(node.getParent());
        } else {
            // If the root has been rotated, update the root reference
            if (node.isLeaf()) {
                setRoot(node);
            }
        }
    }
	
	// Override the insert method to rebalance the tree
    @Override
    public boolean insert(int value) {
        boolean inserted = super.insert(value);
        if (inserted) {
            BinaryNode node = search(value);
            rebalance(node);
        }
        return inserted;
    }

    // Override the remove method to rebalance the tree
    @Override
    public boolean remove(int value) {
        boolean removed = super.remove(value);
        if (removed) {
            if (getRoot() != null) {
                rebalance(getRoot());
            }
        }
        return removed;
    }
	
}
