void DFS(int **grid, int ROW, int COL, int x, int y, int *area){

	//out of the grid
	if(x >= ROW || y >= COL || x < 0 || y < 0) return;

	//not the island
	if(grid[x][y]==0) return;

	//mark as visited and keep DFS the neighbor
	(*area)++;
	grid[x][y] = 0;
	DFS(grid, ROW, COL, x + 1, y, area);
	DFS(grid, ROW, COL, x - 1, y, area);
	DFS(grid, ROW, COL, x, y + 1, area);
	DFS(grid, ROW, COL, x, y - 1, area);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
	int max_area = 0;
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridColSize[0]; j++){
			if(grid[i][j]==1){
				int temp_area = 0;
				DFS(grid, gridSize, gridColSize[0], i, j, &temp_area);
				max_area = temp_area > max_area ? temp_area : max_area;
			}
		}
	}
	return max_area;
}