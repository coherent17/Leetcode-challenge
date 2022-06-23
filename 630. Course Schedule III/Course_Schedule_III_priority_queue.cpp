class Solution {
public:
	static bool compare(vector <int> a, vector <int> b){
		return a[1] < b[1];
	}

    int scheduleCourse(vector<vector<int>>& courses) {
	    sort(courses.begin(), courses.end(), compare);
		priority_queue<int> valid_list;
		int time = 0;
		for(int i = 0; i < (int)courses.size(); i++){
			if(time + courses[i][0] <= courses[i][1]){
				valid_list.push(courses[i][0]);
				time += courses[i][0];
			}
            
			else{
				if(!valid_list.empty() && valid_list.top() > courses[i][0]){
					time += courses[i][0] - valid_list.top();
					valid_list.pop();
					valid_list.push(courses[i][0]);
				}
			}
		}
        return valid_list.size();
    }
};