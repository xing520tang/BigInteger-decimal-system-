#include"BigInteger.h"
int compare(const BigInt &a ,const BigInt &b)//a>b,return 1; a=b,return 0; a<b,return -1;
{
    if(a.sig != b.sig)
    {
        if(a.sig)
            return 1;
        else return -1;
    }else {//符号位相同
        int maxlen ,pmax;
        maxlen = a.len>b.len ? a.len : b.len;
        if(a.len == b.len)
        {
            pmax = 0;//表示a的绝对值等于b的绝对值
            for(int i = a.len-1 ; i >= 0; i--)
            {
                if(a.num[i] > b.num[i])
                {
                    pmax = 1;//a的数值位大于b
                    break;
                }
                else if(a.num[i] < b.num[i])
                {
                    pmax = -1;//a的数值位小于b
                    break;
                }
            }
            if(! pmax)
                return 0;//a=b
            if(a.sig)//若a和b的符号都为正
                return pmax;
            return -pmax;
        }else {
            if(a.len > b.len)
            {
                if(a.sig)
                    return 1;
                return -1;
            }else {
                if(a.sig)
                    return -1;
                return 1;
            }
        }
    }
}
