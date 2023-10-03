def KMP(pat, txt):
    m = len(pat)
    n = len(txt)
 
    lps = [0]*m
    
 
    # calculate lps[] array
    LPSarray(pat, m, lps)
    j = 0  # index for pattern
    i = 0  # index for text
    while (n - i) >= (m - j):
        if pat[j] == txt[i]:
            i += 1
            j += 1
 
        if j == m:
            print("Pattern matched at index " + str(i-j))
            j = lps[j-1]
 
        elif i < n and pat[j] != txt[i]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
 
 
# Function to compute LPS array
def LPSarray(pat,m,lps):
    length = 0
    i = 1
    lps[0] = 0
    while i < m:
        if pat[i] == pat[length]:
            lps[i] = length
            length += 1
            i += 1
        else:
            if length != 0:
                length = lps[length-1]
            else:
                lps[i] = 0
                i += 1

txt = input("Enter text:")
pat = input("Enter pattern:")
KMP(pat, txt)