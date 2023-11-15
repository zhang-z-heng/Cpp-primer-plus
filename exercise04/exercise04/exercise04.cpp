//1编写一个程序，注意该程序应接受的名字包含多个单词，另外程序向下调整成绩
//即向上调一个字母，假设用户请求AB或c不必担心DF空挡
/*#include<iostream>
int main()
{
	using namespace std;
	char name1[20];
	char name2[20];
	char grade1;
	int age;

	cout << "What is your first name? ";
	cin.getline (name1,20);
	cout << "What is your last name? ";
	cin.getline(name2,20);
	cout << "What letter grade do you deserve? ";
	cin >> grade1;
	cout << "What is your age? ";
	cin >> age;
	grade1 = grade1 + 1;
	cout << "Name : " << name2<<" , "<<name1 << endl;
	cout << "Grade: " << grade1 << endl;
	cout << "Age: " << age << endl;

	return 0;	

}*/
//2.修改程序4.4使用c++string类而不是char数组
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;
	
	string name;
	string dessert;

	cout << "Enter your name :\n";
	getline(cin,name);
	cout << "Enter your favorite dessert :\n";
	getline(cin,dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you. " << name << ".\n";
	return 0;
}*/

//3.编写一个程序，要求用户首先输入其名，然后输入其姓，然后程序使用一个
//逗号和空格将姓和名组合起来，并显示结果，使用char数组和cstring中的函数
/*#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	char first_name[20];
	char last_name[20];
	cout << "Enter your first name: ";
	cin.get(first_name, 20).get();
	cout<<"Enter your last name: ";
	cin.get(last_name,20).get();
	cout << "Here's the information in a single string: ";
	strcat_s(last_name, " , ");
	strcat_s(last_name, first_name);
	cout << last_name << endl;
	return 0;
}*/

//4编写一个程序，使用string和头文件string中的函数
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;
	string first_name;
	string last_name;
	cout << "Enter your first name: ";
	getline(cin,first_name);
	cout << "Enter your last name: ";
	getline(cin,last_name);
	cout << "Here's the information in a single string: ";
	
	cout << last_name <<", "<<first_name<< endl;
	return 0;
}*/

//5.结构3各成员，品牌，重量有小数，整数卡路里
//编写一个程序，创建一个名为snak的CandyBar变量，初始化应在声明snack时碱性
//最后显示snack变量的内容
/*#include<iostream>

struct CandyBar {
	char brand[20];
	float weight;
	int calore;
};

int main()
{
	using namespace std;
	CandyBar snack =
	{
		"Mocha Munch",
		2.3,
		350
	};
	cout << "Brand: " << snack.brand<<endl;
	cout << "Weight: " << snack.weight<<endl;
	cout << "Calore: " << snack.calore<<"\n";
	return 0;
}*/

//6.创建一个包含3个元素的数组，并将它们初始化为选择的值
/*#include<iostream>

struct CandyBar {
	char brand[20];
	float weight;
	int calore;
};

int main()
{
	using namespace std;
	CandyBar snack1 =
	{
		"Mocha Munch",
		2.3,
		350
	};
	CandyBar snack2{ "Patatine",500.7,1800 };
	CandyBar snack3{ "Pistacchio",121.3,1500 };
	cout << "Brand_snack1: " << snack1.brand << endl;
	cout << "Weight_snack1: " << snack1.weight << endl;
	cout << "Calore_snack1: " << snack1.calore << "\n";
	cout << "Brand_snack2: " << snack2.brand << endl;
	cout << "Weight_snack2: " << snack2.weight << endl;
	cout << "Calore_snack2: " << snack2.calore << "\n";
	cout << "Brand_snack3: " << snack3.brand << endl;
	cout << "Weight_snack3: " << snack3.weight << endl;
	cout << "Calore_snack3: " << snack3.calore << "\n";
	return 0;
}*/

//7.William Wingate从事pizza分析他要记录如下信息
//pizza公司名称
//直径
//重量
//设计一个能够存储这些信息的结构，并编写一个使用这种结构变量的程序
//程序将请求用户输入上述信息然后显示这些信息cin和cout
/*#include <iostream>
struct William {
	char name[20];
	float diameter;
	double weight;
};
int main()
{
	using namespace std;
	William pizza;
	cout << "Enter the company name: ";
	cin.get(pizza.name, 20).get();
	cout << "Enter the pizza's diameter (cm): ";
	cin >> pizza.diameter;
	cout << "Enter the pizza's weight(g): ";
	cin >> pizza.weight;
	cout << "Company name: " << pizza.name << endl;
	cout << "Pizza diameter: " << pizza.diameter << " cm."<<endl;
	cout << "Pizza weight: " << pizza.weight <<" g."<< endl;
	return 0;
}*/

//8.使用new为结构分配内存，而不是声明一个结构变量
//另外让程序在请求输入比萨饼公司名称之前输入比萨饼直径
/*#include <iostream>
struct William {
	char name[20];
	float diameter;
	double weight;
};
int main()
{
	using namespace std;
	William *pizza = new William;
	
	cout << "Enter the pizza's diameter (cm): ";
	cin >> (*pizza).diameter;
	cout << "Enter the company name: ";
	cin.get(pizza->name, 20).get();
	cout << "Enter the pizza's weight(g): ";
	cin >> (*pizza).weight;
	cout << "Company name: " << pizza->name << endl;
	cout << "Pizza diameter: " << (*pizza).diameter << " cm." << endl;
	cout << "Pizza weight: " << (*pizza).weight << " g." << endl;
	delete pizza;
	return 0;
}*/

//9.练习6使用new来分配数组
/*#include<iostream>

struct CandyBar {
	char *brand;
	float weight;
	int calore;
};

int main()
{
	using namespace std;
	CandyBar* snack = new CandyBar[3];
	*snack ={"Mocha Munch",2.3,350};
	*(snack+1) ={ "Patatine",500.7,1800 };
	*(snack+2) ={ "Pistacchio",121.3,1500 };
	cout << "Brand_snack1: " << (*snack).brand << endl;
	cout << "Weight_snack1: " << snack[0].weight << endl;
	cout << "Calore_snack1: " << snack[0].calore << "\n";
	cout << "Brand_snack2: " << (snack+1)->brand << endl;
	cout << "Weight_snack2: " << (snack+1)->weight << endl;
	cout << "Calore_snack2: " << snack[1].calore << "\n";
	cout << "Brand_snack3: " << snack[2].brand << endl;
	cout << "Weight_snack3: " << snack[2].weight << endl;
	cout << "Calore_snack3: " << snack[2].calore << "\n";
	delete snack;
	return 0;
}*/


//10.编写一个程序，让用户输入三次40码跑的成绩，并显示次数和平均成绩，用array来储存数据
/*#include<iostream>
#include<array>
int main()
{
	using namespace std;
	array<int, 3>grade;
	cout << "Please enter your three times grades: " << endl;
	cout << "Your first grade is ";
	cin >> grade[0];
	cout << "Your second grade is ";
	cin >> grade[1];
	cout << "Your third grade is ";
	cin >> grade[2];
	cout << "Your everage grade is " << double(grade[0] + grade[1] + grade[2]) / 3 << endl;
	return 0;

}*/
#include<iostream> 
#include<stdlib.h>
#include<array>

using namespace std;

int main()
{
	auto* Pointer = new array<double, 3>;
	unsigned short Times = 0;
	cout << "Enter the score of 40m running:\n";
	cout << "First: ";
	cin >> Pointer->at(0);
	++Times;
	cout << "Second: ";
	cin >> Pointer->at(1);
	++Times;
	cout << "Third: ";
	cin >> Pointer->at(2);
	++Times;
	cout << "Times = " << Times << endl;
	cout << "Average = " << (Pointer->at(0) + Pointer->at(1) + Pointer->at(2)) / Times << endl;
	delete Pointer;
	system("pause");
	return 0;
}