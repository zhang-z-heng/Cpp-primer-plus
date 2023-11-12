/*
指针，数组，和指针算术
指针变量加1后，增加的量等于它指向的类型的字节数

*/
//addpntrs.cpp -- pointer addition
/*#include<iostream>
int main()
{
	using namespace std;
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };

	//Here are two ways to get the address of an array
	double* pw = wages; // name of an array = address
	short* ps = &stacks[0]; // or use address operator

	//with array element
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
	pw = pw + 1;
	cout << "add 1 to the pw pointer;\n";
	cout << "pw = " << pw << " , *pw = " << *pw << "\n\n";
	cout << "ps = " << ps << ", *ps =" << *ps << endl;
	ps = ps + 1;
	cout << "add 1 to the ps pointer:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	cout << "access two elements with array notation\n";
	cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
	cout << "access two element with pointer notation\n";
	cout << "*stacks =" << *stacks << ", *(stacks +1) = " << *(stacks + 1) << endl;

	cout << sizeof(wages) << " = size of wages array\n";
	cout << sizeof(pw) << " = size of pw pointer\n";
	return 0;
}*/

/*
程序说明
c++将数组名解释为数组的第一个元素的地址
因此，pw声明为指向double类型的指针，然后将它初始化为wages，就是wages数组中第一个元素的地址
和所有数组一样，wages= &wages[0] = address of first element of array
接下来pw和*pw，前者是地址，后者是存储在该地址中的值
接着pw加1,这样数字地址将增加8，这使得pw的值为第二个元素的地址
*pw现在的值是20000即第二个元素的值
ps指向的是short类型，而short占用2个字节，因此指针加1时，其值增加2，结果是指针也只想数组中的下一个元素
stack【1】，编译器将该表达式看作*（stack + 1）这意味着先计算数组第2个元素的地址，然后找到存储在那里的值
从改程序的输出可知*（stacks + 1）和stacks[1]是等价的
arrayname[i] becomes *(arrayname + i)
所以，可以相同的方式使用指针名和数组名
对于他们，可以使用数组方括号表示法，也可以使用引用算数符*
在多数表达式中，他们都表示地址，区别之一是，可以修改指针的值，而数组名是常量
另一个区别是，对数组sizeof运算符得到的数组长度，对指针得到的是指针长度即使指针指向的是另一个数组
24 = size of wages array
4 = size of pw pointer

对指针解除引用
对指针解除引用意味着获得指针指向的值
cout<<*pn;//print the value of bubble
*pc = 's';//place s into memory location whose address is pc
pn[0]=*pn；对指针解除引用的方法是数组表示法


指针和字符串
char flower[10] = "rose";
cout<<flower<<"s are red`\n`";
数组名是一个元素的地址，因此cout语句中的flower是包含字符r的char元素的地址
cout对象认为char的地址是字符串的地址，因此它打印改地址处的字符，然后继续打印后面的字符
flower是一个char的地址
这意味着可以将指向char的指针变量作为cout的参数，因为它也是char的地址
用引号括起的字符串像数组名一样，也是第一个元素的地址
该程序发送了字符串的地址

*/

//ptrstr.cpp -- using pointers to strings
/*#include <iostream>
#include <cstring>
int main()
{
	using namespace std;
	char animal[20] = "bear";//animal holds bear
	const char *bird = "wren";//bird holds address of string
	char *ps;

	cout << animal << " and ";//dispaly bear
	cout << bird << "\n";//diplay wren
	//cout <<ps<<"\n";//may display garbage may cause a crash

	cout << "Enter a kind of animal: ";
	cin >> animal;
	//cin>>ps;Too horrible a blunder to try;ps doesnot point to allocated space

	ps = animal;//set ps to point to string
	cout << ps << "!\n";
	cout << "Before using strcpy():\n";
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;

	ps = new char[strlen(animal)+1 ];//get new storage
	strcpy( ps, animal);
	cout << "After using strcpy_s():\n";
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;
	delete[] ps;
	return 0;
}*/
/*
程序创建了一个char数组（animal）和两个指向char的指针变量（bird和ps）
该程序首先将animal数组初始化为字符串"bear"
然后程序将char指针初始化指向一个字符串：
wren实际表示的是字符串的地址，因此将这条语句wren的地址赋给了bird指针
这意味着可以像使用字符串“wren”那样使用指针bird
字符串字面值是常量，这就是为什么代码在声明中使用关键字const，以这种方式使用const意味着可以用bird来访问字符串，但不能修改它
指针ps未被初始化，因此不指向任何字符串

对于cout来说，数组animal和指针bird是一样的
对于cin，输入只要比较短，就能够被存储在数组中，则使用animal进行输入是安全的
然而bird来进行输入并不合适，字符串字面值视为只读常量，或者只使用字符串字面值的一个副本来表示程序所有的该字面值

如果程序中多次使用了字符串字面值wren,则编译器将存储该字符串多个副本，也只能存储一个副本
如果是后面的情况，则bird设置为指向一个wren将使它只是指向该字符串的唯一一个副本，将值读入一个字符串可能会影响被认为u是独立的位于其他地方的字符串
试图将信息读入ps指向的位置更糟，由于ps没有被初始化
使用足够大的char数组来接受输入即可，不要使用字符串常量或未被初始化的指针来接受输入

如果给cout提供一个指针，它将打印地址
如果指针类型是char*，则cout将显示指向的字符串
如果要显示的是字符串的地址，则必须将这种指针强制转换为另一种指针类型
如int*
因此ps显示为字符串fox，而（int*）ps显示为该字符串的地址
注意将animal赋给ps并不会复制字符串，而只是赋值地址，这样两个指针将指向相同的内存单元和字符串

要获得字符串的副本还需要其他的工作
首先需要分配内存来存储该字符串，这可以通过声明另一个数组或者使用new来完成
ps = new char[strlen(animal) +1];
字符串fox不能填满整个animal数组，因此这样做浪费了空间
strlen来确定字符串长度，并将它加一来获得包括空字符时该字符串的长度
随后，程序使用new来分配刚好足够存储该字符串的空间
接下来，需要将animal数组中的字符串复制到新分配的空间中
将animal赋给ps是不可行的，因为这样只能修改存储在ps中的地址从而失去程序访问新分配内存的唯一途径
需要使用strcpy函数，他能接受两个参数
第一个是目标地址，第二个是要复制的字符串的地址
应提前确定，分配了目标空间，并有足够的空间来存储副本
在这里我们用strlen()来确定所需空间，并使用new获得可用内存
new在离animal数组很远的地方找到了所需的内存空间
应使用strcpy或strncpy，而不是赋值运算符来将字符串赋给数组

char food[20] = "carrots"；
strcpy(food, "flan);
类似这样的代码会出现问题比如第一个数组food比字符串"........"小,这种情况
函数将字符串中剩余的部分复制到数组后面的内存字节中，可能会覆盖程序正在使用的其他内存
这时使用strcny（a,"BBBBBBBBBBBB",19）;
a[19] = '\0';
这样最多将19个字符复制到数组中，然后将最后一个元素设置为空字符


使用new创建动态结构
在程序运行时为结构分配所需空间，也可以使用new运算符来完成
将new用于结构，由两步组成：创建结构和访问其成员
inflatable *ps = new inflatable;
这将把足以存储inflatable结构的一块可用内存的地址赋给ps
访问成员：创建动态结构时，不能将成员运算符句点用于结构名，因为这种结构没有名称，只是知道它的地址
箭头成员运算符（->）可用于指向结构的指针
如果ps指向一个inflatable结构，则ps->price是被指向的结构的price成员
如果结构标识符是结构名，则使用句点运算符，如果标识符是指向结构的指针，则是用箭头运算符

另一种访问结构成员的方法是，如果ps是指向结构的指针，则*ps是被指向的值--结构本身
由于*ps是一个结构，因此（*ps）.price是该结构的price成员
*/
//newstruct.cpp -- using new with a structure
/*#include<iostream>
struct inflatable // structure definition
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable* ps = new inflatable;
	cout << "Enter name of inflatable item: ";
	cin.get(ps->name, 20);//method 1 for member access
	cout << "Enter volume in cubic feet: ";
	cin >> (*ps).volume;//method 2 for member access
	cout << "Enter price: $";
	cin >> ps->price;
	cout << "Name: " << (*ps).name << endl;//method 2
	cout << "Volume: " << ps->volume << " cubic feet\n";//method 1
	cout << "Price: " << ps->price << "\n";//method 1
	delete ps;
	return 0;
}*/
/*
getname（），这个函数返回一个指向输入字符串的指针
该函数将输入读入到一个大型的临时数组中，然后使用new[]创建一个刚好能够存储该输入字符串的内存块
并返回一个指向该内存块的指针，对于读取大量字符串的程序，这种方法可以节省大量内存

假设程序要读取100个字符串
其中最大的字符串包含79个字符，而其他的很短
如果用char数组来存储则需要1000个数组，每个数组80个字符总共80000个字节
如果用1000个指向char的指针，然后使用new根据每个字符串的需要分配相应数量的内存将节省几万个字节

*/

//delete.cpp -- using the delete operator
#include<iostream>
#include<cstring>
using namespace std;
char* getname(void);//function prototype
int main()
{
	char* name;
	name = getname();
	cout << name << " at " << (int*)name << "\n";
	delete[]name;

	name = getname();
	cout << name << " at " << (int*)name << "\n";
	delete[]name;
	return 0;
}

char* getname()
{
	char temp[80];
	cout << "Enter last name: ";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);

	return pn;
}
/*
函数getname（）
它使用cin将输入的单词放到temp数组中，然后使用new分配新内存，以存储该单词
程序需要strlen（temp）+1个字符来存储该字符串因此将这个值提供给new
获得空间后，getname()使用标准库函数strcpy()将temp中的字符串复制到新的内存块中
该函数并不检查内存块是否能够容纳字符串，但getname（）通过使用new请求合适的字节数来完成这样的工作
最后函数返回pn，这是字符串副本的地址

*/