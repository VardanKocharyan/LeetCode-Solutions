char* longestCommonPrefix(char** strs, int strsSize) 
{
        if(strsSize)
        {
            for(int i = 0 ; strs[0][i] ; i++)
            {
                char ch = strs[0][i];
                for(int j = 0 ; j < strsSize ; j++)
                {
                    if(ch != strs[j][i] || ch == '\0')
                    {
                        strs[0][i] = '\0';
                        return strs[0];
                    }
                }
            }
            return strs[0];
        }
        return "";
}
