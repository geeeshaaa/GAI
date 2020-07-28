#include <iostream>
using namespace std;


class Node {
	unsigned int CarNumber;
	unsigned int id = 0;
	char* offense[10]{};
public:
	Node* left;
	Node* right;
	Node(unsigned int n, const char* offense) :left(0), right(0)
	{
		CarNumber = n;
		this->offense[id] = _strdup(offense);
		id++;
	}
	void SetOffense(const char* offense){
		this->offense[id] = _strdup(offense);
		id++;
	}
	void Print() {
		printf("|%-10d |", CarNumber); cout << endl;
		cout << "=============\n";
		for (size_t i = 0; i < id; i++)
		{
			printf("|%-10d |",i+1); cout << offense[i]<< endl;
		}
		cout << endl;
	}
	int GetCarNum() { return CarNumber; }



	~Node()
	{
		for (size_t i = 0; i < id; i++)
			delete[] offense[i];
		delete offense;
	}
};
class Tree {
	unsigned int size = 0;
	Node* root;
	Node* Insert(Node* node, int car, const char* offen);
	void Print(Node* node);
public:
	Tree() :root(0) {};
	void Insert(int car, const char* offen);
	void Print();
};

Node* Tree::Insert(Node* node, int car, const char* offen)
{
	if (!node)
		return new Node(car, offen);
	if (node->GetCarNum() == car) { node->SetOffense(offen); return node; }
	if (node->GetCarNum() < car)
		node->right = Insert(node->right, car, offen);
	else
		node->left = Insert(node->left, car, offen);
	return node;
}


void Tree::Insert(int car, const char* offen)
{
	size++;
	if (!root) root = new Node(car, offen);
	else
		Insert(root, car, offen);
}

void Tree::Print(Node* node)
{
	if (node) {
		Print(node->left);
		node->Print();
		Print(node->right);
	}
}
void Tree::Print()
{
	Print(root);
}

int main()
{
	Tree GAI;
	GAI.Insert(1234, "Proizd na chervone svitlo");
	GAI.Insert(1234, "Znak STOP");
	GAI.Insert(1234, "Perevyshcennia shvydkosti");
	GAI.Insert(1234, "Porushennia");
	GAI.Insert(1234, "Remin");
	GAI.Print();
}

