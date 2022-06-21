void DFS(char **grid, int ROW, int COL, int x, int y){

	//out of the grid
	if(x >= ROW || y >= COL || x < 0 || y < 0) return;

	//return if the neighbor is not a land
	if(grid[x][y]=='0') return;

	//mark as visted, so that it will not be visited again
	grid[x][y] = '0';

	//keep dfs the neighbor
	DFS(grid, ROW, COL, x - 1, y); //up
	DFS(grid, ROW, COL, x + 1, y); //bottom
	DFS(grid, ROW, COL, x, y + 1); //right
	DFS(grid, ROW, COL, x, y - 1); //left
}

bool isIsland(char gridChar){
	bool result = (gridChar=='1') ? true : false;
	return result;
}

int numIslands(char** grid, int gridSize, int* gridColSize){
	int land = 0;
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridColSize[0]; j++){
			if(isIsland(grid[i][j])){
				DFS(grid, gridSize, gridColSize[0], i, j);
				land++;
			}
		}
	}
	return land;
}