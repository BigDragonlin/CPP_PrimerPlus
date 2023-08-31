//----------8.8�����ϰ
//    test();

//----------8.7��ϰ��
//    review();

//------------8.5����ģ��
//	templateFunc();

// -------------8.3Ĭ�ϲ���
//defaultParam();

//------------8.2 ���ñ���
// firstRef();

//-------------------8.1C++��������
// inLineFunction();


//----------8.1 inline.cpp
inline void testInLineFunction(int* x )
{
    cout << "print x" << *x << endl;
    *x = 100;
}
void inLineFunction()
{
    //ʹ�ú�
#define USEMSCRO(x) x * x
    cout << "USEMSCRO(5) = " << USEMSCRO(5) << endl;

    //-------------------8.1C++��������
    int a = 10;
    testInLineFunction(&a);
    cout << "print a" << a << endl;
}


void file_it(ostream& os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); //����ԭʼ��ʽ
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
    os.setf(initial); //�ָ�ԭʼ��ʽ
}

//------------8.2 firstRef
void firstRef()
{

    // ----------------8.26 ���󡢼̳к�����
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


    //---------------8.2���ñ���
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



    //----------8.1C++��������
    printf("----------8.1C++��������-----------");
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


// -------------8.3Ĭ�ϲ���
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

//---------------8.5����ģ��
void templateFunc()
{

    // 8.15-----�Լ�ѡ��
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;
    cout << lesser(m, n) << endl;//T B
    cout << lesser(x, y) << endl;//T A
    cout << lesser<>(m, n) << endl; //T A
    cout << lesser<int>(x, y) << endl;  //T A


    // 8.14-----�������õ����ȼ�,������ѡ���ĸ�ģ��
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


    //-----8.13 ��ʽ���廯
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

    //------8.12 ���ص�ģ��
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

    //-------8.11 ����ģ��
    int a = 10;
    int b = 20;
    swapUser(a, b);
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
}

void review(){
//    1.���ֺ����ʺ϶���Ϊ����������
//    �𣺺�����򵥣�����Ƶ���ĺ���

//    2.����song()������ԭ�����£�
//    void song(char* name, int times);
//    a.����޸�song()������ԭ�ͣ�ʹ�õڶ���������Ĭ��ֵΪ1��
//    ��void song(char* name, int times = 1);
//    b.�����Ķ�����Ҫ����Щ�޸ģ�
//    c.�ܷ�Ϊname�ṩĬ��ֵ��Billy����
//    �𣺲��ܣ���ΪĬ�ϲ���ֻ�ܴ��������ṩ��

//    3.��дiquote���������ذ汾һ��ʾ����˫��������Ĳ�������д3���汾��һ������int������һ������double��������һ������string������
//    a. void iquote(int a);
//    b. void iquote(double a);
//    c. void iquote(string a);

//    4.������һ������ģ�壺
    struct box
    {
        char maker[40];
        float height;
        float width;
        float length;
        float volume;
    };
//    a.���дһ������������box�ṹ��������Ϊ�βΣ�����ʾÿ����Ա��ֵ��
    box myBox = {"box", 10, 20, 30, 6000};
    [](box& box1)
    {
        cout << "maker is " << box1.maker << endl;
        cout << "height is " << box1.height << endl;
        cout << "width is " << box1.width << endl;
        cout << "length is " << box1.length << endl;
        cout << "volume is " << box1.volume << endl;
    }(myBox);
//    b.���дһ������������box�ṹ��������Ϊ�βΣ�����volume��Ա����Ϊ����3�ߵĳ˻���
    [](box& box1)
    {
        box1.volume = box1.height * box1.width * box1.length;
    }(myBox);


//    5.Ϊ�ú���fll()��show()ʹ�����ò�������Ҫ�Գ����嵥7.15����Щ�޸ģ�


//    6.ָ������ÿ��Ŀ���Ƿ����ʹ��Ĭ�ϲ�������������ɣ����������ַ������޷���ɣ����ṩ��
//    �ʵ�ԭ�͡�
//    a.mass(density,volume)�����ܶ�Ϊdensity�����Ϊvolume���������������mass(denstity)�����ܶ�
//    Ϊdensity�����Ϊl.0�����׵��������������Щֵ�����Ͷ�Ϊdouble��
    // void mass(double density, double volume = 1.0);

//    b.repeat(l0,��i'm OK)��ָ�����ַ�����ʾl0�Σ���repeate(But you're kind of stupid)��ָ�����ַ�
//    ����ʾ5�Ρ�
//    void repeat(int times, const char* str); repeat(const char* str);

//    c.average(3,6)��������int������ƽ��ֵ(int����)����average(3.0,6.0)��������doubleֵ��ƽ��ֵ
//    (double����)��
//        void average(int a, int b); void (double a, double b);

//    d.mangle("i'm glad to meet you'")�����ǽ�ֵ����char��������char*�������ֱ𷵻��ַ�I��ָ����
//    ������I'm mad to gleet you����ָ�롣
//    char mangle(char str); char* mangle(char* str);

//    7.��д�������������нϴ�ֵ�ĺ���ģ�塣
/*
template<typename T>
T Max(T a , T B)
    return a > B ? a : B;
*/

    /*   8.������ϰ��6��ģ��͸�ϰ��4��box�ṹ���ṩһ��ģ����廯������������box������������
       ����ϴ��һ����*/
    [](box& box1, box& box2)
    {
        return box1.volume > box2.volume ? box1 : box2;
    }(myBox, myBox);

/*
 * 9.���������루�ٶ���Щ������һ�����������һ���֣��У�v1��v2��v3��v4��v5�ֱ����������ͣ�
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
     * 1.��дͨ������һ���������ַ����ĵ�ַ��������ӡ���ַ����ĺ�����Ȼ��������ṩ�˵ڶ�������
    (it����)���Ҹò�����Ϊ0����ú�����ӡ�ַ����Ĵ�����Ϊ�ú��������õĴ�����ע�⣬�ַ����Ĵ�ӡ
    ���������ڵڶ���������ֵ�������ں��������õĴ��������ǵģ�����һ���ǳ���Ц�ĺ��������������ܹ�
    ʹ�ñ��½��ܵ�һЩ��������һ���򵥵ĳ�����ʹ�øú���������ʾ�ú�������ι����ġ�
    */




/*
    2.CandyBar�ṹ����3����Ա����һ����Ա�洢candy bar��Ʒ�����ƣ��ڶ�����Ա�洢candy bar
    ��������������С��������������Ա�洢candy bar�������������������дһ��������ʹ��һ�������ĺ�
    ��������CandyBar�����á�charָ�롢double��int��Ϊ�������������3��ֵ������Ӧ�Ľṹ��Ա����
    ��3��������Ĭ��ֵ�ֱ�Ϊ��Millennium Munch����2.85��350�����⣬�ó��򻹰���һ����CandyBar��
    ����Ϊ����������ʾ�ṹ���ݵĺ������뾡����ʹ��const��
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

    /*3.��дһ��������������һ��ָ��string�����������Ϊ������������string���������ת��Ϊ��д��
    Ϊ�˿�ʹ�ñ�6.4�����ĺ���toupper������Ȼ���дһ��������ͨ��ʹ��һ��ѭ�������ܹ��ò�ͬ������
    ����������������ó��������������£�

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
#include <cstring> //for strlen����,strcpy����

struct stringy{
    char str; //points to a string
    int ct; //length of string (not counting \0')
}��

//prototypes for set����,show����,and show����go here
int main����{
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
    show("Done!")��
    return 0;
}
���ṩ���������ĺ�����ԭ�ͣ��Ӷ���ɸó���ע�⣬Ӧ������show����������ÿ����ʹ��Ĭ�ϲ�����
�뾡����ʹ��consnt������set����ʹ��new�����㹻�Ŀռ����洢ָ�����ַ���������ʹ�õļ�������ƺ�
ʵ����ʱʹ�õ����ơ�(���ܻ������޸�ͷ�ļ������ƣ�ɾ��using����ָ���ȡ�������õı�������)
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
     * 5.��дģ�庯��max5����,����һ������5��T����Ԫ�ص�������Ϊ����������������������Ԫ��
    (���ڳ��ȹ̶�����˿�����ѭ����ʹ��Ӳ���룬������ͨ������������)����һ��������ʹ�øú�������
    T�滻Ϊһ������5��itֵ�������һ������5��dowbleֵ�����飬�Բ��Ըú�����
    */
    auto number = max5(1,2,3,4,5);
    cout << number << endl;
    ::printf("-------------------------\n");

    /*
     * 6.��дģ�庯��maxn����,������һ��T����Ԫ����ɵ������һ����ʾ����Ԫ����Ŀ��������Ϊ��
    ��������������������Ԫ�ء��ڳ���������в��ԣ��ó���ʹ��һ������6��tԪ�ص������һ����
    ��4��doubleԪ�ص����������øú��������򻹰���һ�����廯������charָ������������е�ָ������
    ��Ϊ����������������ַ����ĵ�ַ������ж���������ַ������򷵻����е�һ���ַ����ĵ�ַ��ʹ
    ����5���ַ���ָ����ɵ����������Ըþ��廯��
    */
    int arr[6] = {1,2,3,4,5,6};
    auto maxNumber = MyMaxNumber(arr, size(arr));
    for (int i = 0; i < 6; ++i) {
        cout << "arr"<< i <<"address is " << &arr[i] << endl;
    }
    cout << "maxNumer is " << *maxNumber << endl;
    cout << "maxNumer address is " << maxNumber << endl; // "maxNumer address is 0x61fe18


    /*
     * 7.�޸ĳ����嵥8.14��ʹ��ʹ��������ΪSumArray()��ģ�庯������������Ԫ�ص��ܺͣ���������
    ʾ��������ݡ�����Ӧ��ʾthing���ܺ��Լ�����debt���ܺ͡�
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
