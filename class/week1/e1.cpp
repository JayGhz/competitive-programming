#include <iostream>

using namespace std;

int main()
{
    /*
    Dado un número N, determina si es primo o no.
    Entrada: Un entero N (1 ≤ N ≤ 10^6). Es decir 1 ≤ N ≤ 1,00,000
    Salida: "SI" si N es primo, "NO" en caso contrario.
    */

    int n;

    cin >> n;

    if (n == 1 || n == 2)
    {
        cout << "SI";
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                cout << "NO";
                break;
            }
            else if (i == n - 1)
            {
                cout << "SI";
            }
        } 
    }

    return 0;
}