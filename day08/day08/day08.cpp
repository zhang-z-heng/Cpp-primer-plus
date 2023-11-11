/*
数组能够存储多个同类型的值，例如数组可以存储60个int类型的值
12个short值，或365个float值，每个值都存储在一个独立的数组元素
要创建数组，需声明以下三点
存储在每个元素中的值的类型
数组名
数组中的元素数
例如 short months[12];就是一个名为months的数组有12个元素，每个元素都可以存储一个short类型的值
其通用格式为typeName arrayName[arraySize];
表达式arraySize指定元素数目，必须是整型常数或const值也可以是常量表达式

数组都是从0开始编号


*/
//arrayone.cpp -- small arrays of integers
/*#include<iostream>
int main()
{
	using namespace std;
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = { 20, 30, 5 };

	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs ";
	cout << yamcosts[1] << " cents per yam.\n";
	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];
	cout<<"The total yam expense is "<<total<<" cents.\n";

	cout << "\nSize of yams array = " << sizeof yams;
	cout << "bytes.\n";
	cout << "Size of one element = " << sizeof yams[0];
	cout << "bytes.\n";
	return 0;
}*/
/*
数组赋值，需要一个都好分割的值列表，并将他们用花括号括起，列表中的空格是可选的
如果没有初始化函数中定义的数组，则元素值将是不确定的，这意味着元素的值为以前驻留在该内存单元中的值

字符串
是存储在内存的连续字节中的一系列字符，c-风格字符串以空字符\0结尾
char dog[5] = {'b','e','a','u','x'};//not a string
char cat[5] = {'f','a','t','s','\0'};// a string
这两个数组都是char数组，但只有第二个数组是字符串
用cout打印第一个数组，cout将打印出数组的5个字母，并接着将内存中随后的各个字节解释为要打印的字符，知道遇到空字符位置
更好的初始化字符串的方法，只需使用一个引号括起的字符串即可
char bird[10] = "Mr. Cheeps"；
char fish[] = “Bubbles”;这种字符串被称为字符串常量

拼接字符串常量
有时候字符串很长无法放到一行中
c++允许拼接字符串常量，即将两个用引号括起的字符串合为一个

在数组中使用字符串
两种方法，一将数组初始化为字符串常量将键盘或文件输入到数组中
strlen()来确定字符串长度
cstring提供了该函数以及很多字符串相关的其他函数声明
*/

//string.cpp -- storing strings in an array
/*#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	const int Size = 15;
	char name1[Size];//empty array
	char name2[Size] = "C++owboy";//initialized array

	cout << "Howdy! I'm " << name2;
	cout << "! what is your name?\n";
	cin >> name1;
	cout << "Well, " << name1 << ", your name has ";
	cout << strlen(name1) << " letters and is stored\n";
	cout << "in an array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	name2[3] = '\0';
	cout << "Here are the first 3 characters of my name: ";
	cout << name2 << "\n";
	return 0;
}*/
/*
sizeof操作符指出整个数组的长度15字节
strlen()函数返回的是存储在数组中的字符串的长度而不是数组本身的长度
它只计算课件的字符，而不把空字符计算在内
另外该程序将name2[3]设置为空字符，这使得字符串在第三个字符后结束，虽然数组中还有其它字符


字符串输入
*/
//instrl.cpp -- reading more than one string
/*#include<iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name: \n";
	cin >> name;//cin.getline(name,ArSize):
	cout << "Enter your favorite dessert: \n";
	cin >> dessert;//cin.getline(dessert,ArSize)；
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}*/
/*
这个程序可以在第一个问题回答时，输入两个字符串，用空格隔开，第二个字符串会直接回答下一个问题
并进行输出

每次读取一个单词通常不是最好的选择，要将整条短语输入
getline()和get（）,这两个函数都读取一行输入，直到到达换行符
然后随后getline（）将丢弃换行符，而get()将换行符保留在输入序列里

getline（）函数使用回车键输入的换行符来确定输入结尾
要调用这种方法，可以使用cin.getline()
该函数有两个参数
第一个参数是用来存储输入行的数组的名称
第二个参数是要读取的字符数
如果这个参数时20，则函数最多读取19个字符，余下的空间用于存储自动在结尾处添加的空字符
getline函数在读取指定数目的字符或遇到换行符停止读取
cin.getline(name.20)；
这将把一行读入到name数组，如果这行包含的字符不超过19个

get()
get并不再读取并丢弃转行符，而是将其留在输入队列中
假设我们连续两次调用get()
cin.get(name. ArSize);
cin.get(dessert,Arsize);
由于第一次调用后，换行符将留在输入队列里，因此第二次调用时看到的第一个字符就是换行符
因为get()认为已达到行尾，而没有发现任何可读取内容，故而可以这样输入
cin.get(name. ArSize);
cin.get()；
cin.get(dessert,Arsize);
另一种方式是
cin.get(name. ArSize).cin.get()；

*/
//instr3.cpp -- reading more than one word with get()&get()
#include<iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name :\n";
	cin.get(name, ArSize).get();
	cout << "Enter your favorite dessert :\n";
	cin.get(dessert, ArSize).get();
	cout << "I have some delicious " << dessert;
	cout << " for you. " << name << ".\n";
	return 0;
}
/*
如果使用的是cin.get(name,ArSize)则编译器知道是将一个字符串放入数组中，因而使用适当的成员函数
如果使用的是cin.get()则编译器知道是要读取一个字符

为什么要使用get()而不是getline（）呢
使得检查错误更简单些

空行和其他问题
当get()读取空行后将设置失效位，这意味着接下来的输入将被阻断使用
cin.clear():
另一个潜在的问题是，输入字符串可能比分配空间长，如果输入行包括的字符数比指定的多，
则getline()和get()将余下的字符留在输入队列中，而getline（）还会设置失效位并关闭后面的输入

*/