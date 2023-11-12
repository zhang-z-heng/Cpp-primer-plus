/*
类型组合

*/
//mixtypes.cpp -- some type combinations
/*#include<iostream>

struct antarctica_years_end
{
	int year;

};
int main()
{
	antarctica_years_end s01, s02, s03;
	s01.year = 1998;
	antarctica_years_end* pa = &s02;
	pa->year = 1999;
	antarctica_years_end trio[3];//array of 3 structures
	trio[0].year = 2003;
	std::cout << trio->year << std::endl;
	const antarctica_years_end* arp[3] = { &s01, &s02, &s03 };
	std::cout << arp[1]->year << std::endl;
	const antarctica_years_end** ppa = arp;
	auto ppb = arp;//c++11 automatic type deduction
	//or else use const antarctica_years_end **ppb = arp;
	std::cout << (*ppa)->year << std::endl;
	std::cout << (*(ppb + 1))->year << std::endl;
	return 0;
}*/
/*
数组的替代品
模板类vector,运行阶段蛇者其长度，是使用new创建动态数组的替代品
#include<vector>
vector<int>vi;//create a zero*size array of int
int n;
cin>>n;
vector<double> vd(n);//creat an arrayof n doubles
声明创建一个名为vt的vector对象，他可存储n_elem个类型为typeName的元素：
vector<typeName> vt(n_elem);

模板类array
#include<array>
array<int,5>ai;// create array object of 5 ints
array<double,4> ad = {1.2, 2.1, 3.43,4.3};
声明一个名为arr的array对象，包含n_elem个类型为typename的元素
array<typename,n_elem>arr;n_elem不能是变量
*/

//choices.cpp -- array variations
#include<iostream>
#include<vector>
#include<array>
int main()
{
	using namespace std;
	//c,original c++
	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
	//c++98 STL
	vector<double> a2(4);//create vector with 4 elements
	//no simple way to initialize in C98
	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;
	//c++11--create and initialize arrat object
	array<double, 4>a3 = { 3.14, 2.72, 1.62, 1.41 };
	array<double, 4>a4;
	a4 = a3;//valid for array objects of same size

	//use array notation
	cout << "a1[2] : " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2] : " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl;
	//misdeed
	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	return 0;

}
/*
a1[-2] = 20.2;
这将被转换为*（a1-2）=20.2;
其含义为找到a1只想的地方，向前移2个double元素，并将20.2存储在目的地
这是不安全的代码
用成员函数at()
a2.at(1) = 2.3;//assign 2.3 to a2[1]
*/