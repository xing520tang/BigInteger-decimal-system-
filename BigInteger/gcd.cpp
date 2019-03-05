#include"BigInteger.h"
bool is_zero(const BigInt &a)
{
    if(a.num[0]==0 && a.len==1)
        return true;
    return false;
}
void gcd(const BigInt &a ,const BigInt &b ,BigInt &ans)
{
    if(is_zero(b))
    {
        ans = a;
        return ;
    }
    BigInt temp ;
    mod(a,b,temp);
    gcd(b ,temp ,ans);
}
