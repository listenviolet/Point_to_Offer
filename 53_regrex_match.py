def match(s, pattern):
	if s == pattern:
		return True

	if len(pattern) > 1 and pattern[1] == '*':
		if s and (s[0] == pattern[0] or pattern[0] == '.'):
			return match(s, pattern[2:]) or match(s[1:], pattern)
		else:
			return match(s, pattern[2:])

	elif s and pattern and (s[0] == pattern[0] or pattern[0] == '.'):
		return match(s[1:], pattern[1:])

	return False

s = "aa.a"
pattern = "ab*a"
print(match(s, pattern))