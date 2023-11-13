//要求用户使用一个整数指出自己的身高，然后将身高转换为英尺，该程序使用下划线字符来指示输入位置，另外使用一个CONST符号常量来表示转换因子
#include<iostream>
/*int main()
{
	using namespace std;
	int tall;
	cout << "Please enter your height(cm):___\b\b\b" ;
	cin >> tall;
	const int Cm_per_inch = 12;
	int feet = tall / Cm_per_inch;
	int inch = tall % Cm_per_inch;
	cout << "Your height in inch is " << feet << " feets, " << inch << " inches.\n";
	return 0;
}*/

/*
编写一个小程序，要求以几英尺几英寸的方式输入其身高，并以
磅为单位输入其体重，该程序报告其BMI，为了计算BMI该程序以英寸
的方式指出用户的身高，并将以英寸为单位的身高转换为米为单位的身高
1英寸等于0.0253米，然后以磅为单位转换为kg，1kg等于2.2磅
最后计算BMI，体重初一身高的平方，用符号常量表示各种转换因子
*/
/*#include<iostream>
int main()
{
	using namespace std;
	int feet, inch, pound;
	
	cout << "Enter your feet : __\b\b";
	cin >> feet;
	cout << "Enter your inch : __\b\b";
	cin >> inch;
	cout << "Your height is " << feet << " feets," << inch << " inches."<<endl;
	int feet_per_inch = 12* feet;
	float inch_per_meter = 0.0254 * (feet_per_inch+ inch);
	cout << "Your height is "<<inch_per_meter << " meter."<<endl;

	cout << "please enter your weight in pound : ___\b\b\b";
	cin >> pound;
	cout << "Your weight is " << pound << " pounds." << endl;
	float kilo = pound/2.2;
	cout << "Your weight is " << kilo << " kilo." << endl;

	float BMI = kilo / (inch_per_meter * inch_per_meter);
	cout << "Your BMI is " << BMI << "." << endl;

	return 0;
}*/

/*编写程序，用户以度分秒的方式输入一个维度，然后以度为单位显示该维度
1度为60分，1分为60秒，以符号常量表示这些值
*/

/*#include<iostream>
int main()
{
	using namespace std;
	int degree, minute, second;
	cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
	cout << "First enter the degrees: ";
	cin >> degree;
	cout << "Next,enter the minutes of arc: ";
	cin >> minute;
	cout << "Finally, enter the seconds of arcs: ";
	cin >> second;
	const int deg_per_minute = 60;
	const int min_per_second = 60;
	double Degree = degree + double(minute) / deg_per_minute + double(second) / (deg_per_minute * min_per_second);
	cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = "<<Degree<<"degrees"<<endl;
	system("pause");
	return 0;
}*/

/*
编写一个程序，要求用户以整数方式输入秒数（使用long变量存储），然后
以天，小时，分钟和秒来显示这段时间，使用符号常量来表示每天有多少小时
每小时有多少分钟以及没纷争有多少秒
*/
/*#include<iostream>
int main() 
{
	using namespace std;
	long second;
	cout << "Enter the number of seconds: _______\b\b\b\b\b\b\b";
	cin >> second;
	const int day_per_hour = 24;
	const int hour_per_minute = 60;
	const int minute_per_second = 60;
	int day = second / (day_per_hour * hour_per_minute * minute_per_second);
	int hour = (second % (day_per_hour * hour_per_minute * minute_per_second))/(hour_per_minute* minute_per_second);
	int minute = ((second % (day_per_hour * hour_per_minute * minute_per_second)) % (hour_per_minute * minute_per_second)) / minute_per_second;
	int Second = ((second % (day_per_hour * hour_per_minute * minute_per_second)) % (hour_per_minute * minute_per_second)) % minute_per_second;
	cout<<second<<" seconds = "<<day<<" days, "<<hour<<" hours, "<<minute<<" minutes,"<<Second<<" seconds.";
	return 0;
}*/

/*
编写一个程序，要求用户输入驱车历程（英里）和使用汽油量（加仑),然后指出汽车耗油量为1加仑的里程
如果愿意，也可以让程序要求用户以公里为单位输入距离并以升为单位输入汽油量
然后指出欧洲风格的结果即没100公里的耗油量
*/
#include<iostream>
int main()
/* {
	using namespace std;
	double distance;
	double gasoline;
	cout<<"Enter your distance in Mile: ";
	cin >> distance;
	cout << "Enter your gasoline used in Gallon: ";
	cin >> gasoline;
	double consume = distance / gasoline;
	cout << "Your car cosumation is " << consume << "." << endl;
	return 0;

}*/


/*
编写一个程序，要求用户按欧洲风格输入汽车的耗油量，每百公里消耗的汽油量
然后将其转换为美国风格的耗油量每加仑多少英里
美国方法（距离/燃料），欧洲风格（燃料/距离）
100公里等于62.14英里
1加仑等于3.875L
19mpg大约和12.4l/100km,127mpg大约合8.71/100km

*/
{
	using namespace std;
	double con_eu;
	cout << "Enter your consumation : ____\b\b\b\b";
	cin >> con_eu;
	
	const double mile_per_km = 62.14;
	const double gal_per_lt = 3.875;

	
	double con_usa = (1/con_eu) * mile_per_km * gal_per_lt;
	cout << "Your consumation in Gal/mile is " << con_usa << " mpg.";
	return 0;
}