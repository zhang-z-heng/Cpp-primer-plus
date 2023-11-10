/*变量名的命名规则，在名称中只能使用字母字符，数字和下划线,名称的第一个字符不能是数字
* 区分大小写字符，不能将c++关键字用作名称，以两个下划线或下划线和大写字母打头的名称被保留给实现使用
* 以一个下划线开头的名称被保留给实现（编译器及其使用的资源）使用，用作全局标识符
* c++对于名称的长度没有限制，名称中所有的字符都有意义
* 
* 不同整型使用不同的内存量来存储整数
* short至少16位
* int至少与short一样长
* long至少32位，且至少与int一样长
*/
//limits.cpp -- some integer limits
#include<iostream>
#include<climits>
int main()
{
	using namespace std;
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	//sizeof operator yields size of type of variable
	cout << "int is " << sizeof(int) << " bytes." << endl;
	cout << "short is " << sizeof n_short << " bytes." << endl;
	cout << "long is " << sizeof n_long << " bytes." << endl;

	cout << "Maximum values: " << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;

	cout << "Minimum int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;
	return 0;
}