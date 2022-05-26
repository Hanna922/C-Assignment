#include <iostream>
using namespace std;

template <class T>
class TreeNode {
public:
	T data;
	TreeNode<T>* leftChild = NULL;
	TreeNode<T>* rightChild = NULL;
	TreeNode(T temp) : data(temp), leftChild(NULL), rightChild(NULL) {}
};

template <class K, class E>
class Dictinary {
public:
	virtual bool IsEmpty() const = 0;
	virtual pair<K, E>* Get(const K&) const = 0;
	virtual void Insert(const pair<K, E>&) = 0;
	virtual void Delete(const K&) = 0;
};

template <class K, class E>
class BST : public Dictinary<K, E> {
private:
	TreeNode<pair<K, E>>* root;
public:
	BST();
	bool IsEmpty() const;
	pair<K, E>* Get(const K& k) const;
	void Insert(const pair<K, E>& thePair);
	void Delete(const K& k);
	void Inorder();
	void Inorder(TreeNode<pair<K, E>>* currentNode);
	
	template<class K, class E>
	friend ostream& operator<<(ostream& os, const pair<K, E>& p);
};

template<class K, class E>
ostream& operator<<(ostream& os, const pair<K, E>& p)
{
	os << "[" << p.first << "," << p.second << "]" << " ";
	return os;
}

template<class K, class E>
BST<K, E>::BST() : root(NULL) {

}

template<class K, class E>
bool BST<K, E>::IsEmpty() const
{
	return false;
}

template<class K, class E>
pair<K, E>* BST<K, E>::Get(const K& k) const
{
	TreeNode<pair<K, E>>* currentNode = root;
	while (currentNode) {
		if (k < currentNode->data.first) {
			currentNode = currentNode->leftChild;
		}
		else if (k > currentNode->data.first) {
			currentNode = currentNode->rightChild;
		}
		else {
			cout << currentNode->data;
			return &currentNode->data;
		}
	}

	if (currentNode == NULL) {
		cout << "There is no " << k;
	}

	return 0;
}

template<class K, class E>
void BST<K, E>::Insert(const pair<K, E>& thePair) {
	// search for thePair.first, pp is parent of p
	TreeNode<pair<K, E>>* p = root, * pp = 0;
	while (p) {
		pp = p;
		if (thePair.first < p->data.first)p = p->leftChild;
		else if (thePair.first > p->data.first)p = p->rightChild;
		else {
			p->data.second = thePair.second;
			return;
		}
	}

	// perform insertion
	p = new TreeNode<pair<K, E>>(thePair);
	if (root) { // tree not empty
		if (thePair.first < pp->data.first) {
			pp->leftChild = p;
		}
		else {
			pp->rightChild = p;
		}
	}
	else {
		root = p;
	}
}

template<class K, class E>
void BST<K, E>::Delete(const K& k) {
	TreeNode<pair<K, E>>* currentNode = root;
	TreeNode<pair<K, E>>* parentNode = NULL;
	TreeNode<pair<K, E>>* deleteNode = NULL;
	TreeNode<pair<K, E>>* temp = NULL;
	TreeNode<pair<K, E>>* smallestNode_in_right_subtree = NULL;

	while (currentNode) {
		if (currentNode->data.first > k) {
			parentNode = currentNode;
			currentNode = currentNode->leftChild;
		}
		else if (currentNode->data.first < k) {
			parentNode = currentNode;
			currentNode = currentNode->rightChild;
		}
		else {
			deleteNode = currentNode;
			break;
		}
	}
	if (deleteNode == NULL) {
		cout << "There are no node to delete." << endl;
	}

	// case1
	if (currentNode->leftChild == NULL && currentNode->rightChild == NULL) {
		if (parentNode->leftChild == currentNode) {
			parentNode->leftChild = NULL;
		}
		else if (parentNode->rightChild == currentNode) {
			parentNode->rightChild = NULL;
		}
	}

	// case2
	else if (currentNode->leftChild == NULL || currentNode->rightChild == NULL) {
		if (currentNode->leftChild != NULL) {
			temp = currentNode->leftChild;
		}
		else {
			temp = currentNode->rightChild;
		}

		if (parentNode->leftChild == currentNode) {
			parentNode->leftChild = currentNode;
		}
		else {
			parentNode->rightChild = temp;
		}
	}

	// case3
	else if (currentNode->leftChild != NULL && currentNode->rightChild != NULL) {
		currentNode = currentNode->rightChild;
		while (currentNode->leftChild) {
			parentNode = currentNode;
			currentNode = currentNode->leftChild;
		}
		deleteNode->data = currentNode->data;
		deleteNode = currentNode;

		parentNode->leftChild = NULL;
		delete deleteNode;
	}
}

template<class K, class E>
void BST<K, E>::Inorder() {
	Inorder(root);
}

template<class K, class E>
void BST<K, E>::Inorder(TreeNode<pair<K, E>>* currentNode) {
	if (currentNode != NULL) {
		Inorder(currentNode->leftChild);
		cout << currentNode->data; // visit
		Inorder(currentNode->rightChild);
	}
}

int main() {
	BST<int, int> bst;
	bst.Insert(pair<int, int>(20220033, 90));
	bst.Insert(pair<int, int>(20220050, 73));
	bst.Insert(pair<int, int>(20220043, 99));
	bst.Insert(pair<int, int>(20220011, 82));
	bst.Insert(pair<int, int>(20220024, 78));
	bst.Insert(pair<int, int>(20220046, 96));
	bst.Insert(pair<int, int>(20220001, 72));
	bst.Insert(pair<int, int>(20220008, 88));
	bst.Insert(pair<int, int>(20220036, 77));
	bst.Insert(pair<int, int>(20220056, 93));
	bst.Insert(pair<int, int>(20220053, 82));
	bst.Insert(pair<int, int>(20220059, 100));
	
	cout << "test1,2 : ";
	bst.Inorder();
	cout << endl << endl;

	cout << "test3,4 : ";
	bst.Delete(20220050);
	bst.Inorder();
	cout << endl << endl;

	cout << "test5,6 : ";
	bst.Delete(20220008);
	bst.Inorder();
	cout << endl << endl;

	cout << "test7,8 : ";
	bst.Delete(20220056);
	bst.Inorder();
	cout << endl << endl;

	cout << "test9 : ";
	bst.Get(20220056);
	cout << endl << endl;

	cout << "test10 : ";
	bst.Get(20220043);
	cout << endl << endl;

	return 0;
}