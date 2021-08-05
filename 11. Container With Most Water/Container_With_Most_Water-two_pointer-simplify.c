#include <stdio.h>

int maxArea(int *, int);

int main(){
    int height[]={1,8,6,2,5,4,8,3,7};
    int Area=maxArea(height, sizeof(height)/sizeof(int));
    printf("%d\n",Area);
    return 0;
}

//time complexity:O(n)
int maxArea(int* height, int heightSize){
    int left=0;
    int right=heightSize-1;
    int max_area=0;
    while(left<right){
        int current_area=(height[left]<height[right]?height[left]:height[right])*(right-left);
        max_area=(current_area>max_area?current_area:max_area);

        //make min(height[left], height[right]) become greater, let the small one go to next index
        if(height[right]>height[left]) left+=1;
        else right-=1;
    }
    return max_area;
}