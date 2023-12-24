#include <stdio.h>
#include <string.h>


int partition(char arr[], int left, int right)
{
    int pivot = arr[right];
    int low = left - 1;
    for (int p = left; p < right; ++p)
    {
        if (arr[p] < pivot)
        {
            low++;
            if (low < p)
            {
                int temp = arr[p];
                arr[p] = arr[low];
                arr[low] = temp;
            }
        }
    }
    arr[right] = arr[low + 1];
    arr[low + 1] = pivot;
    return low + 1;
}

void sort(char arr[], int left, int right)
{
    if (left < right)
    {
        int poi = partition(arr, left, right);

        sort(arr, left, poi - 1);
        sort(arr, poi + 1, right);
    }
}
void function(char str[])
{
    strlwr(str);
    int l1 = strlen(str);
    sort(str, 0, l1 - 1);
    if (l1 < 26)
    {
        printf("NO");
        return;
    }
    else
    {

        for (int p = 1; p < l1; ++p)
        {
            if (str[p] - str[p - 1] > 1){
            
                printf("NO");
                return;
            }
        }
        if (str[l1 - 1] == 'z' && str[0] == 'a')
        {
            printf("YES");
        }
        else{
           printf("NO");
        }
    }
}

int main(void)
{
    int number;
    scanf("%d",&number);

    char str[number];
    scanf("%s",str);
    function(str);
    return 0;
}