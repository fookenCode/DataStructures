#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

class BinaryTree {
private:

	struct Node {
		Node *left, *right;
		int data;
	};

	Node *root;

	// Copy Constructor
	BinaryTree(const BinaryTree &other) { }
	// Assignment Operator
	BinaryTree operator=(const BinaryTree &other) {}


	void InsertNode(Node **traversal, Node **toAdd) {
		if (*traversal == 0) {
			*traversal = *toAdd;
			return;
		}

		if ((*traversal)->data >= (*toAdd)->data) {
			InsertNode(&(*traversal)->left, toAdd);
		}
		else {
			InsertNode(&(*traversal)->right, toAdd);
		}
	}

	void DeleteNode(Node **nodeToDelete) {
		if (*nodeToDelete == 0)
			return;

		if ((*nodeToDelete)->left != 0) {
			DeleteNode(&(*nodeToDelete)->left);
		}

		if ((*nodeToDelete)->right != 0) {
			DeleteNode(&(*nodeToDelete)->right);
		}

		delete (*nodeToDelete);
		(*nodeToDelete) = 0;
	}

	void PrintInOrder(Node *traversal) {
		if (traversal == 0) {
			return;
		}
		if (traversal->left != 0) {
			PrintInOrder(traversal->left);
		}
		printf("%d\n", traversal->data);
		if (traversal->right != 0) {
			PrintInOrder(traversal->right);
		}
	}

	void PrintPreOrder(Node *traversal) {
		if (traversal == 0) {
			return;
		}
		printf("%d\n", traversal->data);
		if (traversal->left != 0) {
			PrintInOrder(traversal->left);
		}		
		if (traversal->right != 0) {
			PrintInOrder(traversal->right);
		}
	}

	void PrintPostOrder(Node *traversal) {
		if (traversal == 0) {
			return;
		}
		if (traversal->left != 0) {
			PrintInOrder(traversal->left);
		}		
		if (traversal->right != 0) {
			PrintInOrder(traversal->right);
		}
		printf("%d\n", traversal->data);
	}

public:
	BinaryTree() : root(0) { }
	virtual ~BinaryTree() {
		if (root != 0) {
			RemoveAll();
		}
	}

	void RemoveAll() {
		DeleteNode(&root);
	}

	void AddItem(int valueToAdd) {
		Node *toAdd = new Node;
		toAdd->data = valueToAdd;
		toAdd->right = 0;
		toAdd->left = 0;
		if (root == 0) {
			root = toAdd;
		}
		else {
			InsertNode(&root, &toAdd);
		}
	}

	void PrintAllNodesInOrder() {
		PrintInOrder(root);
	}
	void PrintAllNodesPostOrder() {
		PrintPostOrder(root);
	}
	void PrintAllNodesPreOrder() {
		PrintPreOrder(root);
	}

	void Insert(int valueToAdd) {
		Node *toAdd = new Node;
		toAdd->data = valueToAdd;
		toAdd->right = toAdd->left = 0;

		if (root == 0) {
			root = toAdd;
		}
		else {
			Node *traverse = root;

			while (traverse != 0) {
				if (toAdd->data < traverse->data) {
					if (traverse->left != 0) {
						traverse = traverse->left;
					}
					else {
						traverse->left = toAdd;
						break;
					}
				}
				else {
					if (traverse->right != 0) {
						traverse = traverse->right;
					}
					else {
						traverse->right = toAdd;
						break;
					}
				}
			} // end While Loop
		} // end Root check
	} // end Insert

	void Remove(int valueToRemove) {
		if (root == 0) {
			return;
		}
		else {
			Node *traverse = root;
			Node *parent = 0;
			while (traverse != 0) {
				if (valueToRemove < traverse->data) {
					parent = traverse;
					traverse = traverse->left;
				}
				else if (valueToRemove > traverse->data) {
					parent = traverse;
					traverse = traverse->right;
				}
				else {
					// Value found, begin removal
					bool isLeftNodeRemoval = (parent != 0 && parent->left == traverse) ? true : false;
					if (traverse->left == 0 && traverse->right == 0) {
						// If node to delete has no children
						if (traverse == root) {
							root = 0;
						} 
						else {
							if (isLeftNodeRemoval) {
								parent->left = 0;
							}
							else {
								parent->right = 0;
							}
						}
						delete traverse;
						return;
					}
					else if (traverse->right == 0) {
						// If node to delete has 1 child (Left)
						if (traverse == root) {
							root = traverse->left;
						}
						else if (isLeftNodeRemoval) {
							parent->left = traverse->left;
						}
						else {
							parent->right = traverse->left;
						}
						delete traverse;
						return;
					}
					else if (traverse->left == 0) {
						// If node to delete has 1 child (Right)
						if (traverse == root) {
							root = traverse->right;
						}
						else if (isLeftNodeRemoval) {
							parent->left = traverse->right;
						}
						else {
							parent->right = traverse->right;
						}
						delete traverse;
						return;
					}
					else {
						// If node to delete has 2 children
						Node *successor = GetSuccessor(traverse);

						if (traverse == root) {
							root = successor;
						}
						else if (isLeftNodeRemoval) {
							parent->left = successor;
						}
						else {
							parent->right = successor;
						}
						// preserve the subtree of the removed node's left branch
						successor->left = traverse->left;

						delete traverse;
						return;
					}
				}
			} // end While Loop
		} // end Root check
	}

	Node *GetSuccessor(Node *toDelete) {
		Node *successor = toDelete;
		Node *successorParent = toDelete;
		Node *current = toDelete->right;

		while (current != 0) {
			successorParent = successor;
			successor = current;
			current = current->left;
		}

		if (successor != toDelete->right) {
			// Removes the New Node's RIGHT node to its parent (to preserve the sub-tree), frees up the Right pointer in the Node
			successorParent->left = successor->right;
			// Set the Right pointer to the RIGHT subtree of the Node to be deleted.
			successor->right = toDelete->right;
		}
		return successor;
	}
};
#endif //_BINARY_TREE_H_