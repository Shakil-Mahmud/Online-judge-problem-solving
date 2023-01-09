let emptyObj = {};
emptyObj['entry'] = 'check';
emptyObj[5] = 2;
emptyObj[5]++;

// console.log(emptyObj);

let obj = {
    car: 300, 
    bike: 60, 
    motorbike: 200, 
    airplane: 1000,
    helicopter: 400, 
    rocket: 8 * 60 * 60
};

if(typeof obj['car'] !== 'undefined'){} //exist

obj = Object.entries(obj).sort( ([,a],[,b]) => a-b );
obj[4] = 1;
// console.log(obj);


var insert = function(intervals, newInterval) {
    if(intervals.length===0)
        return newInterval;
    
    let start = newInterval[0] < intervals[0][0] ? newInterval[0] : intervals[0][0];
    let end = newInterval[1] > intervals[ intervals.length-1 ][1]? newInterval[1] : intervals[ intervals.length-1 ][1];

    return [start, end];
};

// console.log(insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]) );
console.log(insert([], [4,8]) );