char* reverseOnlyLetters(char* s) {
    int idx = 0;
    int i = 0;
    while(*(s + idx) != '\0')
    {
        idx++;
    }
    idx--;
    while(i < idx){
        if(*(s + i) >= 'a' && *(s + i) <= 'z'|| *(s + i) >= 'A' && *(s + i) <= 'Z'){
            
        
            if(*(s + idx) >= 'a' && *(s + idx) <= 'z' || *(s + idx) >= 'A' && *(s + idx) <= 'Z')
            {
             /*   *(s + i) ^= *(s + idx);
                *(s + idx) ^= *(s + i);
                *(s + i) ^= *(s + idx);
                */
                char temp = *(s + i);
                *(s + i) = *(s + idx);
                *(s + idx) = temp;
                i++;
                idx--;
            }
            else
            {
                idx--;
            }
        }
        else
        {
            i++;
        }
    }
    return s;
} 

