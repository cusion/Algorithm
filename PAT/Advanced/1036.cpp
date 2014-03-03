#include <cstdio>
#include <iostream>
using namespace std;

struct Stu {
	string name;
	string ID;
	int grade;
}female, male;

int main() {
	int n;
	cin >> n;
	Stu person;
	female.grade = -1;
	male.grade = 101;
	for (int i = 0; i < n; ++i) {
		cin >> person.name;
		getchar();
		char gender = getchar();
		cin >> person.ID;
		cin >> person.grade;
		
		switch(gender) {
			case 'M':
				if (male.grade > person.grade) {
					male = person;
				}
				break;
			case 'F':
				if (female.grade < person.grade) {
					female = person;
				}
			break;
		}
		//cout << person.name << " " << gender << " " << person.ID << " " << person.grade << endl;
	}
	
	if (female.grade < 0) {
		cout << "Absent" << endl;
	} else {
		cout << female.name << " " << female.ID << endl;
	}
	if (male.grade > 100) {
		cout << "Absent" << endl;
	} else {
		cout << male.name << " " << male.ID << endl;
	}
	if (female.grade < 0 || male.grade > 100) {
		cout << "NA" << endl;
	} else {
		cout << female.grade - male.grade << endl;
	}
	return 0;
}
