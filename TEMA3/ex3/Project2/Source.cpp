#include<iostream>

using namespace std;

class student {
private:
	int grade;
	int age;
	static int no;

public:
	student() {
		grade = 0;
		age = 0;
		no++;

	}
	student(int x, int y) {
		grade = x;
		age = y;
		no++;
	}
	~student() {
		no = 0;
		cout << "Instance destoryed! \n";
	}
	void setValue(int x, int age) {
		this->grade = x;
		this->age = age;
	}
	void getValue() {
		cout << "grade = " << grade << "  age = " << age << "\n";
	}
	void getNo() {
		cout <<"Number of instances = "<< no << "\n";
	}
};
int student::no = 0;
int main() {
	student student1(2, 3), *student2;
	student2 = new student();
	student2->getValue();
	student2->setValue(10, 20);
	student2->getValue();
	student1.getValue();
	student1.getNo();

	return 0;

}