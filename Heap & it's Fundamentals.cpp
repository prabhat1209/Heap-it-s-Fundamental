#include <iostream>
using namespace std;

void insertHeap(int A[], int n){
    int temp, i=n;
    temp = A[i];
    while( i>1 && temp>A[i/2] ){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int deleteInHeap(int A[], int n){
    int i, j, temp, val;
    val = A[1];
    A[1] = A[n];
    A[n] = val;
    i=1;
    j=2*i;
    while(j<n-1){
        if(A[j+1]>A[j])
            j++;
        if(A[i]<A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        else
            break;
    }
    return val;
}

int main()
{
    int n;
    cout<<"How many elements you wish to enter in the Heap : ";
    cin>>n;
    int H[n];
    cout<<"Enter the elements to be inserted in the Heap : \n";
    for(int i=1;i<=n;i++)
        cin>>H[i];
    for(int i=2;i<=n;i++)
        insertHeap(H, i);
    cout<<"After the elements inserted in the Heap, the arrangement is as follows : ";
    for(int i=1;i<=n;i++)
        cout<<H[i]<<" ";
    cout<<endl;
    //cout<<"The deleted element is : "<<deleteInHeap(H,n)<<endl;
    cout<<"The Heap sort is as follows : ";
    for(int i=7;i>0;i--)
        deleteInHeap(H,i);
    for(int i=1;i<=7;i++)
        cout<<H[i]<<" ";
    
    return 0;
}
