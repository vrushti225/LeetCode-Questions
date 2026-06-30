class Solution {
    public int candy(int[] ratings) {
         //step1: cerate ans array of size n
         //step 2: fill 1 in ans array 
         //step 3: traverse left to right and updates candies if current rating is greater than previous
         //step 4:Traverse right to left and updates candies if current rating is greater than next
         //
         int n = ratings.length;

         int[] ans = new int[n];
         
         for(int i=0; i<n; i++){
         ans[i]=1;
         }
         for(int i=1; i<n; i++)
         {
           if (ratings[i]>ratings[i-1])
           {
            ans[i]=ans[i-1]+1;
           }
           
         }
         for(int i=n-2; i>=0; i--)
         {
            if( ratings[i]>ratings[i+1])
            {
                ans[i]=Math.max(ans[i],ans[i+1]+1);
            }

         }
         int sum=0;
         for(int num:ans)
         {
            sum += num;
         }
         return sum;

    }
}
        
