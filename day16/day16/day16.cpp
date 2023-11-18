/*
分支语句和逻辑运算符
IF语句
if(test-condition)
    statement
*/

//if.cpp--using the if statement
/*#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int spaces = 0;
    int total = 0;
    cin.get(ch);
    while (ch != '.')
    {
        if (ch == ' ')
            ++spaces;
        ++total;
        cin.get(ch);
    }
    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";
    return 0;
}*/
/*
if else语句
if(test-condition)
    statement1
else
    statement2
如果测试条件为true或非零，则程序执行statement1,跳过statement2
如果测试条件为false或0，则程序跳过statement1执行statement2

*/
//ifelse.cpp--using the if else statement
/*#include<iostream>
int main()
{
    char ch;
    std::cout << "Type, and I shall repeat.\n";
    std::cin.get(ch);

    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;
        else
            std::cout << ++ch;
        std::cin.get(ch);
    }
    //try ch +1 instead of ++ch for interesting effect
    std::cout<<"\nPlease excuse the slight confusion.\n";
        //std::cin.get();
        //std::cin.get();
    return 0;
}*/

//ifelseif.cpp -- using if else if else
/*#include<iostream>
const int Fave = 27;
int main()
{
    using namespace std;
    int n;

    cout << "Enter a number in the range 1- 100 to find ";
    cout << "my favorite number: ";
    do
    {
        cin >> n;
        if (n < Fave)
            cout << "Too low -- guess again: ";
        else if (n > Fave)
            cout << "Too high -- guess again: ";
        else
            cout << Fave << " is right!\n";

    } while (n != Fave);
    return 0;
}*/

/*
逻辑表达式
OR(||),AND(&&),NOT(!)
||,&&的优先级比关系运算符低
！运算符将它后面的表达式的真值取反
*/
/*5==5 || 5==9  //true because first expression is true
5>3 ||5>10//true beacuse first enpression is true
5>8 ||5<10//true beacause second is true
5<8||5>2//true because both expressions are true
5>8||5<2//false because both expression are false
*/

// or.cpp -- using the logical OR operator
/*#include<iostream>
int main()
{
    using namespace std;
    cout << "This program may reformat your haed disk\n"
        "and destroy all your data.\n"
        "Do you wish to continue?<y/n>";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        cout << "You were warned!\a\a\n";
    else if (ch == 'n' || ch == 'N')
        cout << "A wise choice ... bye\n";
    else
        cout << "That wasn't a y or n! Apparently you "
        "can't follow\ninstructions, so "
        "I'll trash your disk anyway.\a\a\a\n";
    return 0;

}*/

/*5==5&&4==4//true because both expressions are true
5==3&&4==4//false because first expression is false
5>3&&5>10//false because second expression is false
5>8&&5<10//false because first expression is false
5<8&&5>2//true because both expressions are true
5>8&&5<2//false because both expressions are false*/

//and.cpp -- using the logical AND operator
/*#include<iostream>
const int ArSize = 6;
int main()
{
    using namespace std;
    float naaq[ArSize];
    cout << "Enter the NAAQs(New Age Awareness Quotients) "
        << "of\nyour neighbors. Program terminates "
        << "when you make\n"<<ArSize<<"entries"
        << "or enter a negative value.\n";

    int i = 0;
    float temp;
    cout << "First value: ";
    cin >> temp;
    while (i < ArSize && temp >= 0)//2 quitting criteria
    {
        naaq[i] = temp;
        ++i;
        if (i < ArSize)//room left in the array
        {
            cout << "Next value: ";
            cin >> temp;//so get next value
        }
    }
    if (i == 0)
        cout << "No data--bye\n";
    else
    {
        cout << "Enter your NAAQ: ";
        float you;
        cin >> you;
        int count = 0;
        for (int j = 0; j < i; j++)
            if (naaq[j] > you)
                ++count;
        cout << count;
        cout << " of your neighbors have grester awareness of\n"
            << "the New Age than you do.\n";
    }
    return 0;
}*/
/*
&&还允许建立一系列if else if else语句，其中每种选择都对应于一个特定的取值范围
char指针变量可以通过指向一个字符串的开始位置来标识该字符串一样
char指针数组也可以标识一系列字符串，只要将每一个字符串的地址赋给各个数组元素即可
在下面程序中，使用qualify数组来存储4个字符串地址
例如qualify[1]存储字符串“mud tug-of-war\n”的地址，然后，程序
便能够将cout,strlen()或strcmp()用于qualify[1]，就像用于其它字符串指针一样
使用const限定符可以避免无意间修改这些字符串
*/

//more_and.cpp -- using the logical AND operator
/*#include<iostream>
const char* qualify[4] =    //an array of pointers
{                           //to strings
    "10000 - meter race.\n",
    "mud tug-of-war.\n",
    "masters canoe jousting.\n",
    "pie-throwing festival.\n"
};
int main()
{
    using namespace std;
    int age;
    cout << "Enter your age in years: ";
    cin >> age;
    int index;

    if (age > 17 && age < 35)
        index = 0;
    else if (age >= 35 && age < 50)
        index = 1;
    else if (age >= 50 && age < 65)
        index = 2;
    else
        index = 3;

    cout << "You qualify for the " << qualify[index];
    return 0;
}*/

/*
！运算符用于函数返回值，可筛选可赋给int变量的数字输入
如果用户定义的函数is_int()的参数位于int类型的取值范围内，则将它返回true
然后程序使用while(!is-int(num))测试来拒绝不在该取值范围内的值
*/

//not.cpp --using the not operator
/*#include<iostream>
#include<climits>
bool is_int(double);
int main()
{
    using namespace std;
    double num;

    cout << "Yo, dude! Enter an integer value: ";
    cin >> num;
    while (!is_int(num))   //continue while num is not intable
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }
    int val = int(num);
    cout << "You've entered the integer " << val << "\nBye\n";
    return 0;
}

bool is_int(double x)
{
    if (x <= INT_MAX && x >= INT_MIN) //use climits value
        return true;
    else
        return false;
}*/
/*
逻辑符and优先级高于or，可以加括号提高优先级
字符函数库cctype
例如如果ch是一个字母，isalpha(ch)函数返回一个非零值，否则返回0
    如果ch是标点符号，ispunct(ch)将返回true
使用isalpha()来检查字符是否为字母字符
    isdigits()来测试字符是否为数字字符
    isspace（）来测试字符是否为空白，如换行符，空格和制表符
    ispunct()来测试字符是否为标点符号
    isalnum()来测试字符是否为字母或数字
    iscntrl()来测试字符是否为控制字符
    isgraph()来测试是除空格之外的打印字符
    islower（）小写字母
    isprint()打印字符包括空格
    isupper（）大写字母
    isxdigit()十六进制数字
    tolower()大写字符
    toupper()小写字符
*/

//cctypes.cpp -- using the ctype.h library
/*#include<iostream>
#include<cctype>
int main()
{
    using namespace std;
    cout << "Enter text for analysis, and type @"
        "to terminate input.\n";
    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);    //get first character
    while (ch != '@')
    {
        if (isalpha(ch))
            chars++;
        else if (isspace(ch))
            whitespace++;
        else if (ispunct(ch))
            punct++;
        else if (isdigit(ch))
            digits++;
        else
            others++;
        cin.get(ch);
    }

    cout << chars << " letters, "
        << whitespace << " whitespace, "
        << digits << " digits, "
        << punct << " punctuations, "
        << others << " others.\n";
    return 0;
}*/

/*
？：运算符，条件运算符
expression1?expression2:expression3
如果expression1为true,则整个条件表达式的值为expression2的值
否则整个表达式的值为expression3的值
5>3?10:12//5>3 is true, so expression value is 10
3 == 9?25:18//3 == 9 is false so expression value is 18

*/

//condit.cpp -- using the conditional operator
/*#include<iostream>
int main()
{
    using namespace std;
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "The larger of " << a << " and " << b;
    int c = a > b ? a : b; // c = a if a > b,else c = b
    cout << " is " << c << endl;
    return 0;
}*/
/*
switch语句
switch(integer-expression)
{
      case label1 : statement(s)
      case label2 : statement(s)
      ....
      default : statement(s)
}
*/

//switch.cpp -- using the switch statement
/*#include<iostream>
using namespace std;
void showmenu();
void report();
void comfort();
int main()
{
    showmenu();
    int choice;
    cin >> choice;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1 : cout << "\a\n";
                 break;
        case 2 : report();
                 break;
        case 3 : cout << " The boss was in all day.\n";
                 break;
        case 4 : comfort();
                 break;
        default: cout << " That is not a choice.\n";
        }
        showmenu();
        cin >> choice;
    }
    cout << "Bye!\n";
    return 0;
}

void showmenu()
{
    cout << "Please enter 1, 2, 3, 4, or 5:\n"
        "1) alarm              2) report\n"
        "3) alibi              4) comfort\n"
        "5) quit\n";
}
void report()
{
    cout << "It is been an excellent week for business.\n"
        "Sales are up 120%. Expenses are down 35%.\n";
}
void comfort()
{
    cout << "Your employees think you are the finest CEO\n"
        "in the industry. The board of directors think\n"
        "you are the finest CEO in the industry.\n";
}*/

/*
将枚举量用作标签，enum定义了一组相关的常量，然后在switch语句中使用这些常量
由于cin无法识别枚举类型，因此该程序要求用户选择选项时驶入一个整数
当switch语句将int值和枚举量标签进行比较时，将枚举量提升为int
另外在while循环测试条件中，也会将枚举量提升为int类型
*/

//enum.cpp -- using enum
/*#include<iostream>
//create named constants for 0 - 6
enum{red, orange, yellow, green, blue, violet, indigo};

int main()
{
    using namespace std;
    cout << "Enter color code(0 - 6): ";
    int code;
    cin >> code;
    while (code >= red && code <= indigo)
    {
        switch (code)
        {
        case red : cout<<"Her lips were red.\n";break;
        case orange: cout << "Her hair was orange.\n";break;
        case yellow: cout << "Her shoes were yellow.\n";break;
        case green: cout << "Her nails were green.\n";break;
        case blue: cout << "Her sweatsuit was blue.\n";break;
        case violet: cout << "Her eyes were violet.\n";break;
        case indigo: cout << "Her mood was indigo.\n";break;
        }
        cout << "Enter color code (0 - 6): ";
        cin >> code;
    }
    cout << "Bye\n";
    return 0;
}*/
/*
break和continue语句
break语句在switch语句或循环中使程序跳到switch或循环后面的语句处执行
continue语句用于循环中，让程序跳过循环体中余下的代码并开始新一轮的循环
下面程序，让用户输入一行文本，循环将回显每个字符
如果字符为句点，则使用break结束循环
这表明某种条件为true时，使用break来结束循环
接下来程序计算空格数，但不计算其他字符
当字符不为空格时，循环使用continue语句跳过计数部分
*/
//jump.cpp -- using continue and break
/*#include<iostream>
const int ArSize = 80;
int main()
{
    using namespace std;
    char line[ArSize];
    int spaces = 0;

    cout << "Enter a line of text:\n";
    cin.get(line, ArSize);
    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period:\n";
    for (int i = 0;line[i] != '\0';i++)
    {
        cout << line[i];//display character
        if (line[i] == '.') //quit if it is a period
            break;
        if (line[i] != ' ')//skip rest of loop
            continue;
        spaces++;
    }
    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";
    return 0;

}*/
/*
编写一个程序，计算平均每天捕获的鱼的重量，假设每天最多捕获5条鱼，因此一个包含
5个元素的数组将足以存储所有的数据，但也可能没有捕获这么多鱼
如果数组被填满或者输入了非数字输入，循环将结束
*/
//cinfish.cpp -- non-numeric input terminates loop
/*#include<iostream>
const int Max = 5;
int main()
{
    using namespace std;
    //get data
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
        << " fish<q to terminate>.\n";
    cout << "fish #1: ";
    int i = 0;
    while (i<Max && cin >> fish[i])
    {
        if (++i < Max)
            cout << "fish #" << i + 1 << ": ";
    }
    //calculate average
    double total = 0.0;
    for (int j = 0; j < i;j++)
        total += fish[j];
    //report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of "
        << i << " fish\n";
    cout << "Done.\n";
    return 0;
}*/
/*
输入q结束输入，可如下处理
if(!cin)     //input terminated by non-numeric response
{
     cin.clear();  //reset input
     cin.get();      //read q
}
cin.get();         //read end of line after last input
cin.get(),         //wait for user to press <enter>

cin>>fish[i]实际上是一个cin方法函数调用，该函数返回cin
如果cin位于测试条件中，则将被转换为bool类型
如果输入成功，则转换后的值为true，否则为false
如果表达式为false，则循环结束
如果逻辑AND表达式为false，则C++将不会判断右侧的表达式
对右侧的表达式进行判定意味着用cin将输入放到数组中
如果i等于MAX则循环将结束，而不会将一个值读入到数组后面的位置中
假设程序要求用户提供5个高尔夫得分，以计算平均成绩
如果用户输入非数字输入，程序拒绝，并要求用户继续输入数字
可以使用cin输入表达式的值来检测输入是不是数字，
程序发现用户输入了错误内容时，应采取3个步骤
1，重置cin以接受新的输入
2. 删除错误输入
3. 提示用户再输入
程序必须先重置cin，然后才能删除错误输入
*/

//cingolf.coo -- non numeric input skipped
/*#include<iostream>
const int Max = 5;
int main()
{
    using namespace std;
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for (i = 0;i < Max;i++)
    {
        cout << "Round #" << i + 1 << ": ";
        while (!(cin >> golf[i])) {
            cin.clear();   //rest input
            while (cin.get() != '\n')
                continue;  //get rid of bad input
            cout << "Please enter a number: ";
        }
    }
    //CALCULATE AVERAGE
    double total = 0.0;
    for (i = 0; i < Max;i++)
        total += golf[i];

    //report results
    cout << total / Max << " = average score "
        << Max << " rounds\n";
    return 0;        
}*/

/*
简单文件输入/输出
文本i/o和文本文件
ofstream outFile  //outFile an ofstream object
ofstream fout   //fout an ofstream object

outFile.open("fish.txt");  //outFile used to write to the fish.txt file
char filename[50];
cin>>filename;             //user specifies a name
fout.open(filename);       //fout used to trad specified file
||
double wt = 125.8;
outFile<<wt;    //write a number to fish.txt
char line[81] = "Objects are closer than they appear.";
fout<<line<<endl;   //write a line of text

*/
//outfile.cpp -- writing to a file
/*#include<iostream>
#include<fstream>       //forfile I/O

int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;                  //create object for output
    outFile.open("carinfo.txt");       //associate with a file

    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    //display information on screen with cout

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    //now do exact same things using outFile instear of cout
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close();  //done with file
    return 0;
}*/
/*
屏幕输出的是cout的结果，如果您查看该程序的可执行文件所在的目录
将看到一个名为carinfo.txt的新文件，其中包含使用outFile生成的输出

文件输出
ifstream inFile;           //inFile an ifstream object
ifstream fin;              //fin an ifstream object

inFile.open("bowling.txt");   //inFile used to read bowling.txt file
char filename[50];
cin>>filename;             //user specifies a name
fin.open(filename);             //fin used to read specified file

double wt;
inFile>>wt;               //read a number from bowling.txt
char line[81];       
fin.getline(line,81);        // read a line of text
*/

//sumafile.cpp -- functions with an array argument
#include<iostream>
#include<fstream>
#include<cstdlib>     // support for exit()
const int SIZE = 16;
int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;    //object for handling file input
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);     //associate inFile with a file
    if (!inFile.is_open())      //failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;    //number of items read

    inFile >> value;   //get first value
    while (inFile.good())   //while input good and not at EOF
    {
        ++count;
        sum += value;
        inFile >> value;
    }
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;

    }
    inFile.close();  //finished with the file
    return 0;

}
/*
读取文件时，有几点需要检查
程序读取文件时不应超过EOF，如果最后一次读取数据时遇到EOF，方法eof()将返回true
其次程序可能遇到类型不匹配的情况
最后出现文件受损或硬件故障
方法bad()将返回true
可以用good()方法，在没有发生任何错误时返回true
while(inFile.good()){
...}//while input good and not at EOF
也可以用
 if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
来确定循环终止的真正原因
eof()判断是否到达EOF
fail()用于检查类型匹配
方法good()指出最后一次读取输入的操作是否成功
即在执行读取输入操作后，立刻应用这种测试
因此一种标准方法是，在循环之前放置一条输入语句并在循环的末尾放置另一条输入语句
并在循环的末尾放置另一条输入语句
//standard file-reading loop design
inFile>>value；  //get first value
while(inFile.good())  //while input good and not at EOF
{
    //loop body goes here
    inFile>>value;  //get next value
}
以上两条输入语句用一条用作循环测试的输入语句代替
//abbreviated file-reading loop design
//omit pre-loop input

while(inFile >> value)
{
//loop body goes here
//omit end of loop input
}
*/
