class Solution {
    public int[] twoSum(int[] nums, int target) {
         //brute force approach
        // for(int  i = 0; i < nums.length ; i++){
        //     for(int j=i+1; j<nums.length; j++){
        //         if(nums[i]==target-nums[j]){
        //             return  new int[]{i,j};
        //         }
        //     }
        // }
        // return null;
        
        //second approach (using map)
        Map<Integer,Integer>map= new HashMap<>();
        for(int i=0;i<nums.length;i++){
                map.put(nums[i], i);
        }
        for(int i=0;i<nums.length;i++){
            int remain=target-nums[i];

            if(map.containsKey(remain) && map.get(remain)!=i){
                return new int[] {i,map.get(remain)};
            }
        }

return null;

    }
        
    };