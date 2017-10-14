//rewrite the transaction-processing program
#include <iostream>
#include "Sales_data.h"
//using std::cout;using std::cin; using std::endl;
using namespace std;

int main()
{
    cout << "Hello,world" << endl;
    cout << "please input ISBN, units_sold, sellingprice, saleprice" 
<< endl;
    Sales_data total;
    if (read(cin, total))
    //cout << "finish cin" << endl;
    //if (cin >> total)
    {
        Sales_data trans;                     //save next transaction 
        while (read(cin,trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);         //updata total transaction
            else
            {
                //cout << "total" << endl;        //??
                print(cout, total);
                total = trans;                //deal with next book
            }
        }
        print (cout, total);
        //cout << "total" << endl;            //print the last book msg
    }
    else
    {
        cerr << "No data?" << endl;
        return -1;
    }
    return 0;
}

