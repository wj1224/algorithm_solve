class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 1, end = nums.size() - 2;
        int answer;
        
        if (nums[0] > nums[nums.size() - 1])
            answer = 0;
        else
            answer = nums.size() - 1;
        for (int i=start; i<=end; i++)
        {
            if ((nums[i - 1] < nums[i]) && (nums[i] > nums[i + 1]))
            {
                answer = i;
                break;
            }
        }
        return answer;
    }
};
