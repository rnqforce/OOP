#include<iostream>

using namespace std;

class student {
private:
	int grade;
	static int no;

public:
	student *next;
	student() {
		no++;
		grade = 0;

	}
	student(int x) {
		grade = x;
		no++;
	}
	~student() {
		no = 0;
		cout << "Instance destoryed! \n";
	}

	void setValue(int grade) {
		this->grade = grade;
	}
	void getValue() {
		cout << "grade = " << grade << "\n";
	}
	int getNo() {
		return no;
	}
};

int student::no = 0;

int main() {

	int n;
	cout << "numarul studentilor  = ";
	cin >> n;

	student *root , * nod , *aux;
	nod = new student();
	root = nod;

	while (n--) {
		int x;
		cin >> x;
		aux = new student(x);
		nod->next = aux;
		nod = aux;
		nod->next = NULL;
	}
	nod->next = root; // lista poate fi afisata din orice element

	nod = root;

	while (nod->next != NULL) {
		nod->next->getValue();
		nod = nod->next;
	}

	cout << root->getNo();

	return 0;

}