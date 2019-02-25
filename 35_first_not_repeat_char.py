from collections import Counter

def FirstNotRepeatingChar(s):
    # write code here
    counter = Counter()
    for i in range(len(s)):
        counter[s[i]] += 1
    for k,v in counter.items():
        if v == 1: return s.index(k)
    return -1

# s = "google"
s = "NXWtnzyoHoBhUJaPauJaAitLWNMlkKwDYbbigdMMaYfkVPhGZcrEwp"
print(FirstNotRepeatingChar(s))