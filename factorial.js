//factorial.js

.pragma library //共享

var factorialCount = 0;

function factorial(a) {
    a = parseInt(a);

    if(a>0) return a * factorial(a-1);

    factorialCount +=1;

    return 1;
}

function factorialCallCount() {
    return factorialCount;
}
