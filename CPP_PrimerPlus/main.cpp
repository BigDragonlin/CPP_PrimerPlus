#include <iostream>
#include <string>
using namespace std;


//4.1 ����
void arrayone();
//4.2 �ַ���
void stringone();
//4.4 string��
void strtpye();

int main()
{
	//4.3 string��
	strtpye();

	//4.2 �ַ���
	//stringone();


	//4.1 ����
	//arrayone();
}

//4.3 string��
void strtpye()
{
	//δ��ʼ��
	char charr04[20];
	string str04;
	cout << "charr04�ĳ�����" << strlen(charr04) << endl;
	cout << "str04�ĳ�����" << str04.size() << endl;
	cout << "������charr04" << endl;
	cin.getline(charr04, 20);
	cout << "you enter char is " << charr04 << endl;
	cout << "enter another lin is \n";
	getline(cin, str04);
	cout << "you enter: " << str04 << endl;
	cout << "char size is " << strlen(charr04);
	cout << "str size is " << str04.size();


	
	/* ����д���У�strcpy �� strcat�ǲ���C��
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
	string str1; //�����Զ�������С
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


//4.2 �ַ���
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
	cout << "dog is " << dog << endl; //����������������
	cout << "fish is " << fish << endl; //wanda
	cout << "dog[1] is " << dog[1] << endl; //e
	cout << "dog[1] char " << (int)dog[1] << endl; //e

	char shirt_size = 'M';
	//char shirt_size2 = "s"; //���ܰ��ַ�����ֵ���ַ�


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

//4.1 ����
void arrayone()
{
	using namespace std;
	int yams[3];
	yams[0] = 3;
	yams[1] = 4;
	yams[2] = 5;

	int yamcCosts[3] = { 8, 9, 10 };
	cout << "total yam ��" << yams[0] + yams[1] + yams[2] << endl;
	cout << "total yamCosts :" << yamcCosts[0] + yamcCosts[1] << endl;

	cout << "size of yams is " << sizeof(yams) << endl; //12 bytes 12 * 8 bit �ֽںͱ���
	cout << "size of yamCosts is " << sizeof(yamcCosts) << endl;//12

	int card[4] = { 1, 2, 3, 4 };//allow
	int hand[4]; //allow
	//hand[4] = { 1, 3, 4, 5 };//not allow
	//hand = card; //not allow

	//���û�ж�����û�г�ʼ���꣬���Զ���0
	int notInit[4] = { 1, 0 };
	cout << "size of notInit is " << sizeof(notInit) << endl;
	cout << "size of notInit[0] is " << sizeof(notInit[0]) << endl;
	for (int i = 0; i < size(notInit); ++i)
	{
		cout << "notInit " << i << " is " << notInit[i] << endl;
	}
	//���û����д��ʼ�����������Զ�����
	int notInit2[] = { 1, 2, 3, 4 };
	cout << "size of notInit2 is " << sizeof(notInit2) << endl;
	cout << "size of notInit2[0] is " << sizeof(notInit2[0]) << endl;
	cout << "i "<< sizeof(notInit2) / sizeof(notInit2[0]) << endl;
	for (int i = 0; i < size(notInit2); ++i)
	{
		cout << "notInit2 " << i << " is " << notInit2[i] << endl;
	}

	//C++11�¹��ܣ���ʡ��=��
	int init[4] { 1, 2, 3, 4 };
	for (int i = 0; i < size(init); ++i)
	{
		cout << "init " << i << " is " << init[i] << endl;
	}
	//C++11�¹��ܣ���д��ֱ������
	int init2[4] { };
	for (int i = 0; i < size(init2); ++i)
	{
		cout << "init2 " << i << " is " << init2[i] << endl;
	}
	//�б��ʼ����ֹ��խת��
	//long plifs[] = { 25, 92, 3.0 };
}

