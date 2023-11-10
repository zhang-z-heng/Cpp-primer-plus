//carrot.cpp -- food processing program
//uses and displays a variable

#include <iostream>

/*int main()
{
	using namespace std;

	int carrots;    // declare an integer variable

	carrots = 25;  // assign a value to the variable
	cout << "I have ";
	cout << carrots; //display the value of the variable
	cout << " carrots.";
	cout << endl;
	carrots = carrots - 1; // modify the variable
	cout << "Crunch, crunch, Now I have " << carrots <<" carrots." << endl;
	return 0;
}
*/
/*
* int steinway;
* int baldwin;
* int yamaha;
* yamaha = baldwin = steinway = 88;
* 赋值将从右向左进行，88首先被赋给steinway然后steinway的值被赋给baldwin最后baldwin的值赋给yamaha
* 
* cout可用于数字和字符串，整数25和字符串25的区别是，字符串存储的是书写该数字时使用的字符即字符2和5
* 程序在内部存储的是字符2和字符5的编码，要打印字符串，cout只需打印字符串中各个字符即可
* 但整数25被存储为数值，计算机不是单独存储每个数字而是将25存储为2进制数
*/
//getinfo.cpp-- input and output
int main()
{
	using namespace std;
	int carrots;

	cout << " How many carrots do you have? " << endl;
	cin >> carrots;
	cout << " Here are two more. ";
	carrots = carrots + 2;
	//the next line concatenates output
	cout << " Now you have " <<  carrots  << " carrots. " << endl;
	return 0;
}
/*
cin >> carrots;
从这条语句可知，信息从cin流向carrots，在iostream文件将cin定义为一个表示这种流的对象
输出时？<<操作符将字符串插入到输出流中，输入时，cin使用>>操作符将输入流中抽取字符

类简介
类是用户定义的一种数据类型，类之于对象就像类型之于变量，类定义描述的是数据格式及其用法，
而对象祖师根据数据格式规范创建的实体
int carrots；这个代码将创建一个类型为int的变量，cattots可以存储整数，可以按特定的方式如
加减使用，cout是一个ostream类对象，ostream类定义描述了ostream对象表示的数据以及
可以对它执行的操作，如将数字和字符串插入到输出流中，cin也是一个istream类的对象，也是在iostream中定义的

类描述了一种数据流行的全部属性，对象是根据这些描述创建的实体

函数
有返回值的函数将生成一个可被赋给变量的值，例如，sqrt()函数，假设要计算6.25的平方根，并将这个值
赋给变量x，可以使用 x = sqrt(6.25);表达式将调用sqrt（）函数，称为函数调用，被调用的函数叫做called function
6.25是发送给函数的信息，被称为传递给函数
以这种方式发送给函数的值叫做参数
其得到的结果为2.5，并将这个值发送给调用函数，发送回去的值叫做函数的返回值
函数执行完毕后，语句中的函数调用部分将被替换为返回的值
参数是发送给函数的信息，返回值是从函数中发送回的值

c++程序应当为程序中使用的每个函数提供原型，函数原型之于函数就像变量声明之于变量
在程序中使用sqrt()时，必须提供原型，1.在源代码文件中输入函数原型，2.包含头文件cmath，其中定义了原型
原型只描述函数接口，它描述的是发送给函数的信息和返回的信息
函数定义则包含了函数的代码


*/