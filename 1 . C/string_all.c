#include <stdio.h>
#include <string.h>

int main()
{
    // char s[1001];
    // // fgets(s,1001,stdin);
    // scanf("%s", &s);
    // // s[strlen(s)] = '\0';
    // // printf("%s",s);
    // int flag = 0;
    // for (int i = 0, j = strlen(s) - 1; i <= strlen(s) / 2; i++, j--)
    // {
    //     // printf("%c ",s[i]);
    //     // printf("%d %d\n",i,j);

    //     printf("%c %c\n", s[i], s[j]);

    //     if (s[i] == s[j])
    //     {
    //         // printf("%c ", s[i]);
    //         flag = 1;
    //         continue;
    //     }
    //     else
    //     {
    //         flag = 0;
    //         break;
    //     }
    // }
    // // printf("%d",flag);
    // if (flag == 1)
    //     printf("YES");
    // else
    //     printf("NO");

    // scanf("%s",&s);
    // gets(s);  #doens't take enter as input
    // fgets(s,10009,stdin);  //takes enter as input

    // printf("%s",s);

    // length of string
    // int i=0;
    // int count=0;

    // while(s[i]!='\0'){
    //     // printf("%c",s[i]);
    //     count++;
    //     i++;

    // }

    // printf("%d",count);

    //  // string to interger

    // int i=0;
    // while(s[i]!='\0'){
    //     int converted = (int)s[i];
    //     printf("%d\n",converted-48);
    //     // printf("%c",s[i]);
    //     i++;
    // }

    // char str1[100];
    // char str2[100];

    // scanf("%s", &str1);
    // scanf("%s", &str2);

    // printf("%s", str2);

    // string copy

    // for (int i = 0,j=strlen(str1); i < strlen(str2);i++,j++)
    // {
    //     // printf("%c",str2[i]);
    //     str1[j] = str2[i];

    // }

    // printf("%s\n", str1);

    // string compare

    // for (int i = 0; i < strlen(str1); i++)
    // {

    //     if (str1[i] < str2[i])
    //     {
    //         printf("%s came first", str1);
    //         break;
    //     }
    //     else if (str1[i] > str2[i])
    //     {
    //         printf("%s came first", str2);
    //         break;
    //     }

    //     else
    //     {
    //         continue;
    //     }
    // }

    int test;
    scanf("%d", &test);

    while (test--)
    {

        char str[100001];
        scanf("%s", &str);

        int capital = 0;
        int small = 0;
        int digit = 0;

        for (int i = 0; i < strlen(str); i++)
        {

            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                capital++;
            }
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                small++;
            }
            if (str[i] >= '0' && str[i] <= '9')
            {
                digit++;
            }
        }
        printf("%d %d %d\n", capital, small, digit);
        // printf("%d",consonant);
    }

    return 0;
}