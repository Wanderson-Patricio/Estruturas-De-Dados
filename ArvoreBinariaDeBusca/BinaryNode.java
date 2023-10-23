package classes;

public class BinaryNode{
	private int value;
	private BinaryNode parent;
	private BinaryNode left;
	private BinaryNode right;
	private int height, leftHeight, rightHeight;
	
	public BinaryNode(int value) {
		this.value = value;
	}
	
	
	public int getLeftHeight() {
		return leftHeight;
	}
	public void setLeftHeight(int leftHeight) {
		this.leftHeight = leftHeight;
	}
	public int getRightHeight() {
		return rightHeight;
	}
	public void setRightHeight(int rightHeight) {
		this.rightHeight = rightHeight;
	}
	public int getHeight() {
		return height;
	}
	public void setHeight(int height) {
		this.height = height;
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
		String result = "" + this.value + " - height : " + this.height + " - ";
		
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
