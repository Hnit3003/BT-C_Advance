

#include<stdio.h>
#include<stdlib.h>

typedef struct STRING_Struct
{
    int size;
    char *letter;
}STR;

STR STRING_Enter()
{
    STR STRING;
    char STRING_Buf[100];
    int lenght = 0;
    printf("Enter the String: \n");
    gets(STRING_Buf);
    fflush(stdin);
    while(STRING_Buf[lenght] != '\0')
    {
        lenght++;
    }

    STRING.size = lenght;
    STRING.letter = (char *)malloc(STRING.size * sizeof(char)); 

    int i=0;
    for(int i = 0; i < STRING.size; i++)
    {
        STRING.letter[i] = STRING_Buf[i];
    }

    
    return STRING;
}

void SUBSTRING_Search(STR String, STR SubString)
{
    int count=0, STR_Count=0, SUBSTR_Count=0;
    while(String.letter[STR_Count] != '\0')
    {
        if(String.letter[STR_Count] == SubString.letter[SUBSTR_Count])
        {
            while ((String.letter[STR_Count] == SubString.letter[SUBSTR_Count]) && (String.letter[STR_Count] != '\0'))
            {
                STR_Count++;
                SUBSTR_Count++;
            }
            if((SUBSTR_Count == SubString.size) && ((String.letter[STR_Count] == ' ') || (String.letter[STR_Count] == '\0')))
            {
                count++;
            }
            
        }else
        {
            while(String.letter[STR_Count] != ' ')
            {
                STR_Count++;
                if(String.letter[STR_Count] == '\0')
                break;
            }
        }
        STR_Count++;
        SUBSTR_Count = 0;
    }
    if(count == 0)
    {
        printf("The Sub String doesn't appear in the String");
    }else
    {
        printf("The Sub String appear %d times in the String", count);
    }
}

int main(int argc, char const *argv[])
{
    STR STRING;
    STR SUBSTRING;

    STRING = STRING_Enter();
    SUBSTRING = STRING_Enter();

    SUBSTRING_Search(STRING, SUBSTRING);

    return 0;
}
