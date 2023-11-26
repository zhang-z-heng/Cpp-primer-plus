/*
8.8通过调用同一个函数将数据写入文件和显示到屏幕上来说明这一点
该程序要求用户输入望远镜物镜和一些目镜的焦距并计算显示每个目镜的放大倍数
放大背书等于物镜的焦距除以目镜的焦距，用于cout和ofstream对象
*/

//filefunc.cpp -- function with ostream & parameter
/*#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void file_it(ostream& os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main()
{
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye." << endl;
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "Enter the focal length of your telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:" << endl;
	for (int i = 0; i < LIMIT;i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);//目镜数据写入文件
	file_it(cout, objective, eps, LIMIT);//显示再屏幕上
	cout << "Done" << endl;
	return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;//存储这种信息所需的数据类型名称
	initial = os.setf(ios_base::fixed); // save initial formatting state
	//将对象置于使用定点表示法的模式
	os.precision(0);//os可以指向ostream对象，如cout,也可以指向ofstream对象如fout
	os << "Focal length of objective: " << fo << " mm\n";
	os.setf(ios::showpoint);//将对象置于显示小数点的模式，即使小数部分为0
	//
	os.precision(1);//指定显示多少位小数
	os.width(12);//设置下一次输出操作使用的字段宽度，只对下一个值有效，然后恢复默认设置
	os << "f.1 eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);//restore initial formatting state
	//setf()设置各种格式化状态，将返回值赋给initial将存储调用file_it（）
	//之前的格式化设置，然后initial作为参数来调用setf()，将所有的格式化设置恢复到原来的值
	//每个对象都存储了自己的格式化设置
}
/*
使用引用参数的主要原因
1程序员能够修改调用函数中的数据对象
2通过传递引用而不是整个数据对象可以提高运行速度
如果数据对象是类对象使用const引用
*/
//默认参数
//left.cpp -- string function with a default argument
/*#include<iostream>
const int ArSize = 80;
char* left(const char* str, int n = 1);
int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "Enter a string: " << endl;
	cin.get(sample, ArSize);
	char* ps = left(sample, 4);
	cout << ps << endl;
	delete[]ps; //free old string
	ps = left(sample);
	cout << ps << endl;
	delete[]ps; // free new string
	return 0;
}

//this function returns a pointer to a new string
//consisting of the first n characters in the str string
char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0;i < n && str[i];i++)//str[i]是要复制的字符的编码，遇到空值字符后循环将结束
		p[i] = str[i]; // copy characters
	while (i <= n)
		p[i++] = '\0';//set rest of string to '\0'
	return p;
}
/*
另一种设置新字符串长度的方法是将n设置为传递的值和字符串长度中较小的一个
int len = strlen(str);
n= (n< len) ? n : len;//the lesser of n and len
char*p = new char[n+1];
这样确保new分配的空间不会多于存储字符串所需的空间

重载函数
*/
//8.10 leftover.cpp--overloading the left() function
/*#include<iostream>
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);

int main()
{
	using namespace std;
	char trip[9] = "HAWAII!!"; //test value
	unsigned long n = 12345678; //test value
	int i;
	char* temp;

	for (i = 1;i < 10;i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[]temp;
	}
	return 0;
}
unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0)
		return 0; // return 0 if no digits
	while (n /= 10)
		digits++;
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;  //return left ct digits
	}
	else   // if ct>=number of digits
		return num; // return the whole number
}

//This function returns a pointer to a new string
//consisting of the first n characters in the str string
char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0;i < n && str[i];i++)
		p[i] = str[i]; // copy characters
	while (i <= n)
		p[i++] = '\0'; // set rest of string to '\0'
	return p;
}*/

//8.11FUNTEMP.CPP--USING a function template
/*#include<iostream>
//function template prototype
template<typename T>  //or class T
void Swap(T &a, T &b);

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i,j = " << i << ", " << j << ".\n";
	cout << "Using complier generated int swapper:\n";
	Swap(i, j);//generates void swap(int &,int &)
	cout << "Now i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x,y = " << x << ", " << y << ".\n";
	cout << "Using complier-generated int swapper:\n";
	Swap(x, y);//generates void Swap(double &, double &)
	cout << "Now x, y = " << x << ", " << y << ".\n";
	//cin.get();
	return 0;
}
template<typename T>  //or class T
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
*/

//8.12twotemps.cpp--using overloader template functions
/*#include<iostream>
template<typename T>
void Swap(T& a, T& b);

template<typename T>
void Swap(T* a, T* b, int n);
void Show(int a[]);
const int Lim = 8;
int main()

{
	using namespace std;
	int i = 10, j = 20;
	cout << "i,j = " << i << ", " << j << ".\n";
	cout << "Using complier-generated int swapper:\n";
	Swap(i, j);
	cout << "Now i,j = " << i << ", " << j << ".\n";

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,7,2,0,1,9,6,9 };
	cout << "Original arrays:\n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	cout << "Swapped arrays:\n";
	Show(d1);
	Show(d2);
	//cin.get();
	return 0;
}

template<typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0;i < n;i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	using namespace std;
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4;i < Lim;i++)
		cout << a[i];
	cout << endl;
}*/
//8.13TWOSWAP.CPP --SPECIALIZATION OVERRIDES A TEMPLATE
/*#include<iostream>
template<typename T>
void Swap(T& a, T& b);

struct job
{
	char name[40];
	double salary;
	int floor;
};

//explicit specialization
template<>void Swap<job>(job& j1, job& j2);
void Show(job& j);

int main()
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "Using complier-generated int swapper:\n";
	Swap(i, j);
	cout << "Now i, j= " << i << ", " << j << ".\n";

	job sue = { "Susan Yaffee", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "Before job swapping:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);//uses void Swap(job &, job &)
	cout << "After job swapping:\n";
	Show(sue);
	Show(sidney);
	//cin.get();
	return 0;
}

template<typename T>
void Swap(T& a, T& b) //general version
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
//swaps just the salary and floor fields of a job structure

template<>void Swap<job>(job& j1, job& j2) //specialization
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job& j)
{
	using namespace std;
	cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}*/

//8.14temptempover.cpp--template overloading
/*#include<iostream>
template<typename T>
void ShowArray(T arr[], int n);

template<typename T>
void ShowArray(T* arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe",1300.0},
		{"Iby Stout",1800.0}
	};
	double* pd[3];

	//set pointers to the amount members of the structures in mr_E
	for (int i = 0;i < 3;i++)
		pd[i] = &mr_E[i].amount;
	cout << "Listing Mr.E's counts of things:\n";
	//things is an array of int
	ShowArray(things, 6);//uses template A
	cout << "Listing Mr.E's debts:\n";
	//pd is an array of pointers to double
	ShowArray(pd, 3);
	return 0;
}

template<typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "template A\n";
	for (int i = 0;i < n;i++)
		cout << arr[i] << " ";
	cout << endl;

}

template <typename T>
void ShowArray(T* arr[], int n)
{
	using namespace std;
	cout << "template B\n";
	for (int i = 0;i < n;i++)
		cout << *arr[i] << " ";
	cout << endl;
}*/

//8.15 choices.cpp--choosing a template
#include<iostream>

template<class T>
T lesser(T a, T b)
{
	return a < b ? a : b;
}

int lesser(int a, int b)
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}

int main()
{
	using namespace std;
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;

	cout << lesser(m, n) << endl;
	cout << lesser(x, y) << endl;
	cout << lesser<>(m, n) << endl;
	cout << lesser<int>(x, y) << endl;

	return 0;
}
