class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = {}
        
        for i, str in enumerate(strs):
            count = [0] * 26
            for char in str:
                count[ord(char) - ord('a')] += 1
            hash.setdefault(tuple(count), []).append(str)

        # 转换成数组
        return list(hash.values())