/*
1.第二种比第一种要好在代码执行效率高上。
对于第一种情况而言，进入循环体之后，
判断完第一个 if 之后还要判断第二个 if，
并且不论 ch 是否为空格。但对于第二种情况而言，
一旦 ch 就是空格，则只判断一次 if，
而后面的 if else 语句将被省略掉。

2.就数值而言，两者是相同的，但 ++ch 输出的是字符，
但 ch+1 输出的将是数字，但仍然可以用 char (ch+1) 将其转换为字符。

3.注意 while 循环体内部的 if 判断语句使用的是赋值符号 ‘=’，
而不是相等判断符 ‘==’，
因此在第二次输出的时候所有的 ch 都将被替换为 ‘$’。
所以每循环一次相应的 ct1 和 ct2 的值都将等同地加 1，
因此最后的结果是 ct1 和 ct2 是完全一样的。

4.创建表示下述条件的逻辑表达式
a.weight>=115&&weight<125
b.ch == 'q'&&ch == 'Q'
c.x%2 == 0 && x !=26
d.x%2 == 0 && x%26 ！=0
e.(donation<=2000 &&donation>=1000)||guest == 1
f.(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')

5.如果 x 为 bool 值，则 !!x 与 x 是一样的。
但如果 x 为其它的不为 0 或 1 的值，则不一样。
比如 x=2，则 !x=0，则 !!x=1，显然不再等于 x。

6.创建一个条件表达式
x为正，x,x为负，表达式为-x
x>0?x:-x

7.switch(ch){
case'A':a_grade++;break;
case'B':b_grade++;break;
case'C':c_grade++;break;
case'D':d_grade++;break;
default:f_grade++;break;
}

8.如果使用整数标签，且用户输入了非整数（比如 q），
则程序将因为整数输入不能处理字符而挂起。
但是如果使用字符标签，而用户输入了整数（如 5），
则字符输入将 5 作为字符处理。
然而，switch 语句的 default 部分将提示输入另一个字符。

9.int line=0; 
  char ch; 
  while(cin.get(ch)&&ch!='Q')
  {
          if(ch='\n');
          line++
   }

   1.编写一个程序，读取键盘输入，直到遇到@符号为止，并回显输入
   同时将大写字符转换为小写，将小写字符转换为大写
*/
/*#include<iostream>
#include<cctype>
int main()
{
    using namespace std;
    cout << "Enter text for analysis, and type@ to terminate input.\n";
    char ch;
    cin.get(ch);
    while (ch != '@')
    {
        if (islower(ch))
        {
            ch = toupper(ch);
            cout << ch;
        }
        else if (isupper(ch))
        {
            ch = tolower(ch);
            cout << ch;
        }
        else if(isdigit(ch)==false)
        {
            cout << ch;
        }
        cin.get( ch);
    }
    cout << endl;

    return 0;
    
}*/

/*
2.编写一个程序，最多将10个donation值读入到一个double数组中，或者array模板
程序遇到非数字输入时将结束输入，并报告这些数字的平均值，以及
数组中有多少个数字大于平均值
*/

/*#include<iostream>
int main()
{
    using namespace std;
    double donation[10];
    int count = 0;
    double sum = 0.0;
    cout << "Please enter the value of donation after # "<<endl;
   // cin >> donation[0];
    cout << "Value #1: ";
    int i = 0;
    while (i<10 && cin >> donation[i])
    {
        cout << "Value #" << i + 2 << ": ";
        if (cin.fail())
        {
            cout << "Not a digital!\n";
            continue;
        }
        i++;
    }
    for (int j = 0;j < i;j++)
    {
        sum += donation[j];
    }
    cout <<"The average number of donation is " <<sum/i << endl;
    double ave = sum / i;
    for (i = 0;i < 10;i++)
    {
        if (donation[i]> ave)
            count++;
    }
    cout << "There are "<< count <<" number greater than average." <<endl;
    return 0;
}*/
/*
3.编写一个菜单驱动程序的雏形
该程序显示一个提供4个选项的菜单
每个选项用一个字母标记，如果用户使用有效选项之外的字母进行相应，程序将提示用户输入一个有效的字母
直到用户这样做为止
然后该程序使用一条switch语句根据用户的选择执行一个简单操作

*/

/*#include<iostream>
int main()
{
    using namespace std;
    cout << "Please enter one of the following choices;" << endl;
    cout << "c) carnivore          p) pianist"<<endl;
    cout << "t) tree               g) game" << endl;
    char ch;
    cin.get(ch);
    while (ch != ('c', 'p', 't', 'g'))
    {
         switch (ch)
         {
         case 'C':
         case 'c': cout << "A maple is a carnivore.\n";
                   break;
         case 'p':
         case 'P': cout << "A maple is a pianist.\n";
                   break;
         case 't':
         case 'T': cout << "A maple is a tree.\n";
                   break;
         case 'g': 
         case 'G': cout << "A maple is a game.\n";
                   break;
         default: cout << "Please enter a c, p, t, or g: ";
                 
         }
         cin.get();
         cin.get(ch);   
    }
}*/
/*
4.加入Benevolent Order of Programmer后，在BOP大会上，人们便可以
通过加入者的真实姓名，头衔或秘密BOP姓名来了解她
请编写一个程序，可以使用真实姓名，头衔，秘密姓名或成员偏好来列出成员
编写该程序时请使用下面的结构
//benevolent Order of Programmers name structure
struc bop{
     char fullname[strsize];// real name
     char title[strsize];//job title
     char bopname[strsize];//secret BOP name
     int preference;//0= full name,1= title,2 = bopname
     };
该程序创建一个由上述结构组成的小型数组，并将其初始化为适当的值
另外该程序使用一个循环，让用户在线面的选项中进行选择
注意display by preference 并不意味着成员的偏好，而是意味着根据成员的偏好列出
成员
例如如果编号为1，则选择d显示程序员的头衔
*/

/*#include<iostream>
int main()
{
    using namespace std;
    const int strsize = 30;
    struct bop{
     char fullname[strsize];// real name
     char title[strsize];//job title
     char bopname[strsize];//secret BOP name
     int preference;//0= full name,1= title,2 = bopname
    };
    cout << "Benevolent Order of Programmers Report" << endl;
    cout << "a. display by name       b. display be title" << endl;
    cout << "c. display by bopname    d. display by preference" << endl;
    cout << "q. quit" << endl;
    cout << "Enter your choice: ";
    char ch;
    //bop user1 = { "Wimp Macho","Junior Programmer",};
    cin >> ch;
    while (ch != 'q')
    {
        switch (ch)
        {
        case 'a': cout << "Wimp Machos\n" << "Raki Rhodes\n" << "Celia Laiter\n";
            cout << "Hoppy Hipman\n" << "Pat Hand\n";
            cout << "Next choice: ";
            break;
        case 'd':cout << "Wimp Macho\n" << "Junior Programmer\n";
            cout << "Next choice: ";
            break;
     
           
        }
        cin.get();
        cin.get(ch);
    }
    cout << "Bye!\n";
    return 0;
}*/

/*
在Neutronia王国，货币单位是tvarp，收入所得税的计算方式如下
5000不收税，5001-15000：10%，15001-35000：15%，35000以上：20%
例如38000时所得税为5000*0+10000*0.1+20000*0.15+3000*0.2
请编写一个程序，使用循环要求用户输入收入，并报告所得税
当用户输入负数或非数字时，循环将结束
*/
/*#include<iostream>
int main()
{
    using namespace std;
    int flag;
    double tax;
    double income;
    double a1 = 0.1;
    double a2 = 0.15;
    double a3 = 0.2;
    cout << "Please enter your income: ";
    while (cin >> income)
    {
        if (income >= 0)
        {
            if (income <= 5000)
                flag = 0;
            if (income >= 5001 && income <= 15000)
                flag = 1;
            if (income >= 15001 && income <= 35000)
                flag = 2;
            if (income >= 35001)
                flag = 3;
            switch (flag)
            {
            case 0: tax = 0;
                break;
            case 1: tax = (income - 5000) * a1;
                break;
            case 2: tax = (income - 15000) * a2 + 10000 * a1;
                break;
            case 3: tax = (income - 35000) * a3 + 20000 * a2 + 10000 * a1;
                break;
            }
            cout << "Your tax is : " << tax << endl;
            cout << "Please enter next income: ";
        }
        else if (income < 0)
        {
            cout << "Input fail.\nBye!\n";
            break;
        }
    }
    if (cin.fail())
        cout << "Input fail.\nBye!\n";

    return 0;
 }*/


/*
6.编写一个程序，记录捐助给维护合法权利团体的资金该程序要求用户输入捐献者数目，然后要求每个用户输入每一个捐献者的姓名和款项这些信息被储存在一个动态分配的结构数组中每个结构有两个成员，用来存储姓名的字符数组和用来存储款项的double成员读取所有数据后，
程序将显示所有捐款超过10000的捐款者的姓名及其捐款数额
该列表前应包含一个标题，指出下面的捐款者是重要捐款人
然后，程序将列出其他捐款者以Patrons开头
如果某种类别没有捐款者，则程序将打印单词none
该程序只显示两种类别，而不进行排序

*/
/*#include<iostream>
//#include<string>
struct donation {
    char name[50];
    double money;
};
int main()
{
    using namespace std;
    
    int number;
    
    cout << "Please enter the number of donation people : ";
    cin >> number;
    donation* pd = new donation[number];
    int i = 0;
    int bigger = 0;
    int smaller = 0;
    for (i = 0; i < number;i++)
    {
        cin.get();
        cout << "Please enter one patron name : ";
        cin>>pd[i].name;
        cout << " and his(her) donation: ";
        cin >>pd[i].money;
    }
    cout << "      Grand Patrons  " << endl;
    for (i = 0; i < number; i++)
    {
        if (pd[i].money >= 10000)
        {
            cout << pd[i].name;
            cout << "    " << pd[i].money << endl;
            bigger++;
        
        }   
    }
    if (bigger == 0)
        cout << "None "<<endl;
    cout << "         Patrons         " << endl;
    for (i = 0; i < number;i++)
    {
        if (pd[i].money < 10000)
        {
            cout << pd[i].name;
            cout << "     " << pd[i].money << endl;
            smaller++;
        }
    }
    if (smaller == 0)
            cout << "None "<<endl;
   /*
   if (bigger == number)
   cout<<"None"<<endl;
   

    return 0;
}*/

/*
7.编写一个程序，它每次读取一个单词直到用户只输入q
然后该程序指出有多少个单词原因大头，有多少个单词复印打头，还有多少个单词不属于这两类
为此，方法之一是使用isalpha来区分以字母和其它字符大头的单词
然后对于通过了测试的单词使用if或switch来确定哪些以原因打头
*/
/*#include<iostream>
#include<cctype>
#include<string>
int main()
{
    using namespace std;
    cout << "Enter words (q to quit) : " << endl;
    int type1 = 0;
    int type2 = 0;
    int type3 = 0;
    string input;
    cin >> input;
    while (input != "q")
    {
        if (isalpha(input[0]))
        {
            if (input[0] == 'a'|| input[0]== 'e' || input[0] == 'i' || input[0] == 'o' || input[0] == 'u')
                type1++;
            else
                type2++;
        }
        else
            type3++;
        cin >> input;
    }
    cout << type1 << " words beginning with vowels" << endl;
    cout << type2 << " words beginning with consonants" << endl;
    cout << type3 << " others" << endl;
}*/
/*
8.编写一个程序，它打开一个文件，逐个字符地读取该文件，直到到达文件末尾
然后指出该文件中包含多少个字符
*/
/*#include<iostream>
#include<fstream>
int main()
{
    using namespace std;
    char filename[60];
    ifstream inFile;
    cout << "Enter name of data file: ";
    cin.getline(filename, 60);
    inFile.open(filename);
    //double value;
    //double sum = 0.0;
    int count = 0;
    if (!inFile.is_open())
    {
        cout << "Could not open the file" << filename << endl;
        exit(EXIT_FAILURE);
    }
    char str;
    inFile >> str;
    while (inFile.good())
    {
        count++;
        inFile >> str;
    }
    if(inFile.eof())
        cout<<"End of file reached.\n";
    inFile.close();
    cout << "The total number of characters is " << count << endl;
    return 0;
}*/

/*
9.从文件中读取所需信息，改练习6
*/
#include<iostream>
#include<fstream>
#include<string>
struct donation {
    char name[50];
    double money;
};
int main()
{
    using namespace std;

    ifstream inFile;
    cout << "Please enter the name of your file:";
    char filename[30];
    cin.getline(filename, 30);
    inFile.open(filename);

    int number;  
    inFile >> number;
    char str[30];
    inFile.getline(str, 1);
    cout << "Please enter the number of donation people : ";
    cin >> number;
    donation* pd = new donation[number];
    int i = 0;
    int bigger = 0;
    int smaller = 0;
    for (i = 0; i < number;i++)
    {
        cin.get();
        cout << "Please enter one patron name : ";
        cin >> pd[i].name;
        cout << " and his(her) donation: ";
        cin >> pd[i].money;
    }
    cout << "      Grand Patrons  " << endl;
    for (i = 0; i < number; i++)
    {
        if (pd[i].money >= 10000)
        {
            cout << pd[i].name;
            cout << "    " << pd[i].money << endl;
            bigger++;

        }
    }
    if (bigger == 0)
        cout << "None " << endl;
    cout << "         Patrons         " << endl;
    for (i = 0; i < number;i++)
    {
        if (pd[i].money < 10000)
        {
            cout << pd[i].name;
            cout << "     " << pd[i].money << endl;
            smaller++;
        }
    }
    if (smaller == 0)
        cout << "None " << endl;
    /*
    if (bigger == number)
    cout<<"None"<<endl;


     return 0;
 }