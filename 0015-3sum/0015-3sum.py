class Solution(object):
    def threeSum(self, nums):
        # 1. Sort the array in place and find its length
        nums.sort()
        n = len(nums)
        ans = []

        for i in range(n):
            # 2. Optimization: If the current number is positive, 3 positive numbers can't sum to 0
            if nums[i] > 0:
                break 
                
            # 3. Skip duplicate values for the first element to avoid duplicate triplets
            if i > 0 and nums[i] == nums[i-1]:
                continue

            # 4. Initialize two pointers
            low, high = i + 1, n - 1

            while low < high:
                summ = nums[i] + nums[low] + nums[high]
                
                if summ == 0:
                    ans.append([nums[i], nums[low], nums[high]])
                    
                    # Move pointers inward after finding a valid triplet
                    low += 1
                    high -= 1
                    
                    # Skip duplicate values for the second and third elements
                    while low < high and nums[low] == nums[low - 1]:
                        low += 1
                    while low < high and nums[high] == nums[high + 1]:
                        high -= 1

                elif summ > 0:
                    high -= 1  # Sum too big -> make right side smaller
                else:
                    low += 1   # Sum too small -> make left side bigger
        
        return ans
