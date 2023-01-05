/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];
    let len = -1;
    for(let i=0 ; i<s.length ; i++){
        if(s[i]=== ')'){
            console.log("  check: )");
            if(len<0)
                return false;
            if(stack[len]!== '(' )
                return false;
            else{
                stack.pop();
                len--;
            }
        }
        else if(s[i]=== '}'){
            if(len<0)
                return false;
            if(stack[len]!== '{' )
                return false;
            else{
                stack.pop();
                len--;
            }
        }
        else if(s[i]=== ']'){
            if(len<0)
                return false;
            if(stack[len]!== '[' )
                return false;
            else{
                stack.pop();
                len--;
            }
        }
        else{
            stack.push(s[i]);
            len++;
        }
    }

    if(len>=0)
        return false;

    return true;
};