struct Node
{
	int id;
	vector<bool> visited;
	vector<string> words;
};

class Solution {
private:
	vector<vector<bool> > adj;
	vector<vector<string> > ans;

public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	wordList.insert(wordList.begin(), beginWord);
    	int len = wordList.size();
    	if(len == 1) return ans;
    	adj.resize(len);
    	for (int i = 0; i < len; ++i)
    	{
    		adj[i].resize(len);
    		for (int j = 0; j < len; ++j)
    		{
    			adj[i][j] = false;
    		}
    	}

    	for (int i = 0; i < len; ++i)
    	{
    		string cur_str = wordList[i]; 
    		for (int j = 0; j < len; ++j)
    		{
    			if(i == j) continue;
    			int tmp_dif = 0;
    			string com_str = wordList[j];
    			for (int k = 0; k < cur_str.length(); ++k)
    			{
    				if(cur_str[k] != com_str[k]) tmp_dif++;
    				if(tmp_dif > 1) break;
    			}
    			if(tmp_dif == 1){
    				adj[i][j] = true;
    			}	
    		}
    	}

    	Node start = {0, vector<bool>(len, false), vector<string>(1, beginWord)};
    	start.visited[0] = true;
    	queue<Node> que;
    	que.push(start);
    	int count_max = INT_MAX;
    	while(!que.empty()){
    		Node cur = que.front();
    		que.pop();
    		if(cur.words.size() > count_max) continue;
    		if(wordList[cur.id] == endWord){
    			ans.push_back(cur.words);
    			count_max = min( (int)cur.words.size(), count_max);
    			continue;
    		}
    		for (int i = 0; i < len; ++i)
    		{
    			if(adj[cur.id][i] && !cur.visited[i]){
    				vector<bool> tmp_bool = cur.visited;
    				vector<string> tmp_str_array = cur.words;
    				tmp_str_array.push_back(wordList[i]); 
    				tmp_bool[i] = true;
    				Node next = {i, tmp_bool, tmp_str_array};
    				que.push(next);
    			}
    		}
    	}

    	return ans;
    }
};
