#include <stdio.h>
#include <string.h>
int main()
{

    // int size;
    // scanf("%d", &size);

    // int a[size];
    // int freq_array[100]={0};

    // for (int i = 0; i < size; i++)
    // {
    //     // your code
    //     scanf("%d", &a[i]);
    // }

    // for (int i = 0; i < size; i++)
    // {
    //    freq_array[a[i]]++;
    // }

    // // for (int i = 0; i < size; i++)
    // // {
    // //     // your code
    // //     printf("%d ", a[i]);
    // // }



    // //print frequecy array 

    // for(int i=0;i<size;i++){
    //         printf("%d appears = %d  times\n",a[i],freq_array[a[i]]);
    //     }




    char s[10001];
    // scanf("%s",&str);
    fgets(s,10001,stdin);
    // printf("%s\n",s);


    int freq_array[123]={0};
    // int z = (int)'a';

    // printf("%d",z);  // 97 + 122
    // printf("%d",strlen(str));

    int size = strlen(s);
    for(int i=0;i<size;i++)
    {
        // char chrct = s[i];
        // int ascii = (int)chrct;
        freq_array[(int)s[i]]++;
        // printf("%d\n",ascii);
    }


    // print frequency array 

    for(int i='a';i<='z';i++)
    {
        if(freq_array[i]!=0){
            printf("%c - %d\n",(char)i,freq_array[i]);

        }
        

    }
    






    return 0;
}