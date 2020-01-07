#include <iostream>
#include "lexical_cast.hpp"

using namespace std;

int main(int argc, char** argv)
{
    cout << LexicalCast<int>("123") << endl;
    cout << LexicalCast<long>("1233") << endl;
    cout << LexicalCast<double>("-12.333") << endl;
    cout << LexicalCast<unsigned long>("1233") << endl;
    cout << LexicalCast<bool>("true") << endl;
    cout << LexicalCast<bool>(0) << endl;
    cout << LexicalCast<string>(23443) << endl;
    cout << LexicalCast<string>(2.2333) << endl;
    cout << LexicalCast<string>(true) << endl;
    cout << LexicalCast<string>(false) << endl;
    return 0;
}