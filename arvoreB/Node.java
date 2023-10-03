public class Node {
	private int order;
	private int[] keys;
	private int size;
	private boolean isLeaf;
    private Node parent;
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

    public int[] getKeys(){
        return keys;
    }

	public int getSize() {
		return size;
	}

    public void setSize(int size){
        this.size = size;
    }

	public boolean isLeaf() {
		return isLeaf;
	}

     public Node getParent() {
        return parent;
    }

	public Node getChildren(int i) {
		return this.childrens[i];
	}

    public Node[] getChildrens(){
        return this.childrens;
    }

    
    public boolean isFull(){
        return this.size == 2*this.order;
    }

    public boolean isEmpty(){
        return this.size == 0;
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
		if(this.isFull() || this.busca(valor) != -1) return;
        int index = 0;
		
		if(this.keys[0] > valor){
			index = 0;
        }else if(valor > this.keys[this.size >= 1 ? this.size-1 : 0]){
            index = this.size;
        }else{
            for(int i = 1; i<this.size-1; i++){

                if(this.keys[i] > valor && this.keys[i-1] < valor){
                    index = i;
                    break;
                }

            }
        }


		
		for (int i = this.size - 1; i >= index; i--) {  // Correção aqui
            this.keys[i + 1] = this.keys[i];
        }
		
		this.keys[index] = valor;
        this.size++;
	}

    public void remove(int index){
        if(this.isEmpty() || this.size -1 < index || index < 0) return;

        for(int i = index; i<this.size - 1; i++){
            this.keys[i] = this.keys[i+1];
        }

        this.size--;
    }
	
	void imprime(){
		for(int i = 0; i< this.size; i++){
			System.out.println(this.keys[i]);
		}
	}
	
}
