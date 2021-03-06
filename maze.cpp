#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
	if (sr < 0 || sr > nRows || sc < 0 || sc > nCols ||
		er < 0 || er > nRows || ec < 0 || ec > nCols )
		return false;

	if (sr == er && sc == ec)
		return true;

	maze[sr][sc] = '$';

	if (maze[sr - 1][sc] == '.')
		if (pathExists(maze, nRows, nCols, sr - 1, sc, sr, sc))
			return true;
	if (maze[sr + 1][sc] == '.')
		if (pathExists(maze, nRows, nCols, sr + 1, sc, sr, sc))
			return true;
	if (maze[sr][sc + 1] == '.')
		if (pathExists(maze, nRows, nCols, sr, sc + 1, sr, sc))
			return true;
	if (maze[sr][sc - 1] == '.')
		if (pathExists(maze, nRows, nCols, sr, sc - 1, sr, sc))
			return true;
	return false;
}
