/*
随机生成一个长度为len的大奇数，结果存于ans中
len是指十进制的长度
*/
#include "BigInteger.h"
void generate_num(BigInt &ans ,int len)//随机生成一个大奇数，存入ans中.其中大数的十进制长度为len
{
    for(int i = 1 ; i < len ; i++ )
        ans.num[i] = rand()%10;
    int t;
    while((t=rand()%10)%2 == 0 || t==5);
    ans.num[0] = t;
    if(ans.num[len-1]==0)//如果最高位等于0，则令他等于1
        ans.num[len-1] = 1;
    ans.len = len;
    ans.sig = true;
}
