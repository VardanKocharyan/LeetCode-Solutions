char* reverseVowels(char* s) 
{
    int idx2 = strlen(s) - 1;
    int idx1 = 0;
    
    while(idx1 < idx2)
    {
        if(idx1 < idx2 && s[idx1] != 'a' && s[idx1] != 'e' && s[idx1] != 'i' && s[idx1] != 'o' &&s[idx1] != 'u' && s[idx1] != 'A' && s[idx1] != 'E' && s[idx1] != 'I' && s[idx1] != 'O' && s[idx1] != 'U')
            ++idx1;

        else if(idx1 < idx2 && s[idx2] != 'a' && s[idx2]  != 'e' && s[idx2]  != 'i'&& s[idx2]  != 'o' && s[idx2] != 'u' && s[idx2] != 'A' && s[idx2] != 'E' && s[idx2] != 'I' && s[idx2] != 'O' && s[idx2] != 'U')
            --idx2;

        else if(idx1 < idx2){
            *(s + idx1) ^= *(s + idx2);
            *(s + idx2) ^= *(s + idx1);
            *(s + idx1) ^= *(s + idx2);
            ++idx1;
            --idx2;
    }
        
    }
    return s;

}
