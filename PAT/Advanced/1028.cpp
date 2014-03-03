#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student {
	int id;
	char name[9];
	int grade;
	
	Student(){}
	Student(int i,  char *n, int g):id(i), grade(g){
		int ii = 0;
		for (ii = 0; n[ii] != '\0'; ++ii) {
			name[ii] = n[ii];
		}
		name[ii] = '\0';
	}
		
	static bool compId(const Student &a, const Student &b) {
			return a.id < b.id;
	}

	static bool compName(const Student &a, const Student &b) {
		if (strcmp(a.name, b.name) < 0) {
			return true;
		} else if (strcmp(a.name, b.name) > 0) {
			return false;
		} else {
			return a.id < b.id;
		}
	}

	static bool compGrade(const Student &a, const Student &b) {
		if (a.grade < b.grade) {
			return true;
		} else if (a.grade > b.grade) {
			return false;
		} else {
			return a.id < b.id;
		}
	}
};

int main() {
	int n, c;
	cin >> n >> c;
	vector <Student> stu(n);
	char name[10];
	int id, grade;
	for (int i = 0; i < n; ++i) {
		scanf("%d%s%d", &id, name, &grade);
		//cout << "test " << id << " " << name << " " << grade << endl;
		Student tmp(id, name, grade);
		stu[i] = tmp;
		//stu[i] = Student(id, name, grade);
		//system("pause");
	}
	/*puts("=======================");
	for (int i = 0; i < n; ++i) {
		cout << stu[i].id << " " << stu[i].name << " " << stu[i].grade << endl;
	}
	puts("=======================");*/
	switch(c) {
		case 1:
			//puts("id");
			sort(stu.begin(), stu.end(), Student::compId);
			break;
		case 2:
			//puts("name");
			sort(stu.begin(), stu.end(), Student::compName);
			break;
		case 3:
			//puts("grade");
			sort(stu.begin(), stu.end(), Student::compGrade);
			break;
		default:
			break;
	}
	for (int i = 0; i < n; ++i) {
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}
