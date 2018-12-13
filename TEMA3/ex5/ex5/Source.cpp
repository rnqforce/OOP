#include<iostream>
#include<string>
#include<list>

using namespace std;

class cursuri{

public:
	string nume, profesor;
	
};



class student {
private:
	
	string nume, prenume, grupa;
	list <cursuri> l;
	static int no;

public:
	student() {
		no++;
		nume = ' ';
		prenume = ' ';
		grupa = ' ';

	}
	student(string nume , string prenume , string grupa) {
		this->nume = nume;
		this->prenume = prenume;
		this->grupa = grupa;
		no++;
	}
	~student() {
		no = 0;
		cout << "Instance destoryed! \n";
	}

	void setNume(string nume) {
		this->nume = nume;
	}
	void setPrenume(string prenume) {
		this->prenume = prenume;
	}
	void setGrupa(string grupa) {
		this->grupa = grupa;
	}
	void getStudent() {
		cout << nume << " " << prenume << " " << grupa << "\n";
	}
	void addCurs(string nume, string profesor) {
		cursuri aux;
		aux.nume = nume;
		aux.profesor = profesor;
		l.push_back(aux);
	}
	bool searchCurs(string curs) {
		for (auto it : l) {
			if (it.nume == curs)
				return 1;
		}
		return 0;
	}
	bool potrivire(string nume, string prenume, string grupa) {
		if (this->nume == nume && this->prenume == prenume && this->grupa == grupa)
			return 1;
		else return 0;
	}
	int getNo() {
		return no;
	}
};

int student::no = 0;

int main() {
	list<student> lista;
	int x;
	cin >> x;
	while (x != 0 ) {
		cout << "1.Creare lista student\n";
		cout << "2.Stergere unui student\n";
		cout << "3.Editarea unui student\n";
		cout << "4.Determinarea numarului de studenti\n";
		cout << "5.Cautare student\n";
		cout << "6.Afisare studenti care participa la un curs\n";
		cout << "0.Exit\n";
		cin >> x;
		if (x == 1) {
			cout << "Introdu numar studenti \n";
			int n; 
			cin >> n;
			while (n--) {
				string nume, prenume, grupa , profesor;
				cout << "nume = "; cin >> nume;
				cout << "prenume = "; cin >> prenume;
				cout << "grupa = "; cin >> grupa;
				student auxiliar(nume,prenume,grupa);
				cout << "Introdu numar cursuri\n";
				int k;
				cin >> k;
				while (k--) {
					cout << "curs = "; cin >> nume;
					cout << "profesor = "; cin >> profesor;
					auxiliar.addCurs(nume, profesor);
				}
				lista.push_back(auxiliar);
			}
		}
		else if (x == 2) {
			string nume, prenume, grupa;
			cout << "nume = "; cin >> nume;
			cout << "prenume = "; cin >> prenume;
			cout << "grupa = "; cin >> grupa;
			for (list<student>::iterator it = lista.begin(); it != lista.end(); it++ ) {
				if ((*it).potrivire(nume, prenume, grupa)) {
					lista.erase(it);
					break;
				}


			}
		}
		else if (x == 3) {
			string nume, prenume, grupa;
			cout << "nume = "; cin >> nume;
			cout << "prenume = "; cin >> prenume;
			cout << "grupa = "; cin >> grupa;
			list<student>::iterator it;
			for (it = lista.begin(); it != lista.end(); it++) {
				if ((*it).potrivire(nume, prenume, grupa))
					break;

			}
			if (it != lista.end()) {
				int k;
				cout << "Pentru editare nume apasa 1 \n";
				cout << "Pentru editare penume apasa 2\n";
				cout << "Pentru editare grupa apasa 3\n";
				cin >> k;
				cout << "Introdu string \n";
				string s;
				cin >> s;
				if (k == 1) {

					(*it).setNume(s);
				}
				else if (k == 2) {
					(*it).setPrenume(s);
				}
				else (*it).setGrupa(s);
			}
		}
		else if (x == 4) {
			cout <<"Numarul de elemente din lista "<< lista.size() << '\n';
		}
		else if (x == 5) {
			string nume, prenume, grupa;
			cout << "nume = "; cin >> nume;
			cout << "prenume = "; cin >> prenume;
			cout << "grupa = " ;  cin >> grupa;
			int k = 1;
			for (list<student>::iterator it = lista.begin(); it != lista.end(); it++) {
				if ((*it).potrivire(nume, prenume, grupa))
					cout << "Elementul numarul " << k << '\n';
				k++;

			}
		}
		else if (x == 6) {
			string curs;
			cout << "Introdu curs "; cin >> curs;
			for (list<student>::iterator it = lista.begin(); it != lista.end(); it++) {
				if ((*it).searchCurs(curs))
					(*it).getStudent();
			}
		}
		else return 0;


	}
	return 0;

}