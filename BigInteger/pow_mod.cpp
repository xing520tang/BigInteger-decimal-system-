#include"BigInteger.h"
void pow_mod(const BigInt &A ,const BigInt &B ,const BigInt &M ,BigInt &ans)
{
    BigInt temp = A ,b = B ,t ,two;//temp=A;
    ans.len = 1; ans.sig = true ; ans.num[0] = 1; //ans=1;
    two.len = 1; two.sig = true ; two.num[0] = 2; //two=2
    while(! is_zero(b))//当b!=0时，循环
    {
        if(b.num[0]%2)//如果b是个奇数
        {
            mul(ans,temp,t);//t=ans*temp;
            mod(t,M,ans);   //ans = t%m;
        }
        mul(temp,temp,t);//t = temp*temp
        mod(t,M,temp);   //temp = t%m
        div(b,two,b,t);    //b = b/2;
    }
}
