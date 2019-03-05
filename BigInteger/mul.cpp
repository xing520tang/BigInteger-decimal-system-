#include"BigInteger.h"
//取余所得的余数
int table1[] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
//除法所得的商
int table2[] = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10};
void remove_zero(BigInt &a)
{
    for(int i = a.len-1 ; i >= 0; i--)
            if(a.num[i] == 0)
                a.len--;
            else break;
}
void fuzhi0(BigInt &a)//将a赋值为0
{
    a.num[0] = 0;
    a.sig = true;
    a.len = 1;
}
void fuzhi1(BigInt &a)//将a赋值位1
{
    a.num[0] = 1;
    a.sig = true;
    a.len = 1;
}
void mul(const BigInt &a , const BigInt &b ,BigInt &ans)
{
    if((a.len==1&&a.num[0]==0) || (b.len==1&&b.num[0]==0))//若其中有0，则直接返回0
    {
        fuzhi0(ans);
        return ;
    }
    char temp ,carry;
    int pos ,j;
    for(int i = 0 ; i < NUM_LEN ; i++)
        ans.num[i] = 0;
    for(int i = 0 ; i < b.len ; i++)
    {
        carry=0;
        for(j = 0; j < a.len ; j++)
        {
            temp = a.num[j]*b.num[i]+carry;
            carry = table2[temp];
            temp = table1[temp];
            pos = i+j;
            ans.num[pos] += temp;
            carry += table2[ans.num[pos]];
            ans.num[pos] = table1[ans.num[pos]];
        }
        if(carry > 0)
        {
            ans.num[i+j] = carry;
            ans.len = i+j+1;
        }else ans.len = i+j;
    }
    ans.sig = !(a.sig^b.sig);
}
