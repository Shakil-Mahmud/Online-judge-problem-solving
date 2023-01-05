/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length!==t.length)
        return false;

    let s_letters = [];
    let t_letters = [];
    for(let i=0 ; i<27 ; i++){
        s_letters.push(0); 
        t_letters.push(0); 
    }
    for(let i=0 ; i<s.length ; i++){
        s_letters[ s[i].charCodeAt(0) - 'a'.charCodeAt(0) ] ++;
        t_letters[ t[i].charCodeAt(0) - 'a'.charCodeAt(0) ] ++;
    }

    for(let i=0 ; i<26 ; i++)
        if(s_letters[i]!==t_letters[i])
            return false;

    return true
};