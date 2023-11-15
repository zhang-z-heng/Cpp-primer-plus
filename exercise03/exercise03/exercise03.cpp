//复习题
//1.声明数组
/*char actor[30];
short betsie[100],
float chuck[13];
long double dipsea[64];*/
//2.使用模板类array而不是数组来完成
/*
array<char,30>actor;
array<short,100>betsie;
array<float, 13>chuck;
array<long double,64>dispea;
*/
//3.声明一个包含5个元素的int数组，并将它初始化为前5个正奇数
/*
int a[5] = {1,3,5,7,9};
*/
//4.编辑一条语句，将上述程序中第一个元素和最合一个元素的和赋给变量even
/*
int even = a[0] + a[4];
*/
//5.编辑一条语句显示float数组idears中的第2个元素的值
/*
float idears[3] ={1.2,3.3,5.4};
cout<<idears[1]<<endl;
*/
//6.声明一个char的数组，并将其初始化为字符串cheeseburger
/*
char food[]= "cheeseburger";
*/
//7.声明一个string对象，并将其初始化为字符串“Waldorf Salad”
/*
string food = "Waldorf Salad"
*/
//8.设计一个描述鱼的结构声明，结构中包括品种，重量整数，长度小数
/*
struct fish{
char kind[20],
int weight;
float length;
};
*/
//9.声明一个问题8中定义的结构的变量并将它进行初始化
/*
fish a ={"chicken",80,23.2};
*/
//10.用enum定义一个名为response的类型，它包含yes,no,和maybe等枚举量，yes为1，no为0，maybe为2
/*
enum response{ no ; yes ; maybe };
*/
//11.假设ted是一个double变量，请声明一个指向ted的指针，并使用该指针来显示ted的值
/*
double ted = 3.14;
double *pt = &ted;
cout<<*pt<<endl;

*/
//12.假设treacle是一个包含10个元素的float数组，请生命一个指向treacle的第一个元素的指针
//并使用该指针来显示数组的第一个元素和最后一个元素
/*#include<iostream>
int main() {

    using namespace std;
    float treacle[10] = { 1.0,2.0,3.0,4.0,5.0 };
    float* pt = treacle;
    cout << "The first element in treacle is " << pt[0]
        << " , the last one is " << pt[9] << endl;
    return 0;
}*/
//13.编写一段代码要求用户输入一个正整数
//然后创建一个动态的int数组，其中包含的元素数目等于用户输入的值，首先使用new然后用vector对象完成
/*#include<iostream>
#include<vector>
int main()
{
    using namespace std;
    
    unsigned int a;
    cout << "Enter one integer: ";
    cin >> a;
    int* p_a = new int[a];
    vector<int> vi(a);
    return 0;   
}*/

//14.下面的代码是否有效，如果有效，他将打印出什么结果
//cout<<(int *)"Home of the jolly bytes";
/*
代码有效，他将打印字符串的地址
*/

//15.编写一段代码，给问题8中描述的结构动态分配内存，在读取该结构的成员的值

/*#include<iostream>

struct fish
{
    char kind[20];
   int weight;
   float length;
};
int main()
{
    using namespace std;
    fish* ps = new fish;
    cout << "Enter the kind: ";
    cin.get(ps->kind, 20);
    cout << "Enter the weight: ";
    cin >> (*ps).weight;
    cout << "Enter the length: ";
    cin >> (*ps).length;
    cout << "Kind : " << (*ps).kind;
    cout << "Weight : " << ps->weight;
    cout << "Length : " << ps->length;
    delete ps;
    return 0;
}*/
/*
16.getline() 成员函数在读取指定数目的字符或遇到换行符时停止读取。
而 get() 函数是并不读取换行符，而是将其丢弃在输入队列中。
所以程序清单 4.6 的执行流程可以大致解释为：
当输入 year 的值并按下回车键后， year 的值被存储在 year 中，
但换行符被保留在了输入队列中，因此下面的 getline() 函数一眼便看到了换行符，
于是便以为读到了行尾，因此便把一个空字符赋值给了address。
所以使用 cin>>address 时，它可以使得程序跳过空白继续读取直到再次遇到空白字符位置。
因此它可以跳过数字输入后保留下来的换行符，可以避免这个问题。
但是又会引发另一个问题，也就是它只能读取一个单词，而不是一整行。
*/
//17.声明一个vector对象和一个array对象，他们都包含10个string对象
//指出所需的头文件，但不要使用using，使用const来指定要包含的对象数
/*
vector<string> vs(size);
array<string,size> as;
const int size = 10
*/

