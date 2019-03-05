#include"BigInteger.h"
void ten_to_bi(const char *s ,BigInt &p)
{
    int len = strlen(s) ,bound;
    p.len = len;
    if(s[0] == '-')
    {
        p.sig = false;
        bound = 1;
        p.len = len-1;
    }else {
        p.sig = true;
        bound = 0;
    }
    for(int i = len-1 ,j = 0; i >= bound; i-- ,j++)
        p.num[j] = s[i]-'0';
}
