// TC -> O(N)
class Solution {
public:
    string toGoatLatin(string sentence) {

        auto isStartsWithVowel = [](char& firstWord){
            char lower = tolower(firstWord);
            return (lower == 'a' || lower == 'e' || lower == 'u' || lower == 'i' || lower == 'o' );
        };

        istringstream iss(sentence);
        string word;
        string result;

        int index = 1;
        while(iss >> word){
            if(isStartsWithVowel(word[0])){
                word += "ma";
            }else{
                word = word.substr(1) + word[0] + "ma";
            }
            if(index > 1) result += " ";
            result += word + string(index, 'a');
            index++;
        }
    
    return result;
    }
};
