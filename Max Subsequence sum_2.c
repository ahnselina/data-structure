#include <stdio.h>

int max_subsequence_sum(int A[], int N);

int main(void)
{
    int n;
    //printf("please input a num\n");
    scanf("%d", &n);

    int array[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int result = max_subsequence_sum(array, n);
    printf("%d", result);
    return 0;
}

int max_subsequence_sum(int A[], int N)
{
    int i, j, this_sum, max_sum;
    max_sum = 0;
    for(i = 0; i < N; i++)
    {
        this_sum = 0;
        for(j = i; j < N; j++)
        {
            this_sum += A[j];
            if(this_sum > max_sum)
            {
                max_sum = this_sum;
            }
        }
    }
    return max_sum;
}
