int countNonWhiteCharacters(const char *input) {
    int length = 0;
    for(int i = 0; i < strlen(input); i++) {
        if (input[i] != ' ') {
            length++;
        }
    }
    return length;
}