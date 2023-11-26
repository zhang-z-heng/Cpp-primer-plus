/*
1.哪种函数适合定义为内联函数？
 如果执行函数代码的时间比处理函数调用机制的时间长，
 则节省的时间将只占整个过程的很小一部分。
 如果函数代码执行的时间很短，
 则内联调用就可以节省非内联调用使用的大部分时间。
 因此对于只有一行的小型、非递归函数适合作为内联函数。

 2.假设song()原型如下
 void song(const char * name,int times);
 a.如何修改原型，使times的默认值为1？
 b.函数定义需要做哪些修改？
 c.能否为name提供默认值（O.My Papa）?

 a.void song(const char *name, int times =1);
 b.函数定义不需要做修改，因为只有原型包含默认值的信息。
 c.可以，但是函数参数的默认值是从右到左的，
 因此在对左边的设置默认值的时候，右边的也必须得有默认值。
 比如 void song(const* char name="O, My Papa", int times=1);

 3.编写iquote()重载版本，显示其用双引号括起的参数，编写3个版本，一个
 用于int参数一个用于double参数，一个用于string参数

#include<iostream>
#include<string>
using namespace std;
void iquote(int);
void iquote(double n);
void iquote(string n);

int main()
{
	iquote(2);
	iquote(3.14);
	iquote("Schrodingers cat");
	return 0;
}


4.struct bos
{
    char maker[40];
	float height;
	float width;
	float length;
	float volume;
 };
 a.请编写一个函数，它将box结构的引用作为形参，并显示每个成员的值
 void show_box(const box& container)
{
	cout << "Made_by " << container.maker << endl;
	cout << "Height = " << container.height << endl;
	cout << "Width = " << container.width << endl;
	cout << "Length = " << container.length << endl;
	cout << "Volume = " << container.volume << endl;
}
 b.将box结构的引用作为形参，并将volume成员设置为其他3边乘积

*/
