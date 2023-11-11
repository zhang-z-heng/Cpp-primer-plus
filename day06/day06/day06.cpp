/*
无符号类型，仅当数值不会为负时才应使用无符号类型，只需使用关键字
unsigned来修改声明
unsigned short change;
unsigned int rovert,unsigned quarterback;unsugned long gone;
*/
//exceed.cpp -- exceeding some integer limits
#include<iostream>
#define ZERO 0 // make ZERO symbol for 0 value
#include<climits> // defines INT_MAX as largest int value
/*int main()
{
	using namespace std;
	short sam = SHRT_MAX; // initialize a variable to max value
	unsigned short sue = sam; // okay if variable sam already defined

	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl
		<< "Add $1 to each account." << endl << "Now ";
	sam = sam + 1;
	sue = sue + 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited.\nPoor Sam!" << endl;
	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl;
	cout << "Take $1 from each account." << endl << "Now ";
	sam = sam - 1;
	sue = sue - 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
	return 0;
}*/
/*
该程序将一个short变量（sam)和一个unsigned short 变量（sue）分别设置为最大的short
值，在我们的系统上，是32767，然后将这些变量值都加1，这对于sue来说没有什么问题，
因为新值仍比无符号整数的最大值小得多，但sam的值从32767变成了-32768
同样对于sam，将其设置为0并减去1，也不会有问题，但对于无符号变量sue，将
其设置为0后并减去后，它变成了65636，可以看出，这些整型变量的行为就像里程表
如果超越了限制，其值将为范围另一端的取值，c++确保了无符号类型的这种行
但其并不保证符号整形超越限制时不出错。

还有两种类型long long和unsigned long long，两种类型都是64为，且至少同
long和unsiged long类型一样宽

选择整型类型
通常int 被设置为对目标计算机而言最为自然的长度，若没有非常有说服力的理由来选择其他类型则用int
如果变量表示的值不可能为负，则可以使用无符号类型，这些变量可以表示更大的值
如果变量可能表示的整数值大于16位整数的最大可能值即用long
即使系统上int位32位也应这样做
如果short比int小，则使用short可以节省内存，通常仅当有大型整型数组时，才有必要使用short
如果只需要一个字节则使用 char。

*/

/*
整型常量
是显式地书写的常量，即位10进制，8进制(开头为0，第二位1--7）
16进制（前两位0x或0X）*/
//hexoct.cpp -- shows hex and octal constants
/*#include<iostream>
int main()
{
	using namespace std;
	int chest = 42;
	int waist = 0x42;
	int inseam = 042;

	cout << "Monsieur cuts a striking figure!\n";
	cout << "chest = " << chest << "\n";
	cout << "waist = " << waist << "\n";
	cout << "inseam = " << inseam << "\n";
	return 0;
}
*/
//hexoct2.cpp -- display values in hex and octal
/*#include<iostream>
using namespace std;
int main()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "Monsier cuts a striking figure!\n";
	cout << "chest = " << chest << "(decimal)\n";
	cout << hex;
	cout << "waist = " << waist << " hexadecimal\n";
	cout << oct;
	cout << "inseam = " << inseam << "(octal)\n";
	return 0;
}*/
/*
cout<<hex等代码只是修改cout显式整数的方式，因此，控制符hex实际上是一条小溪，
告诉cout采取何种行为
另外由于hex位于名称空间std中，而程序使用了该名称空间
所以hex不能用作变量名
而std::cout,std::endl,std::hex.std::oct则可以将hex用作变量名

char类型是转为存储字符而设计的，它用作比short更小的整型
*/
//chartype.cpp -- the char type
/*#include<iostream>
int main()
{
	using namespace std;
	char ch;

	cout << "Enter a character: " << endl;
	cin >> ch;
	cout << "Holla!";
	cout << "Thank you for the " << ch << " character." << endl;
	return 0;

}*/
/*
下面这个程序演示了如何在c++中书写字符常量，将字符用单引号括起
对字符串用双引号，另外程序引入了cout的一项特性，cout.put()函数，该函数显示一个字符

*/
//morechar.cpp -- the char type and int type contrasted
/*#include<iostream>
int main()
{
	using namespace std;
	char ch = 'M';
	int i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;

	cout << "Add one to the character code: " << endl;
	ch = ch + 1;
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;
	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);
	cout.put('!');
	cout << endl << "Done" << endl;
	return 0;
}*/
/*
‘M’表示字符M的数值编码，因此将char变量c初始化为‘M’，将把c设置为77
然后程序将同样的值赋给int变量i，这样c和i的值都是77
接下来cout 把c显示为M，而把i显示为77，由于c实际上是一个整数，因此对他可以加一
这是c的值变成了78，然后程序将i重新设置为新的值
cout再次将这个值的char版本显示为字符，将int版本显示为数字
最后程序使用cout.put（）函数来显示c和a字符常量

成员函数cout.put()
是一个C++OOP概念成员函数的一个重要例子，
类定义了如何表示和控制数据，成员函数归类所有描述了操纵类数据的方法
例如ostream有一个put()成员函数来输出字符，只能通过类的特定对象来使用成员函数
要通过对象如cout使用成员函数，必须用.将对象名和函数名称put()连接起来
句点。被称为成员操作符
cout.put()的意思是通过类对象cout来使用函数put()，它提供了另一种显示
字符的方法，可以替代<<操作符

*/
//bondini.cpp -- using escape sequences
#include<iostream>
int main()
{
	using namespace std;
	cout << "\aOperation\"HyperHype\"is now activated!\n";//\a是振铃
	cout << "Enter your agent code:  ________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\aYou entered " << code << "...\n";
	cout << "\aCode verified! Proceed with plan z3!\n";
	return 0;
}
/*
wcha_t
程序需要处理的字符集可能无法用一个8位的字节表示
首先如果大型字符集是实现的基本字符集，则编译器厂商可以将char定义位一个16位的字节或更长的字节
其次一种实现可以同时支持一个小型基本字符集和一个较大的扩展字符集
8位char可以表示基本字符姐
另一种wchar_t可以表示扩展字符集
cin和cout是char流，wcin和wcout是wchar_t流
另外可以通过加上前缀L来指示宽字符常量和宽字符串例如
wchar_t bob = L‘p’;
wcout<<L"tall"<<endl;

bool类型
bool isready = true;
任何数字值或指针值都可以被隐式转换为bool值，任何非0值都被转换为trye，而零被转换为false
bool start = -100;//true
bool stop = 0//false
*/