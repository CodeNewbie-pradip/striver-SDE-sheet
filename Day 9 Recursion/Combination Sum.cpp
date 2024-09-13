/*
Leetcode Link               : 
Leetcode difficulty         : Medium
Leetcode Related Topic      : 
Medium Article Link	        : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Backtracking
//T.C       : O(2^T) T-target value
//S.C       : O(T)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, int i, vector<int>& subSeq)
    {
        if(i==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(subSeq);
            }
            return;
        }
        
        if(candidates[i]<=target)
        {
            subSeq.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, i, subSeq);
            subSeq.pop_back();
        }
        solve(candidates, target, ans, i+1, subSeq);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>subSeq;
        solve(candidates, target, ans, 0, subSeq);
            return ans;
    }
};

//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Optimized solution- (By sorting the candidates array before the 
//                                 backtracking starts, we can prune the search 
//                                 space early. If the current candidate exceeds the 
//                                 remaining target, we skip the recursion for further candidates.)
//T.C       : O(2^T)
//S.C       : O(T)
//-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void findCombination(int start, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result){
        if(target==0){
            result.push_back(current);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++){
            if(candidates[i]>target){
                break;
            }
            current.push_back(candidates[i]);
            findCombination(i, candidates, target-candidates[i], current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>current;
        sort(candidates.begin(), candidates.end()); //optional
        findCombination(0, candidates, target, current, result);
        return result;
        
    }
};
//-----------------------------------------------------------------------------------------------------------------
//------------------------------Solution - in - Java -----------------------------------------------------------

//Approach 1 : Backtracking
//T.C        : O(2^T)
//S.C        : O(T)
//------------------------------------------------------------------------------------------------------------------
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> subSeq = new ArrayList<>();
        solve(candidates, target, ans, 0, subSeq);
        return ans;
    }

    private void solve(int[] candidates, int target, List<List<Integer>> ans, int i, List<Integer> subSeq) {
        if (i == candidates.length) {
            if (target == 0) {
                ans.add(new ArrayList<>(subSeq));
            }
            return;
        }

        if (candidates[i] <= target) {
            subSeq.add(candidates[i]);
            solve(candidates, target - candidates[i], ans, i, subSeq);
            subSeq.remove(subSeq.size() - 1);
        }
        solve(candidates, target, ans, i + 1, subSeq);
    }
}
//------------------------------------------------------------------------------------
