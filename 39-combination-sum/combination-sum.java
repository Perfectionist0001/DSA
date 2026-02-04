class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answer = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        helper(0,target,temp,candidates, answer,candidates.length);
        return answer;
    }
    public void helper(int index, int target, ArrayList<Integer> list , int[] candidates, List<List<Integer>> ans,int n){
        if(index == n){
            if(target == 0){
                ans.add(new ArrayList<>(list));
            }
            return ;
        }
        if(candidates[index]<=target){
            list.add(candidates[index]);
            helper(index,target-candidates[index],list,candidates,ans,n);
            list.remove(list.size()-1);
        }
        helper(index+1,target,list,candidates,ans,n);
    }
}