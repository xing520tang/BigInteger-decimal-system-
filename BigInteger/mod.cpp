#include"BigInteger.h"
void mod(const BigInt &a , const BigInt &b ,BigInt &ans)
{
    BigInt temp;
    div(a ,b ,temp ,ans);
}
