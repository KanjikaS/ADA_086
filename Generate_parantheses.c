/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void solve(int n, int m, char ***ans, char *s, int *returnSize) {
    if (n == 0 && m == 0) {
        (*returnSize)++;
        (*ans) = (char **)realloc(*ans, (*returnSize) * sizeof(char *));
        (*ans)[(*returnSize) - 1] = strdup(s);
        return;
    }
    if (n > 0) {
        strcat(s, "(");
        solve(n - 1, m, ans, s, returnSize);
        s[strlen(s) - 1] = '\0';
    }
    if (m > n) {
        strcat(s, ")");
        solve(n, m - 1, ans, s, returnSize);
        s[strlen(s) - 1] = '\0';
    }
}
char ** generateParenthesis(int n, int* returnSize){
char **ans = NULL;
    char *str = (char *)malloc((2 * n + 1) * sizeof(char));
    str[0] = '\0';

    *returnSize = 0;
    solve(n, n, &ans, str, returnSize);

    free(str);

    return ans;
}
