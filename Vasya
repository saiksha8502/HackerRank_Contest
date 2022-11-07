def merge(start,mid,end,a):
    arr = [0] * (end-start+1)
    p=start
    q=mid+1
    k=0
    i=0
    
    for i in range(start,end+1):
        if p > mid:
            arr[k]=a[q]
            q+=1
        elif ( q > end):
            arr[k]=a[p]
            p+=1
        elif(a[p]>a[q]):
            arr[k]=a[p]
            p+=1
        else:
            arr[k]=a[q]
            q+=1
        k+=1
    
    for i in range(start,end+1):
        a[i]=arr[i-start]

def mergesort(start,end,a):
    if start<end:
        mid=(start+end)//2
        mergesort(start,mid,a)
        mergesort(mid+1,end,a)
        
        merge(start,mid,end,a)
    
t = int(input())
l = 0

while l<t:
    n = int(input())
    a = list(map(int,input().split()))
    start=0
    end=n-1
    mergesort(start,end,a)
    for i in range(n):
        print(a[i],end=" ")
    print()
    l+=1
