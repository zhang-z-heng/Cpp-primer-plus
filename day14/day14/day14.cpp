/*
循环和关系表达式
for 循环
*/
//forloop.cpp--introducing the for loop
/*#include<iostream>
int main()
{
	using namespace std;
	int i;
	for (i = 0; i < 5; i++)
		cout << "C++ knows loops.\n";
	cout << "C++ knows when to stop.\n";
	return 0;
}*/
/*
该循环将整数设置为0，loop initialization
loop test部分检查i小于5，loop update部分将i加1
由于新值小于5，因此循环打印另一行，之后再加1，直到循环将i更新为5为止
之后程序跳出循环

for循环组成部分
for(initialization; test-expression; update-expression)
    body
*/
//num_test.cpp -- use numeric test in for loop
/*#include <iostream>
int main()
{
	using namespace std;
	cout << "Enter the starting countdown value: ";
	int limit;
	cin >> limit;
	int i;
	for (i = limit; i; i--)
		cout << "i = " << i << "\n";
	cout << "Done now that i = " << i << "\n";
	return 0;
}*/
/*
C++常用的方式是，在for和括号之间加上一个空格，而省略函数名与括号之间的空格
*/
//express.cpp -- values of expressions
/*#include<iostream>
int main()
{
	using namespace std;
	int x;

	cout << "The expression x = 100 has the value ";
	cout << (x = 100) << endl;
	cout << "Now x = " << x << endl;
	cout << "The expression x < 3 has the value ";
	cout << (x < 3) << endl;
	cout << "The expression x > 3 has the value ";
	cout << (x > 3) << endl;
	cout.setf(ios_base::boolalpha);
	cout << "The expression x < 3 has the value ";
	cout << (x < 3) << endl;
	cout << "The expression x > 3 has the value ";
	cout << (x > 3) << endl;
	return 0;
}*/
/*
boolalpha来作为cout.setf()的参数
for（for-init-statement condition; expression）
     statement
这里只有一个分号是允许的，因为for-init-statement被视为一条语句，而语句有自己的分号

使用循环来计算并存储前16个阶乘 0！--16！
*/
//formore.cpp -- more looping with for
/*#include<iostream>
const int ArSize = 16;
int main()
{
	using namespace std;
	/*int i = 0, j, N;
	long long S;
	cout << "please enter one integer" << endl;
	cin >> N;
	cout << i << "! = " << 1 << endl;
	for (i = 1; i <= N;i++)
	{
		
		S = 1;
		for (j = 1;j <=i;j++){
			S = S * j;
			
		}
		cout << i << "! = " << S << endl;
		
		
	}*/

	/*long long factorials[ArSize];
	factorials[1] = factorials[0] = 1;
	for (int i = 2; i < ArSize;i++)
		factorials[i] = i * factorials[i - 1];
	for(int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;

	return 0;
}*/
//bigstep.cpp -- count as directed
/*#include<iostream>
int main()
{
	using std::cout;// a using declaration
	using std::cin;
	using std::endl;
	cout << "Enter an integer: ";
	int by;
	cin >> by;
	cout << "Counting by " << by << "s:\n";
	for (int i = 0; i < 100;i = i + by)
		cout << i << endl;
	return 0;
}*/

//forstr1.cpp -- using for with a string
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;
	cout << " Enter a name: ";
	string word;
	cin >> word;
	int i;
	for (i = word.size() - 1;i >= 0;i--)
		cout << word[i];
	cout << "\nBye.\n";
	return 0;
}*/
/*
++，--的区别
a++意味着使用a的当前值计算表达式，然后将a的值加1
++b的意思是先将b的值加1然后使用新的值来计算表达式
int x =5;int y =++x;    y=6,x=6
int z = 5;int y =z++;   y=5,z=6
将递增运算符用于指针时，将把指针的值增加其之乡的数据类型占用的字节数
也可以结合使用这些运算符
double x = *++pt;//increment pointer take the value arr[1] to arr[2]
++*pt;//increment the pointed to value change 23.4to 24.4
(*pt)++;//increment pointed to value;24.4+1=25.4,pt still point to arr[2]
x = *pt++;//dereference original location then increment pointer,25.4but to arr[3]

*/
//plus_one.cpp -- the increment operator
/*#include<iostream>
int main()
{
	using namespace std;
	int a = 20;
	int b = 20;
	cout << "a  =" << a << ":   b=" << b << endl;
	cout << "a++ =" << a++ << ": ++b= " << ++b << endl;
	cout << "a  =" << a << ":  b= " << b << endl;
	return 0;

}*/
/*
i = i+by;可以用i +=by;其合并了加法和赋值运算符
*/
//block.cpp -- use a block statement
/*#include<iostream>
int main()
{
	using namespace std;
	cout << "The Amazing Accounto will sum and average ";
	cout << "five numbers for you.\n";
	cout<<"Please enter five values:\n";
	double number;
	double sum = 0.0;
	for (int i = 1; i <= 5;i++)
	{//block starts here
		cout << "Value " << i << ": ";//loops ends here
		cin >> number;//after the loop
		sum += number;
	}//block ends here
	cout << "Five exquisite choices indeed! ";
	cout << "They sum to " << sum << endl;
	cout << "and average to " << sum / 5 << ".\n";
	cout << "The Amaziong Accounto bids you adieu!\n";
	return 0;
}*/

//forstr2.cpp -- reversing an array
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;
	cout << "Enter a word: ";
	string word;
	cin >> word;
	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i;--i, ++j)
	{
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	cout << word << "\nDone\n";
	return 0;
}*/

//equal.cpp--equality vs assignment
/*#include<iostream>
int main()
{
	using namespace std;
	int quizscores[10] = { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };

	cout << "Doing it rught:\n";
	int i;
	for (i = 0;quizscores[i] == 20;i++)
		cout << "quiz " << i << " is a 20\n";
	cout<<"Doing it dangerously wrong:\n";
	for (i = 0;quizscores[i] == 20;i++)
		cout << "quiz " << i << " is a 20\n";
	return 0;
}*/

/*
该程序显示一个单词，修改其首字母，然后再次显示这个单词，这样循环，
直到确定该单词与字符串mate相同为止
*/
//compstr1.cpp -- comparing string using arrays
/*#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	char word[5] = "?ate";
	for (char ch = 'a';strcmp(word, "mate");ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	cout << "After loop ends, word is " << word << endl;
	return 0;
}*/

//compstr2.cpp--comparing strings using arrays
#include<iostream>
#include<cstring>
#include<string>
int main()
{
	using namespace std;
	string word = "?ate";
	for (char ch = 'a'; word != "mate"; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	cout << "After loop ends, word is " << word << endl;
	return 0;
}