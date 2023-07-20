#include <array>
#include <iostream>
#include <string>
#include <vector>
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
//4.8 指针、数组和指针算术
void pointArray();
//4.12 复习题
void reviewFunc();
//4.13 编程练习
void codeFunc();

//4.13 编程练习
void codeFunc()
{

	//-------------------4.13.10
	//array和vector的区别
	//array是固定长度的，vector是可变长度的
	//array是数组，vector是容器
	//array是值语义，vector是引用语义
	array<double, 3> grade;
	cin >> grade[0] >> grade[1] >> grade[2];
	cout << "成绩是： " << (grade[0] + grade[1] + grade[2]) / size(grade) << endl;
	vector<double> grade1(3);
	cin >> grade1[0] >> grade1[1] >> grade1[2];
	cout << "成绩是： " << (grade1[0] + grade1[1] + grade1[2]) / grade1.size() << endl;

	//-------------------4.13.7
	struct Pizza
	{
		string name;
		float diameter;
		float weight;
	};

	//-------------------4.13.8
	Pizza* pizza1 = new Pizza;
	cout << "Enter the diameter of the pizza: ";
	cin >> pizza1->diameter;
	cout << "Enter the name of the pizza: ";
	cin >> pizza1->name;
	cout << "Enter the weight of the pizza: ";
	cin >> pizza1->weight;
	cout << "pizza name is " << pizza1->name << endl;
	cout << "pizza diameter is " << pizza1->diameter << endl;
	cout << "pizza weight is " << pizza1->weight << endl;
	cout << pizza1->name << endl;

	//-------------------4.13.7
	Pizza pizza;
	cout << "Enter the company name: ";
	cin >> pizza.name;
	cout << "Enter the diameter of the pizza: ";
	cin >> pizza.diameter;
	cout << "Enter the weight of the pizza: ";
	cin >> pizza.weight;
	cout << "pizza name is " << pizza.name << endl;
	cout << "pizza diameter is " << pizza.diameter << endl;
	cout << "pizza weight is " << pizza.weight << endl;

	//-------------------4.13.5
	struct CandyBar
	{
		string name;
		float weight;
		int calorie;
	};
	CandyBar snack = { "Mocha Munch",2.3,350 };
	cout << "snack name is " << snack.name << endl;
	cout << "snack weight is " << snack.weight << endl;
	cout << "snack calorie is " << snack.calorie << endl;
	//-------------------4.13.6
	CandyBar snacks[3] = { {"Mocha Munch",2.3,350},{"Mocha Munch",2.3,350},{"Mocha Munch",2.3,350} };
	for (int i = 0; i < size(snacks); ++i)
	{
		cout << "snack name is " << snacks[i].name << endl;
		cout << "snack weight is " << snacks[i].weight << endl;
		cout << "snack calorie is " << snacks[i].calorie << endl;
	}
	//-------------------4.13.9
	CandyBar* snacks1 = new CandyBar[3];




	//-------------------4.13.4
	cout << "Enter your first name: ";
	string sfirstName;
	cin >> sfirstName;
	cout << sfirstName << endl;
	cout << "Enter your last name: ";
	string slastName;
	cin >> slastName;
	cout << slastName << endl;
	cout << "Here's the information in a single string: " << slastName << ", " << sfirstName << endl;

	//-------------------4.13.3
	cout << "Enter your first name: ";
	char firstName[20];
	cin.getline(firstName, 20);
	cout << firstName << endl;
	cout << "Enter your last name: ";
	char lastName[20];
	cin >> lastName;
	//cin.getline(lastName, 20); 更加安全，可以读取空格，但是会读取回车。cin>>这种方式不会读取回车，而且不太安全
	cout << lastName << endl;
	cout << "Here's the information in a single string: " << lastName << ", " << firstName << endl;

	//-------------------4.13.2
	//-------------------4.13.1

}


//4.12 复习题
void reviewFunc()
{
	//-------------------4.12.1
	char actor[30];
	short betsie[100];
	float chuck[13];
	//精度更高，double是8个字节，long double是10个字节或者16个字节
	long double dipsea[64];
	//-------------------4.12.2
	//-------------------4.12.3
	int array[5] = { 1,3,5,7,9 };
	int enen[2] = { array[0],array[size(array) - 1] };
	//-------------------4.12.4
	float idea[2] = { 1,2 };
	cout << idea[1] << endl;
	//-------------------4.12.5
	char name[] = "cheeseburger";
	//-------------------4.12.6
	string str = "Waldorf Salad";
	//-------------------4.12.7
	struct Fish
	{
		string kind;
		int weight;
		float length;
	};
	//-------------------4.12.8
	Fish myFish = { "hu",12,43.2 };
	enum Response
	{
		No,
		Yes,
		Maybe
	};
	//-------------------4.12.9
	double ted = 2.0;
	double* pd = &ted;
	//-------------------4.12.12
	float treacle[10] = { 1 };
	for (int i = 0; i < 10; ++i)
	{
		cout << treacle[i] << endl;
	}
	float* pf = treacle;
	cout << "pf[0] is " << pf[0] << endl;
	cout << "sizeof(treacle)-1 " << sizeof(treacle) / sizeof(treacle[0]) << endl;
	int num = sizeof(treacle) / sizeof(treacle[0]);
	cout << "pf lase is " << pf[num - 1] << endl;
	//-------------------4.12.13
	int cinNum;
	cin >> cinNum;
	int* myArray = new int[cinNum];
	vector<int> myVector(cinNum);
	//-------------------4.12.14
	cout << (int*)"Home of the jolly bytes";
	//-------------------4.12.15
	Fish* myFish1 = new Fish;
	myFish1->kind = "hu";
	myFish1->weight = 12;
	myFish1->length = 43.2;
	cout << myFish1->kind << endl;
	cout << myFish1->weight << endl;
	cout << myFish1->length << endl;
	cout << "地址" << myFish1 << endl;
	delete myFish1;
	cout << "地址" << myFish1 << endl;
	//-------------------4.12.16
	//cin.getline()； 整行的读
	//-------------------4.12.17
	const int vectorNum = 12;
	vector<string> vi(vectorNum);
	std::array<std::string, vectorNum> arrayBane = { "test","test1" };

}


char* getName()
{
	char temp[80];
	cout << "Enter last name: ";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	strcpy_s(pn, strlen(temp) + 1, temp);
	return pn;
}

//4.8 指针、数组和指针算术
void pointArray()
{
	double rr[4] = { 1.2,2.4,3.6,4.8 };
	vector<double> r1(5);
	r1[0] = 1.0 / 3.0;
	r1[1] = 1.0 / 5.0;
	r1[2] = 1.0 / 7.0;
	r1[3] = 1.0 / 9.0;
	array<double, 4> r2 = { 1.2,2.4,3.6,4.8 };
	array<double, 4> r3;
	r3 = r2;
	cout << "rr[0] is " << rr[0] << "at" << &rr[0] << endl;
	cout << "rr[1] is " << rr[1] << "at" << &rr[1] << endl;
	cout << "rr[2] is " << rr[2] << "at" << &rr[2] << endl;
	cout << "r2[0] is " << r2[0] << "at" << &r2[0] << endl;
	cout << "r2[1] is " << r2[1] << "at" << &r2[1] << endl;
	cout << "r2[2] is " << r2[2] << "at" << &r2[2] << endl;
	cout << "r3[0] is " << r3[0] << "at" << &r3[0] << endl;
	cout << "r3[1] is " << r3[1] << "at" << &r3[1] << endl;
	cout << "r3[2] is " << r3[2] << "at" << &r3[2] << endl;
	rr[-2] = 20.2;
	cout << "--------------------" << endl;
	cout << "rr[-2] is " << rr[-2] << "at" << &rr[-2] << endl;
	cout << "r2[2]" << r2[2] << "at" << &r2[2] << endl;
	cout << "r3[2]" << r3[2] << "at" << &r3[2] << endl;



	struct antarctica_years_end
	{
		int year;
	};
	antarctica_years_end s01, s02, s03;
	antarctica_years_end* pa = &s02;
	s01.year = 1998;
	pa->year = 199;
	antarctica_years_end trio[3];
	trio[0].year = 2003;
	cout << trio->year << endl;
	const antarctica_years_end* arp[3] = { &s01,&s02,&s03 };
	cout << arp[1]->year << endl;
	const antarctica_years_end** ppa = arp;
	auto ppb = arp;
	cout << (*ppa)->year << endl; //1998
	cout << (*(ppb + 1))->year << endl;//1


	char* name;
	name = getName();
	cout << name << " at " << (int*)name << endl;
	delete[] name;
	name = getName();
	cout << name << " at " << (int*)name << endl;
	delete[] name;

	//------------------------
	struct inflatable
	{
		char name[20];
		float volume;
		double price;
	};
	inflatable* inf = new inflatable;
	cout << "Enter name of inflatable item: ";
	cin.get(inf->name, 20);
	cout << "Enter volume in cubic feet: ";
	cin >> (*inf).volume;
	cout << "Enter price: $";
	cin >> inf->price;
	cout << "Name: " << (*inf).name << endl;
	cout << "Volume: " << inf->volume << " cubic feet\n";
	cout << "Price: $" << inf->price << endl;
	delete inf;



	char animal[20] = "bear";
	const char* bird = "wren";
	char* psa = nullptr;
	cout << animal << " and " << bird << endl;
	//cout << "ps is " << psa << endl;
	cout << "Enter a kind of animal: ";
	cin >> animal;
	cout << "animal is " << animal << endl;
	cout << "Enter another kind of animal psa: ";
	//cin >> psa; //use not right
	psa = animal;
	cout << "psa is " << psa << endl;
	cout << "before using strcpy():" << endl;
	cout << animal << " at " << (int*)animal << endl;
	cout << psa << " at " << (int*)psa << endl;
	psa = new char[strlen(animal) + 1];
	strcpy_s(psa, strlen(psa) + 1, animal);
	cout << "after using strcpy():" << endl;
	cout << animal << " at " << (int*)animal << endl;
	cout << psa << " at " << (int*)psa << endl;
	delete[] psa;


	//指针和字符串
	char flower[10] = "rose";
	cout << flower << " is red" << endl;

	int tacos[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pt = tacos;
	pt += 1;
	cout << "pt is " << pt << endl;
	int* pe = &tacos[9];
	pe -= 1;
	cout << "pe is " << pe << endl;
	//pt is 00000025AA6FF96C
	//pe is 00000025AA6FF988
	int diff = pe - pt;
	cout << "diff is " << diff << endl;

	double wages[3] = { 1000.0,2000.0,3000.0 };
	short stacks[3] = { 3,2,1 };
	//指针数组
	double* pw = wages;
	short* ps = &stacks[0];
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "add o1 to the pw pointer" << endl;
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps += 1;
	cout << "add o1 to the ps pointer" << endl;
	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	cout << "get two elements with array notation" << endl;
	cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
	cout << "get two elements with pointer notation" << endl;
	cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1) << endl;
	cout << sizeof(wages) << " = size of wages array" << endl;
	cout << sizeof(pw) << " = size of pw pointer" << endl;

}


//4.7 指针和自由空间
void pointFunc()
{
	double* p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1] is " << p3[0] << endl;//0.5
	p3 += 1;
	cout << "p3[0] is " << p3[0] << endl; //0.5
	cout << "p3[1] is " << p3[1] << endl; //0.8


	int donuts = 10;
	double cups = 12.1;
	cout << "douts is " << donuts;
	cout << "address douts is " << &donuts << endl;
	cout << "cups is " << cups;
	cout << "address cups is " << &cups << endl;

	int updates = 6;
	int* p_updates;
	p_updates = &updates;
	cout << "updates is " << updates << endl; //6
	cout << "address updates is " << &updates << endl;//0x61fe1c
	cout << "*p_updates is " << *p_updates << endl;//6
	cout << "p_updates is " << p_updates << endl;//0x61fe1c
	*p_updates = *p_updates + 1;
	cout << "now updates is " << updates << endl;//7


	//这可能把程序用到的内存地址赋值，导致程序出现错误
	//long* fellow;
	//*fellow = 2333;

	int* pt = new int;
	cout << "address pt is " << pt << endl;
	//这个地址是随机的，因为是在堆中分配的
	cout << "*pt number is" << *pt << endl;

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
	enum color1 { red1 = -1, orange1 = 16 };
	//使用四个字节
	cout << "size of color is " << sizeof(color1) << endl;
}

void unionFunc() {
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
			int age;
			double price;
		};
	}myStruct2;
	myStruct2.age = 11;
	cout << "匿名共用体的age是 " << myStruct2.age << endl;
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
	cout << "gest size is " << sizeof(gest) << endl;
	inflatable gest3 = {};
	cout << "gest3 size is" << sizeof(gest3) << endl;
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
	strncpy_s(charr3, charr4, 20);
	strr1 += " paste";
	// ReSharper disable once CppDeprecatedEntity
	strncat_s(charr3, " juice", 20);
	int len1 = strr1.size();
	int len2 = strlen(charr3);
	cout << "The string " << strr1 << " contains " << len1 << " characters.\n";
	cout << "The string " << charr3 << " contains " << len2 << " characters.\n";


	string firstName = "meng";
	string lastName = " long";
	cout << "firstName + lastName is " << firstName + lastName << endl;
	firstName += lastName;
	cout << "firstName + lastName is " << firstName << endl;


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
	cout << "What year was your house built?\n";
	int year;
	(cin >> year).get();
	cout << "What is its street address?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";



	const int nameSize = 20;
	char name[nameSize];
	char dessert1[nameSize];
	cout << "Enter your name:\n";
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


	cout << "I'd give my right arm to be " " a great violinist.\n";
	cout << "I'd give my right arm to be a great violinist.\n";
	cout << "I'd give my right arm to be "
		"a great violinist.\n";

	const int ArSize = 20;
	char name1[20];
	char name2[ArSize] = "C++owboy";
	cout << "Howdy! I'm " << name2;
	cout << "! What's your name?\n";
	cin >> name1;
	cout << "well, " << name1 << ", your name has ";
	cout << strlen(name1) << " letters and is stored\n";
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
	cout << "i " << sizeof(notInit2) / sizeof(notInit2[0]) << endl;
	for (int i = 0; i < size(notInit2); ++i)
	{
		cout << "notInit2 " << i << " is " << notInit2[i] << endl;
	}

	//C++11新功能，可省略=号
	int init[4]{ 1, 2, 3, 4 };
	for (int i = 0; i < size(init); ++i)
	{
		cout << "init " << i << " is " << init[i] << endl;
	}
	//C++11新功能，不写，直接填零
	int init2[4]{ };
	for (int i = 0; i < size(init2); ++i)
	{
		cout << "init2 " << i << " is " << init2[i] << endl;
	}
	//列表初始化禁止缩窄转换
	//long plifs[] = { 25, 92, 3.0 };
}

