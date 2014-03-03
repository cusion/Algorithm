#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isFound = false;

struct Node {
	int data;
	string strform;
}arr[4];


Node Max(Node a, Node b) {
	if (a.data >= b.data) return a;
	return b;
}

Node Min(Node a, Node b) {
	if (a.data < b.data) return a;
	return b;
}

void Print(Node a, Node b, char ch){
	cout << a.strform << ch << b.strform << endl;
}

void check (Node *node, int len, int target){
	if (isFound) return ;
	if (len <= 2) {
		Node node_max = Max(node[0], node[1]);
		Node node_min = Min(node[0], node[1]);
		//cout << "=========================" << endl;
		//cout << node_max.strform<< " " << node_min.strform<<endl;
		if (node_max.data - node_min.data == target){
			isFound = true;
			Print(node_max, node_min, '-');
		} else if (node_max.data + node_min.data == target){
			isFound = true;
			Print(node_max, node_min, '+');
		} else if ((node_min.data>0)&& (node_max.data%node_min.data == 0) && (node_max.data / node_min.data == target)){
			isFound = true;
			Print(node_max, node_min, '/');
		} else if (node_max.data * node_min.data == target){
			isFound = true;
			Print(node_max, node_min, '*');
		}
		return;
	}
	Node tmp[len-1];

	/*for (int i = 0; i < len; ++i) {
		cout << node[i].strform << " ";
	}cout << endl;*/
	
	for (int i = 0; i < len; ++i) {
		if (!isFound) {
			for (int j = i+1; j < len; ++j) {
				Node tmp1 = Max(node[i], node[j]);
				Node tmp2 = Min(node[i], node[j]);
				int ind = 0;
				for(int k = 0; k < len; ++k) {
					if (k!=i && k!=j) {
						tmp[ind++] = node[k];
					}
				}
				string tmpstr;

				// check +
				tmp[ind].data = tmp1.data+tmp2.data;
				tmpstr = "";
				tmpstr.append("(");
				tmpstr.append(tmp1.strform);
			    tmpstr.append("+");
				tmpstr.append(tmp2.strform);
				tmpstr.append(")");
				tmp[ind].strform = tmpstr;
				check(tmp, len-1, target);

				// check *
				tmp[ind].data = tmp1.data*tmp2.data;
				tmpstr = "";
				tmpstr.append("(");
				tmpstr.append(tmp1.strform);
			    tmpstr.append("*");
				tmpstr.append(tmp2.strform);
				tmpstr.append(")");
				tmp[ind].strform = tmpstr;
				check(tmp, len-1, target);

				// check /
				if((tmp2.data != 0)&&(tmp1.data % tmp2.data == 0)) {
					tmp[ind].data = tmp1.data/tmp2.data;
					tmpstr = "";
					tmpstr.append("(");
					tmpstr.append(tmp1.strform);
			    	tmpstr.append("/");
					tmpstr.append(tmp2.strform);
					tmpstr.append(")");
					tmp[ind].strform = tmpstr;
					check(tmp, len-1, target);
				}
				
				// check - 
				tmp[ind].data = tmp1.data-tmp2.data;
				tmpstr = "";
				tmpstr.append("(");
				tmpstr.append(tmp1.strform);
		    	tmpstr.append("-");
				tmpstr.append(tmp2.strform);
				tmpstr.append(")");
				tmp[ind].strform = tmpstr;
				check(tmp, len-1, target);
			}
		}
	}
}

string Num2String(int data) {
	string str = "";
	if (data >= 10) {
		str.append("1");
		str.append(Num2String(data-10));
	} else {
		str.append(1, (char)(data + '0'));
	}
	return str;
}


int main()
{
	for (int i = 0; i < 4; ++i) {
		cin >> arr[i].data;
		arr[i].strform = Num2String(arr[i].data);
	}

	check(arr, 4, 24);

	if (isFound == false) {
		cout << -1 << endl;
	}

	return 0;
}
