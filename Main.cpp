#include"Headers.h"
using namespace std;

//***********************MAIN METHOD*******************//


int main()
{

    Admin adm;
    
    adm.ReadData();

    int choise = 0;


    while (1)
    {
        cout << "1. ADMIN LOGIN 2.EMPLOYEE LOGIN" << endl;

        try {
            cin >> choise;
            if (choise < 0 || choise > 5)
            {
                return 0;
               // throw exptn;
            }
        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }

        switch (choise)
        {
        case 1: adm.AdminLogin();
       
        }


    }

}
