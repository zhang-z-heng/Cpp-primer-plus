/*
7.3.4使用数组区间的函数
元素区间，通过传递两个指针来完成，一个指针标识数组的开头，一个指针标识尾部
double elbuod[20]
elboud和elboud+20定义了区间
elboud指向了第一个元素，表达式elboud+19指向最后个元素
*/
//arrfun4.cpp--functions with an array range
/*#include<iostream>
const int ArSize = 8;
int sum_arr(const int* begin, const int* end);
int main()
{
	using namespace std;
	int cookies[ArSize] = { 1, 2,4,8,16,32,64,128 };
	//some systems require preceding int with static to
	//enable array initialization

	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "Total cookies eaten: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "First three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "Last four eaters ate " << sum << " cookies.\n";
	return 0;
}
//return the sum of an integer array
int sum_arr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;

	for (pt = begin; pt != end;pt++)
		total = total + *pt;
	return total;
}*/
/*
指针和const
可以用两种不同的方式将const关键字用于指针
第一种方法是让指针指向一个常量对象
第二种方法时将指针本身声明为常量
int age =39;
const int *pt = &age;
该声明指出pt指向一个const int因此不能使用pt来修改这个值
但可以直接通过age变量来修改age的值  age = 20;
以前我们将常规变量的地址赋给常规指针，这里将常规变量地址赋给const指针
const float g_earth = 9.8;
const float *pe = &g_earth;
既不能使用g_earth修改值，也不能使用pe来修改，
若省略第二行的const，其g_earth的地址赋给pt，则可以通过修改pt的值修改g_earth的值
这第一行的const就很荒谬
指针指向指针
int age = 39;
int *pd = &age;
const int *pt = pd;  //*pt =42 is an invalid operation
然而进入两级间接关系时，与一级间接关系一样将const和非const
混合的指针赋值方式将不再安全
const int **pp2;
int *p1;
const int n = 13;
pp2 = &p1;//not allowed but suppose it were
*pp2 = &n;//valid both const but sets p1 to point at n
*p1 = 10; //valid but changes const n
上述代码将非const地址赋给了const指针，因此可以使用pl修改const数据

7.4函数和二维数组
int sun(int ar2[][4],int size)
{
           int total = 0;
		   for(int r = 0; r<size;r++)
		      for(int c = 0; c<4; c++)
			     total += ar2[r][c];
		   return total;
}ar2指向数组的第一个元素，ar2+r指向编号为r的元素，由于该元素本身就是一个
由4个int组成的数组，因此ar2[r]是由4个int组成的数组的名称，[r][c]一个是元素
一个是int值，必须对指针ar2执行两次解除引用才能得到数据
ar2[r][c] == *(*(ar2+r)+c)  


*/

//7.9 strgfun.cpp -- functions with a string argument
/*#include<iostream>
unsigned int c_in_str(const char* str, char ch);
int main()
{
	using namespace std;
	char mmm[15] = "minimum";  //string in an array
	//some systems require preceding char with static to enable array initialization

	char wail[15] = "ululate";  //wail points to string

	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << ms << " m characters in " << mmm << endl;
	cout << us << " u characters in " << wail << endl;
	return 0;
}
//this function counts the number of ch characters in the string str
unsigned int c_in_str(const char* str, char ch)
{
	unsigned int count = 0;

	while (*str)   //quit when *str is '\0'
	{
		if (*str == ch)
			count++;
		str++;  // move pointer to next char
	}
	return count;
}*/
/*
c_int_str()函数不应修改原始字符串，因此他在声明形参str时使用了const
该函数本身演示了处理字符串中字符的标准方式
while(*str){
      statements; 
	  str++}
str最初指向字符串的第一个字符，*str表示的是第一个字符
str++将指针增加一个字节，使之指向字符串中的下一个字符
最终str将指向结尾空值字符从而结束循环
*/
//7.10 strgback.cpp -- a function that returns a pointer to char
/*#include<iostream>
char* buildstr( char c, int n );
int main()
{
	using namespace std;
	int times;
	char ch;

	cout << "Enter a character: ";
	cin >> ch;
	cout << "Enter an integer: ";
	cin >> times;
	char* ps = buildstr(ch, times);
	cout << ps << endl;
	delete[]ps;  //free memory
	ps = buildstr('+', 20);  //reuse pointer
	cout << ps << "-Done-" << ps << endl;
	delete[]ps;
	return 0;
}
//builds string made of n c characters
char* buildstr(char c, int n)
{
	char* pstr = new char[n + 1];
	pstr[n] = '\0';  //terminate string
	while (n-- > 0)
		pstr[n] = c; // fill rest of string
	return pstr;
}*/

/*
传递和返回结构，当结构较小时，按值传递结构最合理

*/
//7.11travel.cpp -- using structures with functions
/*#include<iostream>
struct travel_time
{
	int hours;
	int mins;
};
const int Mins_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main()
{
	using namespace std;
	travel_time day1 = { 5, 45 };  //5 hrs 45min
	travel_time day2 = { 4, 55 };  //4 hrs 55min

	travel_time trip = sum(day1, day2);
	cout << "Two-day total: ";
	show_time(trip);

	travel_time day3 = { 4, 32 };
	cout << "Three-day total: ";
	show_time(sum(trip, day3));

	return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
	travel_time total;

	total.mins = (t1.mins + t2.mins) % Mins_per_hr;
	total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;
	return total;
}

void show_time(travel_time t)
{
	using namespace std;
	cout << t.hours << " hours, " << t.mins << " minutes\n";
}*/

//7.12 strctfun.cpp -- function with a structure argument
/*#include<iostream>
#include<cmath>

//structure declarations
struct polar
{
	double distance;  //distance from origin
	double angle;  //direction from origin
};
struct rect
{
	double x; // horizontal distance from origin
	double y; //vertical distace from origin
};

//prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;

	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)  //slick use of cin
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Done.\n";
	return 0;
}

//convert rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;

	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;  //return a polar structure
}

//show polar coordinates,converting angle to degrees
void show_polar(polar dapos)
{
	using namespace std;
	const double Rad_to_deg = 57.29577951;

	cout << "distance = " << dapos.distance;
	cout << ", angle = " << dapos.angle * Rad_to_deg;
	cout << " degrees\n";
}*/
/*
假设要传递的结构地址而不是整个结构以节省时间和空间，使用指向结构的指针
调用函数时，将结构的地址（&pplace）而不是结构本身（pplace）传递给它
将形参声明为指向polar的指针，即polar*类型，由于函数不应该修改结构，使用const
由于形参是指针而不是结构，因此应间接成员运算符而不是成员运算符
为了充分利用指针的效率使用指针而不是返回值
则需要两个指针，一个指向要转换的结构，一个指向存储转换结果的结构
*/

//7.13 strctptr.cpp -- functions with pointer to structure arguments
/*#include<iostream>
#include<cmath>

//structure templates
struct polar
{
	double distance;
	double angle;
};
struct rect 
{
	double x;
	double y;
};
//prototypes
void rect_to_polar(const rect* pxy, polar* pda);
void show_polar(const polar* pda);

int main()
{
	using namespace std;
	rect rplace;
	polar pplace;
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		rect_to_polar(&rplace, &pplace);  //pass addresses
		show_polar(&pplace);   // pass address
		cout << " Next two numers (q to quit): ";
	}
	cout << "Done.\n";
	return 0;
}

//show polar coordinates converting angle to degrees
void show_polar(const polar* pda)
{
	using namespace std;
	const double Rad_to_deg = 57.295779951;

	cout << "distance = " << pda->distance;
	cout << ", angle = " << pda->angle * Rad_to_deg;
	cout << "degrees\n";
}
//convert rectangular to polar coordinates
void rect_to_polar(const rect* pxy, polar* pda)
{
	using namespace std;
	pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}*/

//函数和string对象
//7.14 topfive.cpp -- handling an array of string objects
/*#include<iostream>
#include<string>
using namespace std;
const int SIZE = 5;
void display(const string sa[], int n);
int main()
{
	string list[SIZE];   // an array holding 5 string object
	cout << "Enter your " << SIZE << " favorite astronomical signts:\n";
	for (int i = 0;i < SIZE;i++)
	{
		cout << i + 1 << ": ";
		getline(cin,list[i]);
	}
	cout << "Your list: \n";
	display(list, SIZE);

	return 0;
}

void display(const string sa[], int n)
//sa[i]是一个string对象，sa是一个指向string对象的指针
{
	for (int i = 0;i < n;i++)
		cout << i + 1 << ": " << sa[i] << endl;
}*/
//函数与array对象
/*
假设使用一个array对象来存储一年四季的开支
std::array<double,4>expenses;
如果函数来显示expenses的内容可按值传递expenses:
show(expenses);
但如果函数要修改对象expenses，则需将该对象的地址传递给函数
fill(&expenses)
声明两个函数必须在函数圆形中指定array的类型
void show(std::array<double, 4>da);  //da an object
void fill(std :: array<double, 4>*pa); //pa a pointer to an object

*/

//7.15 arrobj.cpp -- function with array objects(c++11)
/*#include<iostream>
#include<array>
#include<string>
// constant data
const int Seasons = 4;
const std::array<std::string, Seasons>Snames =
       { "Spring","Summer","Fall","Winter" };

//function to modify array object
void fill(std::array<double, Seasons>* pa);
//function that uses array object without modifying it
void show(std::array<double, Seasons>da);

int main()
{
	std::array<double, Seasons>expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}

void fill(std::array<double, Seasons>* pa)
{
	using namespace std;
	for (int i = 0;i < Seasons;i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> (*pa)[i];
	}
}

void show(std::array<double, Seasons>da)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons;i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;
}*/
/*
show()存在的问题是expenses存储了4个double值，而创建一个新对象并
将expenses的值复制到其中的效率太低
fill()中（*pa）[i]是该对象的一个元素，括号必不可少

递归
void recurs(argumentlist)
{
       statements1
	   if(test)
	       recurs(arguments)
	   statements2
}
test最终将为false调用链将断开
只要if语句为true每个recurs（）调用都将执行statements 1,然后再调用recurs()，
而不会执行statement2
当if语句为false，当前调用将执行statements2
当前调用结束后，程序控制权将返回给调用它的recurs()而该recurs（）将执行statement2部分
然后结束，并将控制权返回给前一个调用，以此类推
因此假如进行了5此递归调用
则statement1部分将按函数调用执行5此
然后statements2部分将以与函数调用相反的顺序执行5次
进入5蹭递归后，程序将沿进入的路径返回

*/

//7.16 recur.cpp -- using recursion
/*#include<iostream>
void countdown(int n);

int main()
{
	countdown(-5); //call the recursive function
	return 0;
}

void countdown(int n)
{
	using namespace std;
	cout << "Counting down ... " << n << endl;
	if (n < 0)
		countdown(n + 1); //function calls itself
	cout << n << ": Kaboom!\n";
}*/
/*
在需要将一项工作不断分为2项小的，类似的工作时，递归非常有用
例如，绘制标尺，标出两端，找到中点，并将其标出
然后将同样的操作用于标尺的左半部分和右半部分
*/
//7.17 ruler.cpp -- using recursion to sybdivide a ruler
/*#include<iostream>
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int hign, int level);
int main()
{
	char ruler[Len];
	int i;
	for (i = 1;i < Len - 2;i++)
	{
		ruler[i] = ' ';
	}
	ruler[Len - 1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;

	for (i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1; j < Len - 2; j++)
			ruler[j] = ' ';  //reset to blank ruler
	}
	return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}*/
/*
subdivide()函数使用变量level来控制递归层,函数调用自身时
函数调用自身时，将把level减1，当level为0时该函数将不再调用自己
注意，subdivide（）调用自己两次，一次针对左半部分，另一次针对右半部分
最初的中点被用作一次调用的右端点和另一次调用的左端点
调用次数将呈几何级数增长
也就是说调用一次后导致两个调用然后4个调用再导致8个调用
*/
/*
函数指针
函数的地址是存储其机器语言代码的内存的开始地址
假设要设计一个函数，估算编写指定行数代码所需时间，并且希望不同程序员都将使用
该函数对于所有用户来说，函数的一部分代码都是相同的，但该函数允许每个程序员
提供自己的算法来估算时间，即使用算法函数地址传递
1.获取函数地址
只要使用函数名不跟参数即可
process(think);    //passes address of think() to process()
thought(think());  //passes return value of think() to thought()
process()调用使得process（）函数能够在其内部调用thnk（）函数，
thought()调用首先调用think函数，然后将think的的返回值传递给thought()函数
2.声明函数指针
必须指定指针指向的函数类型
double pam(int);  //prototype
double (*pf)(int); //pf points to a function that takes one int argument and
                     one int argument and that returns type double
pf = pam;  //pf now points to the pam() function
*pf是函数，pf是函数指针
声明指向特定类型的函数指针，可以首先编写这种函数的原型然后用（*pf）替换函数名
double (*pf)(int);  //pf points to a function that returns double
double *pf(int);  //pf() a function that returns a pointer to double
3.使用指针来调用函数
使用（*pf）时，只需将它看作函数名即可
double x = pam(4);    //call pam() using the function name
double y = (*pf)(5);  //call pam() using the pointer pf
double y = pf(5);   //also call pam() using the pointer pf


*/

//7.18 fun_ptr.cpp -- pointers to functions
/*#include<iostream>
double betsy(int);
double pam(int);

//second argument is pointer to a type double function that takes a type int argument
void estimate(int lines, double(*pf)(int));

int main()
{
	using namespace std;
	int code;
	cout << "How many lines of code do you need? ";
	cin >> code;
	cout << "Here's Betsy's estimate: \n";
	estimate(code, betsy);
	cout << "Here's Pam's estimate:\n";
	estimate(code, pam);
	return 0;
}

double betsy(int lns)
{
	return 0.05 * lns;
}

double pam(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double(*pf)(int))
{
	using namespace std;
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)\n";
}*/

//7.19 arfupt.cpp -- an array of function pointers
#include<iostream>
//various notations same signatures
const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
	using namespace std;
	double av[3] = { 1112.3, 1542.6, 2227.9 };

	//pointer to a function
	const double* (*p1)(const double*, int) = f1;
	auto p2 = f2;//c++11 automatic type dedution
	//pre c++11 can use the following code instead
	//const double *(*p2)(const double *, int) = f2;
	cout << "Using pointers to functions:\n";
	cout << " Address Value\n";
	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
	//（*p1）(av,3)和p2(av,3)都调用指向的函数,并将av和3作为参数	
	//因此显示的是这两个函数的返回值，其类型为const double*即double的地址
	//鉴于需要使用三个函数，如果有一个函数指针数组将很方便
	//pa an array of pointers
	//auto doesnot work with list initialiation
	const double* (*pa[3])(const double*, int) = { f1,f2,f3 };
	//所以使用[3]来以指出这是一个包含三个函数指针的数组
	// pa是一个包含三个元素的数组，*pa[3]表明pa是一个包含三个指针的数组
	// const double *为返回类型，这里不能使用auto，只能用于单值初始化，不能用于初始化列表
	// 但声明数组pa后再声明就简单了
	//but it does work for initializing to a single value
	//pb a pointer to first element of pa
	auto pb = pa;
	//pa和pb都是指向函数指针的指针
	//pre c++11 can use the following code instead
	//const double *(**pb)(const double *, int) = pa;
	cout << "\nUsing an array of pointers to functions: \n";
	cout << " Address Value\n";
	for (int i = 0; i < 3;i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
	cout << "\nUsing a pointer to a pointer to a function:\n";
	cout << " Address Value\n";
	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

	//what about a pointer to an array of function pointers
	cout << "\nUsing pointers to an array of pointers:\n";
	cout << " Address Value\n";
	//easy way to declare pc
	auto pc = &pa;
	//const double *(*(*pc)[3])(const double *, int) = &pa;
	//pd是一个指针，它指向一个包含三个元素的数组，*pd就是数组
	//而（*pd）[i]是数组中的元素，即函数指针，而*（*pd）[i](av,3)是返回的指针指向的值
	//也就是（*（*pd）[i]（av,3）)来调用函数，而*（*（*pd）[i]（av,3）)是指向的double值
	//pa+1为数组中下一个元素的地址
	//&pa +1 为数组pa后面一个12字节内存块的地址
	//**&pa == *pa == pa[0]对&pa接触两次引用才能得到第一个元素的值
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
	//hard way to declare pd
	const double* (*(*pd)[3])(const double*, int) = &pa;
	//store return value in pdb
	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;
	//alternative notation
	cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
	//cin.get();
	return 0;
}

//some rather dull functions
const double* f1(const double* ar, int n)
{
	return ar;
}

const double* f2(const double ar[], int n)
{
	return ar + 1;
}
const double* f3(const double ar[], int n)
{
	return ar + 2;
}
/*
其他简化声明的工具
typedef double real; // makes real another name for double
p_fun声明为7.19使用的指针类型的别名
typedef const double *(*p_fun)(const double *, int);  //p_fun now a type name
p_fun p1 = f1;   //f1 points to the f1() function

然后使用这个别名来简化代码
p_fun pa[3] = {f1, f2, f3};  //pa an array of 3 function pointers
p_fun(*pd)[3] = &pa;  // pd points to an attay of 3 function pointers

*/