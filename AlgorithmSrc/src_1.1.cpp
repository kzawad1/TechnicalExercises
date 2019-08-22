#include <stdio.h>
#include <string.h>

bool isUnique(const char* pcStr)
{
    unsigned char ucCharCounter[128] = { 0 }; // Create and array for all 128 ASCII characters 
    bool bRet = true;

    if (0 != pcStr)
    {
        unsigned int uiStrLen = strlen(pcStr);
        if (uiStrLen > 128)
        {
            // String has repetitive characters because more than 128 characters
            bRet = false;
        }
        else
        {
            char *pcCurrCharAddr = (char*)pcStr;

            // Loop for the entire character array until reach end null character
            while ('\0' != *pcCurrCharAddr)
            {
                unsigned char ucIndex = *pcCurrCharAddr;
                if (ucIndex < 128)
                {
                    if (0 == ucCharCounter[ucIndex])
                    {
                        // Do nothing, first occurence of this character
                    }
                    else
                    {
                        bRet = false;
                        break;
                    }

                    ucCharCounter[ucIndex]++;
                    pcCurrCharAddr++;
                }
                else
                {
                    // Does not meet assumption, character is not ASCII
                }
            }
        }
    }

    return bRet;
}

void test(void)
{
    bool bRet;
    const char* pcStr1 = "This is a test.";
    const char* pcStr2 = "abcdefghijklmnop.";

    bRet = isUnique(pcStr1);
    printf("bRet: %d (true=%d, false=%d)\n", bRet, true, false);

    bRet = isUnique(pcStr2);
    printf("bRet: %d (true=%d, false=%d)\n", bRet, true, false);
}


int main_11(int argc, char* argv[])
{
    test();
    
    return 0;
}