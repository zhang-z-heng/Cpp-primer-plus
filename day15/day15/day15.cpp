/*
While循环
while(test-condition)
         body
test-condition为true则执行循环语句
执行完循环体，程序返回测试条件，对它进行重新评估
如果该条件为非0，则再次执行循环体

*/
//while.cpp--introducing the while loop
/*#include<iostream>
const int ArSize = 20;
int main()
{
    using namespace std;
    char name[ArSize];
    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";
    int i = 0; //start at beginning of string
    while (name[i] != '\0')//process to end of string
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;//dont forget this step
    }
    return 0;
}*/
/*
long wait = 0;
while (wait < 10000)
    wait++;
让计算机进行计数，以等待一段时间
clock（）函数，返回程序开始执行后所用的系统时间
如何使用clock()和头文件ctime来创建延迟循环
*/
//waiting.cpp -- using clock() in a time delay loop
/*#include<iostream>
#include<ctime>//describe clock() function,clock_t type
int main()
{
    using namespace std;
    cout << "Enter the delay time in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;//convert to clock ticks
    cout << "starting\a\n";
    clock_t start = clock();
    while (clock() - start < delay)   //wait until time elapses
    {
    }                             //note the semicolon
    cout << "done \a\n";
    return 0;
}*/

/*
do while循环，它是出口条件循环
循环将首先执行循环体，然后再判定测试表达式，决定是否循环
如果false则终止
do   
    body
while(test expression)
有时用do while会好点，比如程序先获得输入，然后对它进行测试
*/
//dowhile.cpp--exit-condition loop
/*
#include<iostream>
int main()
{
    using namespace std;
    int n;

    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favorite number\n";
    do
    {
        cin >> n;//execute bofy
        //cout << n << "is not my number.\n";
        //cout << "Please enter again: ";
    } while (n != 7);//then test
    cout << "Yes, 7 is my favorite.\n";
    return 0;
}*/
/*
循环和文本输入
停止读取文本输入需要一个特殊字符，叫做sentinel character将其作为停止标记
设计程序计算读取的字符数，并显示读取的字符
按下键盘上的键不能自动将字符显示到屏幕上
程序必须通过回显输入字符来完成这项工作
运行完毕后，报告处理的总字符数
*/

//textin1.cpp--reading chars with a while loop
/*#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;   //use basic input
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;         //get a character
    while (ch != '#')  //test the character
    {
        cout << ch;     //echo the character
        count++;       //count the character
        cin >> ch;    //get the next character
    }
    cout << endl << count << " characters read\n";
    return 0;
}*/
/*
上面程序在输出时忽略了空格和换行符，没有回显也没有计数
使用cin.get（ch）可以修补这个问题
*/
//textin2.cpp -- using cin.get(char)
/*#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;   //use basic input
    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);         //get a character
    while (ch != '#')  //test the character
    {
        cout << ch;     //echo the character
        count++;       //count the character
        cin.get(ch);    //get the next character
    }
    cout << endl << count << " characters read\n";
    return 0;
}*/
/*
在C语言中，要修改变量的值，必须将变量的地址传给函数
cin.get()传递的是ch而不是&ch
c++中，iostream将函数的参数声明为引用类型，因此该函数可以修改其参数的值
*/

//textin3.cpp -- reading chars to end of file
/*#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cin.get(ch); // attempt to read a char
    while (cin.fail() == false)//test for EOF// while (cin.get(ch))
    {
        cout << ch;//echo character
        ++count;
        cin.get(ch);//attempt to read another char
    }
    cout << endl << count << " characters read\n";
    return 0;
}*/
/*int ch;
ch = cin.get();//可以使用int ch并用cin.get()来代替cin.get(char)用cout.put()代替cout，用EOF代替cin.fail()测试
while (ch != EOF)//如果ch是一个字符则循环显示它，如果是EOF则循环结束
{
    cout.put(ch);
    ++count;
    ch = cin.get();
}*/
//textin4.cpp -- reading chars with cin.get()
/*#include<iostream>
int main(void)
{
    using namespace std;
    int ch;
    int count = 0;
    while ((ch = cin.get()) != EOF)//test for end of file
    {
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read\n";
    return 0;

}*/

/*
cin.get(ch)是赋给参数ch，用于字符输入时函数的返回值istream对象，执行bool转换后为true
到达EOF时函数返回值istream对象
ch =cin.get()将函数返回值赋给ch，int类型的字符编码，返回值是EOF

嵌套循环和二维数组
int maxtemp[4][5];这是生命一个包含4个元素的数组，其中每个元素都是由5
个整数组成的数组要打印数组所有内容需要for循环来改变行
另一个被嵌套的for循环来改变列
for(int row = 0;row<4;row++)
{
     for(int col =0;col<5；++col)
         cout<< maxtemps[row][col]<<"\t";
     cout<<endl;
}

将一个指针数组初始化为一组字符串常量，这使得每个元素都是一个char指针
可悲初始化为一个字符串的地址，该指针数组的行为与字符串数组类似
*/

//nested.cpp -- nested loops and 2-d array
#include<iostream>
const int Cities = 5;
const int Years = 4;
int main()
{
    using namespace std;
    const char* cities[Cities] = //char cities[Cities][25]// array of 5 arrays of 25 char
    {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };

    int maxtemp[Years][Cities] =
    {
        {96, 100, 87, 101, 105},
        {96, 98, 91, 107, 104},
        {97, 101, 93, 108, 107},
        {98, 103, 95, 109, 108}
    };

    cout << "Maximun temperatures for 2008 - 2011\n\n";
    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ": \t";
        for (int year = 0;year < Years;++year)
            cout << maxtemp[year][city] << "\t";
        cout << endl;
    }
    //cin.get();
    return 0;
}