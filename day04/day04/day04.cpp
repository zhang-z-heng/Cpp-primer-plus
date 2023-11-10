//convert.cpp -- converts stone to pounds
#include <iostream>
int stonetolb(int);
int main()
{
	using namespace std;
	int stone;
	cout << "Enter the weight in stone: " << endl;
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " stone = ";
	cout << pounds << " pounds. " << endl;
	return 0;
}
int stonetolb(int sts)
{
	return 14 * sts;
}
/*
在main()中，程序使用cin来给整形变量stone提供一个值
这个值作为参数传递给了stonetolb（）函数，在该函数中，这个值被赋给变量sts
然后，stonetolb（）用关键字return将14*sts返回给main()
这表明return后面并非一定得跟一个简单的数字
这里通过使用较为复杂的表达式避免创建一个新变量
将结果赋给该变量，然后将他返回，其等于
int stonetolb(int sts)
{
   int pounds = 14*sts;
   return pounds；
}
通常，在可以使用一个简单变量的地方，都可以使用一个返回值类型与该常量相同的函数
例如stonetolb()返回一个int值,这意味着可以以下面的方式使用该函数
int aunt = stonetolb(20);
int aunts = aunt + stonetolb(10);
cout <<"Ferdie weighs "<< stonetolb(16)<<"pounds."<<endl;
在上述任何一种情况下，程序都将计算返回值，然后在语句中使用这个值

*/