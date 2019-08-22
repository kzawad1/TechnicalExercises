#include <stdio.h>
#include <string>

void URLify_scan(char* pcInput)
{
    unsigned int uiStrLen;
    unsigned int uiSpaceCharCount = 0;
    int iIndexDst = 0;

    if (0 != pcInput)
    {
        uiStrLen = strlen(pcInput);

        // Next determine how many spaces
        for (unsigned int uiIndex = 0; uiIndex < uiStrLen; uiIndex++)
        {
            if (' ' == pcInput[uiIndex])
            {
                uiSpaceCharCount++;
            }
        }

        // First, check if there are any space characters to replace
        if (uiSpaceCharCount)
        {
            // There are spaces, so determine where to start from the end
            iIndexDst = (uiStrLen - 1) + (2*uiSpaceCharCount);

            // Now, starting from end, perform substitution
            for (int iIndex = (uiStrLen - 1); iIndex >= 0; iIndex--)
            {
                if (' ' == pcInput[iIndex])
                {
                    printf(" pcInput[iIndex=%2d]: %c | pcInput[iIndexDst=%2d]: %c\n", iIndex, pcInput[iIndex], iIndexDst, '0');
                    printf(" pcInput[iIndex=%2d]: %c | pcInput[iIndexDst=%2d]: %c\n", iIndex, pcInput[iIndex], iIndexDst, '2');
                    printf(" pcInput[iIndex=%2d]: %c | pcInput[iIndexDst=%2d]: %c\n", iIndex, pcInput[iIndex], iIndexDst, '%');

                    pcInput[iIndexDst--] = '0';
                    pcInput[iIndexDst--] = '2';
                    pcInput[iIndexDst] = '%';
                    
                }
                else
                {
                    pcInput[iIndexDst] = pcInput[iIndex];

                    printf(" pcInput[iIndex=%2d]: %c | pcInput[iIndexDst=%2d]: %c\n", iIndex, pcInput[iIndex], iIndexDst, pcInput[iIndexDst]);
                }
                
                iIndexDst--;
            }
        }
    }
}

int main_13_scan(int argc, char* argv[])
{
    std::string str1 = "Mr John Smith";
    unsigned int uiStrLen = str1.size();
    unsigned int uiMaxSize = (((3 * uiStrLen) + 1) * sizeof(char));

    // Allocate the max amount of memory for the string
    char* pcStr1 = (char*)malloc(uiMaxSize);
    if (0 != pcStr1)
    {
        // Set all the memory to null
        memset(pcStr1, 0, uiMaxSize);

        // Place the string in the max buffer
        memcpy(pcStr1, str1.c_str(), uiStrLen);

        // Now, call the URL-ify function
        URLify_scan(pcStr1);

        // Finally, print the input & output
        printf("Input: \"%s\", %d\n", str1.c_str(), uiStrLen);
        printf("Output: \"%s\"", pcStr1);

        free(pcStr1);
    }

    return 0;
}
