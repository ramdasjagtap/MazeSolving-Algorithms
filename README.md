# MazeSolving-Algorithms

Maze-solving logic for a small robot, written in C.

## Wall follower (`mazesolver_algorithms/wallfollower.c`)

The robot has three wall sensors (left, front, right; 1 means a wall is there)
and two wheels. It follows the left-hand rule:

1. No walls at all → it is out of the maze, so stop
2. No wall on the left → turn left and go forward
3. Otherwise, no wall on the right → turn right and go forward
4. Otherwise, no wall in front → go forward
5. Walls everywhere → turn around

The program reads one set of sensor values and prints the move it would make.

## Try it

```
gcc mazesolver_algorithms/wallfollower.c -o wallfollower
echo "1 0 1" | ./wallfollower     # left wall, no right wall, front wall
```
