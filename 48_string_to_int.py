def StrToInt(s):
	if not s: return 0
	flag = 1
	start = 0
	res = -1
	# +XXX
	if s[0] == '+': 
		res = isInt(s, 1, len(s))
	# -XXX
	elif s[0] == '-':
		flag = -1
		res = isInt(s, 1, len(s))
	# XXX
	elif s[0] >= '0' and s[0] <= '9':
		res = isInt(s, 0, len(s))
	if res == -1: return False
	else: return flag * res

def isInt(s, start, length):
	number = 0
	if start >= length: return -1
	if s[start] <'0' or s[start] > '9': return -1
	else:
		number += ord(s[start]) - ord('0')
		for i in range(start + 1, length, 1):
			if s[i] >='0' and s[i] <= '9':
				number = number * 10 + ord(s[i]) - ord('0')
			else: return -1
	# 000
	if number == 0: return -1
	else: return number

s1 = '123'
s2 = '+123'
s3 = '-123'
s4 = '000'
s5 = '-000'
s6 = '+'
print(StrToInt(s1))
print(StrToInt(s2))
print(StrToInt(s3))
print(StrToInt(s4))
print(StrToInt(s5))
print(StrToInt(s6))
	