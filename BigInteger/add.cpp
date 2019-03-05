#include"BigInteger.h"
void add(const BigInt &a,const BigInt &b ,BigInt &ans)
{
    const BigInt *pmax = &a ;
    if(a.sig == b.sig)
    {
        int lenmin=b.len ,lenmax=a.len;
        if(a.len < b.len)
        {
            lenmin = a.len;
            lenmax = b.len;
            pmax = &b;
        }
        ans.len = lenmax;
        ans.sig = a.sig;
        char carry = 0;
        int i = 0;
        for(; i < lenmin ; i++)
        {
            ans.num[i] = a.num[i]+b.num[i]+carry;
            if(ans.num[i] > 9)
            {
                ans.num[i] -= 10;
                carry = 1;
            }else carry = 0;
        }
        for(; i < lenmax ;i++)
        {
            ans.num[i] = pmax->num[i]+carry;
            if(ans.num[i] > 9)
            {
                ans.num[i] -= 10;
                carry = 1;
            }else carry = 0;
        }
        if(carry == 1)
        {
            ans.num[i] = 1;
            ans.len = lenmax+1;
        }
    }else {//否则两个数一正一负
        BigInt temp = b;
        temp.sig = !b.sig;
        sub(a ,temp ,ans);
    }
}
