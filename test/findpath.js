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
