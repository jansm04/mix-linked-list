using namespace std;

class Node {
public:
	Node();				
	Node(int ndata);	

	Node* next;		// pointer to next node in chain
	Node* prev;		// pointer to previous node in chain
	int data;		// data held by this Node.
};


class Chain {
private:
	/**
	 * Private member variables.
	 */
	Node* head;	// pointer to the northwest node; the first node in the list
	Node* tail;	// pointer to the southeast node; the last node in the list
	unsigned int length;	// counts the number of nodes in the Chain.

public:
	Chain();					
	void Insert(int data);
	void Mix();
	void PrintChain();
};