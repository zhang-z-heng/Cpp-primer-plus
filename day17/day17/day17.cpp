//calling.cpp -- defining, prototyping, and calling a function
/*  1.
#include<iostream>
void simple();  //function prototype

int main()
{
	using namespace std;
	cout << "main() will call the simple() function:\n";
	simple();  //function call
	cout << "main() is finished with the simple() function.\n";
	//cin.get();
	return 0;
}

//function definition
void simple()
{
	using namespace std;
	cout << "I am but a simple function.\n";
}*/
/*
定义函数
void functionName (parameterList)
{
     statement
	 return  //optional
}
parameterList指定了传递给函数的参数类型和数量
例如void cheers(int n)意味着调用函数cheers()时，应将一个int值作为参数传递给它
*/
//protos.cpp --using prototypes and function calls
/*#include<iostream>
void cheers(int);//prototype no return value
double cube(double x);//prototypes returns a double
int main()
{
	using namespace std;
	cheers(5);
	cout << "Give me a number: ";
	double side;
	cin >> side;
	double volume = cube(side);  //function call
	cout << "A " << side << "-foot cube has a volume of ";
	cout << volume << " cubic feet.\n";
	cheers(cube(2)); //prototype protection at work
	return 0;
}
void cheers(int n)
{
	using namespace std;
	for (int i = 0;i < n;i++)
		cout << "Cheers! ";
	cout << endl;
}
double cube(double x)
{
	return x * x * x;
}*/

//7.3 twoarg.cpp -- a function with 2 arguments
/*#include<iostream>
using namespace std;
void n_chars(char, int);
int main()
{
	int times;
	char ch;

	cout << "Enter a character: ";
	cin >> ch;
	while (ch != 'q')  //q to quit
	{
		cout << "Enter an integer: ";
		cin >> times;
		n_chars(ch, times); // function with two arguments
		cout << "\nEnter another character or press the q-key to quit: ";
		cin >> ch;
	}
	cout << "The value of times is " << times << ".\n";
	cout << "Bye\n";
	return 0;
}

void n_chars(char c, int n)   //displays c n times
{
	while (n-- > 0)   //continue until n reaches 0
		cout << c;
}*/

//7.4 lotto.cpp -- probability of winning
/*#include<iostream>
//Note: some implementations require double instead of long double
long double probability(unsigned numbers, unsigned picks);
int main()
{
	using namespace std;
	double total, choices;
	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed:\n";
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices); //compute the odds
		cout << " of winning.\n";
		cout << "Next two numbers (q to quit): ";
	}
	cout << "bye\n";
	return 0;

}
//following function calculates the probability of picking picks
//numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0; //here come some local variables
	long double n;
	unsigned p;

	for (n = numbers, p = picks;p > 0;n--, p--)
		result = result * n / p;
	return result;
}*/

//7.5 arrfun1.cpp-- functions with an array argument
/*#include<iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n); //prototype int sum_arr(int *arr,int n)
int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	//some system require preceding int with static to enable array initialization
	int sum = sum_arr(cookies, ArSize);
	cout << "Total cookies eaten: " << sum << "\n";
	return 0;
}
//return the sum of an integer array
int sum_arr(int arr[], int n)
{
	int total = 0;
	for (int i = 0;i < n;i++)
		total = total + arr[i];
	return total;
}*/

//7.6 arrfun2.cpp--functions with an array argument
/*#include<iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);
//use std :: instead of using directive
int main()
{
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	//some systems require preceding int with static to enable array initialization
	std::cout << cookies << " = array address, ";
	//some system require atype cast: unsigned(cookies)

	std::cout << sizeof cookies << " = sizeof cookies\n";
	int sum = sum_arr(cookies, ArSize);
	std::cout << "Total cookies eaten: " << sum << std::endl;
	sum = sum_arr(cookies, 3);      //a lie
	std::cout << "First three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, 4);  //another lie
	/*这是计算5，6，7，8个元素的总和，因为cookies+4是第5个元素的地址
	*/
	/*std::cout << "Last four eaters ate " << sum << " cookies.\n";
	return 0;
}*/
//return the sum of an integer array
/*int sum_arr(int arr[], int n)
{
	int total = 0;
	std::cout << arr << " = arr, ";
	//some systems require a type cast: unsigned(arr)

	std::cout << sizeof arr << " =sizeof arr\n";
	for (int i = 0;i < n;i++)
		total = total + arr[i];
	return total;
}*/
/*
假设要使用一个数组来记录房地产的价值，数组数目
两个基本操作，将值读入到数组中和显示数组内容
另一个操作是重新评估每种房地产的值，以相同的比率增加或减少
1.填充数组
程序可以管理多个人的投资，因此需要多个数组，因此不能在函数中设置数组长度，而要将数组长度作为第二个参数传递
另外用户也可能希望在数组被填满之前停止读取数据
由于用户输入的元素数目可能少于数组的长度，因此函数应返回实际输入的元素数目
int fill_array(double ar[], int limit);
该函数接受两个参数，一个数组名，一个要读取的最大元素数，该函数返回实际读取的元素数
如何提早结束循环，一种是使用一个特殊值来指出输入结束，比如负数
另外该函数应对错误输入作出反应，如停止输入
int fill_array(double ar[], int limit)
{
      using namespace std;
	  double temp;
	  int i;
	  for(i = 0; i < limit; i++)
	  {
	        cout<<"Enter value "<<(i+1)<<": ";
			cin>>temp;
			if(!cin)    //bad input
			{
			      cin.clear();
				  while(cin.get() != '\n')
				       continue;
				  cout<<"Bad input; input process terminated.\n";
				  break;
			}
			else if (temp < 0)   //signal to terminate
			      break;
		    ar[i] = temp;
	  }
	  return i;
}
2.显示数组及用const保护数组，将数组名和元素数目传递给函数，然后该函数
使用循环来显示每个元素，然而还有另一个问题确保显示函数不修改原始数组
为防止函数无意中修改数组的内容，可在声明形参时使用关键字const
void show_array(const double ar[], int n);
指针ar指向的是常量数据，这意味着不能使用ar修改该数据，也就是说，可以使用
像ar[0]这样的值，但不能修改
这不是意味着原始数组必须是常量，而只是意味着不能在show_array()函数中使用
ar来修改这些数据。ar指向的是一个常量值
void show_array(const double ar[], int n)
{
       using namespace std;
	   for(int i = 0; i<n; i++)
	   {
	        cout<<"Property "<< (i+1)<<" : $";
			cout<< ar[i]<< endl;
	   }
}
3.修改数组
在这个例子中，对数组进行的第三项操作是将每个元素与同一个重新评估因子相乘
需要给函数传递三个参数
void revalue(double r, double ar[], int n)
{
          for(int i = 0; i < n; i++)
		        ar[i] *= r;
}由于这个函数将修改数组值，因此声明ar时不能使用const
*/
//arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;
//function prototypes
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
	using namespace std;
	double properties[Max];

	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))   //bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input;Please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}

int fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin)   //bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)  //signal to terminate
			break;
		ar[i] = temp;
	}
	return i;
}
//the following function can use but not alter
//the array whose address is ar
void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0;i < n;i++)
	{
		cout << "Property #" << i + 1 << ": $";
		cout << ar[i] << endl;
	}
}
//multiplies each element of ar[] by r
void revalue(double r, double ar[], int n)
{
	for (int i = 0;i < n;i++)
		ar[i] *= r;
}
