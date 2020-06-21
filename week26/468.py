class Solution:
    def validIPAddress(self, IP: str) -> str:
        if IP.find('.') > 0:
            strs = IP.split('.')
            if len(strs) != 4:
                return "Neither"
            for s in strs:
                if len(s) == 0 or (len(s) > 1 and s[0] == '0') or len(s) > 3:
                    return "Neither"
                try:
                    num = int(s)
                    if num > 255 or num < 0:
                        return "Neither"
                except ValueError:
                    return "Neither"
            return "IPv4"
        else:
            strs = IP.split(':')
            if len(strs) != 8:
                return "Neither"
            for s in strs:
                if len(s) == 0 or len(s) > 4:
                    return "Neither"
                try:
                    num = int(s, 16)
                except ValueError:
                    return "Neither"
            return "IPv6"