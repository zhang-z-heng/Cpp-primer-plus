/*
结构简介
结构是用户定义的类型，而结构声明定义了这种类型的数据属性
定义了类型后，便可以创建这种类型的变量
首先，定义结构描述--它描述并标记了能够存储在结构中的各种数据类型，然后按描述创建结构变量
struct inflatable{
char name[20];
float volume;
double price;
}
关键字struct表明这些代码定义的是一个结构的布局
inflatable是这种数据格式的名称，这样便可以船舰char或int类型的变量
定义结构后，便可以创建这种类型的变量了
inflatable hat；
inflatable woopie;
C++允许在声明结构变量时省略关键字struct
由于hat类型为inflatable，因此可以使用.来访问各个成员，
hat.volume指的就是结构的volume成员
hat.price指的就是price成员
总之通过成员名能够访问结构的成员就像通过索引能够访问数组元素一样

*/
//structur.cpp -- a simple structure
/*#include<iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable guest =
	{
		"Glorious Glorua",
		1.88,
		29.99
	};
	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n";
	cout << "You can have both for $ ";
	cout << guest.price + pal.price << "!\n";
	return 0;
}*/
/*
结构声明，可以放在main函数中紧跟在开始括号的后面
或者将声明放在main函数的前面
C++使用户定义的类型与内置类型尽可能相似
另外还可以使用赋值运算符将结构赋给另一个同类型的结构
*/

//assgn_st.cpp -- assigning structures
/*#include<iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable bouquet =
	{
		"sunflowers",0.20,12.49
	};
	inflatable choice;
	cout << "Bouquet: " << bouquet.name << "for $";
	cout << bouquet.price << endl;

	choice = bouquet;
	cout << "choice : " << choice.name << " for $";
	cout << choice.price << endl;
	return 0;
}*/
/*
成员赋值是有效的，因为choice结构的成员值与bouquet结构中存储的值相同，可以同时完成定义结构和创建结构变量的工作
为此只需将变量名放在结束括号后面即可
stryct perks{
int key_number;
char car[12];}mr_smith,ms_jonue;
甚至可以初始化以这种方式创建的变量
struct perks{
int key_number;
char car[12];}mr_glitz ={
7,"packard"}然而，将结构定义和变量声明分开，可以是程序更易于阅读和理解

结构数组
inflatable结构包含一个数组，也可以创建元素为结构的数组，方法和创建基本类型数组完全相同
例如inflatable gift[100];即为一个包含100个inlatable结构的数组
gift的每个元素都是inflatable对象
cin>>gifts[0].volume;
cout<<gifts[99].price<<endl;
初始化结构数组
inflatable guests[2] ={
{"Bambi",0.5,21.99}
{"Godzilla", 2000, 565.99}}；
*/
//arrstruc.cpp -- an array of structures
/*#include<iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable guests[2] =
	{
		{"Bambi",0.5,21.99},
		{"Godzilla", 2000, 565.99}
	};

	cout << "The guests " << guests[0].name << " and " << guests[1].name << "\nhave a combined volume of "
		<< guests[0].volume + guests[1].volume << " cubic feet.\n";
	return 0;
}*/

/*
结构中的位字段
c++允许指定占用特定位数的结构成员，字段的类型应为整型或枚举
接下来是冒号，冒号后面是一个数字，指定了使用的位数，可以使用没有名称的字段来提供间距
struct torgle_register{
unsigned int SN : 4;//4 bits for SN value
unsigned int : 4;//4birs unused
bool goodIn : 1;//valid inpuy
bool goodTorgle : 1;//successful torgling};
*/
/*
共用体
是一种数据格式，它能够存储不同的数据类型，但只能同时存储其中的一种类型
union one4all
{
    int int_val;
	long long_val;
	double double_val;
};
可以使用one4all变量来存储int，long或double，条件是在不同的时间进行
one4all pail;
pail.int_val = 15;   //store an int
cout<<pail.int_val;
pail.double_val = 1.38 // store a double,int value is lost
cout<< pail.double_val;
因此pail有时可以是int变量，而有时可以是double变量，成员名称表示了变量的容量
由于共用体每次只能存储一个值，所以共用体的长度为其最大成员的长度
共用体的用途之一是，当数据项使用两种或更多种格式时可节省空间

枚举
enum工具提供了另一种创建符号常量的方式，这种方式可以代替const
它还允许定义新类型，enum的句法与使用结构相似
enum spectrum{red, orange, yellow, green,blue,violet,indigo,ultraviolet};
这条语句让spectrum成为新类型的名称
将red等作为符号常量，他们对应的整数值为0--7
枚举常被用来定义相关的符号常量而不是新类型
枚举的取值范围，首先要找出上限，需要知道枚举量的最大值，找到大于这个最大值的，最小的2的幂，将他减去1，得到的便是取值范围的上限
比如enum bigstep{first, second = 100, third};
third =101所以取2的幂中最小值为128，其上限为127
要找到下限，需要知道没巨量的最小值，如果不小于0 即为0，否则同样用取上限的方式再加上符号
比如-6，比它小的-8，下限为-7

*/