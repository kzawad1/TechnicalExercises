#include <stdio.h>
#include <string.h>
#include <unordered_set>

bool isUniqueViaHash(const char* pcStr)
{
    bool bRet = true;

    if (0 != pcStr)
    {
        unsigned int uiStrLen = strlen(pcStr);
        if (uiStrLen > 128)
        {
            // In ASCII there is only 128 characters.
            // More characters means automtic duplication
            bRet = false;
        }
        else
        {
            std::unordered_set<unsigned char> list; // A hash table of sorts with O(1)

            // Loop for the entire string
            for (unsigned int uiIndex = 0; uiIndex < uiStrLen; uiIndex++)
            {
                
                unsigned char uiChar = pcStr[uiIndex];
                if (list.find(uiChar) != list.end())
                {
                    // Found, the character
                    bRet = false;
                    break;
                }
                else
                {
                    // Did not find the character, so insert it
                    list.insert(uiChar);
                }
            }
        }
    }

    return bRet;
}

void testHash(void)
{
    bool bRet;
    const char* pcStr1 = "This is a test.";
    const char* pcStr2 = "abcdefghijklmnop.";

    bRet = isUniqueViaHash(pcStr1);
    printf("bRet: %d (true=%d, false=%d)\n", bRet, true, false);

    bRet = isUniqueViaHash(pcStr2);
    printf("bRet: %d (true=%d, false=%d)\n", bRet, true, false);
}

int main_11_hash(int argc, char* argv[])
{
    testHash();

    return 0;
}
