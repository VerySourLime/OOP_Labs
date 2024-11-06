#include <iostream>
#include <string>
using namespace std;
#include "Receipt.h"

int main()
{
    Receipt first_rec;
    Receipt second_rec(38234, "03.04.2024", 3000.5);
    Receipt third_rec(second_rec);
    first_rec.getInfo();
    first_rec.setInfo(1010102, "04.04.2024", 120.1823);
    first_rec.getInfo();
}