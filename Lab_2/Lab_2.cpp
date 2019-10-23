
#include "Sort.h"


int main()
{
    datatype  br[] = {9,8,7,6,5,4,3,2,1,0};

    print_arr(br, 10);
    //bubble(br, 10);
    ins_sort(br, 10);
    print_arr(br, 10);

    return 0;
}