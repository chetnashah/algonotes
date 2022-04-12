

## Sample BinaryTree Implementation

```java
/**
 * Interface for dictionary data structures, defined on page 197 of
 * <i>Introduction to Algorithms</i>, Second edition.  Any object
 * inserted into a dictionary must implement the
 * <code>Comparable</code> interface.  In addition, for specific
 * implementations of the <code>Dictionary</code> interface, there may
 * be stronger restrictions on inserted objects, such as having to
 * implement the {@link DynamicSetElement} interface.
 */
public interface Dictionary
{
    /**
     * Inserts an element that implements <code>Comparable</code>.
     *
     * @param o The element to insert.
     * @return A handle to the inserted element.
     */
    public Object insert(Comparable o);

    /**
     * Removes an element.
     *
     * @param handle A handle to the element to remove.
     */
    public void delete(Object handle);

    /**
     * Searches for an element with a given key.  Depending on the
     * type of element inserted into the dictionary, the type of the
     * key given to this method may be the same as the type of the
     * objects inserted, or the type of the key given to this method
     * may be a different type than the type of the objects inserted
     * but still can be compared to the type of the inserted objects.
     * For example, see {@link DynamicSetElement.Helper#compareTo}.
     *
     * @param k The key being searched for.
     * @return A handle to the object found, or <code>null</code> if
     * there is no match.
     */
    public Object search(Comparable k);
}

/**
 * Implements the {@link Dictionary} interface as a binary search tree
 * from Chapter 12 of <i>Introduction to Algorithms</i>, Second
 * edition.  Objects inserted into a binary search tree must implement
 * the <code>Comparable</code> interface.
 *
 * <p>
 *
 * When extending this class, you must instantiate a new
 * <code>nil</code> of the proper type and override constructors along
 * with the other methods.  See {@link RedBlackTree} for an example.
 */

public class BinarySearchTree implements Dictionary
{
    /** Root of the binary search tree. */
    protected Node root;

    /** Sentinel, replaces NIL in the textbook's code. */
    protected Node nil;

    /**
     * Interface for when we visit a node during a walk.
     */
    public interface Visitor
    {
	/**
	 * Perform some action upon visiting the node.
	 *
	 * @param handle Handle that identifies the node being visited.
	 */
	public Object visit(Object handle);
    }

    /**
     * Inner class for a node of a binary search tree.  May be
     * extended in subclasses of <code>BinarySearchTree</code>.
     */
    protected class Node implements Comparable
    {
	/** The data stored in the node. */
	protected Comparable data;

	/** The node's parent. */
	protected Node parent;

	/** The node's left child. */
	protected Node left;

	/** The node's right child. */
	protected Node right;

	/**
	 * Initializes a node with the data and makes other pointers
	 * nil.
	 *
	 * @param data Data to save in the node.
	 */
	public Node(Comparable data)
	{
	    this.data = data;
	    parent = nil;
	    left = nil;
	    right = nil;
	}

	/**
	 * Compares this node to another node.  The comparison is
	 * based on the <code>data</code> instance variables of the
	 * two nodes.
	 *
	 * @param o The other node.
	 * @return A negative integer if this node is less than
	 * <code>o</code>; 0 if this node equals <code>o</code>; a
	 * positive integer if this node is greater than
	 * <code>o</code>.
	 * @throws ClassCastException if <code>o</code> is not a
	 * <code>Node</code>.
	 */
	// Compare this node to another node.
	public int compareTo(Object o)
	{
	    return data.compareTo(((Node) o).data);
	}

	/**
	 * Returns the <code>data</code> instance variable of this node
	 * as a <code>String</code>.
	 */
	public String toString()
	{
	    if (this == nil)
		return "nil";
	    else
		return data.toString();
	}

	/**
	 * Returns a multiline <code>String</code> representation of
	 * the subtree rooted at this node, representing the depth of
	 * each node by two spaces per depth preceding the
	 * <code>String</code> representation of the node.
	 *
	 * @param depth Depth of this node.
	 */
	public String toString(int depth)
	{
	    String result = "";

	    if (left != nil)
		result += left.toString(depth + 1);

	    for (int i = 0; i < depth; i++)
		result += "  ";

	    result += toString() + "\n";

	    if (right != nil)
		result += right.toString(depth + 1);

	    return result;
	}
    }

    /**
     * Sets the sentinel <code>nil</code> to a given node.
     *
     * @param node The node that <code>nil</code> is set to.
     */
    protected void setNil(Node node)
    {
	nil = node;
	nil.parent = nil;
	nil.left = nil;
	nil.right = nil;
    }

    /**
     * Creates a binary search tree with just a <code>nil</code>,
     * which is the root.
     */
    public BinarySearchTree()
    {
	setNil(new Node(null));
	root = nil;
    }

    /**
     * Returns <code>true</code> if the given node is the sentinel
     * <code>nil</code>, <code>false</code> otherwise.
     *
     * @param node The node that is being asked about.
     */
    public boolean isNil(Object node)
    {
	return node == nil;
    }

    /**
     * Traverses the tree in inorder applying a <code>Visitor</code>
     * to each node.
     *
     * @param visitor Object implementing <code>Visitor</code> whose
     * <code>visit</code> method is applied to each node in the tree.
     */
    public void inorderWalk(Visitor visitor)
    {
	inorderWalk(root, visitor);
    }

    /**
     * Performs an inorder walk of the the subtree rooted at a node,
     * applying a <code>Visitor</code> to each node in the subtree.
     *
     * @param x Root of the subtree.
     * @param visitor Object implementing <code>Visitor</code> whose
     * <code>visit</code> method is applied to each node in the
     * subtree.
     */
    protected void inorderWalk(Node x, Visitor visitor)
    {
	if (x != nil) {
	    inorderWalk(x.left, visitor);
	    visitor.visit(x);
	    inorderWalk(x.right, visitor);
	}
    }

    /**
     * Traverses the tree in preorder applying a <code>Visitor</code>
     * to each node.
     *
     * @param visitor Object implementing <code>Visitor</code> whose
     * <code>visit</code> method is applied to each node in the tree.
     */
    public void preorderWalk(Visitor visitor)
    {
	preorderWalk(root, visitor);
    }

    /**
     * Performs a preorder walk of the the subtree rooted at a node,
     * applying a <code>Visitor</code> to each node in the subtree.
     *
     * @param x Root of the subtree.
     * @param visitor Object implementing <code>Visitor</code> whose
     * <code>visit</code> method is applied to each node in the
     * subtree.
     */
    protected void preorderWalk(Node x, Visitor visitor)
    {
	if (x != nil) {
	    visitor.visit(x);
	    preorderWalk(x.left, visitor);
	    preorderWalk(x.right, visitor);
	}
    }

    /**
     * Traverses the tree in postorder applying a <code>Visitor</code>
     * to each node.
     *
     * @param visitor Object implementing <code>Visitor</code> whose
     * <code>visit</code> method is applied to each node in the tree.
     */
    public void postorderWalk(Visitor visitor)
    {
	postorderWalk(root, visitor);
    }

    /**
     * Performs a postorder walk of the the subtree rooted at a node,
     * applying a <code>Visitor</code> to each node in the subtree.
     *
     * @param x Root of the subtree.
     * @param visitor Object implementing <code>Visitor</code> whose
     * <code>visit</code> method is applied to each node in the
     * subtree.
     */
    protected void postorderWalk(Node x, Visitor visitor)
    {
	if (x != nil) {
	    postorderWalk(x.left, visitor);
	    postorderWalk(x.right, visitor);
	    visitor.visit(x);
	}
    }

    /**
     * Returns a multiline <code>String</code> representation of the
     * tree, representing the depth of each node by two spaces per
     * depth preceding the <code>String</code> representation of the
     * node.
     */
    public String toString()
    {
	return root.toString(0);
    }

    /**
     * Searches the tree for a node with a given key.  Works
     * recursively.
     *
     * @param k The key being searched for.
     * @return A reference to a <code>Node</code> object with key
     * <code>k</code> if such a node exists, or a reference to the
     * sentinel <code>nil</code> if no node has key <code>k</code>.
     * The <code>Node</code> class is opaque to methods outside this
     * class.
     */
    public Object search(Comparable k)
    {
	return search(root, k);
    }

    /**
     * Searches the subtree rooted at a given node for a node with a
     * given key.  Works recursively.
     *
     * @param x Root of the subtree.
     * @param k The key being searched for.
     * @return A reference to a <code>Node</code> object with key
     * <code>k</code> if such a node exists, or a reference to the
     * sentinel <code>nil</code> if no node has key <code>k</code>.
     * The <code>Node</code> class is opaque to methods outside this
     * class.
     */
    protected Object search(Node x, Comparable k)
    {
	int c;

	if (x == nil || (c = k.compareTo(x.data)) == 0)
	    return x;

	if (c < 0)
	    return search(x.left, k);
	else
	    return search(x.right, k);
    }

    /**
     * Searches the tree for a node with a given key.  Works
     * iteratively.
     *
     * @param k The key being searched for.
     * @return A reference to a <code>Node</code> object with key
     * <code>k</code> if such a node exists, or a reference to the
     * sentinel <code>nil</code> if no node has key <code>k</code>.
     * The <code>Node</code> class is opaque to methods outside this
     * class.
     */
    public Object iterativeSearch(Comparable k)
    {
	Node x = root;
	int c;

	while (x != nil && (c = k.compareTo(x.data)) != 0) {
	    if (c < 0)
		x = x.left;
	    else
		x = x.right;
	}

	return x;
    }

    /**
     * Returns the node with the minimum key in the tree.
     *
     * @return A <code>Node</code> object with the minimum key in the
     * tree, or the sentinel <code>nil</code> if the tree is empty.
     */
    public Object minimum()
    {
	return treeMinimum(root);
    }

    /**
     * Returns the node with the minimum key in the subtree rooted at
     * a node.
     *
     * @param x Root of the subtree.
     * @return A <code>Node</code> object with the minimum key in the
     * tree, or the sentinel <code>nil</code> if the tree is empty.
     */
    protected Object treeMinimum(Node x)
    {
	while (x.left != nil)
	    x = x.left;

	return x;
    }

    /**
     * Returns the node with the maximum key in the tree.
     *
     * @return A <code>Node</code> object with the maximum key in the
     * tree, or the sentinel <code>nil</code> if the tree is empty.
     */
    public Object maximum()
    {
	return treeMaximum(root);
    }

    /**
     * Returns the node with the maximum key in the subtree rooted at
     * a node.
     *
     * @param x Root of the subtree.
     * @return A <code>Node</code> object with the maximum key in the
     * tree, or the sentinel <code>nil</code> if the tree is empty.
     */
    protected Object treeMaximum(Node x)
    {
	while (x.right != nil)
	    x = x.right;

	return x;
    }

    /**
     * Returns the successor of a given node in an inorder walk of the
     * tree.
     *
     * @param node The node whose successor is returned.
     * @return If <code>node</code> has a successor, it is returned.
     * Otherwise, return the sentinel <code>nil</code>.
     */
    public Object successor(Object node)
    {
	Node x = (Node) node;
	
	if (x.right != nil)
	    return treeMinimum(x.right);

	Node y = x.parent;
	while (y != nil && x == y.right) {
	    x = y;
	    y = y.parent;
	}

	return y;
    }

    /**
     * Returns the predecessor of a given node in an inorder walk of
     * the tree.
     *
     * @param node The node whose predecessor is returned.
     * @return If <code>node</code> has a predecessor, it is returned.
     * Otherwise, return the sentinel <code>nil</code>.
     */
    public Object predecessor(Object node)
    {
	Node x = (Node) node;

	if (x.left != nil)
	    return treeMaximum(x.left);

	Node y = x.parent;
	while (y != nil && x == y.left) {
	    x = y;
	    y = y.parent;
	}

	return y;
    }

    /**
     * Inserts data into the tree, creating a new node for this data.
     *
     * @param data Data to be inserted into the tree.
     * @return A reference to the <code>Node</code> object created.
     * The <code>Node</code> class is opaque to methods outside this
     * class.
     */
    public Object insert(Comparable data)
    {
	Node z = new Node(data);
	treeInsert(z);

	return z;
    }

    /**
     * Inserts a node into the tree.
     *
     * @param z The node to insert.
     */
    protected void treeInsert(Node z)
    {
	Node y = nil;
	Node x = root;

	while (x != nil) {
	    y = x;
	    if (z.compareTo(x) <= 0)
		x = x.left;
	    else
		x = x.right;
	}

	z.parent = y;
	if (y == nil)
	    root = z;		// the tree had been empty
	else {
	    if (z.compareTo(y) <= 0)
		y.left = z;
	    else
		y.right = z;
	}
    }

    /**
     * Removes a node from the tree.
     *
     * @param node The node to be removed.
     * @throws DeleteSentinelException if there is an attempt to
     * delete the sentinel <code>nil</code>.
     * @throws ClassCastException if <code>node</code> does not
     * reference a <code>Node</code> object.
     */
    public void delete(Object node)
    {
	Node z = (Node) node;

	// Make sure that there is no attempt to delete the sentinel
	// nil.
	if (z == nil)
	    throw new DeleteSentinelException();

	Node x;			// Replaces z as the subtree's root
	
	if (z.left == nil)
	    x = z.right;
	else 
	    if (z.right == nil)
		x = z.left;
	    else {		// neither child is nil
		x = (Node) successor(z); // replace with next item
		delete(x);	// Free x from its current position
		
		// Splice out z and put x in its place by fixing links
		// with children.
		x.left = z.left; 
		x.right = z.right;
		x.left.parent = x;
		x.right.parent = x;
	    }

	// Fix links between the parent of the subtree and x.
	if (x != nil)
	    x.parent = z.parent;
	
	if (root == z)
	    root = x;
	else
	    if (z == x.parent.left)
		x.parent.left = x;
	    else
		x.parent.right = x;
    }

    /**
     * Returns the data stored in a node.
     *
     * @param node The node whose data is returned.
     * @throws ClassCastException if <code>node</code> does not
     * reference a <code>Node</code> object.
     */
    public static Comparable dereference(Object node)
    {
	return ((Node) node).data;
    }
}

// $Id: BinarySearchTree.java,v 1.1 2003/10/14 16:56:20 thc Exp $
// $Log: BinarySearchTree.java,v $
// Revision 1.1  2003/10/14 16:56:20  thc
// Initial revision.
//
```

## Sample RBTree implementation

```java
import java.awt.Color;

/**
 * Implements the {@link Dictionary} interface as a red-black tree
 * from Chapter 13 of <i>Introduction to Algorithms</i>, Second
 * edition.  Objects inserted into a red-black tree must implement the
 * <code>Comparable</code> interface.
 */

public class RedBlackTree extends BinarySearchTree
{
    /** Color for a red node. */
    protected static final Color RED = Color.red;

    /** Color for a black node. */
    protected static final Color BLACK = Color.black;

    /**
     * Exception thrown by {@link #blackHeight} if the black-height of
     * a node is ill-defined.
     */
    public static class BlackHeightException extends RuntimeException
    {
    }

    /**
     * Inner class for a red-black tree node.  Extends a binary search
     * tree node with an additional color field.
     */
    protected class Node extends BinarySearchTree.Node
    {
	/** The node's color, either RED or BLACK. */
	protected Color color;

	/**
	 * Initializes a node with the data, makes other pointers nil,
	 * and makes the node red.
	 *
	 * @param data Data to save in the node.
	 */
	public Node(Comparable data)
	{
	    super(data);
	    this.color = RED;
	}

	/**
	 * Returns the <code>data</code> instance variable of this
	 * node and this node's color as a <code>String</code>.
	 */
	public String toString()
	{
	    return super.toString() + ", " + (color == RED ? "red" : "black");
	}
    }

    /**
     * Set the sentinel <code>nil</code> to a given node, and make the
     * sentinel black.
     *
     * @param node The node that <code>nil</code> is set to.
     */
    protected void setNil(Node node)
    {
	node.color = BLACK;
	super.setNil(node);
    }

    /**
     * Creates a red-black tree with just a <code>nil</code>, which is
     * the root.
     */
    public RedBlackTree()
    {
	setNil(new Node(null));
	root = nil;
    }

    /**
     * Performs a left rotation on a node, making the node's right
     * child its parent.
     *
     * @param x The node.
     */
    protected void leftRotate(Node x)
    {
	Node y = (Node) x.right;

	// Swap the in-between subtree from y to x.
	x.right = y.left;
	if (y.left != nil)
	    y.left.parent = x;

	// Make y the root of the subtree for which x was the root.
	y.parent = x.parent;
	
	// If x is the root of the entire tree, make y the root.
	// Otherwise, make y the correct child of the subtree's
	// parent.
	if (x.parent == nil)
	    root = y;
	else 
	    if (x == x.parent.left)
		x.parent.left = y;
	    else
		x.parent.right = y;

	// Relink x and y.
	y.left = x;
	x.parent = y;
    }

    /**
     * Performs a right rotation on a node, making the node's left
     * child its parent.
     *
     * @param x The node.
     */
    protected void rightRotate(Node x)
    {
	Node y = (Node) x.left;

	x.left = y.right;
	if (x.left != null)
	    y.right.parent = x;

	y.parent = x.parent;

	y.right = x;
	x.parent = y;

	if (root == x)
	    root = y;
	else
	    if (y.parent.left == x)
		y.parent.left = y;
	    else
		y.parent.right = y;
    }

    /**
     * Inserts data into the tree, creating a new node for this data.
     *
     * @param data Data to be inserted into the tree.
     * @return A reference to the <code>Node</code> object created.
     * The <code>Node</code> class is opaque to methods outside this
     * class.
     */
    public Object insert(Comparable data)
    {
	Node z = new Node(data);
	treeInsert(z);

	return z;
    }

    /**
     * Inserts a node into the tree.
     *
     * @param z The node to insert.
     */
    protected void treeInsert(Node z)
    {
	super.treeInsert(z);
	insertFixup(z);
    }

    /**
     * Restores the red-black conditions of the tree after inserting a
     * node.
     *
     * @param z The node inserted.
     */
    protected void insertFixup(Node z)
    {
	Node y = null;

	while (((Node) z.parent).color == RED) {
	    if (z.parent == z.parent.parent.left) {
		y = (Node) z.parent.parent.right;
		if (y.color == RED) {
		    ((Node) z.parent).color = BLACK;
		    y.color = BLACK;
		    ((Node) z.parent.parent).color = RED;
		    z = (Node) z.parent.parent;
		}
		else {
		    if (z ==  z.parent.right) {
			z = (Node) z.parent;
			leftRotate(z);
		    }
		    
		    ((Node) z.parent).color = BLACK;
		    ((Node) z.parent.parent).color = RED;
		    rightRotate((Node) z.parent.parent);
		}
	    }
	    else {
		y = (Node) z.parent.parent.left;
		if (y.color == RED) {
		    ((Node) z.parent).color = BLACK;
		    y.color = BLACK;
		    ((Node) z.parent.parent).color = RED;
		    z = (Node) z.parent.parent;
		}
		else {
		    if (z ==  z.parent.left) {
			z = (Node) z.parent;
			rightRotate(z);
		    }
		    
		    ((Node) z.parent).color = BLACK;
		    ((Node) z.parent.parent).color = RED;
		    leftRotate((Node) z.parent.parent);
		}
	    }
	}
	((Node) root).color = BLACK;
    }

    /**
     * Removes a node from the tree.
     *
     * @param node The node to be removed.
     * @throws DeleteSentinelException if there is an attempt to
     * delete the sentinel <code>nil</code>.
     * @throws ClassCastException if <code>node</code> does not
     * reference a <code>Node</code> object.
     */
    public void delete(Object handle)
    {
	Node z = (Node) handle;
	Node y = z;
	Node x = (Node) nil;

	// Do not allow the sentinel to be deleted.
	if (z == nil)
	    throw new DeleteSentinelException();
	    
	if (z.left != nil && z.right != nil)
	    y = (Node) successor(z);

	if (z.left != nil)
	    x = (Node) y.left;
	else
	    x = (Node) y.right;

	x.parent = y.parent;

	if (y.parent == nil)
	    root = x;
	else
	    if (y == y.parent.left)
		y.parent.left = x;
	    else
		y.parent.right = x;

	if (y != z) {
	    y.left = z.left;
	    y.left.parent = y;
	    y.right = z.right;
	    y.right.parent = y;
	    y.parent = z.parent;
	    if (z == root)
		root = y;
	    else
		if (z == z.parent.left)
		    z.parent.left = y;
		else
		    z.parent.right = y;
	}

	if (y.color == BLACK)
	    deleteFixup(x);
    }
    
    /**
     * Restores the red-black properties of the tree after a deletion.
     *
     * @param x Node at which there may be a violation.
     */
    protected void deleteFixup(Node x)
    {
	while (x != root && x.color == BLACK) {
	    if (x.parent.left == x) {
		Node w = (Node) x.parent.right;

		if (w.color == RED) {
		    w.color = BLACK;
		    ((Node) x.parent).color = RED;
		    leftRotate((Node) x.parent);
		    w = (Node) x.parent.right;
		}

		if (((Node) w.left).color == BLACK 
		    && ((Node) w.right).color == BLACK) {
		    w.color = RED;
		    x = (Node) x.parent;
		}
		else {
		    if (((Node) w.right).color == BLACK) {
			((Node) w.left).color = BLACK;
			w.color = RED;
			rightRotate(w);
			w = (Node) x.parent.right;
		    }

		    w.color = ((Node) x.parent).color;
		    ((Node) x.parent).color = BLACK;
		    ((Node) w.right).color = BLACK;
		    leftRotate((Node) x.parent);
		    x = (Node) root;
		}
	    }
	    else {
		Node w = (Node) x.parent.left;

		if (w.color == RED) {
		    w.color = BLACK;
		    ((Node) x.parent).color = RED;
		    rightRotate((Node) x.parent);
		    w = (Node) x.parent.left;
		}

		if (((Node) w.right).color == BLACK 
		    && ((Node) w.left).color == BLACK) {
		    w.color = RED;
		    x = (Node) x.parent;
		}
		else {
		    if (((Node) w.left).color == BLACK) {
			((Node) w.right).color = BLACK;
			w.color = RED;
			leftRotate(w);
			w = (Node) x.parent.left;
		    }

		    w.color = ((Node) x.parent).color;
		    ((Node) x.parent).color = BLACK;
		    ((Node) w.left).color = BLACK;
		    rightRotate((Node) x.parent);
		    x = (Node) root;
		}		
	    }
	}
	x.color = BLACK;
    }

    /**
     * Returns the number of black nodes from a given node down to any
     * leaf.  The value should be the same for all paths.
     *
     * @param z The node.
     * @throws BlackHeightException if the number of black nodes on a
     * path from the left child down to a leaf differs from the number
     * of black nodes on a path from the right child down to a leaf.
     */
    public int blackHeight(Node z)
    {
	if (z == nil)
	    return 0;

	int left = blackHeight((Node) z.left);
	int right = blackHeight((Node) z.right);
	if (left == right)
	    if (z.color == BLACK)
		return left + 1;
	    else
		return left;
	else
	    throw new BlackHeightException();
    }

    /**
     * Returns the number of black nodes from the root down to any
     * leaf.  The value should be the same for all paths.
     *
     * @param z The node.
     * @throws BlackHeightException if the number of black nodes on a
     * path from the left child down to a leaf differs from the number
     * of black nodes on a path from the right child down to a leaf.
     */
    public int blackHeight()
    {
	return blackHeight((Node) root);
    }
}

// $Id: RedBlackTree.java,v 1.1 2003/10/14 16:56:20 thc Exp $
// $Log: RedBlackTree.java,v $
// Revision 1.1  2003/10/14 16:56:20  thc
// Initial revision.
//
```