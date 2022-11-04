class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        stack_size = 0
        for i in range(len(s)):
            if s[i] in [ '(','{','[' ]:
                stack.append(s[i])
                stack_size+=1
                continue
            if s[i]== ']':
                if stack_size>0 and stack[stack_size-1]=='[':
                    stack.pop()
                    stack_size-=1
                    continue
                else:
                    return False
            if s[i]== '}':
                if stack_size>0 and stack[stack_size-1]=='{':
                    stack.pop()
                    stack_size-=1
                    continue
                else:
                    return False
            if s[i]== ')':
                if stack_size>0 and stack[stack_size-1]=='(':
                    stack.pop()
                    stack_size-=1
                    continue
                else:
                    return False
        if stack_size>0:
            return False
        return True