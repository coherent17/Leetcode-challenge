void DFS(int **grid, int ROW, int COL, int x, int y){

	//out of the grid
	if(x >= ROW || y >= COL || x < 0 || y < 0) return;

	//not the island
	if(grid[x][y]!=0) return;

	//mark as visited and keep DFS the neighbor
	grid[x][y] = 2;
	DFS(grid, ROW, COL, x + 1, y);
	DFS(grid, ROW, COL, x - 1, y);
	DFS(grid, ROW, COL, x, y + 1);
	DFS(grid, ROW, COL, x, y - 1);
}

//DFS the island that the boundary is contain the grid boundary
//and DFS the remaining island

int closedIsland(int** grid, int gridSize, int* gridColSize){
	
	//DFS for the boundary that is next to the grid boundary
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridColSize[0]; j++){
			if(i==0 || j==0 || i==gridSize - 1 || j == gridColSize[0] - 1){
				if(grid[i][j]==0) DFS(grid, gridSize, gridColSize[0], i, j);
			}
		}
	}

	//DFS the remaining island
	int lands = 0;
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridColSize[0]; j++){
			//ignore the water and the land that next to the grid boundary
			if(grid[i][j]!=0) continue;
			DFS(grid, gridSize, gridColSize[0], i, j);
			lands++;
		}
	}
	return lands;
}