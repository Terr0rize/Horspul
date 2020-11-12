#include <iostream>
#include <string>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}


void search(string txt, string pat)
{
    int m = pat.length();
    int n = txt.length();
    int badchar[256];

    functions(pat, m, badchar);

    int s = 0; 

    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            cout << "\nПозиция: " << s << endl;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }

}

void functions(string str, int size, int badchar[256])
{

    for (int i = 0; i < 256; i++)
        badchar[i] = -1;

    for (int i = 0; i < size; i++)
        badchar[str[i]] = i;
}

int main()
{
    
    setlocale(LC_ALL, "rus");

    string txt;
    cout << "Введите строку: ";  cin >> txt;

    string pat;
    cout << "Введите подстроку: ";  cin >> pat;

    search(txt, pat);
    system("pause");
    return 0;
}
