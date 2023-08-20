class Solution {
public:


    void groupSortParcours(vector<int>& group_vector,vector<bool>& vu,vector<int>& group,vector<int>& sorted_vector,int element_index,vector<vector<int>>& beforeItems,bool& impossible)
    {
        vu[element_index]=true;
        for(int item_before:beforeItems[group_vector[element_index]])
        {
            if(group[item_before]==group[group_vector[0]])
            {
                int item_before_index = find(group_vector.begin(), group_vector.end(), item_before)-group_vector.begin();

                if(!vu[item_before_index])
                {groupSortParcours(group_vector,vu,group,sorted_vector,item_before_index,beforeItems,impossible);}
                else if(find(sorted_vector.begin(), sorted_vector.end(),item_before) == sorted_vector.end()){
                     impossible=true;
                }
                
            }
        }
        sorted_vector.push_back(group_vector[element_index]);
    }

    void itemsSortParcours(vector<vector<int>>& groupAnswer,vector<bool>& vu,vector<int>& group,vector<int>& ans,int element,vector<vector<int>>& beforeItems,bool& impossible)
    {
        vu[element]=true;
        if(group[element]!=-1)
        {
            for(int item:groupAnswer[group[element]])
            {
                vu[item]=true;
            }
        }

        if(group[element]!=-1)
        {
            for(int item:groupAnswer[group[element]])
        {
            for(int item_before:beforeItems[item])
            {
                if(group[item_before]!=group[item])
                {
                    if(!vu[item_before]) itemsSortParcours(groupAnswer,vu,group,ans,item_before,beforeItems,impossible);
                    else if((find(ans.begin(), ans.end(),item_before) == ans.end())&&(group[item]!=group[item_before]))
                    {
                        impossible = true;
                    }
                }
                
            }
        }
        }
        else{
            for(int item_before:beforeItems[element])
            {
                if(group[item_before]!=group[element])
                {
                    if(!vu[item_before]) itemsSortParcours(groupAnswer,vu,group,ans,item_before,beforeItems,impossible);
                    else if((find(ans.begin(), ans.end(),item_before) == ans.end())&&(group[element]!=group[item_before]))
                    {
                        impossible = true;
                    }
                }
                
            }
        }
        
        if(group[element]!=-1)
        {
            for(int item:groupAnswer[group[element]])
            {
                ans.push_back(item);
            }
        }
        else{ans.push_back(element);}
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> ans;
        bool impossible=false;

        //create a vector for each  group  that contains a solution if we only look at that vector
        vector<vector<int>> groupAnswer(m);
        for(int i=0;i<n;i++)
        {
            if(group[i]!=-1)
            {
                groupAnswer[group[i]].push_back(i);
            }
        }

        for(int i=0;i<groupAnswer.size();i++)
        {
            if(groupAnswer[i].size()!=0)
            {
                vector<int> sorted_vect;
                vector<bool> vu(groupAnswer[i].size(),false);
                for(int j=0;j<groupAnswer[i].size();j++)
                {
                    if(!vu[j]) groupSortParcours(groupAnswer[i],vu,group,sorted_vect,j,beforeItems,impossible);
                    if(impossible)return ans;
                }
                //if(sorted_vect.size()!=groupAnswer[i].size()){return ans;}
                groupAnswer[i]=sorted_vect;
            }
            
        }
        
        vector<bool> group_vu(n,false);
        for(int i=0;i<n;i++)
        {
            if(!group_vu[i]) itemsSortParcours(groupAnswer,group_vu,group,ans,i,beforeItems,impossible);
            if(impossible){
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
};