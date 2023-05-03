﻿#include <iostream>
#include <string>
using namespace std;


// 1.仿函数，重载()运算符的类，使得对象在使用阶段像函数调用
class MyPrint {
public:
	// 仿函数
	void operator()(string test) { 
		cout << test << endl;
		m_Count++;
	}
	int m_Count = 0;
};
void test01() {
	MyPrint mp;
	mp("hello world");//不是真正的函数，而是一个对象  仿函数
}

//仿函数 超出普通函数的概念  可以拥有自己的一些内部状态
void test02() {
	MyPrint mp;
	mp("hello");
	mp("hello");
	mp("hello");
	mp("hello");
	mp("hello");

	cout << "mp 使用的次数为：" << mp.m_Count << endl;

}

// 3.函数对象可以作为函数的参数
void dowork(MyPrint mp, string str) {
	mp(str);
}
void test03() {
	MyPrint mp;
	dowork(mp, "hello");
}
int main() {
	//test01();
	//test02();
	test03();
	return 0;
}