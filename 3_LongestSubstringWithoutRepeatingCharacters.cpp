#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		// TODO: char - 65 => map
        int charsMap[256];
		memset(charsMap, -1, sizeof(charsMap));

		int maxSize = 0;
		int lastPos = -1;
		int strSize = s.size();
		char c;
		for (int i = 0; i < strSize; ++i) {
			c = s[i];
			if (charsMap[c] != -1 && lastPos < charsMap[c]) {
				lastPos = charsMap[c];
			}
			if (i - lastPos > maxSize) {
				maxSize = i - lastPos;
			}
			charsMap[c] = i;
		}

		return maxSize;
    }
};

int main()
{
	Solution solution;
	printf("%d\n", solution.lengthOfLongestSubstring("abcdefgabcsjfiaasjkdasdjinqwms"));
}