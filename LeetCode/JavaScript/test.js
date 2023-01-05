let emptyObj = {};
emptyObj['entry'] = 'check';


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
console.log(obj);
