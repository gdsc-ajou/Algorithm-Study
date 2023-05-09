class Solution:
    def isPalindrome(self, s: str) -> bool:
        remove = re.findall(r'[0-9a-zA-Z]+', s.lower())
        return ''.join(remove) == ''.join(remove)[::-1]
        
