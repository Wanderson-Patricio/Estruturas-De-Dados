public class Node {
	private int order;
	private int[] keys;
	private int size;
	private boolean isLeaf;
	private Node[] childrens;
	
	public Node(int order, boolean isLeaf) {
		this.order = order;
		this.size = 0;
		this.isLeaf = isLeaf;
		this.keys = new int[2*order];
		this.childrens = new Node[2*order + 1];
	}

	public int getOrder() {
		return order;
	}

	public int getKey(int i) {
		return this.keys[i];
	}

	public int getSize() {
		return size;
	}

	public boolean isLeaf() {
		return isLeaf;
	}

	public Node getChildren(int i) {
		return this.childrens[i];
	}
	
	public int busca(int valor){
		int fim = this.size-1;
		int inicio = 0;
		int meio = (fim+inicio)/2;
		
		int index = -1;
		
		while(inicio <= fim){
			
			if(this.keys[meio] == valor){
				index = meio;
				break;
			}
			
			if(valor < this.keys[meio]) fim = meio - 1;
			if(valor > this.keys[meio]) inicio = meio + 1;
			
			meio = (inicio + fim)/2;
		}
		
		return index;
	}
	
	public void insert(int valor){
		if(this.busca(valor) == 1 || this.size >= 2*this.order) return;
		
		int fim = this.size-1;
		int inicio = 0;
		int meio = (fim+inicio)/2;
		
		int index = -1;
		
		if(this.keys[0] > valor){
			index = 0;
		}else if(valor > this.keys[this.size - 1]){
			index = this.size;
		}else{
			while(inicio <= fim){
				
				if(valor < this.keys[meio]){
					
					if(valor > this.keys[meio - 1]){
						index = meio;
						break;
					}else{
						fim = meio - 1;
					}
					
				}else{
					
					if(valor < this.keys[meio + 1]){
						index = meio + 1;
						break;
					}else{
						inicio = meio + 1;
					}
					
				}
				
				meio = (inicio + fim)/2;
				
			}
		}
		
		for(int i=index; i<this.size; i++){
			this.keys[i+1] = this.keys[i];
		}
		
		this.keys[index] = valor;
	}
	
	void imprime(){
		for(int x: this.keys){
			System.out.println(x);
		}
	}
	
	
	public static void main(String[] args) {
		Node n = new Node(15, true);
		
		n.insert(5);
		n.insert(15);
		n.insert(25);
		n.insert(-5);
		n.insert(0);
		
		n.imprime();
	}
}
