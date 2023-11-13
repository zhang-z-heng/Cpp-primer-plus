/*打印两个数的积*/
/*#include <iostream>
int main()
{
	using namespace std;
	int v1, v2;
	cout << "Please enter one integer: " << endl;
	cin >> v1;
	cout << "Please enter another integer:" << endl;
	cin >> v2;
	cout << "Their multiple answer is "<< v1 * v2 << "." << endl;
	return 0;
}
*/
/*编写一个程序以浪为单位的距离，然后将他装换成码，一浪等于220码*/
/*#include <iostream>
int main()
{
	using namespace std;
	int lang;
	cout << "Please enter one integer : " << endl;
	cin >> lang;
	int ma = 220 * lang;
	cout << "It is equal " << ma << " inch." << endl;
	return 0;
}*/
/*#include <iostream>
int langtoma(int);
int main()
{
	using namespace std;
	int lang;
	cout << "Enter the distance in lang : ";
	cin >> lang;
	int ma = langtoma(lang);
	cout << lang << " lang = ";
	cout << ma << " ma. " << endl;
	return 0;
}
int langtoma(int a)
{
	return 220 * a;
}*/
/*编写一个程序，其main（）调用一个用户定义的函数，并显示如下结果*/
/*#include <iostream>
double CelsiustoFahrenheit(double);
void main()
{
	using namespace std;
	double Celsius;
	cout << "Please enter a Celsius value : "  ;
	cin >> Celsius;
	double fahrenheit = CelsiustoFahrenheit(Celsius);
	cout << Celsius << " degrees Celsius is " << fahrenheit << " degrees Fahreheit. " << endl;
	
}
double CelsiustoFahrenheit(double sts)
{
	return 1.8 * sts + 32.0;
}*/
/*编写程序，其main()调用一个用户定义的函数该程序按以下格式要求用户输入光年值并得到结果*/
/*#include <iostream>
float lightyeartoastronomical(float);
int main()
{
	using namespace std;
	float lightyear;
	cout << "Enter the number of light years: ";
	cin >> lightyear;
	float astronomical = lightyeartoastronomical(lightyear);
	cout << lightyear << " light years =" << astronomical << " astronomical units." << endl;
	return 0;
}
float lightyeartoastronomical(float a)
{
	return a * 63240;
}*/
//编写一个程序，要求用户输入小时数和分钟数，在main（）函数中，将两个值传递给一个void函数，后者以下面的格式显示这两个值
#include <iostream>
int main()
{
	using namespace std;
	int a, b;
	cout << "Enter the number of hours: ";
	cin >> a;
	cout << "Enter the number of minutes: ";
	cin >> b;
	cout << "Time: " << a << " : " << b << endl;
	return 0;
}