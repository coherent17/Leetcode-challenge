#include <stdio.h>
#include <stdlib.h>

void DFS(int **image, int row, int col, int r, int c, int color, int newColor){
	//if the color of the pixel is same as the source, then color it with the newcolor
	if(image[r][c] == color){
		image[r][c] = newColor;
		//upper pixel
		if(r >=1) DFS(image, row, col, r - 1, c, color, newColor);

		//left pixel
		if(c >=1) DFS(image, row, col, r, c - 1, color, newColor);

		//right pixel
		if(c + 1 < col) DFS(image, row, col, r, c + 1, color, newColor);

		//bottom pixel
		if(r + 1 < row) DFS(image, row, col, r + 1, c, color, newColor);
	}
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
	*returnSize = imageSize;
	*returnColumnSizes = malloc(sizeof(int) * imageSize);
	for(int i = 0; i < imageSize; i++){
		(*returnColumnSizes)[i] = *imageColSize;
	}

	//if the source pixel is originally colored in newcolr
	if(image[sr][sc]==newColor) return image;

	DFS(image, imageSize, *imageColSize, sr, sc, image[sr][sc], newColor);
    return image;
}


void printImage(int **image, int row, int col){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("%d ", image[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//driven code

int main(){

	//malloc the memory space of the image
	int imageSize = 3;
	int imageColSize = 3;
	int **image = malloc(sizeof(int ) * imageSize);
	for(int i = 0; i < imageSize; i++){
		image[i] = malloc(sizeof(int ) * (imageColSize));
	}

	//set up the image
	image[0][0] = 1;
	image[0][1] = 1;
	image[0][2] = 1;
	image[1][0] = 1;
	image[1][1] = 1;
	image[1][2] = 0;
	image[2][0] = 1;
	image[2][1] = 0;
	image[2][2] = 1;


	printImage(image, imageSize, imageColSize);

	int returnSize;
	int *returnColumnSizes;
	image = floodFill(image, imageSize, &imageColSize, 1, 1, 2, &returnSize, &returnColumnSizes);

	printImage(image, imageSize, imageColSize);
	return 0;
}