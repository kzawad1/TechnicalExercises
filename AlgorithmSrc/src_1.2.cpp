#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

bool isPermutation(std::string & str1, std::string & str2)
{
    bool bReturn = true;

    if (str1.size() == str2.size())
    {
        //std::unordered_set<char *> usStr1 = { std::begin(str1.c_str()), std::end(str1.c_str()) };
        char *pcStr1 = (char *)str1.c_str();
        char *pcStr2 = (char *)str2.c_str();
        std::vector<char> vcStr1;
        std::vector<char> vcStr2;

        // Convert the string into a character set
        for (unsigned int uiIndex = 0; uiIndex < str1.size(); uiIndex++)
        {
            vcStr1.push_back(*pcStr1);
            vcStr2.push_back(*pcStr2);
            pcStr1++;
            pcStr2++;
        }

        // Sort both vecrtors
        std::sort(vcStr1.begin(), vcStr1.end());
        std::sort(vcStr2.begin(), vcStr2.end());

        for (unsigned int uiIndex = 0; uiIndex < str1.size(); uiIndex++)
        {
            printf("usStr1[%d]: %c, usStr2[%d]: %c \n", uiIndex, vcStr1[uiIndex], uiIndex, vcStr2[uiIndex]);

            if (vcStr1[uiIndex]  == vcStr2[uiIndex])
            {
                // Just ignore, characters are the same
            }
            else
            {
                // Characters are not the same
                bReturn = false;
                break;
            }
        }
    }
    else
    {
        bReturn = false;
    }

    return bReturn;
}

int main_12(int argc, char* argv[])
{
    bool bReturn;
    std::string str1 = "abcd";
    std::string str2 = "dcba";
    std::string str3 = "fagg";

    bReturn = isPermutation(str1, str2);
    printf("bReturn: %d (true=%d, false=%d)\n", bReturn, true, false);

    bReturn = isPermutation(str1, str3);
    printf("bReturn: %d (true=%d, false=%d)\n", bReturn, true, false);

    return 0;
}
