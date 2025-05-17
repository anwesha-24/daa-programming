#include <stdio.h>
#include <string.h>

int lcs(char *str1, char *str2, char *lcs_str) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    int index = dp[len1][len2];
    lcs_str[index] = '\0';
    int i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs_str[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return dp[len1][len2];
}

int main() {
    char str1[100], str2[100], lcs_str[100];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int length = lcs(str1, str2, lcs_str);
    printf("Length of Longest Common Subsequence: %d\n", length);
    printf("Longest Common Subsequence: %s\n", lcs_str);

    return 0;
}
