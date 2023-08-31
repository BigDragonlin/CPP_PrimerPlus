//----------8.8编程练习
//    test();

//----------8.7复习题
//    review();

//------------8.5函数模板
//	templateFunc();

// -------------8.3默认参数
//defaultParam();

//------------8.2 引用变量
// firstRef();

//-------------------8.1C++内联函数
// inLineFunction();


//----------8.1 inline.cpp
inline void testInLineFunction(int* x )
{
    cout << "print x" << *x << endl;
    *x = 100;
}
void inLineFunction()
{
    //使用宏
#define USEMSCRO(x) x * x
    cout << "USEMSCRO(5) = " << USEMSCRO(5) << endl;

    //-------------------8.1C++内联函数
    int a = 10;
    testInLineFunction(&a);
    cout << "print a" << a << endl;
}


void file_it(ostream& os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); //保存原始格式
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f.1. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; ++i)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }
    os.setf(initial); //恢复原始格式
}

//------------8.2 firstRef
void firstRef()
{

    // ----------------8.26 对象、继承和引用
    ofstream font;
    const char* fn = "ep-data.txt";
    font.open(fn);
    if (!font.is_open())
    {
        cout << "Can't open " << fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Enter the focal length of your"
            "telescope objective in mm: ";
    double objective;
    cin >> objective;
    double eps[5];
    cout << "Enter the focal lengths, in mm, of 5 eyepieces:\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }
    file_it(font, objective, eps, 5);
    file_it(cout, objective, eps, 5);
    cout << "Done\n";


    //---------------8.2引用变量
    int rates1 = 100;
    int& rodents = rates1;
    cout << "rates1 is " << rates1 << endl;
    cout << "rodents is " << rodents << endl;
    cout << "rates1 address is " << &rates1 << endl;
    cout << "rodents address is " << &rodents << endl;
    int bunnies = 50;
    rodents = bunnies;
    cout << "rates1 is " << rates1 << endl;
    cout << "rodents is " << rodents << endl;
    cout << "rates1 address is " << &rates1 << endl;
    cout << "rodents address is " << &rodents << endl;
    cout << "bunnies address is " << &bunnies << endl;

    printf_s("---------------------\n");
    int rats2 = 101;
    int* pt = &rats2;
    printf("pt is %x\n", pt);
    int& rodents2 = *pt;
    printf("rodents2 is %d\n", rodents2);
    printf("&rodents2 address is %x\n", &rodents2);
    int bunnies2 = 50;
    pt = &bunnies2;
    printf_s("&bunnies2 address is %x\n", &bunnies2);
    printf("pt is %x\n", pt);

    printf_s("------------swaps---------\n");
    int wallet1 = 20;
    int wallet2 = 30;
    [](int& a, int& b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }(wallet1, wallet2);
    cout << "wallet1 is " << wallet1 << endl;
    cout << "wallet2 is " << wallet2 << endl;
    [](int* a, int* b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }(&wallet1, &wallet2);
    cout << "wallet1 is " << wallet1 << endl;
    cout << "wallet2 is " << wallet2 << endl;
    [](int a, int b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }(wallet1, wallet2);
    cout << "wallet1 is " << wallet1 << endl;
    cout << "wallet2 is " << wallet2 << endl;


    printf("----------------strref-----------------\n");
    struct free_throws
    {
        std::string name;
        int made;
        int attempts;
        float percent;
    };
    //initializations
    free_throws one = { "Ifelsa Branch",13,15 };
    free_throws two = { "Andor Knott",10,16 };
    free_throws three = { "Minnie Max",5,64 };
    free_throws four = { "Whily Looper",5,6 };
    free_throws five = { "Long Long",6,23 };
    free_throws team = { "Throwgoods",0,0 };
    free_throws dup;
    [](free_throws& initialization)
    {
        initialization.percent = float(initialization.made) / float(initialization.attempts);
    }(one);
    [](const free_throws& ft)
    {
        cout<<"Name:"<<ft.name<<endl;
        cout << "Made:" << ft.made << endl;
        cout << "Attempts" << ft.attempts << endl;
        cout << "Parents: " << ft.percent << endl;
    }(one);
    const free_throws* test = [](free_throws& ft)->const free_throws*
    {
        free_throws* pt = new  free_throws;
        *pt = ft;
        return pt;
    }(one);
    cout << "&one " << &one << endl;
    cout << "test " << test << endl;



    //----------8.1C++内联函数
    printf("----------8.1C++内联函数-----------");
    int rats = 10;
    int& ratsRef = rats;
    cout << "rats is " << rats << endl;
    cout << "rateRef is " << ratsRef << endl;
    ratsRef += 1;
    cout << "rats is " << rats << endl;
    cout << "rateRef is " << ratsRef << endl;
    cout << "rats address is " << &rats << endl;
    cout << "rateRef address is " << &ratsRef << endl;

}

char* userLeft(const char* str, int n = 1);

char* userLeft(const char* str, int n)
{
    if (n < 0) n = 0;
    char* p = new char[n + 1];
    int i = 0;
    for (int i = 0; i < n && str[i]; ++i)
        p[i] = str[i];
    while (i < n)
        p[i++] = '\0';
    return p;

}


// -------------8.3默认参数
void defaultParam()
{
    char sample[80];
    cout << "Enter a string:\n";
    cin.get(sample, 80);
    char* ps = userLeft(sample, 4);
    cout << ps << endl;
    delete[] ps;
    ps = userLeft(sample);
    cout << ps << endl;
    delete[] ps;
}


template<typename T>
void swapUser(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}


template<typename T>
void swapUserArray(T* a, T* b, int lim = 8);
template<typename T>
void swapUserArray(T* a, T* b, int lim)
{
    T temp;
    for (int i = 0; i < lim; ++i)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

struct job
{
    char name[40];
    double salary;
    int floor;
};

template<>
void swapUser<job>(job& a, job& b)
{
    job temp;
    temp = a;
    a = b;
    b = temp;
}

void swapUser(job& a, job& b)
{
    job temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    cout << "template A" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void ShowArray(T* arr[], int n)
{
    cout << "template B" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T lesser(T a, T b)
{
    cout << "T A" << "\t";
    return a < b ? a : b;
}

int lesser(int a, int b)
{
    cout << "T B" << "\t";
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

//---------------8.5函数模板
void templateFunc()
{

    // 8.15-----自己选择
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;
    cout << lesser(m, n) << endl;//T B
    cout << lesser(x, y) << endl;//T A
    cout << lesser<>(m, n) << endl; //T A
    cout << lesser<int>(x, y) << endl;  //T A


    // 8.14-----函数调用的优先级,编译器选择哪个模板
    int things[6] = { 13, 31, 103, 301, 310, 130 };
    struct debts
    {
        char name[50];
        double number;
    };
    struct debts mr_E[3] =
            {
                    {"Ima Wolfe", 2400.1},
                    {"Ure Foxe", 1300.0 },
                    {"Iby Stout", 1800.0}
            };
    double* pd[3];
    for (int i = 0; i < 3; ++i)
    {
        pd[i] = &mr_E[i].number;
    }
    cout << "Listing Mr.E's counts of things:\n";
    ShowArray(things, 6); //template A
    ShowArray(&things, 6); //template A
    ShowArray(pd, 3); //template B
    ShowArray(*pd, 3);//template A


    //-----8.13 显式具体化
    cout << cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    job sue = { "Susan Yaffee",73000.60,7 };
    job sidney = { "Sidney Taffee",78060.72,9 };
    cout << "Before job swapping:\n";
    cout << sue.name << ": $" << sue.salary << " on floor " << sue.floor << endl;
    cout << sidney.name << ": $" << sidney.salary << " on floor " << sidney.floor << endl;
    swapUser(sue, sidney);
    cout << "After job swapping:\n";
    cout << sue.name << ": $" << sue.salary << " on floor " << sue.floor << endl;
    cout << sidney.name << ": $" << sidney.salary << " on floor " << sidney.floor << endl;
    printf("---------------------------------------");

    //------8.12 重载的模板
    int a1 = 10;
    int b1 = 20;
    cout << "i , j =" << a1 << "," << b1 << endl;
    swapUser(a1, b1);
    cout << "Using compiler-generated int swapper:\n";
    cout << "Now i, j = " << a1 << ", " << b1 << endl;
    int c1[8] = { 0,7,0,4,1,7,7, 6 };
    int d1[8] = { 0,7,2,0,1,9,6,9 };
    cout << "Original arrays:\n";
    cout << c1[0] << c1[1] << "/";
    cout << c1[2] << c1[3] << c1[4] << c1[5] << c1[6] << c1[7] << endl;
    cout << d1[0] << d1[1] << "/";
    cout << d1[2] << d1[3] << d1[4] << d1[5] << d1[6] << d1[7] << endl;
    swapUserArray(c1, d1);
    cout << c1[0] << c1[1] << "/";
    cout << c1[2] << c1[3] << c1[4] << c1[5] << c1[6] << c1[7] << endl;
    cout << d1[0] << d1[1] << "/";
    cout << d1[2] << d1[3] << d1[4] << d1[5] << d1[6] << d1[7] << endl;

    //-------8.11 函数模板
    int a = 10;
    int b = 20;
    swapUser(a, b);
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
}

void review(){
//    1.哪种函数适合定义为内联函数？
//    答：函数体简单，调用频繁的函数

//    2.假设song()函数的原型如下：
//    void song(char* name, int times);
//    a.如何修改song()函数的原型，使得第二个参数的默认值为1？
//    答：void song(char* name, int times = 1);
//    b.函数的定义需要做哪些修改？
//    c.能否为name提供默认值”Billy”？
//    答：不能，因为默认参数只能从右往左提供。

//    3.编写iquote（）的重载版本一显示其用双引号括起的参数。编写3个版本：一个用于int参数，一个用于double参数，另一个用于string参数。
//    a. void iquote(int a);
//    b. void iquote(double a);
//    c. void iquote(string a);

//    4.下面是一个函数模板：
    struct box
    {
        char maker[40];
        float height;
        float width;
        float length;
        float volume;
    };
//    a.请编写一个函数，它将box结构的引用作为形参，并显示每个成员的值。
    box myBox = {"box", 10, 20, 30, 6000};
    [](box& box1)
    {
        cout << "maker is " << box1.maker << endl;
        cout << "height is " << box1.height << endl;
        cout << "width is " << box1.width << endl;
        cout << "length is " << box1.length << endl;
        cout << "volume is " << box1.volume << endl;
    }(myBox);
//    b.请编写一个函数，它将box结构的引用作为形参，并将volume成员设置为其他3边的乘积。
    [](box& box1)
    {
        box1.volume = box1.height * box1.width * box1.length;
    }(myBox);


//    5.为让函数fll()和show()使用引用参数，需要对程序清单7.15做哪些修改？


//    6.指出下面每个目标是否可以使用默认参数或函数重载完成，或者这两种方法都无法完成，并提供合
//    适的原型。
//    a.mass(density,volume)返回密度为density、体积为volume的物体的质量，而mass(denstity)返回密度
//    为density、体积为l.0立方米的物体的质量。这些值的类型都为double。
    // void mass(double density, double volume = 1.0);

//    b.repeat(l0,“i'm OK)将指定的字符串显示l0次，而repeate(But you're kind of stupid)将指定的字符
//    串显示5次。
//    void repeat(int times, const char* str); repeat(const char* str);

//    c.average(3,6)返回两个int参数的平均值(int类型)，而average(3.0,6.0)返回两个double值的平均值
//    (double类型)。
//        void average(int a, int b); void (double a, double b);

//    d.mangle("i'm glad to meet you'")根据是将值赋给char变量还是char*变量，分别返回字符I和指向字
//    符串“I'm mad to gleet you”的指针。
//    char mangle(char str); char* mangle(char* str);

//    7.编写返回两个参数中较大值的函数模板。
/*
template<typename T>
T Max(T a , T B)
    return a > B ? a : B;
*/

    /*   8.给定复习题6的模板和复习题4的box结构，提供一个模板具体化，它接受两个box参数，并返回
       体积较大的一个。*/
    [](box& box1, box& box2)
    {
        return box1.volume > box2.volume ? box1 : box2;
    }(myBox, myBox);

/*
 * 9.在下述代码（假定这些代码是一个完整程序的一部分）中，v1、v2、v3、v4和v5分别是哪种类型？
    int g(int x);
    ...
    float m = 5.5f;
    float& rm = m;
    decltype(m)v1 = m; //float
    decltype(rm)v2  = m; //float&
    decltype((m))v3 = m; //float&
    decltype (g(100))v4; //int
    decltype (2.0 * m)v5; //double

    */

}

template<class T>
void show(T& string, int times = 1) {
    for (int i = 0; i < times; ++i) {
        cout << string <<endl;
    }
}

template<class T>
T& max5(const T& a, const T& b, const T& c, const T& d, const T& e) {
    T max = a;
    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }
    if (max < d) {
        max = d;
    }
    if (max < e) {
        max = e;
    }
    cout << "max is " << max << endl;
}

template <class T>
T* MyMaxNumber(T* arr , int size){
    T& tempMax = arr[0];
    cout << "tempMax is " << tempMax << endl;
    cout << "tempMax address is " << &tempMax << endl;
    for (int i = 1; i < size; ++i) {
        if(arr[i] > tempMax){
            tempMax = arr[i];
        }
    }
    cout << "final tempMax is " << tempMax << endl;
    cout << "final tempMax address is " << &tempMax << endl;
    return &tempMax;
}

template <class T>
T sumArray(T arr[], int size){
    cout<<"template A"<<endl;
    T sum = 0;
    for (int i = 0; i < size; i++)
        sum ++;
    return sum;
}


template <class T>
int sumArray(T* arr[], int size){
    cout<<"template B"<<endl;
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum ++;
    return sum;
}



template <>
char* MyMaxNumber(char* charArr, int size){
    char& tempChar = charArr[0];
    for (int i = 1; i < size; ++i) {

    }
    return &tempChar;
}


void test(){

    /*
     * 1.编写通常接受一个参数（字符串的地址），并打印该字符串的函数。然而，如果提供了第二个参数
    (it类型)，且该参数不为0，则该函数打印字符串的次数将为该函数被调用的次数（注意，字符串的打印
    次数不等于第二个参数的值，而等于函数被调用的次数）。是的，这是一个非常可笑的函数，但它让您能够
    使用本章介绍的一些技术。在一个简单的程序中使用该函数，以演示该函数是如何工作的。
    */




/*
    2.CandyBar结构包含3个成员。第一个成员存储candy bar的品牌名称；第二个成员存储candy bar
    的重量（可能有小数）；第三个成员存储candy bar的热量（整数）。请编写一个程序，它使用一个这样的函
    数，即将CandyBar的引用、char指针、double和int作为参数，并用最后3个值设置相应的结构成员。最
    后3个参数的默认值分别为“Millennium Munch”、2.85和350。另外，该程序还包含一个以CandyBar的
    引用为参数，并显示结构内容的函数。请尽可能使用const。
*/
    struct CandyBar
    {
        char name[20];
        double weight;
        int hot;
    };
    CandyBar candyBar;
    auto setCandyBar = [](CandyBar& candyBar, const char* name = "Millennium Munch", const double weight = 2.85, const int hot = 350)
    {
        strcpy(candyBar.name, name);
        candyBar.weight = weight;
        candyBar.hot = hot;
    };
    setCandyBar(candyBar);
    auto showCandyBar = [](const CandyBar& candyBar)
    {
        cout << "name is " << candyBar.name << endl;
        cout << "weight is " << candyBar.weight << endl;
        cout << "hot is " << candyBar.hot << endl;
    };
    showCandyBar(candyBar);
    ::printf("-------------------\n");
    char name[20] = "test01";
    strcpy(candyBar.name, name);
    candyBar.weight = 3.00;
    candyBar.hot = 400;
    showCandyBar(candyBar);

    /*3.编写一个函数，它接受一个指向string对象的引用作为参数，并将该string对象的内容转换为大写，
    为此可使用表6.4描述的函数toupper（）。然后编写一个程序，它通过使用一个循环让您能够用不同的输入
    来测试这个函数，该程序的运行情况如下：

    Enter a string (g to quit):go away
    GO AWAY
    Next string (g to quit):good grief!
    GOOD GRIEF!
    Next string (g to quit):q
    Bye.
     */
    ::printf("Enter a string (g to quit):");
    auto toUpper = [](string& str)
    {
        for (char & singleChar : str)
        {
            singleChar = std::toupper(singleChar);
            if (singleChar == 'q')
            {
                return;
            }
        }
    };
    string str = "hello world";
    toUpper(str);
    cout << str << endl;
    ::printf("Next string (g to quit):");
    string str2 = "good grief!";
    toUpper(str2);
    cout << str2 << endl;
    ::printf("--------------------\n");

/*
#include <iostream>
using namespace std;
#include <cstring> //for strlen（）,strcpy（）

struct stringy{
    char str; //points to a string
    int ct; //length of string (not counting \0')
}；

//prototypes for set（）,show（）,and show（）go here
int main（）{
    stringy beany;
    char testing[] = "Reality isn't what it used to be."
    set(beany,testing);
    //first argument is a reference,
    //allocates space to hold copy of testing,
    //sets str member of beany to point to the
    //new block,copies testing to new block,
    //and sets ct member of beany

    show(beany);//prints member string once
    show(beany,2);//prints member string twice
    testing[0]='D';
    testing [1]'u';
    show(testing);//prints testing string once
    show(testing,3);//prints testing string thrice
    show("Done!")；
    return 0;
}
请提供其中描述的函数和原型，从而完成该程序。注意，应有两个show（）函数，每个都使用默认参数。
请尽可能使用consnt参数。set（）使用new分配足够的空间来存储指定的字符串。这里使用的技术与设计和
实现类时使用的相似。(可能还必须修改头文件的名称，删除using编译指令，这取决于所用的编译器。)
*/
    string beany;
    char testing[] = "Reality isn't what it used to be.";
    auto set = [](string& beany, const char* testing)
    {
        beany = testing;
    };
    set(beany,testing);
    //first argument is a reference,
    //allocates space to hold copy of testing,
    //sets str member of beany to point to the
    //new block,copies testing to new block,
    //and sets ct member of beany
    show(beany);//prints member string once
    ::printf("--------------------\n");
    show(beany,2);//prints member string twice
    testing[0] = 'D';
    testing[1] = 'u';
    ::printf("----------------------\n");
    show(testing);//prints testing string once
    ::printf("----------------------\n");
    show(testing,3);//prints testing string thrice
    show("Done!");
    ::printf("-----------------------\n");


    /*
     * 5.编写模板函数max5（）,它将一个包含5个T类型元素的数组作为参数，并返回数组中最大的元素
    (由于长度固定，因此可以在循环中使用硬编码，而不必通过参数来传递)。在一个程序中使用该函数，将
    T替换为一个包含5个it值的数组和一个包含5个dowble值的数组，以测试该函数。
    */
    auto number = max5(1,2,3,4,5);
    cout << number << endl;
    ::printf("-------------------------\n");

    /*
     * 6.编写模板函数maxn（）,它将由一个T类型元素组成的数组和一个表示数组元素数目的整数作为参
    数，并返回数组中最大的元素。在程序对它进行测试，该程序使用一个包含6个t元素的数组和一个包
    含4个double元素的数组来调用该函数。程序还包含一个具体化，它将char指针数组和数组中的指针数量
    作为参数，并返回最长的字符串的地址。如果有多个这样的字符串，则返回其中第一个字符串的地址。使
    用由5个字符串指针组成的数组来测试该具体化。
    */
    int arr[6] = {1,2,3,4,5,6};
    auto maxNumber = MyMaxNumber(arr, size(arr));
    for (int i = 0; i < 6; ++i) {
        cout << "arr"<< i <<"address is " << &arr[i] << endl;
    }
    cout << "maxNumer is " << *maxNumber << endl;
    cout << "maxNumer address is " << maxNumber << endl; // "maxNumer address is 0x61fe18


    /*
     * 7.修改程序清单8.14，使其使用两个名为SumArray()的模板函数来返回数组元素的总和，而不是显
    示数组的内容。程序应显示thing的总和以及所有debt的总和。
     */
    int things[6] = { 13, 31, 103, 301, 310, 130 };
    struct debts
    {
        char name[50];
        double number;
    };
    struct debts mr_E[3] =
            {
                    {"Ima Wolfe",2400.0},
                    {"Ura Foxe",1300.0},
                    {"Iby Stout",1800.0}
            };
    cout << "sum of things" << sumArray(things,sizeof(things) ) << endl;
    double *pd[3];
    for (int i = 0; i < 3; ++i) {
        pd[i] = &mr_E[i].number;
    }
    cout << "sum of mr_E" << sumArray(pd, sizeof(pd)) << endl;

}
