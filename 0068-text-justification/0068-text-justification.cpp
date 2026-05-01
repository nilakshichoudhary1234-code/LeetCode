class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;

        while (i < words.size()) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            // 1. Greedy: See how many words fit in this line
            while (j < words.size() && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }

            string line = "";
            int numWords = j - i;
            int numSpaces = maxWidth - (lineLength - (numWords - 1));

            // 2. Case: Last line or a line with only one word (Left Justified)
            if (j == words.size() || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (line.length() < maxWidth) line += " ";
                }
                // Pad remaining spaces at the end
                while (line.length() < maxWidth) line += " ";
            } 
            // 3. Case: Fully Justified
            else {
                int baseSpaces = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToAdd = baseSpaces + (extraSpaces-- > 0 ? 1 : 0);
                        line.append(spacesToAdd, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; // Move to the next set of words
        }

        return result;
    }
};