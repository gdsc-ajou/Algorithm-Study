class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)

        while length:
            for i in range(0, len(s) - length + 1):
                string = s[i:i+length]
                if string == string[::-1]:
                    return string

            length -= 1
            
