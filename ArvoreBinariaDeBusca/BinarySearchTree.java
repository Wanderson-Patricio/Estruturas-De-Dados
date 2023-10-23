package classes;

public class BinarySearchTree {
	private BinaryNode root;
	

	public BinaryNode getRoot() {
		return root;
	}

	public void setRoot(BinaryNode root) {
		this.root = root;
	}
	
	private BinaryNode search(BinaryNode n, int value) {
		if(n == null) return null;
		
		if(n.getValue() == value) return n;
		if(n.getValue() > value) return this.search(n.getLeft(), value);
		return this.search(n.getRight(), value);
	}
	
	public BinaryNode search(int value) {
		return this.search(this.root, value);
	}
	
	public void updateHeight(BinaryNode node) {
        
        int left = (node.getLeft() != null) ? node.getLeft().getHeight() : 0;
        int right = (node.getRight() != null) ? node.getRight().getHeight() : 0;
        
        node.setHeight(Math.max(left, right) + 1);
        node.setLeftHeight(left);
        node.setRightHeight(right);
    }
	
	private void inOrderUpdateHeight(BinaryNode node) {
		if(node != null) {
			inOrderUpdateHeight(node.getLeft());
			inOrderUpdateHeight(node.getRight());
			updateHeight(node);
		}
	}
	
	private void insert(BinaryNode n, int value) {
		if(n.getValue() > value) {
			
			if(n.getLeft() == null) {
				n.setLeft(new BinaryNode(value));
				n.getLeft().setParent(n);
			}else {
				this.insert(n.getLeft(), value);
			}
			
		}else {
			
			if(n.getRight() == null) {
				n.setRight(new BinaryNode(value));
				n.getRight().setParent(n);
			}else {
				this.insert(n.getRight(), value);
			}
			
		}
	}
	
	public boolean insert(int value) {
		if(this.search(value) != null) return false;
		
		if(this.root == null) {
			this.root = new BinaryNode(value);
			this.root.setLeft(null);
		}else {
			this.insert(root, value);
		}
		
		inOrderUpdateHeight(root);
		return true;
	}
	
	private void printOrder(BinaryNode n) {
		if(n == null) return;
		
		this.printOrder(n.getLeft());
		System.out.println(n.toString());
		this.printOrder(n.getRight());
	}
	
	public void printOrder() {
		this.printOrder(root);
	}
	
	/*
	private BinaryNode findPredecessor(BinaryNode n) {
	 
		BinaryNode aux = n.getLeft();
		while(aux.getRight() != null) {
			aux = aux.getRight();
		}
		
		return aux;
	}
	*/
	
	private BinaryNode findSucessor(BinaryNode n) {
		BinaryNode aux = n.getRight();
		while(aux.getLeft() != null) {
			aux = aux.getLeft();
		}
		
		return aux;
	}
	
	public boolean remove(int value) {
	    BinaryNode nodeToRemove = this.search(value);

	    if (nodeToRemove == null) return false;

	    BinaryNode parent = nodeToRemove.getParent();

	    if (nodeToRemove.isLeaf()) {
	        if (nodeToRemove.isLeftChildren()) {
	            parent.setLeft(null);
	        } else {
	            parent.setRight(null);
	        }
	    } else if (nodeToRemove.getLeft() != null && nodeToRemove.getRight() != null) {
	        // Node has two children
	        // Find the in-order successor (smallest value in the right subtree)
	        BinaryNode successor = findSucessor(nodeToRemove);
	        int successorValue = successor.getValue();

	        // Remove the successor node, which is guaranteed to have 0 or 1 child
	        remove(successorValue);

	        // Replace the value of the node to be removed with the value of the successor
	        nodeToRemove.setValue(successorValue);
	    } else {
	        // Node has only one child
	        BinaryNode child = (nodeToRemove.getLeft() != null) ? nodeToRemove.getLeft() : nodeToRemove.getRight();

	        if (nodeToRemove.isLeftChildren()) {
	            parent.setLeft(child);
	            child.setParent(parent);
	        } else {
	            parent.setRight(child);
	            child.setParent(parent);
	        }
	    }
	    
	    this.inOrderUpdateHeight(root);

	    return true;
	}

}
