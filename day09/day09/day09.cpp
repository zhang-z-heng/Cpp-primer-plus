/*
混合输入字符串和数字
*/
//numstr.cpp -- following number input with line input
/*#include<iostream>
int main()
{
	using namespace std;
	cout << "What year was your house built: \n";
	int year;
	cin >> year;
	cin.get();//(cin>>year).get();
	cout << "What is its street adress?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";
	return 0;
}*/
/*
这个程序让用户根本没有输入地址的机会
问题在于，当cin读取年份时，将会车键生成的换行符留在了输入队列中
后面的cin.getline()看到换行符后将认为是一个空行
并将一个空字符串给了address数组
解决办法是，在读取地址之前，先读取并丢弃换行符
即加入cin.get()
*/

/*
String类简介
string类位于名称空间std中，string类定义隐藏了字符串的数组性质，让
你能够像处理普通变量那样处理字符串

*/
//strtype1.cpp -- using c++ string class
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "Enter a kind of feline: ";
	cin>>charr1;
	cout << "Enter another kind of feline: ";
	cin >> str1;
	cout << "Here are some felines:\n";
	cout << charr1 << "" << charr2 << "" << str1 << "" << str2 << endl;
	cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
	cout << "The third letter in " << str2 << " is " << str2[2] << endl;
	return 0;

}*/
/*
string对象声明为简单变量，而不是数组，且能够自己处理string大小
可以用运算符+将两个string对象合并起来，还可以使用+=将字符串附加到string对象的末尾，继续前面的代码
转义序列\"表示双引号，而不是字符串结尾
*/
//strtype2.cpp--assigning adding,and appending
/*#include<iostream>
#include<string>
int main()
{
	using namespace std;
	string s1 = "penguin";
	string s2, s3;

	cout << "You can assign one string object to another: s2 = s1\n";
	s2 = s1;
	cout << "s1:" << s1 << ", s2: " << s2 << endl;
	cout<<"You can assign a C-style string to a string object.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;
	cout << "You can concatenate strings: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "You can append strings.\n";
	s1 += s2;
	cout << "s1 += s2 yields s1 = " << s1 << endl;
	s2 += " for a day";
	cout << "s2+=\" for a day\"yields s2 = " << s2 << endl;

	return 0;
}*/
/*
对用于string对象的技术和用于字符数组的技术进行了比较
例如可以使用strcpy()将字符串复制到字符数组中，使用函数strcat（）将字符串附加到字符数组末尾
strcpy_s(charr1,charr2);//copy charr2 to charr1
strcat_s(charr1,charr2);//append contents of charr2 to charr1

*/
//strtype3.cpp -- more string class features
/*#include<iostream>
#include<string>
#include<cstring>
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	//assignment for string objects and character arrays
	str1 = str2;
	strcpy_s(charr1, charr2);

	//appending for string objects and character arrays
	str1 += " paste"; // add paste to end of str1
	strcat_s(charr1, " juice"); // add juice to end of charr1

	//finding the length of a string object and a C-style string
	int len1 = str1.size();//obtain length of str1
	int len2 = strlen(charr1);//obtain length of charr1

	cout << "The string " << str1 << " contains " << len1 << " characters.\n";
	cout << "The string " << charr1 << " contains " << len2 << " characters.\n";

	return 0;
}*/
/*
string类i/o
每次读取一行而不是一个单词时，使用的句法不同

*/
//strtype4.cpp --line input
#include<iostream>
#include<string>
#include<cstring>
int main()
{
	using namespace std;
	char charr[20];
	string str;

	cout << "Length of string in charr before input: " << strlen(charr) << endl;
	cout << "Length of string in str before input: " << str.size() << endl;
	cout << "Enter a line of text:\n";
	cin.getline(charr, 20);
	cout << "You entered " << charr << endl;
	cout << "Enter another line fo text:\n";
	getline(cin, str);//cin now an argument; no length specifier
	cout << "You entered: " << str << endl;
	cout << "Length of string in charr after input: " << strlen(charr) << endl;
	cout << "Length of string in str after input: " << str.size() << endl;
	return 0;
}
/*
在用户输入之前，该程序指出数组charr中的字符串长度为27，比数组长度要打
首先，为初始化的数组的内容是未定义的
其次，函数strlen（）从数组的第一个元素开始计算字节数，知道遇到空字符
对于未被初始化的数据，第一个空字符的出现位置是随机的，因此运行该程序是，得到的数组长度很可能与此不同

另外用户输入之前，str的长度为零，因为未被初始化的string都为0

原始字符串将“”用作定界符，并使用前缀R来标识原始字符串
cout<<R"(Jim"king"Tutt uses"`n" instead of endl.)"<<'\n';
或
cout<< "Jim\"King\"Tutt uses \"\\n\"instead of endl."\\'`n';
上述代码中使用了\\来显示\，因为单个\表示转义序列的第一个字符
*/