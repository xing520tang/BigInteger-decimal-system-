/*
�������һ������Ϊlen�Ĵ�����
*/
#include"BigInteger.h"
bool mod_prime(BigInt &n)//��������nģǰprime_num������������ͨ�����ԣ��򷵻�true
{
    BigInt temp ,ans;
    for(int i = 0 ; i < prime_num ; i++)
    {
        tenint_to_bi(PRIME[i] ,temp);//��rime[i]ת��Ϊ������
        mod(n,temp,ans); //ans = n%temp
        if(is_zero(ans))
            return false;
    }
    return true;
}
void generate_prime(BigInt &ans ,int len)//����1��������������ans��
{
    generate_num(ans ,len);//���������һ������ans
    while(1)
    {
        if(mod_prime(ans) && Miller_Rabin(ans))
            break;
        generate_num(ans ,len);
    }
}
