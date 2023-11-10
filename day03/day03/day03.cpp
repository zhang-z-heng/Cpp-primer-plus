//sqrt.cpp -- using the sqrt() function

/*#include <iostream>
#include <math.h>

int main()
{

	using namespace std;

	double area;
	cout << "Enter the floor area, in square feet, of your home : ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "That's the equivalent of a square "<< side
		<< " feet to the side." << endl;

	cout << "How fascinating !" << endl;
	return 0;
}
*/
/*
库函数存储在库文件中，如果运行程序时，得到一条消息，指出sqrt是一个没有定义的外部函数
则很可能是由于编译器不能自动搜索数学库，如果得到这样的消息，请查看编译器文档
如在unix实现要求在命令行结尾使用-lm选项，cc sqrt.c -lm
在linux系统中使用gnu编译器的方法于此类似 q++ sqrt.c -lm
只包含cmath头文件可以提供原型，但不一定会导致编译器搜索正确的库文件

也可以 double side = sqrt(area) ;这个过程叫做初始化

函数变体，有些函数需要多项信息，这些函数使用多个参数，参数见用逗号分开
pow()接受两个参数，返回值为以第一个参数为底，第二个参数为指数的幂
double pow (double, double);如要计算5的8次方则可以使用
answer = pow(5.0, 8.0)；

另外一些函数不接受任何参数 如 int rand(void);void明确指出该函数不接受任何参数
如果省略void，让括号为空，则是一个不接受任何参数的隐式声明 myGuess = rand();

还有一些函数没有返回值，可以写为 void bucks(double);即不调用程序，不返回任何值
由于他不返回值，因此不能将该函数调用放在赋值语句或其他表达式中





*/
// ourfunc.cpp -- defining your own function
#include <iostream>
void simon(int); // function prototype for simon()

int main()
{
	using namespace std;
	simon(3); // call the simon() function
	cout << "Pick an integer: "; // <<endl;
	int count;
	cin >> count ;
	simon(count); // call it again
	cout << "Done!" << endl;
	return 0;
}
void simon(int n) // define the simon () function
{
	using namespace std;
	cout << "Simon says touch your toes " << n << " times. " << endl;

} // void functions dont need return statement
/*
main()函数两次调用simon()函数，一次为3，一次为变量count，在这两次调用之间，
用户输入一个整数用来设置count的值，这个例子没有在cout提示消息中使用换行符
这样将导致用户输入予提示出现在同一行中

simon()函数的定义与main()的定义采用的格式相投即
type functioname(argumentlist)
{
statements
}
注意定义simon（）的源代码位于main()的后面，c++不允许将函数定义嵌套在另一个函数定义中，每个函数定义都是独立的，所有函数的创建是平等的
#include<iostream>
using namespace std;
void simon(int);  //函数原型
double taxes(double);
int main()  // 函数1
{
....
return 0;
}
void simon(int n) // 函数2
{
....
}
double taxes(double t) //函数3
{
...
return 2 * t;
}


simon（）函数的函数头如下 void simon(int n)
开头的void表明simon（）没有返回值，因此调用simon()不会生成可在main（）中将其赋给变量的数字
因此 第一个函数的调用方式为 simon(3)；
由于simon()没有返回值因此不能这样使用它 simple = simon(3);
括号中的int n表明，使用simon()时，应提供一个int参数，n是一个新的变量，函数调用时传递的值将被赋给它，因此函数调用
simon(3);将3赋给simon（）函数头中定义的变量n，当函数体中的cout使用n时，将使用函数调用时传递的值，这就是为什么simon（3）
在输出中显示3的原因所在
之后simon(count)导致函数显示count，因为这正是赋给count的值
简而言之，simon()的函数头表明，该函数接受一个int参数，不返回任何值




*/