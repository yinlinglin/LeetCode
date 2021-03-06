/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 8, 2013
 Problem:    Text Justification
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_68
 Notes:
 Given an array of words and a length L, format the text such that each line has exactly L 
 characters and is fully (left and right) justified.
 You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
 Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 Extra spaces between words should be distributed as evenly as possible. If the number of spaces 
 on a line do not divide evenly between words, the empty slots on the left will be assigned more 
 spaces than the slots on the right.
 For the last line of text, it should be left justified and no extra space is inserted between words.

 For example,
 words: ["This", "is", "an", "example", "of", "text", "justification."]
 L: 16.
 Return the formatted lines as:
 [
 "This    is    an",
 "example  of text",
 "justification.  "
 ]
 Note: Each word is guaranteed not to exceed L in length.
 Corner Cases:
 A line other than the last line might contain only one word. What should you do in this case?
 In this case, that line should be left-justified.

 Solution: ...
 */

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0;
        while (i < words.size())
        {
            int length = words[i].size();
            int j = i + 1;
            while (j < words.size() && length + words[j].size() + (j-i) <= L)
                length += words[j++].size();
            // build line
            string s(words[i]);
            bool isLastLine = (j == words.size());
            bool oneWord = (j == i + 1);
            int even = isLastLine || oneWord ? 1 : (L - length) / (j - i - 1);
            int extra = isLastLine || oneWord ? 0 : (L - length) % (j - i - 1);
            for (int k = i + 1; k < j; ++k)
            {
                int space = even + ((extra-- > 0) ? 1 : 0);
                while (space--) s += " ";
                s += words[k];
            }
            while (s.size() < L) s += " ";
            // push line
            res.push_back(s);
            i = j;
        }
        return res;
    }
};