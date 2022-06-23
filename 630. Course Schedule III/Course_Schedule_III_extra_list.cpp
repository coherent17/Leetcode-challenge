class Solution {
public:
	static bool compare(vector <int> a, vector <int> b){
		return a[1] < b[1];
	}

    int scheduleCourse(vector<vector<int>>& courses) {
	    sort(courses.begin(), courses.end(), compare);
		vector <int> valid_list;
		int time = 0;
		for(int i = 0; i < (int)courses.size(); i++){
			if(time + courses[i][0] <= courses[i][1]){
				valid_list.push_back(courses[i][0]);
				time += courses[i][0];
			}
            
			else{
				int max_j_index = 0;
				for(int j = 1; j < valid_list.size(); j++){
					if(valid_list[j] > valid_list[max_j_index]) max_j_index = j;
				}

				if(valid_list.size() > max_j_index && valid_list[max_j_index] > courses[i][0]){
					time += courses[i][0] - valid_list[max_j_index];
					valid_list[max_j_index] = courses[i][0];
				}
			}
		}
        return valid_list.size();
    }
};