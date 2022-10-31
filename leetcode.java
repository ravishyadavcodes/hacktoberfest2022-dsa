Find Original Array From Doubled Array


class Solution {
    public int[] findOriginalArray(int[] changed) {
        int n = changed.length;
        if(n%2 != 0) return new int[]{};
        
        int[] ans = new int[n/2];
        int[] count = new int[100001];
        for(int i=0; i<n; i++){
            count[changed[i]]++;
        }
        
        int k=0;
        for(int i=0; i<count.length; i++){
            while(count[i] > 0 && i*2 < 100001 && count[i*2] > 0){
                ans[k++] = i;
                count[i]--;
                count[i*2]--;
            }
        }
        
        for(int i=0; i<count.length; i++){
            if(count[i] != 0) return new int[]{};
        }
        
        return ans;
    }
}
