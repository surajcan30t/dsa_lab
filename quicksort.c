#include<stdio.h>
void display(int arr[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low+1, j = high, temp;
    do{
        while(arr[i]<=pivot)
           i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
        {
            temp= arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);

    temp = arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}


void quicksort(int arr[],int low, int high)
{
    int pi;
    if(low<high)
    {
        pi=partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}


int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    int i;
    printf("enter array elements:\n");
    for(i =0; i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("entered array is : ");
    display(arr,n);
    quicksort(arr,0,n);
    printf("\n\nSorted array is :");
    display(arr,n);
    return 0;
}
