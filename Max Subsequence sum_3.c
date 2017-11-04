#include <stdio.h>

int max_subsequence_sum(int list[], int n);

int main(void)
{
    int n;
    //printf("please enter a num:\n");
    scanf("%d", &n);
    int array[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int result = max_subsequence_sum(array, n);
    printf("%d\n", result);

    return 0;
}


static int max3(int a, int b, int c)
{
    int max = 0;
    max = a>b?a:b;
    max = max>c?max:c;
    return max;
}

static int max_sub_sum(const int A[], int left, int right)
{
    int max_left_sum, max_right_sum;
    int max_left_border_sum, max_right_border_sum;
    int left_border_sum, right_border_sum;
    int center, i;

    if(left == right)
    {
        if(A[left] > 0)
        {
            return A[left];
        }
        else
        {
            return 0;
        }
    }

    center = (left + right) / 2;
    max_left_sum = max_sub_sum(A, left, center);
    max_right_sum = max_sub_sum(A, center+1, right);

    max_left_border_sum = 0;
    left_border_sum = 0;
    for(i = center; i >=  left; i--)
    {
        left_border_sum += A[i];
        if(left_border_sum > max_left_border_sum)
        {
            max_left_border_sum = left_border_sum;
        }
    }

    max_right_border_sum = 0;
    right_border_sum = 0;
    for(i = center + 1; i <= right; i++)
    {
        right_border_sum += A[i];
        if(right_border_sum > max_right_border_sum)
        {
            max_right_border_sum = right_border_sum;
        }
    }

    return max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}

int max_subsequence_sum(int A[], int N)
{
    return max_sub_sum(A, 0, N-1);
}
