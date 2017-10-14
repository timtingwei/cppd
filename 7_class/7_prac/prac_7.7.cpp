//rewrite the transaction-processing program
#include <iostream>
using std::cout;using std::cin; using std::endl;

int main()
{
    cout << "please input ISBN, units_sold, sellingprice, saleprice" << 
endl;
    Sales_data total;
    if (cin >> total)
    {
        Sales_data trans;                     //save next transaction 
        while (cin >> trans)
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);         //updata total transaction
            else
            {
                cout << total << endl;        //??
                total = trans;                //deal with next book
            }
        }
        cout << total << endl;                //print the last book msg
    }
    else
    {
        cerr << "No data?" << endl;
        return -1;
    }
    return 0;
}
