#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;
//5.1 for循环
void for_loop()
{
	//----------5.3 express.cpp
	cout << "the expression x = 100 has the value ";
	int x;
	cout << (x = 100) << endl;
	cout << "the expression x < 3 has the value ";
	//cout << "<<"的优先级比"<"高
	cout << (x < 3) << endl;
	cout.setf(ios_base::boolalpha);
	cout << "the expression x < 3 has the value ";
	cout << (x < 3) << endl;

	//----------5.1 for_loop.cpp
	for (int i = 0; i < 5; ++i)
		cout << "C++ knows loops.\n";
	cout << "C++ knows when to stop.\n";

	//----------5.2 num_test.cpp
	int limit;
	cin >> limit;
	int i;
	//注意C++好像没有使用逗号的
	for (i = limit; i; i--)
		cout << "i = " << i << "\n";
}

//5.2 while循环
void whiile_loop()
{
	//----------5.15 dowhile.cpp
	int guessNumber;
	cout << "Enter a number in 1 to 10: ";
	cin >> guessNumber;
	int targetNumber = 7;
	do
	{
		cout << "猜错了" << endl;
		if (guessNumber > targetNumber)
		{
			guessNumber--;
		}
		else
		{
			guessNumber++;
		}
	}
	while (guessNumber != targetNumber);
	cout << "猜对了，是7" << endl;

	//----------5.14 waiting.cpp
	int wait_time;
	cout << "Enter the delay time, in seconds: ";
	cin >> wait_time;
	wait_time *= CLOCKS_PER_SEC;
	clock_t start = clock();
	int m = 0;
	while (clock() - start < wait_time)
	{
		m++;
		cout << "done \n";
		cout << "i = " << m << "\n";
	}

	//----------5.13 while.cpp
	cout << "Enter numbers: ";
	char name[10];
	cin >> name;
	int i = 0;

	while (name[i] != '\0')
	{
		cout << "name[" << i << "] is " << name[i] << " ascii :" << (int)name[i] << endl;
		i++;
	}
}

//5.4 基于范围的for循环
void forLoopBaseRange()
{
	int array[5] = {1, 2, 3, 4, 5};
	for (auto element : array)
	{
		cout << element << endl;
	}
	cout << "----------------" << endl;
	for (auto& element : array)
	{
		element += 1;
		cout << element << endl;
	}
	cout << "----------------" << endl;
	for (auto element : array)
	{
		cout << element << endl;
	}
}

//5.5 循环和文本输入
void loopTxtInput()
{
	//--------5.18 textin3.cpp
	char input1;
	cout << "enter any charactor to continue, and S+Z to end" << endl;
	cin.get(input1);
	int count1 = 0;
	while (cin.fail() == false)
	{
		cout << input1;
		//cin.get 和 cin >>的区别
		cin.get(input1);
		count1++;
	}
	cout << "the end count is " << count1 << endl;

	//--------5.17 textin2.cpp
	cout << "enter any charactor to continue, and # to end" << endl;
	char input;
	cin.get(input);
	int count = 0;
	while (input != '#')
	{
		cout << input;
		//cin.get 和 cin >>的区别
		cin.get(input);
		count++;
	}
	cout << "the end count is " << count << endl;
}

void functionAndArray()
{
	auto n_char = [](char inputChar, int num)
	{
		while (num-- > 0)
		{
			cout << inputChar << "\t";
		}
	};
	int time;
	char inputChar;
	cout << "enter char" << std::endl;
	cin >> inputChar; // 读取输入的字符

	while (inputChar != 'q')
	{
		cout << "enter print num" << std::endl;
		cin >> time;
		n_char(inputChar, time);
		cout << "enter new inputChar" << endl;
		cin >> inputChar;
	}
}

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


//    9.在下述代码（假定这些代码是一个完整程序的一部分）中，v1、v2、v3、v4和v5分别是哪种类型？
//    int g(int x);
//    float m 5.5f;
//    float rm m;
//    decltype(m)vi m;
//    decltype(rm)v2 m;
//    decltype((m))v3 m;
//    decltype (g(100))v4;
//    decltype (2.0 m)v5;
}

int main()
{
    //----------8.7复习题
    review();

	//------------8.5函数模板
    //	templateFunc();

	// -------------8.3默认参数
	//defaultParam();

	//------------8.2 引用变量
	// firstRef();

	//-------------------8.1C++内联函数
	//inLineFunction();

 	// ------------------7.3函数和数组
	//functionAndArray();


	//----------5.5 循环和文本输入
	// loopTxtInput();

	//----------5.4 基于范围的for循环
	//forLoopBaseRange();

	//----------5.3 while循环
	//whiile_loop();

	//----------5.1 for循环
	//for_loop();
}
