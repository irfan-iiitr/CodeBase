void merge(int arr[], int low, int mid, int high)
    {
        vector<int> temp;
        
        int left=low;
        int right=mid+1;
        
        while(left<=mid and right<=high)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        
        
        
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        
         // Your code here
    }






    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
       if(l>=r)
       return;
       
           int m=l + (r-l)/2;
           mergeSort(arr,l,m);
           mergeSort(arr,m+1,r);
           
           merge(arr,l,m,r);
      
    }