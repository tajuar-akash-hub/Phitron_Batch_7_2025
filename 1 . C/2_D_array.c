#include <stdio.h>
#include <stdbool.h>

void check_diagonal_matrix(int row_size, int column_size, int a[row_size][column_size])
{
    // primary diagonal

    // logic : sqare matrix firs,and then values except diagonal need to be 0 : a[1][1] a[2][2] are diagonal
    bool primary_diagonal = false;
    bool secondary_diagonal = false;

    if (row_size == column_size)
    {
        bool primary_loop_stop = false;

        for (int i = 0; i < row_size && primary_loop_stop == false; i++)
        {
            for (int j = 0; j < column_size; j++)
            {
                if (i != j)
                {
                    // printf("i = %d  j = %d\n",i,j);

                    if (a[i][j] == 0)
                    {
                        primary_diagonal = true;
                        continue;
                    }

                    else
                    {
                        primary_diagonal = false;
                        primary_loop_stop = true;
                        break; 
                    // break is for to help to close j for moving to the i loop's condition

                    }
                }
            }
            // if(diagonal==false) break;
            // printf("\n");
        }

        // seconary diagonal 
        //diagonally i+j == row-1 (index starts from 0)
       

        bool secondary_loop_stop =  false;

        for (int i = 0; i < row_size && secondary_loop_stop == false; i++)
        {
            for (int j = 0; j < column_size; j++)
            {
                if ((i+j) != row_size-1)
                {
                    // printf("i = %d  j = %d\n",i,j);
                    // printf("inside if value %d\n",a[i][j]);

                    if (a[i][j] == 0)
                    {
                        // printf("inside if %d\n",a[i][j]);
                        secondary_diagonal = true;
                        continue;
                    }

                    else
                    {
                        // printf("else %d\n",a[i][j]);
                        secondary_diagonal = false;
                        secondary_loop_stop = true;
                        break;
                    }
                }
            }
            // if(secondary_diagonal==false) break;
            // printf("\n");
        }
    }

    else
    {
        primary_diagonal = false;
        secondary_diagonal = false;
    }

    if (primary_diagonal == true)
        printf("Primary Diagonal\n");

    if (primary_diagonal == false)
        printf("not primary Diagonal\n");

    if (secondary_diagonal == true)
        printf("Secondary Diagonal\n");

    if (secondary_diagonal == false)
        printf("not secondary Diagonal\n");

    // secondary diagonal  logic : i+j = row (diagonal values)
}

void two_d_array_output(int row_size, int column_size, int a[row_size][column_size])
{
    printf("printing from the function\n");

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < column_size; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void two_D_array_input()
{
    int row_size, column_size;
    scanf("%d %d", &row_size, &column_size);

    int a[row_size][column_size];

    // take input
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < column_size; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // output
    two_d_array_output(row_size, column_size, a);
    // print_only_row(row_size,column_size,a);
    // print_only_column(row_size,column_size,a);

    // output array

    // for (int i = 0; i < row_size; i++)
    // {
    //     for (int j = 0; j < column_size; j++)
    //     {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    // check diagonal or not

    check_diagonal_matrix(row_size, column_size, a);
}

void print_only_row(int row_size, int column_size, int a[row_size][column_size])
{
    printf("printing only row\n");

    for (int i = 0; i < column_size; i++)
    {
        printf("%d ", a[0][i]);
    }
}

void print_only_row(int row_size, int column_size, int a[row_size][column_size])
{
    printf("printing only row\n");

    for (int i = 0; i < column_size; i++)
    {
        printf("%d ", a[0][i]);
    }
}

int main()
{
    // int a[2][2]={
    //     {1,2},
    //     {3,4}
    // };

    // printf("%d",a[1][0])  ;

    // // for(int i=0;i<2;i++){

    // // }
    two_D_array_input();

    return 0;
}