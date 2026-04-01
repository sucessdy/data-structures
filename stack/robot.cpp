// 2751. Robot Collisions  
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int,int,char,int>> robots;
        
        // {position, health, direction, original index}
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // sort by position
        sort(robots.begin(), robots.end());
        
        stack<int> st; // store indices of robots in 'robots'
        
        for(int i = 0; i < n; i++) {
            auto &[pos, health, dir, idx] = robots[i];
            
            if(dir == 'R') {
                st.push(i);
            } else {
                // dir == 'L'
                while(!st.empty() && get<2>(robots[st.top()]) == 'R' && health > 0) {
                    int j = st.top();
                    int &r_health = get<1>(robots[j]);
                    
                    if(r_health < health) {
                        // R dies
                        st.pop();
                        health--;
                        r_health = 0;
                    }
                    else if(r_health > health) {
                        // L dies
                        r_health--;
                        health = 0;
                    }
                    else {
                        // both die
                        r_health = 0;
                        health = 0;
                        st.pop();
                    }
                }
            }
        }
        
        // collect survivors
        vector<pair<int,int>> survivors; // {index, health}
        
        for(auto &[pos, health, dir, idx] : robots) {
            if(health > 0) {
                survivors.push_back({idx, health});
            }
        }
        
        // sort by original index
        sort(survivors.begin(), survivors.end());
        
        vector<int> ans;
        for(auto &p : survivors) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};