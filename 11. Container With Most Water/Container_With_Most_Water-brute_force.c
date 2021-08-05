#include <stdio.h>

int max(int, int);
int min(int, int);
int maxArea(int *, int);

int main(){
    int height[]={1,8,6,2,5,4,8,3,7};
    int Area=maxArea(height, sizeof(height)/sizeof(int));
    printf("%d\n",Area);
    return 0;
}

//time complexity:O(n^2):Time Limit Exceeded
int maxArea(int* height, int heightSize){
    int left,right;
    int max_area=0;
    for(left=0;left<heightSize-1;left++){
        for(right=left+1;right<heightSize;right++){
            int current_area=min(height[left],height[right])*(right-left);
            max_area=max(current_area, max_area);
        }
    }
    return max_area;
}

int max(int a, int b){
    return a>b?a:b;
}

int min(int a, int b){
    return a<b?a:b;
}