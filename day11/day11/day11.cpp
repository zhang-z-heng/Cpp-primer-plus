/*
指针和自由存储空间
指针是一个变量，其存储的是值的地址，而不是值本身
在讨论之前我们先看一看如何找到常规变量的地址
地址运算符&
*/
//address.cpp -- using the & operator to find addresses
/*#include<iostream>
int main()
{
	using namespace std;
	int donuts = 6;
	double cups = 4.5;

	cout << "donuts value = " << donuts;
	cout << " and donuts address = " << &donuts << endl;
	cout << "cups value = " << cups;
	cout << " and cups address = " << &cups << endl;
	return 0;
}*/
/*
显式地址时，该实现的cout使用16进制表示法
面向对象编程，其强调的是在运行阶段而不是编译阶段进行决策
在运行阶段确定数组的长度，使用new请求正确数量的内存以及使用指针来跟踪新分配的内存的位置
处理储存数据时，将地址视为指定的量，而将值视为派生量
指针名表示的是地址
*运算符被称为间接值或解除引用运算符，将其用于指针，*manly就是存储在manlu的地址值
*/

//pointer.cpp -- our first pointer variable
/*#include<iostream>
int main()
{
	using namespace std;
	int updates = 6;
	int *p_updates;
	p_updates = &updates;

	cout << "Values : updates = " << updates;
	cout << " , *p_updates = " << *p_updates << endl;

	cout << "Adresses : &updates = " << &updates;
	cout << " , p_updates = " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "Now updates = " << updates << endl;
	return 0;

}*/
/*
声明和初始化指针
指针声明必须指定指针指向的数据的类型
int *p_updates; *p_updates的类型是int，而不是指针，p_updates是指针（地址）
*运算符两边的空格是可选的，int *ptr或int* ptr或int*ptr
int*p1,p2是声明创建一个指针p1和变量p2
*/
//init_ptr.cpp -- initialize a pointer
/*#include<iostream>
int main()
{
	using namespace std;
	int higgens = 5;
	int *pt = &higgens;

	cout << "Value of higgens = " << higgens << " ;Address of higgens = " << &higgens << endl;
	cout << "Value of *pt = " << *pt << "; Value of pt = " << pt << endl;
	return 0;
}*/
/*
程序将pt而不是*pt初始化为higgens的地址
C++创建指针时，计算机将分配用来存储地址的内存，但不会分配用来存储指针所指向的数据内存，
为数据提供空间是一个独立的步骤，不能忽略这一步

long*fellow; // creat a pointer to long
*fellow = 223323;//place a value in never-never land
fellow是一个指针，但上述代码没有将地址赋给fellow，他无法指向，223323也没地方放
由于fellow没有被初始化，他可能有任何值
不管值是什么，程序都将他解释为存储223323的地址
如果fellow的值为1200，计算机将把数据放在地址1200上，即使这恰巧是程序代码的地址
fellow指向的地方很可能并不是所有存储223323的地方

一定要在对指针应用解除引用运算符之前，将指针初始化为一个确定适当的地址

指针和数字
指针不是整型，虽然计算机通常把地址当作整数来处理，但不能简单地将整数赋给指针
int * pt；
pt = 0xBB000000;
在这里，左边是指向int的指针，因此可以把它赋给地址，但右边是一个整数
要将数字值作为地址来使用，应通过强制类型转换将数字转换为适当的地址类型
int *pt;
pt = （int*） 0xBB000000;
这样赋值语句两边都是整数的地址，因此这样赋值有效

使用new来分配内存
前面我们将指针初始化为变量的地址，变量是在编译时分配的又名陈的内存，
而指针只是为可以通过名称直接访问的内存提供一个别名
在运行阶段为一个int值分配未命名的内存，并使用指针来访问这个值
使用new为哪种类型数据分配内存，new将找到一个长度正确的内存块，并返回内存块的地址
程序员的责任是将该地址赋给一个指针
int *pn= new int;
new int告诉程序，需要适合存储int的内存，new运算符根据类型来确定需要多少字节的内存，
然后找到这样的内存，并返回其地址
接下来，将地址赋给pn，pn是被声明为指向int的指针
现在，pn是地址，而*pn是存储在那里的值
int higgens;
int *pt = &higgens;
在这两种情况下，都是将一个int变量的地址赋给了指针
第二种情况可以通过名臣higgens访问该int，而第一种只能通过该指针进行访问
pn指向一个数据对象，，指的是为数据分配的内存块
为一个数据对象获得并分配内存的通用格式如下
typeName * pointer_name = new typeName;
需要在两个地方指定数据类型，用来指定需要什么样的内存和用来声明合适的指针


*/

//use_new.cpp --using the new operator
/*#include<iostream>
int main()
{
	using namespace std;
	int nights = 1001;
	int* pt = new int;//allocate space for an int
	*pt = 1001;// store a value there

	cout << "night value = ";
	cout << nights << ": location " << &nights << endl;
	cout << "int ";
	cout << "value = " << *pt << ": location = " << pt << endl;
	double* pd = new double;
	*pd = 10000001.0;

	cout << "double ";
	cout << "value = " << *pd << ": location = " << pd << endl;
	cout << "location of pointer pd: " << &pd << endl;
	cout << "size of pt = " << sizeof(pt);
	cout << ": size of *pt = " << sizeof(*pt) << endl;
	cout << " size of pd = "<<sizeof (pd);
	cout << ": size of *pd = " << sizeof(*pd) << endl;
	return 0;

}*/
/*
该程序使用new分别给int类型和double类型的数据对象分配内存
指针pt,pd只想这两个数据对象，如果没有他们，将无法访问这些内存单元，有了这两个指针
就可以像使用变量那样使用*pt和*pd了
将值赋给*pt和*pd从而将这些值赋给新的数据对象

该程序还指出了必须声明指针所指向的类型原因之一
地址本身只指出了对象存储地址的开始，而没有指出其类型（使用的字节数）
另外指向int的指针长度与指向double的指针相同
对于指针，new分配的内存块通常与常规变量声明分配的内存块不同
变量nights和pd的值都存储在栈stack的内存区域中，而new从被称为堆heap或自由存储区free store的内存区域分配内存


delete释放内存
在使用完内存后，能够将其归还给内存池，这是通向最有效的使用内存的关键一步
归还或释放内存可供程序的其他部分使用
int *ps =new int;//allocate memory with new
delete ps,//free memory with delete when done

使用new来创建动态数组
在运行阶段需要数组则创建它，如果不需要则不创建，这被称为dynamic binding
动态联编，意味着数组是在程序运行时创建的，这种数组叫做动态数组
程序将在运行时确定数组的长度

1使用new创建动态数组
int * psome = mew int[10]；//get a block of 10 ints
new元素符返回第一个元素的地址，在这个例子中，该地址被赋给指针psome
delete[]psome;释放整个数组，不仅仅是指针只想的元素
使用new时不带方括号则使用delet时也不应带方括号
psome是指向一个int(数组第一个元素)的指针，你的责任是跟踪内存块中的元素个数
也就是说，编译器不能堆psome是指向10个整数中的第一个这种情况进行跟踪，因此编写程序时，必须让程序跟踪元素的数目
实际上，程序确实跟踪了分配的内存量以便以后使用delete元素安抚能够正确的释放这些内存
为数组分配内存的通用格式如下
type_name *pointer_name = new type_name[num_elements];
使用new运算符可以确保内存块足以存储num_elements个类型为type_name的元素
而poimter_name将指向第一个元素

2使用动态数组
int *psome = new int[10];
假设int占4个字节，那移动4个字节后则指向第2个元素
对于第一个元素psome[0]，而不是*psome
对于第2个元素可以使用psome[1]


*/
//arraynew.cpp -- using the new operator for arrays
#include<iostream>
int main()
{
	using namespace std;
	double* p3 = new double [3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1] is " << p3[1] << ".\n";
	p3 = p3 + 1;
	cout << "Now p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << ". \n";
	p3 = p3 - 1;
	delete[] p3;
	return 0;
}
/*
注意，将p3加1的效果，表达式p3[0]现在指的是数组的第二个值，因此其导致它指向第二个元素而不是第一个
将它减一后，指针将指向原来的值，这样程序便可以给delete[]提供正确的地址
相邻的int地址通常相差2或4个字节，而加1后他将指向下一个元素的地址
*/