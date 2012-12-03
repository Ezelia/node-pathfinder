node-pathfinder
===============
This module is a port of an [HTML5 MMORPG Project](http://ezelia.com/en)

A native nodejs module implementing A* with JPS path finding algorithm.

A* Algorithm is borrowed from a C implementation by [Ari Rahikkala](https://github.com/arirahikkala) 

I just converted it to C++ and added NodeJS addon interface + node-gyp bindings




Setup 
=====

    npm install node-pathfinder



usage example
=============

```js
var findpath = require('../').AStarJPS;

var grid = [];
for (var x =0; x<200; x++)
{
    if (grid[x] === undefined) grid[x] = [];
    for (var y=0; y<200; y++)
    {
	if (x >= 2 && x < 130 && y == 3) //making a wall
	    grid[x][y] = 1;
	else
	    grid[x][y] = 0;
    }
}

//find path from (5,1) to (5,5)
var result = findpath(grid, 5, 1, 5, 5);

//print result
console.log(result);
```



[View Copyright notice of astar-jps C Library](https://github.com/arirahikkala/astar-jps)



Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of
      conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice, this list
      of conditions and the following disclaimer in the documentation and/or other materials
      provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
