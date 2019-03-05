#include"BigInteger.h"
BigInt GCD;
void extend_gcd(const BigInt &a ,const BigInt &b ,BigInt &x ,BigInt &y)
{
    if(is_zero(b))
    {
        fuzhi0(y);//y=0;
        fuzhi1(x);//x=1;
        GCD = a;
        return ;
    }else {
        BigInt temp ,t;
        mod(a,b,temp);
        extend_gcd(b , temp ,y ,x);
        div(a,b,temp,t);//temp=a/b;
        mul(x,temp,t);//t = x*temp;
        sub(y,t,temp);//temp = y-t;
        y = temp;
    }
}
void inverse(const BigInt &a ,const BigInt &b ,BigInt &ans)
{
    BigInt y;
    extend_gcd(a,b,ans,y);
    printf("gcd:");
    print(GCD);
    if(GCD.len==1 && GCD.sig && GCD.num[0]==1)
    {
        if(! ans.sig)//若乘法逆小于0，则加上模数
        {
            add(ans,b,y);
            ans = y;
        }
    }else printf("两数不互素，没有乘法逆！\n");

}
