#include <iostream>
#include "lexical_cast.hpp"

using namespace std;

int main(int argc, char** argv)
{
    cout << LexicalCast<int>("123") << endl;
    cout << LexicalCast<long>("12333333333") << endl;
    cout << LexicalCast<long long>("-1233333333333333333") << endl;
    cout << LexicalCast<unsigned long>("23234444433333") << endl;
    cout << LexicalCast<unsigned long long>("14344444444444233") << endl;
    cout << LexicalCast<double>("12.454444444") << endl;
    cout << LexicalCast<long double>("123434444545.66666666666") << endl;
    cout << LexicalCast<float>("12.3444") << endl;
    cout << LexicalCast<bool>("true") << endl;
    cout << LexicalCast<bool>(0) << endl;
    cout << LexicalCast<string>(23443) << endl;
    cout << LexicalCast<string>(2.2333) << endl;
    cout << LexicalCast<string>(true) << endl;

    const string case1 = "12334";
    const string case2 = "122.3333";
    const string case3 = "false";
    char case4[] = "1234";
    char case5[] = "-21.3333";
    char case6[] = "true";
    const char* case7 = case4;
    const char* case8 = case5;
    const char* case9 = case6;

    cout << LexicalCast<int>(case1) << endl;
    cout << LexicalCast<int>(case4) << endl;
    cout << LexicalCast<int>(case7) << endl;
    cout << LexicalCast<double>(case2) << endl;
    cout << LexicalCast<double>(case5) << endl;
    cout << LexicalCast<double>(case8) << endl;
    cout << LexicalCast<bool>(case3) << endl;
    cout << LexicalCast<bool>(case6) << endl;
    cout << LexicalCast<bool>(case9) << endl;

    return 0;
}