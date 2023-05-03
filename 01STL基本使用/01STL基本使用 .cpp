#include <iostream>
#include<vector>
#include<algorithm>   //标准算法头文件
#include<string>

using namespace std;

void myprint(int val) {
	cout << val << endl;
}

void test01() {
	vector<int> v;
	//插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//遍历方式1 迭代器 是指针
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}

	//遍历方式2 for 循环
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	//遍历方式3  for_each
	for_each(v.begin(), v.end(), myprint);

}

//自定义数据类型
class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->age = age;
	}

	string m_Name;
	int age;
};

void test02() {
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	for (vector<Person>::iterator it = v.begin();it != v.end();it++) {
		cout << "Name: " << (*it).m_Name << "  Age: " << it->age << endl;
	}
}

//容器的嵌套
void test04() {
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; ++i) {
		v1.push_back(i + 1);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	//遍历
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		// *it  vector<int>
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}

}

int main() {
	//test01();
	//test02();
	test04();
	return 0;
}
