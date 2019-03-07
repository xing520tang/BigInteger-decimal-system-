/*
随机生成一个长度为len的大素数
*/
#include"BigInteger.h"
bool mod_prime(BigInt &n)//将大整数n模前prime_num个素数，若都通过测试，则返回true
{
    BigInt temp ,ans;
    for(int i = 0 ; i < prime_num ; i++)
    {
        tenint_to_bi(PRIME[i] ,temp);//将rime[i]转换为大整数
        mod(n,temp,ans); //ans = n%temp
        if(is_zero(ans))
            return false;
    }
    return true;
}
void generate_prime(BigInt &ans ,int len)//生成1个大素数，存入ans中
{
    generate_num(ans ,len);//先随机生成一个大数ans
    while(1)
    {
        if(mod_prime(ans) && Miller_Rabin(ans))
            break;
        generate_num(ans ,len);
    }
}
