#include <iostream>
#include <string>
using namespace std;


//4.1 数组
void arrayone();
//4.2 字符串
void stringone();
//4.3 string类
void strtpye();
//4.4 结构介绍
void structur();
//4.5共同体
void unionFunc();
//4.6  枚举
void enumFunc();
//4.7 指针和自由空间
void pointFunc();

int main()
{
	// 4.7指针和自由空间
	pointFunc();

	//4.6  枚举
	// enumFunc();

	//4.5共同体
	// unionFunc();

	//4.4 结构
	// structur();

	//4.3 string类
	//strtpye();

	//4.2 字符串
	//stringone();


	//4.1 数组
	//arrayone();
}

//4.7 指针和自由空间
void pointFunc()
{
	int donuts = 10;
	double cups = 12.1;
	cout << "douts is " << donuts;
	cout << "address douts is "<< &donuts << endl;
	cout << "cups is " << cups;
	cout << "address cups is " << &cups << endl;
}


//4.6  枚举
void enumFunc()
{
	//而枚举的变量是直接在全局作用域定义的,所以可以直接访问,不需要通过"枚举变量."的方式。
	enum color { red, orange, yellow, green, blue, violet, indigo };
	cout << "打印颜色 " << red;
	cout << "打印颜色 " << orange;
	color myColor = orange;
	cout << "my color is " << myColor << endl;

	//枚举的值可以相同
	enum color1 { red1 = -1 ,orange1 = 16};
	//使用四个字节
	cout<<"size of color is "<< sizeof(color1)<<endl;
}

void unionFunc(){
	//共用体
	union one4all
	{
		int age;
		double money;
	};
	one4all one4_all;
	cout << "before one4all的大小是" << sizeof(one4_all) << endl;
	one4_all.age = 11;
	cout << "after one4all的大小是" << sizeof(one4_all) << endl;
	struct struct1 {
		int state;
		union my_union
		{
			int age = 0;
			double price;
		}MyUnion;
	};
	struct1 myStruct;

	// 匿名共用体
	struct struct2
	{
		int state;
		union
		{
			int age ;
			double price;
		};
	}myStruct2;
	myStruct2.age= 11;
	cout<<"匿名共用体的age是 "<< myStruct2.age <<endl;
	cout << "匿名共用体的price是 " << myStruct2.price << endl;
}

void structur()
{
	//结构数组
	struct stringStruct3
	{
		string name;
	};
	stringStruct3 stringStc3[2] = {
		{"meng"},
		{"long"}
	};
	cout << "stringStc3[0] is " << stringStc3[0].name << endl;
	cout << "stingStc3[0] is " << stringStc3[1].name << endl;

	//拷贝
	struct stringStruct1
	{
		string name;
	};
	stringStruct1 string_s_struct1 = { "萌萌哒哒" };
	stringStruct1 string_s_struct2 = string_s_struct1;
	cout << "name is " << string_s_struct2.name << endl;
	//结构定义+声明
	struct stringStruct2
	{
				string name;
	} string_struct3;
	string_struct3.name = "萌萌哒哒2";
	cout << "name is " << string_struct3.name << endl;
	//结构定义+声明 + 赋值
	struct stingStruct3
	{
		string name;
	} string_struct4 = {
		"萌萌哒哒3"
	};
	cout << "name is " << string_struct4.name << endl;
	//匿名结构体
	struct 
	{
		string name;
	} sting_struct5 = {
			"萌萌大大5"
	};
	cout << "name is " << sting_struct5.name << endl;

	struct stringStruct
	{
		string address;
	};
	//打印出来是28，因为内部存在有缓冲区设置
	stringStruct strStruct{ "赵谦孙俪" };
	cout << "strStruct size is " << sizeof(strStruct) << endl;
	stringStruct strStruct1 = {};
	cout << "strStruct1 size is " << sizeof(strStruct1) << endl;
	
	
	struct inflatable
	{
		char name[20];
		float volume;
		double price;
	};
	inflatable gest = {
		"menglong",
		1.88,
		29.99
	};
	inflatable pal = {
			"menglong2",
			1.8,
			29.9
		};
	cout << "gest name is " << gest.name << endl;
	cout << "gest volume is " << gest.volume << endl;
	cout << "gest price is " << gest.price << endl;
	cout << "pal name is " << pal.name << endl;
	cout << "pal volume is " << pal.volume << endl;
	cout << "pal price is " << pal.price << endl;

	inflatable gestC11{ "menglong2",22,33 };
	inflatable gestC112 = { "menglong3",44,55 };
	inflatable gest2 = { "menglong4",1.333,22 };//缩窄转换有问题
	cout <<"gest size is " << sizeof(gest) << endl;
	inflatable gest3 = {};
	cout << "gest3 size is" << sizeof(gest3) <<endl;
	cout << "gest3.volum is " << gest3.volume << endl;
	cout << "gest3.name is " << gest3.name << endl;
}


//4.3 string类
void strtpye()
{
	//未初始化
	char charr04[20];
	string str04;
	cout << "charr04的长度是" << strlen(charr04) << endl;
	cout << "str04的长度是" << str04.size() << endl;
	cout << "请输入charr04" << endl;
	cin.getline(charr04, 20);
	cout << "you enter char is " << charr04 << endl;
	cout << "enter another lin is \n";
	getline(cin, str04);
	cout << "you enter: " << str04 << endl;
	cout << "char size is " << strlen(charr04);
	cout << "str size is " << str04.size();


	
	/* 这样写不行，strcpy 和 strcat是操作C的
	 *string str3 = "hello";
	string str4 = "world";
	strcpy(str3, str4);
	cout << "str1" << str3;
	*/
	char charr3[20];
	char charr4[20] = "jaguar";
	string strr1;
	string strr2 = "panther";
	strr1 = strr2;
	// ReSharper disable once CppDeprecatedEntity
	strncpy_s(charr3, charr4,20);
	strr1 += " paste";
	// ReSharper disable once CppDeprecatedEntity
	strncat_s(charr3, " juice",20);
	int len1 = strr1.size();
	int len2 = strlen(charr3);
	cout << "The string " << strr1 << " contains " << len1 << " characters.\n";
	cout << "The string " << charr3 << " contains " << len2 << " characters.\n";


	string firstName = "meng";
	string lastName = " long";
	cout << "firstName + lastName is " << firstName + lastName << endl;
	firstName += lastName;
	cout << "firstName + lastName is " << firstName<< endl;


	char charr1[20];
	char charr2[20] = "jaguar";
	string str1; //可以自动调整大小
	string str2 = "panther";
	cout << "Enter a kind of feline: ";
	cin >> charr1;
	cout << "Enter another kind of feline: ";
	cin >> str1;
	cout << "Here are some felines:\n";
	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2
		<< endl;
	cout << "The third letter in " << charr2 << " is "
		<< charr2[2] << endl;
	
}


//4.2 字符串
void stringone()
{
	 using namespace std;
	 cout <<"What year was your house built?\n";
	 int year;
	(cin >> year).get();
	cout<< "What is its street address?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";



	 const int nameSize = 20;
	 char name[nameSize];
	char dessert1[nameSize];
	cout	<< "Enter your name:\n";
		cin.get(name, nameSize).get();
	cout << "Enter your favorite dessert:\n";
	cin.get(dessert1, nameSize).get();
	cout << "I have some delicious " << dessert1;
	cout << " for you, " << name << ".\n";

	 char dog[8] = { 'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I' };
	char fish[] = "wanda";
	cout << "dog is " << dog << endl; //烫烫烫烫烫烫烫烫
	cout << "fish is " << fish << endl; //wanda
	cout << "dog[1] is " << dog[1] << endl; //e
	cout << "dog[1] char " << (int)dog[1] << endl; //e

	char shirt_size = 'M';
	//char shirt_size2 = "s"; //不能把字符串赋值给字符


	cout << "I'd give my right arm to be " " a great violinist.\n" ;
	cout << "I'd give my right arm to be a great violinist.\n" ;
	cout << "I'd give my right arm to be "
	"a great violinist.\n" ;

	const int ArSize = 20;
	char name1[20];
	char name2[ArSize] = "C++owboy";
	cout << "Howdy! I'm " << name2;
	cout << "! What's your name?\n";
	cin >> name1;
	cout << "well, " << name1 << ", your name has ";
	cout <<strlen(name1) << " letters and is stored\n";
	cout << "in an array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	name1[3] = '\0';
	cout << "Here are the first 3 characters of my name: ";
	cout << name1 << endl;

	const int ArSize2 = 20;
	char name3[ArSize2];
	char dessert[ArSize2];
	cout << "Enter your name:\n";
	cin >> name3;
	cout << "Enter your favorite dessert:\n";
	cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name3 << ".\n";
}

//4.1 数组
void arrayone()
{
	using namespace std;
	int yams[3];
	yams[0] = 3;
	yams[1] = 4;
	yams[2] = 5;

	int yamcCosts[3] = { 8, 9, 10 };
	cout << "total yam ：" << yams[0] + yams[1] + yams[2] << endl;
	cout << "total yamCosts :" << yamcCosts[0] + yamcCosts[1] << endl;

	cout << "size of yams is " << sizeof(yams) << endl; //12 bytes 12 * 8 bit 字节和比特
	cout << "size of yamCosts is " << sizeof(yamcCosts) << endl;//12

	int card[4] = { 1, 2, 3, 4 };//allow
	int hand[4]; //allow
	//hand[4] = { 1, 3, 4, 5 };//not allow
	//hand = card; //not allow

	//如果没有对数组没有初始化完，则自动填0
	int notInit[4] = { 1, 0 };
	cout << "size of notInit is " << sizeof(notInit) << endl;
	cout << "size of notInit[0] is " << sizeof(notInit[0]) << endl;
	for (int i = 0; i < size(notInit); ++i)
	{
		cout << "notInit " << i << " is " << notInit[i] << endl;
	}
	//如果没有填写初始化数量，则自动计算
	int notInit2[] = { 1, 2, 3, 4 };
	cout << "size of notInit2 is " << sizeof(notInit2) << endl;
	cout << "size of notInit2[0] is " << sizeof(notInit2[0]) << endl;
	cout << "i "<< sizeof(notInit2) / sizeof(notInit2[0]) << endl;
	for (int i = 0; i < size(notInit2); ++i)
	{
		cout << "notInit2 " << i << " is " << notInit2[i] << endl;
	}

	//C++11新功能，可省略=号
	int init[4] { 1, 2, 3, 4 };
	for (int i = 0; i < size(init); ++i)
	{
		cout << "init " << i << " is " << init[i] << endl;
	}
	//C++11新功能，不写，直接填零
	int init2[4] { };
	for (int i = 0; i < size(init2); ++i)
	{
		cout << "init2 " << i << " is " << init2[i] << endl;
	}
	//列表初始化禁止缩窄转换
	//long plifs[] = { 25, 92, 3.0 };
}

