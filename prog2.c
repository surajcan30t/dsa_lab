#include<stdio.h>
int lsearch();
int bsearch();

int main()
{
    int arr[10],i,n,size;
    int l=0;
    printf("Enter size of the array:\n");
    scanf("%d",&size);
    int h = size-1;
    printf("Enter elements of the array in sorted order:\n");
    for(i = 0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&n);
    printf("searched using recursive linear search\n");
    int ans1 = lsearch(arr,size,n);
    printf("%d is at the position %d\n",n,ans1);
    printf("searched using recursive binary search\n");
    int ans2 = bsearch(arr,0,h,n);
    printf("%d is at the position %d\n",n,ans2);


    return 0;
}

int lsearch(int arr[],int size, int n)
{
    if(arr[size]==n)
    {
        return size;
    }
    return lsearch(arr,size-1,n);

}

int bsearch(int arr[],int l, int h, int n)
{
    int mid = (l+h)/2;
    if(l<=h)
    {
        if(arr[mid]==n)
        {
            return mid;
        }
        else if(arr[mid]>n)
        {
            h = mid-1;
            return bsearch(arr, l, h, n);
        }
        else if(arr[mid]>n)
        {
            l = mid+1;
            return bsearch(arr, l, h, n);
        }
        else
            return -1;
    }
}
