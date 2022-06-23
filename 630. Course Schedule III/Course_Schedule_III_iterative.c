int compare(const void *a, const void *b){
	int last_day_a = (*(int **)a)[1];
	int last_day_b = (*(int **)b)[1];
	return last_day_a > last_day_b;
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize){
	qsort(courses, coursesSize, sizeof(int **), compare);

	int time = 0;
	int count = 0;

	for(int i = 0; i < coursesSize; i++){
		if(time + courses[i][0] <= course[i][1]){
			count++;
			time += courses[i][0];
		}

		//find a maximum duration taken course
		else{
			int max_i = i;
			for(int j = 0; j < i; j++){
				if(course[j][0] > course[max_i][0]) max_i = j;
			}

			//update the time if replace max_ith course with ith class
			if(max_i != i) time += courses[i][0] - course[max_i][0];

			//mark as -1 so that we will not take this class anymore
			course[max_i][0] = -1;
		}
	}
	return count;
}