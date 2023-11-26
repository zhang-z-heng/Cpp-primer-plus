/*
内联函数
在函数声明前加上inline，在顶以前加上inline

//8.inline.cpp -- using an inline funchtion
#include<iostream>
//an inline function definition
inline double square(double x) { return x * x; }

int main()
{
	using namespace std;
	double a, b;
	double c = 13.0;
	a = square(5.0);
	b = square(4.5 + 7.5);
	cout << "a = " << a << ", b = " << b << endl;
	cout << "c= " << c;
	cout << ", c squared = " << square(++c) << endl;//++c,14,c++,13
	cout << "Now c = " << c << endl;
	return 0;
}*/
/*
引用变量
引用时已定义的变量的别名，主要用途是用作函数的形参
int &rodents = rats;//&不是地址运算符，而是类型标识符的一部分
就像char*指的是指向char的指针一样
int&指的是指向int的引用,必须在声明引用时将其初始化
*/
//8.2firstref.cpp --defining and using a reference
/*#include<iostream>
int main()
{
	using namespace std;
	int rats = 101;
	int& rodents = rats;//rodents is a reference
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	//some implementation require type casting the following
	//addresses to type unsigned
	cout << "rats address = "<<&rats;
	cout << ", rodents address = " << &rodents << endl;
	return 0;
}*/
//8.3secref.cpp -- defining and using a reference
/*#include<iostream>
int main()
{
	using namespace std;
	int rats = 101;
	int& rodents = rats;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;

	int bunnies = 30;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnies address = " << &bunnies;
	cout << ", rodents address = " << &rodents << endl;
	return 0;
}*/

/*
将引用用作函数参数，使得函数中的变量名成为调用程序中的变量的别名
按引用传递允许别调用的函数能够访问调用函数中的变量，c语言只能按值传递
*/
//8.4 swaps.cpp -- swapping with references and with pointers
/*#include<iostream>
void swapr(int& a, int& b); //a,b are aliases for ints
void swapp(int* p, int* q); // p,q are addresses of ints
void swapv(int a, int b); // a b are new variables

int main()
{
	using namespace std;
	int wallet1 = 300;
	int wallet2 = 350;
	cout << "wallet1 = $" << wallet1;
	cout << "wallet2 = $" << wallet2 << endl;

	cout << "using references to swap content:\n";
	swapr(wallet1, wallet2); // pass variables
	cout << "wallet1 = $" << wallet1;
	cout << "wallet2 =$" << wallet2 << endl;

	cout << "using pointers to swap contents again:\n";
	swapp(&wallet1, &wallet2);//pass addresses of variables
	cout << "wallet1 = $" << wallet1;
	cout << "wallet2 = &" << wallet2 << endl;

	cout << "tring to use pass by value:\n";
	swapv(wallet1, wallet2);
	cout << "wallet1 = $" << wallet1;
	cout << "wallet2 = $" << wallet2 << endl;

	return 0;

}

void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
/*
引用和指针都成功交换了内容，按值传递却失败了

*/
//8.5 cubes.cpp -- regular and reference arguments
#include<iostream>
/*double cube(double a);
double refcube(double& ra);
int main()
{
	using namespace std;
	double x = 3.0;

	cout << cube(x);
	cout << " = cube of " << x << endl;  //27=cube of 3
	cout << refcube(x);
	cout << " = cube of " << x << endl;  //27=cube of 27
	return 0;
}
double cube(double a)
{
	a *= a * a;
	return a;
}
double refcube(double& ra)
{
	ra *= ra * ra;
	return ra;
}
/*
recube函数修改了x值，而cube没有
右值引用
用&&声明，让库设计人员能够提供有些操作的更有效实现
引用用于结构可这样编写函数原型
void set_pc(free_throws&ft)
如果不希望函数修改传入的结构可使用const
*/
//8.6 strc_ref.cpp -- using structure references
/*#include<iostream>
#include<string>
struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;

};

void display(const free_throws& ft);
void set_pc(free_throws& ft);
free_throws& accumulate(free_throws& target, const free_throws& source);

int main()
{
//partial initializations - remaining members set to 0
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Max", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };
//no initialization
	free_throws dup;

	set_pc(one);//其形参ft为引用，ft指向one，set_pc的代码设置成员one.percent
	//按值传递不可行，因此这将导致设置的是one临时拷贝的成员percent
	display(one);//其显示结构内容而不修改它使用了const
	//也可按值传递结构，但与赋值的原始结构的拷贝相比节省时间内存
	accumulate(team, one);//两个参数并将第二个结构成员attempts和made的数据
	//添加到第一个结构相应成员中，因此第一个参数为引用，而第二个参数为const引用
	display(team);
	//use return value as argument
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);
	//use return value in assignment
	dup = accumulate(team, five);
	std::cout << "Displaying team:\n";
	display(team);
	std::cout << "Displaying dup after assignment:\n";
	display(dup);
	set_pc(four);
	//ill*advanced assignment
	accumulate(dup, five) = four;
	std::cout << "Displaying dup after ill-advised assignment:\n";
	display(dup);
	return 0;

}

void display(const free_throws& ft)
{
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << " Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Perccent: " << ft.percent << '\n';

}

void set_pc(free_throws& ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	else
		ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}*/
//原本可以将返回值声明为VOID，但由于独特方式的使用accumulate，其返回值是一个引用
//函数按值返回这条语句将不能通过编译accumulate(accumulate(team, three), four)
/*
为何要返回引用
dup = accumulate(team, five);
如果accumulate返回一个结构而不是指向结构的引用，将把整个结构复制到一个临时位置
再将这个拷贝赋值给dup但在返回值为引用时，将直接把team复制到dup其效率更高
返回引用的函数实际上是被引用的变量的别名
返回引用需注意避免返回函数终止时不再存在的内存单元引用，也应避免返回指向临时变量的指针
为避免这种问题，应返回一个座位参数传递给函数的引用
另一种方法是用new来分配新的存储空间
const free_throws&clone(free_throws & ft)
{
   free_throws * pt;
   *pt = ft;   // copy info
   return *pt; // return reference to copy
}
第一条语句创建一个无名的free_throws的结构并让指针pt指向该结构
*pt就是该结构，函数声明表明该返回为这个结构的引用
这样便可这样使用该函数
free_throws & jolly = clone(three);使得jolly成为新结构的引用

为何将const用于引用返回类型？
accumulate(dup, five) = four;
首先将five数据添加到dup中，在使用four的内容覆盖dup
在赋值语句中，左边必须是可修改的左值，左边的子表达式必须表示一个可修改的内存块
函数返回指向dup的引用，他确实表示的是一个这样的内存快

*/
//8.7 strquote.cpp -- different designs
#include<iostream>
#include<string>
using namespace std;
string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2); // has side effect
const string& version3(string& s1, const string& s2); //bad design

int main()
{
	string input;
	string copy;
	string result;

	cout << "Enter a string: ";
	getline(cin, input);
	copy = input;
	cout << "Your string as entered: " << input << endl;
	result = version1(input, "***");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	result = version2(input, "###");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	cout << "Reseting original string." << endl;
	input = copy;
	result = version3(input, "@@@");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	return 0;
}

string version1(const string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;
	return temp;
}
const string& version2(string& s1, const string& s2)//has side effect
{
	s1 = s2 + s1 + s2;
	//safe to return reference passed to function
	return s1;
}//该函数可以修改s1因为不同于s2所以没有const
const string& version3(string& s1, const string& s2)//bad design
{
	string temp;
	temp = s2 + s1 + s2;
	//unsafe to return reference to local variable
	return temp;
}
/*
返回一个指向version3中声明的变量的引用，程序引用已经释放内存
*/
