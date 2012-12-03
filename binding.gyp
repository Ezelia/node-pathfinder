{
  "targets": [
    {
	"target_name": "pathfinder",
	"cflags": ['-march=native', '-std=c99',  '-Wall'],
	"sources": ["src/IndexPriorityQueue.cc", "src/AStar.cc", "src/pathfinder.cc"  ]
    }
  ]
}
