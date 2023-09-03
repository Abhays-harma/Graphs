//Leetcode:433-> Minimum Genetic Mutation

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> strbank(bank.begin(),bank.end());
        set<string> visited;
        visited.insert(startGene);
        queue<string> que;
        que.push(startGene);
        int level=0;

        while(!que.empty())
        {
            int n=que.size();
            while(n--)
            {
                string curr=que.front();
                que.pop();
                if(curr==endGene)
                {
                    return level;
                }

                for(auto &ch:"ACGT")
                {
                    for(int i=0;i<curr.size();i++)
                    {
                        string temp=curr;
                        temp[i]=ch;
                        if(visited.find(temp)==visited.end() && strbank.find(temp)!=strbank.end())
                        {
                            visited.insert(temp);
                            que.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
