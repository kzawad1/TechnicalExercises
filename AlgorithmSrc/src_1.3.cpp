#include <stdio.h>
#include <string>

void URLify(char * pcInput)
{
    unsigned int uiStrLen;
    unsigned int uiIndexDst = 0;
    bool bFlagPerformCopy = false;
    char * pcStrDst = 0;

    if (0 != pcInput)
    {
        // Determine the size of input string
        uiStrLen = strlen(pcInput);

        // Allocate the max needed size
        pcStrDst = (char*)malloc( ((3*uiStrLen)+1)*sizeof(char) );
        if (0 != pcStrDst)
        {
            // Clear the memory, make it all null
            memset(pcStrDst, 0, ((3 * uiStrLen) + 1) * sizeof(char));

            // Loop through all characters and check for spaces to replace
            for (unsigned int uiIndex = 0; uiIndex < uiStrLen; uiIndex++)
            {
                if (' ' == pcInput[uiIndex])
                {
                    pcStrDst[uiIndexDst] = '%';
                    pcStrDst[uiIndexDst+1] = '2';
                    pcStrDst[uiIndexDst+2] = '0';
                    uiIndexDst += 2;

                    // Insert a character, so copy will be needed
                    bFlagPerformCopy = true;
                }
                else
                {
                    pcStrDst[uiIndexDst] = pcInput[uiIndex];
                }

                uiIndexDst++;
            }

            // Now, copy over new buffer if inserts have been made
            if (bFlagPerformCopy)
            {
                for (unsigned int uiIndex = 0; uiIndex < uiIndexDst; uiIndex++)
                {
                    pcInput[uiIndex] = pcStrDst[uiIndex];
                }
                pcInput[uiIndexDst] = '\0';
            }

            free(pcStrDst);
            pcStrDst = 0;
        }
    }
}

int main_13(int argc, char* argv[])
{
    bool bReturn;
    std::string str1 = "Mr John Smith";
    unsigned int uiStrLen = str1.size();
    unsigned int uiMaxSize = ( ( (3*uiStrLen) + 1) * sizeof(char));

    // Allocate the max amount of memory for the string
    char * pcStr1 = (char *)malloc(uiMaxSize);
    if (0 != pcStr1)
    {
        // Set all the memory to null
        memset(pcStr1, 0, uiMaxSize);

        // Place the string in the max buffer
        memcpy(pcStr1, str1.c_str(), uiStrLen);

        // Now, call the URL-ify function
        URLify(pcStr1);

        // Finally, print the input & output
        printf("Input: \"%s\", %d\n", str1.c_str(), uiStrLen);
        printf("Output: \"%s\"", pcStr1);

        free(pcStr1);
    }

    return 0;
}
