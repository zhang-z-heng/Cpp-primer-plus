/*
1.使用函数的3个步骤是什么
要使用C++函数，必须完成如下工作：提供函数定义、提供函数原型、调用函数。

2.请创建与下面的描述匹配的函数原型
a. void igor(void);
b. float tofu(int a);
c. double mpg(double a,double b);
d. long summation(long arr[i], int size);
e. double doctor(const char*str);
f. void ofcourse( boss BOSS);
g. char* plot(map *pmap);

3.编写一个接受3个参数的函数，int数组名，数组长度和一个int值，并将数组的
所有元素都设置为该int值
void inilization( int arr[], int size, int value)
{
    for (int i = 0; i< size; i++)
         arr[i] = value;
}

4.编写一个接受3个参数的函数，指向数组区间中的第一个元素的指针，指向数组
区间最后一个元素后面的指针，以及一个int值，并将数组中的每个元素都设置为该
int值
void range( int * begin, int * end +1,int value)
{
       int *pt;
       for (pt = begin; pt < = end; pt++)
            *pt = value;
 }

 5.编写将double数组名和数组长度作为参数，并返回该数组中最大值的函数，
 该函数不应修改数组的内容
 double array(const double arr[],const double size)
 {
        double Max;
        if(size < 1)
          std:: cout<<"invalid return";
        else
          {
             Max = arr[0];
             for ( int i = 1; i < size; i++)
                 {if (arr[i]> Max)
                      Max = arr[i]}
             return Max;
           }
          
 }

 double MaxArray(const double Arr[],int Size)
 {
           double Max;
           if(Size<1)
           {
                cout<<"Invalid array size of "<<Size<<endl;}
           else
           {
                Max=Arr[0];
                for(int i=1;i<Size;i++)
                      if(Arr[i]>Max)
                          Max=Arr[i];
                       return Max;}
 }

 6.为什么部队类型为基本类型的函数参数使用const限定符
 如果某个函数的参数为指针，则当指针指向原始数据的地址时，
 则就很有可能在函数体内故意或者非故意地“篡改”原始数据，
 因此将 const 限定符作用于指针时就可以防止这种“恶意”的篡改。
 但是对于基本数据类型而言，传递给函数的并不是原始数据本身，
 而是原始数据的“拷贝”，或者称之为副本，因此在这种按值传递的过程中，
 原始数据将得到保护。

 7.c++程序可以使用哪3种c-风格字符串格式？
 有指针形式，比如这样的定义 char* str; 
 也有数组形式，比如 char str[]; 
 还有字符串的字面值形式。
 这三种形式实际上都按照指针的方式进行操作。

 8.编写一个函数，其原型如下
 int replace(char * str, char c1, char c2);
 该函数将字符串种所有c1都替换为c2，并返回替换次数

 int replace(char * str, char c1, char c2)
 {
    int count = 0;
    while(*str )
    {
        if ( c1 = *str)
            {*str = c2;
            count ++;}
            str ++;
    }
    return count;
}
 
 9. 表达式*“pizza"的含义是什么？"taco"[2]呢？
 由于C++将“pizza”解释为其第一个元素的地址，
 因此使用 * 运算符将得到其第一个元素的值，即字符 p。
 同理，“taco”也将被解释为第一个元素的地址，
 因此“taco”[2]表示第二个元素的值，即字符c，
 也就是说字符串常量的行为与数组名相同。

 10.c++允许按值传递结构，也允许传递结构的地址，如果glitz是一个结构变量
 如何按值传递它？如何传递它的地址？这两种方法有何利弊？
 如果要按值传递结构 glitz，则只需要传递结构名 glitz即可。
 要传递它的地址的话就必须得使用取地址运算符 &glitz。
 按值传递仍然会像基本数据类型那样使用该结构体的副本，
 这将自动保护原始数据，
 但是当结构很大时，这种“拷贝”行为将会很耗时间和内存。
 当按地址传递时，虽然可以节省时间和内存，但是不能够保护原始数据，
 除非对函数参数使用 const 限定符。
 另外，按值传递意味着可以使用常规的结构成员表示法，
 但按指针传递则必须间接成员运算符。

 11.函数judge()的返回类型为int，它将这样一个函数的地址作为参数，将
 const char指针作为参数，并返回一个int值，请编写原型

 int judge(int(*pf)(const char*));

 12.假设有如下结构声明
 struct applicant{
      char name[30];
      int credit_ratings[3];
 };
 a.编写一个函数，它将application结构作为参数，并显示该结构的内容
 b.编写一个函数，它将application结构的地址作为参数，并显示该参数指向的结构的内容

 a) void display(applicant ap)
 {
      cout<<ap.name<<endl;
      for(int i=0;i<3;i++)
           cout<<ap.credit_ratings[i]<<endl;
  }
  
  b) void show(const applicant *pa)
  {
           cout<<pa->name<<endl;
           for(int i=0;i<3;i++)
                cout<<pa->credit_ratings[i]<<endl;
   }
 
 13. 假设函数f1和f2的原型如下
 void f1(applicant * a)；
 const char * f2(const applocant * a1, const applicant * a2);
 请将p1和p2分别声明为指向f1和f2的指针
 将ap声明为一个数组，它包含5个类型与p1相同的指针
 将pa声明为一个指针，它指向的数组包含10个类型与p2相同的指针
 使用 typedef来帮助完成这项工作
 typedef void (*p_f1)(applicant*);
 p_f1 p1 = f1;
 typedef const char *（*p_f2）(onst applocant * a1, const applicant * a2);
 p_f2 p2 = f2;
 p_f1 ap[5];
 p_f2 (*pa)[10];

// void *(*p1) (applicant *a) = f1;
// const char *(*p2)(const applicant *a1,const applocant * a2) = f2;


 */

/*
1.编写一个程序，不断要求用户输入两个数，直到其中的一个为0
对于每两个数，程序将使用一个函数来计算他们的调和平均数
并将结果返回给main()而后者将报告结果
调和平均数指的是倒数平均值的倒数 = 2.0 * x * y/(x+y)
*/
/*#include<iostream>
double average(double x, double y);


int main()
{
    using namespace std;
    double x, y;
    while (1)
    {
        cout << "Please enter two values(0 to quit): ";
        cin >> x >> y;
        if (x == 0 || y == 0)
        {
            cout << "start ending....";
            break;
        }
        else
        {
            double ave = average(x, y);
            cout << "The harmonic average is " << ave << endl;
        }
    }
    return 0;
}
double average(double x, double y)
{
    
    return 2.0 * x * y / (x + y);
}
*/
/*
编写一个程序，要求用户输入最多10个高尔夫成绩，
并将其存储在一个数组中，程序允许用户提早结束输入，并在一行上显示
所有成绩并报告平均成绩
请使用3个数组处理函数来分别进行输入，显示和计算平均成绩

*/
/*#include<iostream>
const int Max = 10;
int input(double ar[], int limit);
void show(const double ar[], int n);
double average(double ar[], int n);
using namespace std;

int main()
{
    double scores[Max];
    int size = input(scores, Max);
    show(scores, size);
    double ave;
    ave = average(scores, size);
    cout << "\nThe average score is " << ave << " ."<<endl;
    return 0;

}

int input(double ar[], int limit)
{
    int i;
    double score;
    cout << "Please enter your golf scores, 'q' to quit."<<endl;
    for (i = 0; i < limit; i++)
    {
        cout << "Please enter the scores #"<<(i+1)<<": ";
        cin >> score;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Input process terminated\nQuit\n";
            break;
        }
        ar[i] = score;
    }
    return i;
}

void show(const double ar[], int n)
{
    cout << "Your entered " << n << "scores.\n";
    cout << "The scores are :\n";
    for (int i = 0;i < n;i++)
        cout << ar[i]<<"\t";
}

double average(double ar[], int n)
{
    double ave;
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += ar[i];
    ave = sum / n;
    return ave;

}*/
/*
3.下面是一个结构声明，编写一个函数，按值传递box结构并显示每个成员的值
b.传递box结构的地址，并将volume成员设置为其他三维长度的乘积
c.编写一个使用这两个函数的简单程序
*/

/*#include<iostream>
using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void display(box temp);
float cal(box* temp);
int main()
{
    cout << "Please enter the box maker: ";
    box temp;
    cin >> temp.maker;
    cout << "Please enter the box height : ";
    cin >> temp.height;
    cout << "Please enter the box width: ";
    cin >> temp.width;
    cout << "Please enter the box length: ";
    cin >> temp.length;
    //cout << "Please enter the box volume: ";
    //cin >> temp.volume;
    display(temp);
    float vol;
    vol = cal(&temp);
    cout << "\nAfter the calculation the volume of the box is " << vol << endl;
    return 0;
}
void display(box temp)
{
    cout << "The maker of the box is " << temp.maker << " ." << endl;
    cout << "The height of the box is " << temp.height << " ." << endl;
    cout << "The width of the box is " << temp.width << " ." << endl;
    cout << "The length of the box is " << temp.length << " ." << endl;
    //cout << "The volume of the box is " << temp.volume << " ." << endl;
}

float cal(box* temp)
{
    float vol;
    vol = temp->height * temp->width * temp->length;
    return vol;
}*/

/*
4.许多洲的彩票发行机构使用如下玩法
玩家从一组被称为域号码的号码中选择几个
例如从1-47选择5个号码
1-27选择1个号码
要赢得头奖必须猜中所有号码，中头奖的几率是选中所有域号码的几率与选中
特选号码几率的成绩，请计算中得头奖的几率
*/
/*#include<iostream>
using namespace std;
double cal(int num1, int num2, int bingo1, int bingo2);
const int Num1 = 47;
const int Num2 = 27;
const int Bingo1 = 5;
const int Bingo2 = 1;
int main()
{
    cout << "Your probability to win the first prize in this game is\t";
    double pro;
    pro = cal(Num1, Num2, Bingo1, Bingo2);
    cout << pro << endl;
    return 0;
}
double cal(int num1, int num2, int bingo1, int bingo2)
{
    double probability1;
    double probability2;
    double pro;
    probability1 = double(bingo1) / double(num1);
    probability2 = double(bingo2) / double(num2);
    pro = probability1 * probability2;
    return pro;
}*/
/*
5.定义一个递归函数，接受一个整数参数，并返回该参数的阶乘 n(n-1)!
在程序中对该函数进行测试，程序使用循环让用户输入不同的值，程序将报告这些值的阶乘
*/
/*#include<iostream>
using namespace std;
long long recur(int i);
int main()
{
    
    int n;
    while (1)
    {
        cout << "Please enter one integer: ";
        cin >> n;
        if (!cin)
        {
            cout << "Input terminated.\nQuit\n";
            break;
        }
        else if (n < 0)
        {
            cout << "Bad input,please enter a positive number!" << endl;
            continue;
        }
        else if (n >= 0)
        {
            long long result = recur(n);
            cout << "The factorial of " << n << " is " << result << endl;
        }
    }
    return 0;
}
long long recur(int i)
{
    long long result;

    if (i == 0 || i == 1)
    {
        result = 1;
        //cout << result<<endl;
    }
    else
    {
        result = i * recur(i - 1);
        
    }
    return result;   
}*/
/*
6.编写一个程序，使用下列函数
Fill_array()将一个double数组的名称和长度作为参数
它提示用户输入double值，并将这些值存储在数组中
当数组被填满或用户输入非数字时，输入将停止，
并返回实际输入了多少个数字
Show_array（）将一个double数组的名称和长度作为参数并显示该数组内容
Reversr_array()将一个double数组的名称和长度作为参数并将存储在数组中的值的顺序反转
程序将使用这些函数来填充数组，显示数组，反转数组
然后显示数组，反转数组中除第一个和最后一个元素值为的所有元素，然后显示数组
*/
/*#include<iostream>
int Fill_array(double array[], int size);
void Show_array(double array[], int size);
void Reverse_array(double array[], int size);
using namespace std;
const int Max = 20;

int main()
{
    cout << "Please enter the data of array.'q' to quit.\n";

    double array[Max];
    int size;
    size = Fill_array(array, Max);
    Show_array(array, size);
    Reverse_array(array, size);
    cout << "\nAfter the reverse.";
    Show_array(array, size);
    Reverse_array(array, size);
    cout << "\nAfter the reverse.";
    Reverse_array(array + 1, size - 2);
    Show_array(array, size);
    cout << endl;
    system("pause");
    return 0;
        
}
int Fill_array(double array[], int size)
{
    int i;
    double j;
    int num;
    for (i = 0;i < size;i++)
    {
        cin >> j;
        if (!cin)
        {
            cout << "Input terminated.\nQuit\n";
            break;
        }
        else
        {
            array[i] = j;
        }
        num = i + 1;   
    }
    return num;
}

void Show_array(double array[], int size)
{
    int i;
    cout << "\nThe array is : \n";
    for (i = 0; i < size;i++)
        cout << array[i] << " ";
}

void Reverse_array(double array[], int size)
{
    int i;
    double temp;
    for (i = 0; i < size/2;i++)
    {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}*/

/*
7.修改7.7中的3个数组处理函数，使之使用两个指针参数来表示区间
fill_array（）函数不返回实际读取了多少个数字，而是返回一个指针
该指针指向最后被填充的位置，其他的函数可以将该指针作为第二个参数，以标识数据结尾
*/
/*#include<iostream>
const int Max = 5;
double* fill_array(double* ar, double* limit);
void show_array(const double* ar, double* n);
void revalue(double r, double* ar, double* n);
int main()
{
    using namespace std;
    double properties[Max];
    double* size = fill_array(properties, properties + Max);
    show_array(properties, size);
    cout << "Enter revaluation factor: ";
    double factor;
    cin >> factor;
    revalue(factor, properties, size);
    show_array(properties, size);
    cout << "Done.\n";
    system("pause");
    return 0;
}
double* fill_array(double* ar, double* limit)
{
    using namespace std;
    double temp;
    int i = 0;
    double* p;
    for (p = ar; p < limit;p++, i++)
    {
        cout << "Enter value#" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input;input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        *p = temp;
    }
    return p;
}
void show_array(const double* ar, double* n)
{
    using namespace std;
    int i = 0;
    for (const double* p = ar; p < n;p++, i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << *p << endl;
    }
}
void revalue(double r, double* ar, double* n)
{
    for (double* p = ar; p < n;p++)
        *p *= r;
}*/

/*
8.在不使用array类的情况下完成程序清单7.15的工作编写两个这样的版本
a.使用const char*数组存储表示极度名称的字符串，并用double数组存储开支
b.使用const char*数组存储表示季度名称的字符串，并使用一个结构包含一个成员
一个用于存储开支的double数组，这种设计与使用array类的基本设计类似
*/
/*#include<iostream>
const int Seasons = 4;
const char* Snames[Seasons] = { "Spring","Summer","Fall","Winter" };
void fill(double pa[]);
void show(double pa[]);
using namespace std;

int main()
{
    double expenses[Seasons];
    fill(expenses);
    show(expenses);
    system("pause");
    return 0;
}
void fill(double pa[])
{
    for (int i = 0;i < Seasons;i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa[i];
    }
}
void show(double pa[])
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0;i < Seasons;i++)
    {
        cout << Snames[i] << ": $" << pa[i] << endl;
        total += pa[i];
    }
    cout << "Total Expenses: $" << total << endl;
}*/

/*#include<iostream>
const int Seasons = 4;
struct ex
{
    double expenses[Seasons];
};
const char* Snames[Seasons] = { "Spring","Summer","Fall","Winter" };
void fill(ex * pa);
void show(ex* pa);
using namespace std;

int main()
{
    ex pa;
    fill(&pa);
    show(&pa);
    system("pause");
    return 0;
}
void fill(ex *pa)
{
    for (int i = 0;i < Seasons;i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa->expenses[i];
    }
}
void show(ex *pa)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0;i < Seasons;i++)
    {
        cout << Snames[i] << ": $" << pa->expenses[i] << endl;
        total += pa->expenses[i];
    }
    cout << "Total Expenses: $" << total << endl;
}*/

/*
9.下面是程序的框架，请提供其中描述的函数已完成该程序
*/
/*#include<iostream>
using namespace std;
const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
//get info() has two arguments: a pointer to rhe first element of an array
//of student structures and an int representing the number of elements of 
//the array.The function solicits and stores data about students,It terminates
//input upon filling the array or upon encountering a blank line for the
//student name.The function returns the actual number of array elements filled

int getinfo(student pa[], int n);

//display1()takes a student structure as an argument and displays its contents
void display1(student st);

//display2()takes the address of student structure as an argument and 
//displays the structure's contents
void display2(const student* ps);

//display3() takes the address of the first element of an array of student
//structures and the number of array elements as arguments and display
//the contents of the structures
void display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;

    student* ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0;i < entered;i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete[]ptr_stu;
    cout << "Done\n";
    return 0;
}

/*int getinfo(student pa[], int n)
{
    int count = 0;
    
    for (int i = 0; i < SLEN;i++)
    {
        cout << "Please enter student name["<<count+1<<"]: ";
        cin.getline( pa[i].fullname,SLEN);
        if (strlen(pa[i].fullname == 0))break;
        cout << "Please enter the hobby: ";
        cin >> pa[i].hobby;
        cout << "Please enter the ooplevel: ";
        cin >> pa[i].ooplevel;
        cin.get();
        count++;
    }
    cout << "Enter end!" << endl;
    return count;
}*/
/*int getinfo(student pa[], int n)
{
    int count = 0;
    for (int counter = 0; counter < n; counter++)
    {
        cout << "Enter the fullname of student[" << counter + 1 << "]: ";
        cin.getline(pa[counter].fullname, SLEN);
        if (strlen(pa[counter].fullname) == 0)break;
        else
        {
            cout << "Enter the hobby of student[" << counter + 1 << "]: ";
            cin.getline(pa[counter].hobby, SLEN);
            cout << "Enter the ooplevel of student[" << counter + 1 << "]: ";
        logo:cin >> pa[counter].ooplevel;
            if (!cin)
            {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "Please input the value of ooplevel again." << endl;
                goto logo;
            }
            count++;
            cin.get();
        }
    }
    return count;
    }
void display1(student st)
{
    cout << "\nDisplay1:\nFullname:" << st.fullname << "\nHobby: " << st.hobby << "\nOoplevel: " << st.ooplevel << endl;
}
void display2(const student* ps)
{
    cout << "\nDisplay2:\nFullname: " << *ps->fullname << "\nHobby: " << ps->hobby << "\nOoplevel: " << ps->ooplevel << endl;
}
void display3(const student pa[], int n)
{
    cout << "\nDisplay3: " << endl;
    for (int i = 0;i < n;i++)
        cout << i << ":\nFullname: " << pa[i].fullname << "\nHobby: " << pa[i].hobby << "\nOoplevel:" << pa[i].ooplevel << endl;

}*/
/*
10.设计一个名为calculate的函数，他接受两个double值，和一个指向函数的指针，
而被指向的函数接受两个double参数并返回一个double值
calculate函数的类型也是double并返回被指向的函数使用calculate的两个
double参数计算得到的值，例如，假设add（）函数的定义如下
double add(double x, double y)
{
    return x+y;
}
则下述代码中的函数调用将导致calculate把2.5和10.4传递给add函数并返回
add（）的返回值（12.9）
double q = calculate(2.5,10.4,add);
请编写一个程序，它调用上述两个函数和至少另一个与add（）类似的函数
该程序使用循环来让用户成对地输入数字
对于每对数字，程序都是用calculate()来调用add（）和至少一个其他的函数
如果读者爱冒险可以尝试创建一个指针数组
其中的指针指向add()样式的函数并编写一个循环，使用这些指针连续让calculate（）
调用这些函数
double(*pf[3])(double,double);
可以采用数组初始化语法，并将函数名作为地址来初始化这样的数组

*/
#include<iostream>
double add(double x, double y);
double sub(double x, double y);
double calculate(double x, double y, double (*pfun)(double x, double y));
using namespace std;

int main()
{
    while (1)
    {
        cout << "Please enter two numbers,'q' to quit: ";
        double x, y;
        double result;
        cin >> x >> y;
        if (!cin)
        {
            cout << "Input terminated.\n";
            break;
        }
        double q = calculate(x, y, add);
        double w = calculate(x, y, sub);
        cout << x << " add " << y << " equals to " << q << endl;
        cout << x << " minus " << y << " equals to" << w << endl;

    }
    system("pause");
    return 0;
}
double add(double x, double y)
{
    return x + y;
}
double sub(double x, double y)
{
    return x - y;
}
double calculate(double x, double y, double (*pfun)(double x, double y))
{
    double result;
    result = (*pfun)(x, y);
    return result;
}