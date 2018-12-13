#include<iostream>

using namespace std;

class student {
	private:
		int grade;
		int age;

	public:
		student() {
			grade = 0;
			age = 0;
		}

		student(int x , int y) {
			grade = x;
			age = y;
		}

		void setValue(int x, int age) {
			this->grade = x;
			this->age = age; 
		}
		void getValue() { 
			cout << "grade=" << grade << "  age="<< age << "\n"; 
		}
};

int main() {
	student student1(2,3), *student2;
	student2 = new student();
	student2->setValue(10, 20);
	student2->getValue();
	student1.getValue();

	return 0;

}