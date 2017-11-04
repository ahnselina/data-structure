#include <stdio.h>

int max_subsequence_sum(int list[], int n);

int main(void)
{
    int n;
    //printf("please enter a num\n");
    scanf("%d", &n);
    int array[n];
    int i=0;
    for(; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int result = max_subsequence_sum(array, n);
    printf("%d\n", result);

    return 0;
}


int max_subsequence_sum(int list[], int n)
{
    int max_sum = 0;
    int this_sum = 0;
    int i=0;
    for(; i<n; i++)
    {
        this_sum += list[i];

        if (this_sum > max_sum)
        {
            max_sum = this_sum;
        }

        if (this_sum < 0)
        {
            this_sum = 0;
        }
    }

    return max_sum;
}
