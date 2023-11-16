//
// Created by Administrator on 2023/11/15/015.
//
using namespace std;
//functionAndArray();
//---------5.6 嵌套循环和二维数组
//    nestedLoopAnd2DArray();
//
//
//	----------5.5 循环和文本输入
//	 loopTxtInput();
//
//----------5.4 基于范围的for循环
//forLoopBaseRange();
//
//----------5.3 while循环
//whiile_loop();
//
//----------5.1 for循环
//for_loop();


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

//5.6 嵌套循环和二维数组
void nestedLoopAnd2DArray(){


//    for (int i = 1; i < 128; i = 2 * i) {
//        ::printf("i = %d\n", i);
//    }
//
//    ::printf("--------------------\n");
//    int i = 1;
//    while (i < 128){
//        ::printf("i = %d\n", i);
//        i *= 2;
//    }

//    ::printf("--------------------\n");
//    int k = 8;
//    do {
//        cout << "k = " << k << endl; //8 9 10
//    } while (k++ < 10);
//
//    ::printf("--------------------\n");
//    int m = 5;
//    while (++m < 10){ //6 7 8 9 10
//        cout << "m = " << m << endl;
//    }
//    ::printf("--------------------\n");
//    int n = 5;
//    while (n++ < 10){ //5 6 7 8 9; 6 7 8 9 10
//        ::printf("n = %d\n", n);
//    }
//
//    ::printf("--------------------\n");
//    for (int i = 0; i < 11; ++i) {
//        ::printf("i = %d\n", i);
//    }
//    for (int i = 0; i < 11; i++) {
//        ::printf("i = %d\n", i);
//    }
//
//    ::printf("--------------------\n");
//    int j;
//    for (j = 0; j < 11; j += 3){
//        ::printf("j = %d\n", j);
//    }
//
//    ::printf("--------------------\n");
//    int i ;
//    for (i = 0; i < 5; ++i) {
//        ::printf("i = %d\n", i);
//    }
//
//    ::printf("--------------------\n");
//    const char* cities[4] = {
//            "city_1",
//            "city_2",
//            "city_3",
//            "city_4"
//    };
//    int maxTemps[4][4] = {
//            {32, 34, 35, 36},
//            {31, 33, 34, 35},
//            {30, 32, 33, 34},
//            {29, 31, 32, 33}
//    };
//
//    for (auto & citie : cities) {
//        cout << citie << '\t';
//        int i = 0;
//        for (auto & temps : maxTemps[i]) {
//           cout << temps << '\t';
//        }
//        cout << endl;
//    }
//
//    cout<< "----------------" << endl;
//    for (int year = 2020; year < 2024; ++year) {
//        for (int city = 1; city < 5; ++city) {
//            cout << "year = " << year << " city = " << "city_"<<city << '\t';
//        }
//        cout << endl;
//    }
}

void functionAndArray()
{
    //匿名函数
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
