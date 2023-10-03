public class BTree{
    private int order;
    private Node root;

    public BTree(int order){
        this.order = order;
        this.root = new Node(order, true);
    }

    public int getOrder() {
        return order;
    }

    public Node getRoot() {
        return root;
    }

    public void setRoot(Node root) {
        this.root = root;
    }

    public boolean isEmpty(){
        return this.root.isEmpty();
    }

    public Node busca(int valor){
        if(this.root == null || this.isEmpty()) return null;
        Node aux = this.root;

        while(aux.busca(valor) == -1 || aux == null){
            if(valor < aux.getKey(0)){
                aux = aux.getChildren(0);
            }else if(valor > aux.getKey(aux.getSize()-1)){
                aux = aux.getChildren(aux.getSize());
            }else{

                for(int i=1; i<aux.getSize()-1; i++){
                    if(valor > aux.getKey(i) && valor < aux.getKey(i+1)){
                        aux = aux.getChildren(i+1);
                        break;
                    }
                }

            }
        }

        return aux;
    }

    private void splitChild(Node parentNode, int childIndex) {
        Node childNode = parentNode.getChildrens()[childIndex];
        Node newChildNode = new Node(order, childNode.isLeaf());

        parentNode.setSize(parentNode.getSize() + 1);
        for (int j = parentNode.getSize() - 1; j > childIndex; j--) {
            parentNode.getKeys()[j] = parentNode.getKeys()[j - 1];
        }
        parentNode.getKeys()[childIndex] = childNode.getKeys()[order];

        for (int j = parentNode.getSize(); j > childIndex + 1; j--) {
            parentNode.getChildrens()[j] = parentNode.getChildrens()[j - 1];
        }
        parentNode.getChildrens()[childIndex + 1] = newChildNode;

        for (int j = 0; j < order; j++) {
            newChildNode.getKeys()[j] = childNode.getKeys()[j + order];
        }

        if (!childNode.isLeaf()) {
            for (int j = 0; j < order; j++) {
                newChildNode.getChildrens()[j] = childNode.getChildrens()[j + order];
            }
        }

        childNode.setSize(order);
    }

    private void insertNonFull(Node node, int key) {
        int i = node.getSize() - 1;

        if (node.isLeaf()) {
            while (i >= 0 && key < node.getKeys()[i]) {
                node.getKeys()[i + 1] = node.getKeys()[i];
                i--;
            }
            node.getKeys()[i + 1] = key;
            node.setSize(node.getSize() + 1);
        } else {
            while (i >= 0 && key < node.getKeys()[i]) {
                i--;
            }
            i++;

            Node child = node.getChildrens()[i];
            if (child.getSize() == 2 * order) {
                splitChild(node, i);
                if (key > node.getKeys()[i]) {
                    i++;
                }
            }
            insertNonFull(node.getChildrens()[i], key);
        }
    }

    public void insert(int key) {
        Node rootNode = root;

        if (rootNode.getSize() == 2 * order) {
            Node newRoot = new Node(order, false);
            newRoot.getChildrens()[0] = root;
            splitChild(newRoot, 0);
            root = newRoot;
            insertNonFull(root, key);
        } else {
            insertNonFull(rootNode, key);
        }
    }

    private  void printBTree(Node node) {
        if (node != null) {
            System.out.print("Keys: ");
            for (int i = 0; i < node.getSize(); i++) {
                System.out.print(node.getKeys()[i] + " ");
            }
            System.out.println();

            if (!node.isLeaf()) {
                System.out.println("Children:");
                for (int i = 0; i <= node.getSize(); i++) {
                    printBTree(node.getChildrens()[i]);
                }
            }
        }
    }

    public void print(){
        printBTree(root);
    }

}
