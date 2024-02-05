
/*You are required to complete this function */

string encode(string src)
{
    string result = "";
    int count = 1;
    char currentChar = src[0];

    for (int i = 1; i < src.length(); i++) {
        if (src[i] == currentChar) {
            count++;
        } else {
            result += currentChar + to_string(count);
            currentChar = src[i];
            count = 1;
        }
    }

    result += currentChar + to_string(count);

    return result;
}     