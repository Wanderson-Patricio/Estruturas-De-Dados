package classes;

public class BinaryNode{
	private int value;
	private BinaryNode parent;
	private BinaryNode left;
	private BinaryNode right;
	
	public BinaryNode(int value) {
		this.value = value;
	}
	
	
	public boolean isLeaf() {
		return this.left == null && this.right == null;
	}
	public BinaryNode getParent() {
		return parent;
	}
	public void setParent(BinaryNode parent) {
		this.parent = parent;
	}
	public int getValue() {
		return value;
	}
	public void setValue(int value) {
		this.value = value;
	}
	public BinaryNode getLeft() {
		return left;
	}
	public void setLeft(BinaryNode left) {
		this.left = left;
	}
	public BinaryNode getRight() {
		return right;
	}
	public void setRight(BinaryNode right) {
		this.right = right;
	}
	
	public boolean isLeftChildren() {
		if(this.parent == null) return false;
		
		return this.parent.left.equals(this);
	}
	
	public String toString() {
		String result = "" + this.value + " - ";
		
		if(!this.isLeaf()) {
			result += "Childrens: ";
			
			if(this.left != null) {
				result += "left - " + this.left.value + " ";
			}
			if(this.right != null) {
				result += "right - " + this.right.value + " ";
			}
		}
		
		return result;
	}
	
	public boolean equals(BinaryNode o) {
		return this.value == o.value;
	}
}
