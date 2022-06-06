/*
Lab 8
COMP-2540
By: Lucas Sarweh
ID: 110042658 
*/

/**
 * Lab 8 binary search tree
 */
public class Lab8 {
    // Attributes

    /**
     * Node class, each node is part of a Binary search tree
     */
    class Node {
        private Integer key; // Key

        private Node left; // Left node
        private Node parent; // Parent node
        private Node right; // Right node

        /**
         * Constructor constructs a node with given key setting attaching nodes to null
         * @param key The key of the node
         */
        public Node(Integer key){
            this.key = key;
            this.left = null;
            this.right = null;
            this.parent = null;
        }

        /**
         * Constructor constructs a node with given key setting left and right to null
         * and parent node to given parent
         * @param key The key of the node
         * @param parent The parent of the created node
         */
        public Node(Integer key, Node parent){
            this.key = key;
            this.left = null;
            this.right = null;
            this.parent = parent;
        }
    }

    // Root node attribute
    Node root;

    // Methods

    /**
     * No-arg constructor sets root to null
     */
    public Lab8(){
        this.root = null;
    }

    /**
     * Creates root node with given key
     * @param key Key of node
     */
    public Lab8(Integer key){
        // Initialize root node
        root = new Node(key);
    }

    /**
     * Creates node stemming from a given parent
     * @param key Key of node
     * @param parent Parent of node
     */
    public Lab8(Integer key, Node parent){
        // Initialize root node
        root = new Node(key, parent);
    }

    /**
     * Inserts a new node into binary search tree
     * @param x Root node
     * @param k Key of node
     * @return A node for recursion
     */
    public Node treeInsert(Node x, Integer k){
        // Catch any keys unable to be created
        try{
            Node t = null;
            if(x == null){
                // Create new node t with key k
                x = new Node(k);
                return x;

            }else if(k < x.key){
                t = x;
                x.left = treeInsert(x.left, k, x);
            }else if(k > x.key){
                t = x;
                x.right = treeInsert(x.right, k, x);
            }else{ // Aleady exists
                throw new Exception("Existing key!");
            }
            // Return new node
            return t;
        }catch(Exception e){
            // Notify std out of error
            System.out.println(e.getMessage());
            // Return self no new node created
            return x;
        }
    }

    /**
     * Recursive function called in other treeInsert() to include parent
     * node initialization
     * @param x The root node
     * @param k The node key
     * @param parent The parent of the node
     * @return The child node of the caller
     */
    private Node treeInsert(Node x, Integer k, Node parent){
        // Catch any keys unable to be created
        try{
            Node t = null;
            if(x == null){
                // Create new node t with key k
                t = new Node(k, parent);

            }else if(k < x.key){
                t = x;
                x.left = treeInsert(x.left, k, x);
            }else if(k > x.key){
                t = x;
                x.right = treeInsert(x.right, k, x);
            }else{ // Aleady exists
                throw new Exception("Existing key!");
            }
            // Return new node
            return t;
        }catch(Exception e){
            // Notify std out of error
            System.out.println(e.getMessage());
            // Return self no new node created
            return x;
        }
    }

    /**
     * Searches the binary search tree
     * @param x The root node
     * @param k The key to search for
     * @return The node containing key being searched for or null on failure
     */
    public Node treeSearch(Node x, Integer k){
        if(x == null || k == x.key){
            return x;
        }else if(k < x.key){
            return treeSearch(x.left, k);
        }else{
            return treeSearch(x.right, k);
        }
    }

    /**
     * Finds the smallest key node
     * @param x The root node
     * @return The smallest key node
     */
    public Node treeMin(Node x){
        while(x.left != null){
            x = x.left;
        }
        return x;
    }

    /**
     * Finds the smallest key node with a key greater than k
     * @param x Root node
     * @param k key must be k + 1 or more
     * @return The successor k in tree x
     */
    public Node successor(Node x, Integer k){
        Node start = treeSearch(x, k);
        if(start == null){
            return null;
        }
        if(start.right != null){
            return treeMin(start.right);
        }else{
            Node p = start.parent;
            while(p != null && start == p.right){
                start = p;
                p = start.parent;
            }
            return p;
        }
    }

    /**
     * In order tree traversal
     * @param x Root node of the tree
     */
    public void printTree(Node x){
        if(x == null){
            return;
        }
        if(x.left != null){
            printTree(x.left);
        }
        System.out.print(x.key + " ");
        if(x.right != null){
            printTree(x.right);
        }
    }

    public static void main(String[] args){
        // Part A
        // Create tree
        Lab8 mytree = new Lab8(16);
        // Values to insert
        Integer arr[] = {5, 18, 2, 15, 17, 19, 1, 3, 13, 12, 14};
        for(Integer i : arr){
            // Insert each value into tree
            mytree.treeInsert(mytree.root, i);
        }
        // Print tree using In order traversal
        mytree.printTree(mytree.root);
        System.out.println("");

        // Part B
        for(Integer k = 1; k <= 20; ++k){
            Node temp = mytree.treeSearch(mytree.root, k);
            if(temp != null){
                System.out.println("Value " + k + " found? " + "True");
                if(temp.parent != null){
                    System.out.println("Parent value: " + temp.parent.key);
                }else{
                    System.out.println("Parent value: null");
                }
            }else{
                System.out.println("Value " + k + " found? " + "False");
            }
        }

        // Part C
        for(Integer k = 1; k <= 20; ++k){
            Node succ = mytree.successor(mytree.root, k);
            if(succ != null){
                System.out.println("Successor of " + k + ": " + succ.key);
            }else{
                System.out.println("Successor of " + k + ": none");
            }
        }
    }
}
