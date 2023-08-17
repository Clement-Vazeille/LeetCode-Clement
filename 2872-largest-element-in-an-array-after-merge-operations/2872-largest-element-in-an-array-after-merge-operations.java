class Solution {
    public long maxArrayValue(int[] nums) {
        int n=nums.length;
        long max=0;
        long actuel=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<=actuel)
            {
                actuel+=nums[i];
            }
            else{actuel=nums[i];}
            max=Math.max(actuel,max);
        }
        return max;
    }
}