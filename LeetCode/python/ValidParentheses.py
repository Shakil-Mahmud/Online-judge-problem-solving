class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        last=-1
        for i in range(len(s)):
            if s[i] == ')':
                if last<0:
                    return False
                if stack[last]!= '(':
                    return False
                stack.pop()
                last-=1
                continue
    
            if s[i] == '}':
                if  last<0:
                    return False
                if stack[last]!= '}':
                    return False
                stack.pop()
                last-=1
                continue
            
            if s[i] == ']':
                if  last<0:
                   return False
                if stack[last]!= '[':
                    return False
                stack.pop()
                last-=1
                continue
                
            last+=1
            stack.append(s[i])
        
        if len(stack)>0:
            return False

        return True
        