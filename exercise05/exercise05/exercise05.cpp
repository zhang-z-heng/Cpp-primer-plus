/*
1.入口条件循环和出口条件循环之间的区别是什么
各种C++循环分别属于其中哪一种？

入口条件循环是指在进入循环体之前检测条件表达式是否满足条件，
如果条件为 false 则不执行循环，但继续执行循环体后面的语句；
出口条件循环是指先执行一次循环体再检测条件表达式是否满足条件，
如果满足则继续执行循环体，如果不满足则退出循环体继续执行循环体后面的语句。
在C++中，for 和 while 都属于入口条件循环，但 do while 是出口条件循环。


2.01234

3.0369
  12//换行为12不是9

4.将打印出 6 换行 8。
j 的初始值为 5，++j意味着先将 j 加 1，然后再测试，此时 6<9 满足条件，
因此进入循环体，cout<<j++<<endl; 意味着先打印 j，也就是打印出 6，
然后再把 j 的值加上 1，第二轮循环意味着 7+1<9，因此进入循环体打印出 8，
然后 8+1<9 不满足，退出循环体，因此输出为 6 换行 8。

5.将打印 k=8。因为是 do while 循环，所以先执行一次循环体，然后再检测。

6.编写一个打印1，2，4，8，16，32，64的for循环
每轮循环都将计数变量乘以2


#include<iostream>
int main()
{
	using namespace std;
	int i = 2;
	for (int j = 1;j < 65;j = j * i)
		
	     cout << "j = "<<j<<endl;
	return 0;
}

7.将语句用花括号括起来形成语句块
8.表达式 int x=(1,024)，这个表达式的右边由逗号运算符连接，
因此 x 的值将被赋予 024，
这是一个八进制形式，转换为十进制即为 20，
也就是说 x 的值是20。
而表达式 int y; y=1,024; 
的意思是先将常量 1 赋给 y，而整个表达式的结果为 024，
也就是 20，但结果并没有用而已

9.cin>>ch 将跳过空白字符，
比如换行符、空格以及制表符，而其它的两种形式都将读取这些字符。

1.编写一个要求用户输入两个integer的程序，该程序将计算并输出这两个整数之间的所有整数的和
这里假设先输入最小整数



#include<iostream>
int main()
{
	using namespace std;
	int Min_A, Max_B;
	int sum = 0;
	cout << "Please enter a minimum integer: ";
	cin >> Min_A;
	cout << "Please enter a maximum integer: ";
	cin >> Max_B;
	for (Min_A;Min_A <= Max_B;Min_A++)
		sum = sum + Min_A;
	cout << sum<<endl;
	
	return 0;
}
2.使用array对象和long double重新编写程序，并计算100！的值


*/
/*#include<iostream>
#include<array>
const int ArSize = 101;
int main()
{
	using namespace std;
	
	array<long double, ArSize>Ai;
	Ai[0] = Ai[1] = 1;
	for (int i = 2;i < ArSize;i++)
	{
		Ai[i] = Ai[i - 1] * i;
		//cout << Ai[10];
	}
	cout << Ai[100];
	//for (int i = 0; i < ArSize; i++)
	//	cout << i << "! = " << Ai[i] << endl;
	return 0;
}*/
/*
3.
编写一个要求用户输入数字的程序
每次输入后程序都将报告到目前为止所有输入的累积和
当用户输入0时，程序结束
*/
/*#include<iostream>
int main()
{
	using namespace std;
	int n;
	int sum = 0;
	cout << "Enter the numeber you want: ";
	do {
		cin >> n;
		cout << "The sum of your entered number is ";
		sum = sum + n;
		cout << sum << " \nNow you can enter next number: ";
		
	} while (n != 0);
	cout << "Encountered 0! The program is terminated! " << endl;
	cout << "The sum of all the inputed number = " << sum << endl;
	return 0;
}*/
/*#include<iostream> 
#include<stdlib.h>

using namespace std;

int main()
{
	int Input, Sum = 0;
	cout << "Enter a number firstly." << endl;
	cin >> Input;
	while (Input)
	{
		Sum += Input;
		cout << "The temporary sum = " << Sum << endl;
		cout << "Enter the next number:";
		cin >> Input;
	}
	cout << "Encountered 0! The program is terminated! " << endl;
	cout << "The sum of all the inputed number = " << Sum << endl;
	system("pause");
	return 0;
}*/
/*
4.Daphne以10%的单利投资了100美元
也就是说每一年的利润都是投资额的百分之10，即每年10美元 0.1*原始存款
而CLEO以5%的复利投资了100美元，利息是当前存款的5%  0.05*当前存款
Cleo在第一年投资100美元的盈利是得到了105美元，下一年是105的5%即5.25美元
编写一个程序，计算多少年后cleo投资价值才能超过daphne的投资价值
并显示此时两个人的投资价值
*/
/*#include<iostream>
int main()
{
	using namespace std;
	const int year = 100;
	int	i;
	double daphne = 100;
	double cleo[year] ;
	double sum_da = 100;
	//double sum_cl = 100;
	cleo[0] = 100;
	cleo[1] = 105;
	
	for (i = 0;sum_da + i * daphne * 0.1 >= cleo[i]; i++)
	{
		//sum_da = sum_da + i * daphne * 0.1;
		cleo[i+1] = cleo[i] * 0.05 + cleo[i];
        
	};
	cout << i<<endl;
	cout << sum_da + i * daphne * 0.1 << endl;
	cout << cleo[i];
	
	

	return 0;
}*/
/*#include<iostream>

int main()
{
	using namespace std;

	double money[2] = { 100,100 };
	int y;
	cout << "Daphne and Cleo both have $100 at first." << endl;
	for (y = 0;money[0] >= money[1];y++)
	{
		money[0] = 0.1 * 100 + money[0];
		money[1] = 0.05 * money[1] + money[1];
	}
	cout << y << endl;
	cout << money[1]<<endl;
	cout << money[0];
	return 0;
}*/
/*
5.假设要销售一本书，编写一个程序，输入全年中每个月的销售量（图书数量）
程序循环，使用初始化为月份字符串的char*数组逐月进行提示
并将输入数据存储在一个int数组中
然后程序计算数组中各元素的总数，并报告这一年的销售情况
*/

/*#include<iostream>
int main()
{
	using namespace std;
	int num_month[12];
    const char *month[12] = { "January","February","March",  //very important settting
		"April","May","June","July","August",
		"September","October","November","December" };
	int total = 0;
	for (int i = 0;i < 12;i++)
	{
		cout << "Please enter the number of selled book in " <<month[i]<<" : ";
		cin >> num_month[i];
		total = total + num_month[i];
	
	}
	cout << "This year we sold " << total << " books.";
	return 0;
}*/
/*
6.练习5使用一个二维数组来存储输入，3年终每个月的销售量，
程序将报告每年销售量以及三年的总销售量
*/
/*#include<iostream>
int main()
{
	using namespace std;
	const int Years = 3;
	const int Months = 12;
	int total = 0;
	int sum[3] = { 0,0,0 };
	const char* month[12] = { "January","February","March",  //very important settting
		"April","May","June","July","August",
		"September","October","November","December" };
	int books[Years][Months];
	for (int i = 0;i < 3;i++)
	{
		cout << "Now we insert the " << i + 1 << " year sold books :"<<endl;
		for (int j = 0;j < 12;j++) 
		{
			cout << "Please enter the number of selled book in " << month[j] << " : ";
			cin >> books[i][j];
		    sum[i] = sum[i] + books[i][j];
			
		}
	}
	cout << "The first year we sold " << sum[0] << " books.\n";
	cout << "The second year we sold " << sum[1] << " books.\n";
	cout << "The third year we sold " << sum[2] << " books.\n";
	cout << "We sold " << sum[0]+sum[1]+sum[2] << " books in  3 years." << endl;
	return 0;
}*/
/*
7.设计一个名为car的结构，用它存储下述有关汽车的信息
生产商
生产年份
编写一个程序，向用户询问有多少辆汽车
随后程序使用new来创建一个由相应数量的car结构组成的动态数组
接下来，程序提示用户输入每辆车的生产商和年份信息
注意它将交替读取数值和字符串
最后程序将显示每个结构的内容
*/
/*#include<iostream>
struct inflatable
{
	char industry[100];
	int year;
};
int main()
{
	using namespace std;

	int i;
	cout << "How many cars do you wish to catalog? ";
	cin >> i;//该语句最后一个cin输入会使缓冲区里多一个回车符，这是会出现在先使用cin>>而后使用getline()函数时发生的问题；
	//所以我们需要加一个cin.get()函数将缓冲区中多余的回车符消耗掉，之所以加在循环体内部，是因为循环体里面也有一个cin输入，所以每次执行getline()函数之前都需要消耗一个缓冲区中多余的回车符，因而加在循环体内部来循环消耗；之前说的在循环体外面加一个，在循环体里面的最后加一个，其实效果是一样的，只是第一次消耗是在循环之外消耗的，后来每次都是在循环内部消耗的，只是这样写比较规范，每次出现cin输入就赶紧在其后使用cin.get()来解决问题。
	
	inflatable *pcar = new inflatable[i];

	for (int j = 0;j < i;j++)
	{
		cout << "Car #" << j+1 << " : " << endl;
		cout << "Please enter the make : " ;
		//cin >> (*pcar).industry;
		cin.get();//这是因为如果只使用一个该语句，还不等你输入，程序会直接把后面的提示输入车辆生成年份的语句一并输出出来，
		//正常解决办法是在getline()函数前面加一个cin.get()函数，
		//或者在循环外面加一个cin.get()函数，并在循环体内部的最后面也加一个cin.get()函数，这两种写法都是完全正确的。
		cin.getline(pcar[j].industry, 40);
		//cin.getline(pcar[j].industry, 40);//不打两遍不让输入后面的东西为什么
		/*连写两句getline()函数，这是由于getline(cin, str)函数也是用于输入，
		当缓冲区中多余的回车符碰到这个函数时，
		会和碰到cin.get()函数一样，直接消耗掉，
		所以会接着执行下一个getline()函数，
		于是就正常完成了我们的任务。
		*/
		/*cout << "Please enter the year made: ";
		cin>>pcar[j].year;
		//cout << "\n";
		
	}
	cout << "Here is your collection: " << endl;
	for (int j = 0;j <= i;j++)
	{
		cout << pcar[j].year << " " << pcar[j].industry<<endl;
	}
	
}*/
/*
8.编写一个程序，它使用一个char数组和循环来每次读取一个单词，直到用户输入
done为止，随后，该程序指出用户输入了多少个单词，不包括done在内
您应在程序中包含头文件cstring，并使用函数strcmp（）来进行比较测试
*/
//#include<iostream>
//#include<cstring>
//#include<string>
/*int main()
{
	using namespace std;

	char str1[100];
	char str2[] = "done";
	int count = 0;
	cout << "Enter words(to stop,type the word done): \n";
	cin >> str1;
	//int i = 1;
	while( strcmp(str1,str2)!=0)
	{
	
		++count;
		cin >> str1;
		
	}
	cout << "You entered a total of " << count << " words\n";
	return 0;
}*/
/*using namespace std;

int main()
{
	const int MAX = 20;
	char Word[MAX];
	int Counter = 0;
	cout << "Enter words (to stop, type the word 'done')" << endl;
	cin >> Word;
	while (strcmp(Word, "done"))
	{
		//cout << "Enter the next words:";
		cin >> Word;
		++Counter;
	}
	cout << "You entered a total of " << Counter << " words." << endl;
	system("pause");
	return 0;
}*/

/*
9.编写一个满足前一个练习中描述的程序，但使用string对象而不是字符数组
请在程序中包含头文件string，并使用关系运算符来比较测试
*/

#include<iostream>
#include<cstring>
#include<string>
/*int main()
{
	using namespace std;

	string str1;
	string str2 = "done";
	int count = 0;
	cout << "Enter words(to stop,type the word done): \n";
	cin >> str1;
	//int i = 1;
	while( str1!=str2)
	{
		cin>>str1;
        count++;
	}
	cout << "You entered a total of " << count << " words\n";
	return 0;
}*/

/*
10.编写一个使用嵌套循环的程序，要求用户输入一个值
指出要显示多少行，然后程序将显示相应行数的星号
其中第一行包括一个星号，第二行包括两个星号
以此类推，每一行包含的字符数等于用户指定的行数，在星号不够的情况下
在星号前面加上句号
*/
#include<iostream>
int main()
{
	using namespace std;

	cout << "Enter number of rows : ";
	int i;
	cin >> i;
	for (unsigned int k = i-1;k >0;k--) 
	{
		for (int j = i-k;j < i;j++)
		{
			cout << ".";
		}
		for(int l = 0;l<i-k;l++)
		cout << "*";
		cout << endl;
	}
	return 0;
}