#include <stdio.h>

int max_subsequence_sum(int list[], int n);

int main(void)
{
    int n;
    printf("please enter a num\n");
    scanf("%d", &n);
    int array[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int result = max_subsequence_sum(array, n);
    printf("%d\n", result);
}

int max_subsequence_sum(int list[], int n)
{
    int this_sum, max_sum, i, j, k;
    max_sum = 0;
    for(i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            this_sum = 0;
            for(k = i; k<= j; k++)
            {
                this_sum += list[k];
            }
            if(this_sum > max_sum)
            {
                max_sum = this_sum;
            }
        }
    }
    return max_sum;
}
