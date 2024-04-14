#include<stdio.h>
#include<stdlib.h>

void sort(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
        for(j=0;j<n-i;j++)
            if(a[j]>a[j+1])
                {
                    t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
}

int search(int a[],int n,int head)
{
    int i;
    for(i=0;i<n;i++)
        {
            if(head < a[i])
                return i;
        }
    return -1;
}

int CSCAN(int request[], int n, int head, int direction,int size)
{
	int seek_count = 0;
	int distance, cur_track;	
    int seek_sequence[200],index,i,j=0;
	
    sort(request,n);

    index = search(request,n,head);


	// if movement is towards right/high value
	if(direction==1)
	{
 		for(i=index;i<n;i++)
 			{
 			seek_count=seek_count+abs(request[i]-head);
			seek_sequence[j++] = request[i];
 			head=request[i];
 			}
		// last movement for max size
 		seek_count=seek_count+abs(request[i-1]-(size-1));
 		head = size-1;

        /*movement max to min disk */
        // seek_count = seek_count + abs(size-1-0);
        seek_count = seek_count + 0;
        head = 0;
        
        for(i=0;i<index;i++)
 			{
 			seek_count=seek_count+abs(request[i]-head);
			seek_sequence[j++] = request[i];
 			head=request[i];
			}
 	}
 	// if movement is towards left/low value
	else
	{ 
		for(i=index-1;i>=0;i--)
			{
			seek_count=seek_count+abs(request[i]-head);
			seek_sequence[j++] = request[i];
			head=request[i];
			}
		// last movement for min size
		seek_count=seek_count+abs(request[i+1]-0);
		head = 0;

        /*movement min to max disk */
        // seek_count = seek_count + abs(size-1-0);
        seek_count = seek_count + 0;
        head = size-1;

		for(i=n-1;i>=index;i--)
			{
			seek_count=seek_count+abs(request[i]-head);
			seek_sequence[j++] = request[i];
			head=request[i];
			}
	}
	printf("Seek Sequence is ");
	for (i = 0; i < j; i++)
		printf("%d\n",seek_sequence[i]);
    return seek_count;
}

// Driver code
int main()
{
    // int request[100];
    // int head;

    int i,n,seek_cnt,direction,size;

    // request array
	int request[] = { 176, 79, 34, 60, 92, 11, 41, 114 };
	int head = 50;

    printf("\nEnter number of request:");
    scanf("%d",&n);

    printf("Enter total disk size\n");
    scanf("%d",&size);
 
	// printf("\nEnter disk request string:");
    // for(i=0;i<n;i++)
    //     scanf("%d",&request[i]);

    // printf("\nEnter current head position:");
    // scanf("%d",&head);

    printf("\nEnter sequence:(0:left,1:right)");
    scanf("%d",&direction);

    seek_cnt = CSCAN(request, n, head, direction,size);

    printf("\nTotal Number of head movement : %d",seek_cnt);

	return 0;
}
