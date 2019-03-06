#include"BigInteger.h"
void tenint_to_bi(const long n ,BigInt &s)//��ʮ����int�洢��nת��Ϊ������
{
    if(n < 0)
        s.sig = false;
    else s.sig = true;
    long t = n ,i = 0;
    while(t)
    {
        s.num[i++] = t%10;
        t /= 10;
    }
    s.len = i;
}
bool is_one(const BigInt n)//��n=1���򷵻���
{
    if(n.len==1 && n.sig && n.num[0]==1)
        return true;
    return false;
}
bool Miller_Rabin(const BigInt n)
{
    long A = rand();
    //printf("\nA:%d\n" ,A);
    BigInt a ,temp1 ,n_1;
    fuzhi1(temp1);//temp1=1;
    tenint_to_bi(A ,a);//��Aת��Ϊ������
    sub(n,temp1,n_1);//n_1=n-temp1=n-1;
    pow_mod(a,n_1,n,temp1);//temp1=a^n_1%n;
    //printf("pow_mod:");
    //print(temp1);
    if(is_one(temp1))
        return true;
    return false;
}
