/*
�������һ������Ϊlen�Ĵ��������������ans��
len��ָʮ���Ƶĳ���
*/
#include "BigInteger.h"
void generate_num(BigInt &ans ,int len)//�������һ��������������ans��.���д�����ʮ���Ƴ���Ϊlen
{
    for(int i = 1 ; i < len ; i++ )
        ans.num[i] = rand()%10;
    int t;
    while((t=rand()%10)%2 == 0 || t==5);
    ans.num[0] = t;
    if(ans.num[len-1]==0)//������λ����0������������1
        ans.num[len-1] = 1;
    ans.len = len;
    ans.sig = true;
}
