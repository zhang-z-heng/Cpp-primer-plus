/*
const限定符
常量的符号名称，指出常量表示的内容，另外如果程序在多个地方使用同一个常量，而需要修改该常量值
则只需修改一个符号定义即可，这种方法就是使用const关键字来修改变量声明和初始化
const int MONTHS = 12；//MONTHS is symbolic constant for 12
这样便可以在程序中使用MONTHS而不是12了
常量被初始化后，其值就被固定了，编译器不允许在修改该常量的值,一半将名称大写

浮点数
能够表示带小数部分的数字
浮点值带E/e如2.52e+8,9.33e-4(9.33/10000)
浮点类型有float,double和long double,float至少为32位，double至少为48位，且不少于float
long double至少和double一样多80，96或128位

*/
//floatnum.cpp -- floating-point types
/*#include<iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);//fixed-point
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;

	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ",\nand ten million tubs = ";
	cout << 10 * million * tub << endl;

	cout << "mint = " << mint << "and a million mints = ";
	cout << million * mint << endl;
	return 0;

}*/
/*
cout会删除结尾的零，float至少6位有效位，而第7位就有了误差
double显式13位有效位则在该例子中还是精确的
浮点常量
如果希望常量为float类型以f或F后缀，对于long double类型以l或L后缀
*/
/*
算术操作符+-*和/
%求模，也就是说他生成第一个数初一第二个数后的余数
*/
//ARITH.CPP -- some c++ arithmetic
/*#include<iostream>
int main()
{
	using namespace std;
	float hats, heads;

	cout.setf(ios_base::fixed, ios_base::floatfield);//fixed point
	cout << "Enter another number: ";
	cin >> hats;
	cout << "Enter another number: ";
	cin >> heads;

	cout << "hats = " << hats << "; heads = " << heads << endl;
	cout << "hats + heads = " << hats + heads << endl;
	cout << "hats - heads = " << hats - heads << endl;
	cout << "hats * heads = " << hats * heads << endl;
	cout << "hats / heads = " << hats / heads << endl;
	return 0;
}*/
/*
可以使用括号来执行优先级，c++使用优先级规则来决定首先使用哪个操作符
算术操作符遵循通常的代数优先级，先乘除，后加减
*/
//modulus.cpp--uses% operator to convert lbs to stone
/*#include<iostream>
int main()
{
	using namespace std;
	const int Lbs_per_stn = 14;
	int lbs;

	cout << "Enter your weight in pounds: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn;
	int pounds = lbs % Lbs_per_stn;
	cout << lbs << "pounds are " << stone << "stone, " << pounds << " pound(s).\n";
	return 0;
}*/
/*
类型转换
赋值时进行的转换，将一种类型的值赋给另一种类型的变量，这样做时，值将被转换为接受变量的类型
将short赋给long可以，但long赋给float将降低精度，因为float只有6为有线数字
小到大ok，大到小会出现问题

*/
//assign.cpp -- type changes on assignment
/*#include<iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;
	int guess = 3.9832;
	int debt = 7.2E12;
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	return 0;


}*/
/*
在程序中，浮点值3.0给了tree，3.9832给了int变量guess而取值3，浮点到
整型，截取丢弃小数部分，int变量debt无法存储3.0e12，这导致没有对结果
进行定的情况发生，即为1.6e09
*/
/*
表达式中的准换
当同一个表达式包含两种不同类型的算数，将执行自动转换
首先一些类型再出现是就会自动转换
其次有些类型在于其他类型同时出现在表达式中时将被转换

在计算表达式时，bool，char,unsigned char,signed char,short将转换为int
如果short比int短， unsigned short将被转换为int
如果两种类型长度相同，则unsigned short将被转换为unsigned int
wchar_t会被提升为下列类型中第一个宽度足够存储其取值范围的类型，int,unsigned int,long,unsigned long
如果有一个操作数类型为long double，则另一个操作数转换为long double
否则如果有一个double，则将另一个转换为double
否则如果一个为float,则将另一个转换为float
否则都是整型，因此执行整型提升
在这种情况下 一个是unsigned long，另一个也转为unsigned long
否则一个时long int,一个是unsigned int，则转换取决于两种类型的相对长度
如果long能够表示unsigend int所有可能值，则将unsigned int 转换为long
否则都转换为unsigned long
否则一个为long,将另一个操作数转换为long
否则unsigned int 转换为unsigned int
否则都是int类型

传递参数时的转换char和short类型应用整型提升
强制类型的转换
将该程序第一部分是想象为一个功能强大的生态模拟程序的一个部分
该程序执行浮点计算，结果被转换为鸟和动物的数目
计算auks时首先浮点值相加，然后在赋值时，蒋总数转换为int
但计算bats和coots时，首先通过强制类型转换将浮点值转换为int，然后计算总和，
程序最后演示了如何通过强制类型转换来显示char值的ASCII码


*/
//typecast.cpp -- torcing type changes
#include<iostream>
int main()
{
	using namespace std;
	int auks, bats, coots;

	auks = 19.99 + 11.99;

	bats = (int)19.99 + (int)11.99;
	coots = int(19.99) + int(11.99);
	cout << "auks = " << auks << ",bats =" << bats;
	cout << ", coots = " << coots << endl;
	char ch = 'Z';
	cout << "The code for " << ch << " is ";
	cout << int(ch) << endl;
	return 0;
}