#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define int long long
#define N 3000006
int arr[N];

int binarysearch(int low,int high,int x)
{
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid] == x)
		{
			return mid;
		}
		if(arr[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int findpivot(int low,int high)
{
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid] > arr[mid-1])return mid;

		if(arr[mid] > arr[0])
		{
			low = mid + 1;
		}
		else
		{
			high = mid + 1;
		}
	}
}
int32_t main()
{	

	int n;
	scanf("%lld",&n);

	for(int i = 0;i < n; i++)
	{
		scanf("%lld",&arr[i]);
	}

	int pivotpos = findpivot(0,n-1);
	int pivot = arr[pivotpos];


	int x;
	scanf("%lld",&x);
		
		int ans;
	if(arr[0] <= x && x <= pivot)
	{
		ans = binarysearch(0,pivotpos,x);
	}
	else
	{
		ans = binarysearch(pivotpos+1,n-1,x);
	}

	if(ans == -1)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	printf("%lld",ans);


	return 0;
}

