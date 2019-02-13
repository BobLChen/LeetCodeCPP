#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	unordered_map<int, int> numDict;
	numDict[nums[0]] = 0;

	for (int i = 1; i < nums.size(); ++i)
	{
		int complement = target - nums[i];
		auto it = numDict.find(complement);
		if (it != numDict.end())
		{
			result.push_back(i);
			result.push_back(it->second);
			return result;
		}
		numDict[nums[i]] = i;
	}

	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	auto result = twoSum(nums, 9);
	for (int i = 0; i < result.size(); ++i) {
		printf("%d ", result[i]);
	}
	printf("\n");
}