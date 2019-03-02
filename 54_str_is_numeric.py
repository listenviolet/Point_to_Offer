def isNumeric(s):
	s = s.lower()
	ind = -1
	ind = s.find('e')

	if ind == -1:
		return isNumber(s)
	else:
		if ind == len(s) - 1: return False
		s_left = s[:ind]
		s_right = s[ind+1:]
		return isNumber(s_left, 0) and isNumber(s_right, 1)


def isNumber(s, flag = 0):
	if s[0] == '+' or s[0] == '-':
		s = s[1:]
	dot_num = 0
	for i in range(len(s)):
		if s[i] == '.':
			dot_num += 1
			if flag == 1: return False
			if dot_num > 1: return False
		elif ord(s[i]) > ord('9') or ord(s[i]) < ord('0'): return False
	return True

s1 = '+100'
s2 = '5e2'
s3 = "-123"
s4 = "3.1416"
s5 = "-1E-16"

s6 = "12e"
s7 = "1a3.14"
s8 = "1.2.3"
s9 = "+-5"
s10 = "12e+4.3"
s11 = "123.45e+6"
s12 = "1.79769313486232E+308"

# print(isNumeric(s1))
# print(isNumeric(s2))
# print(isNumeric(s3))
# print(isNumeric(s4))
# print(isNumeric(s5))
# print('--------------')
# print(isNumeric(s6))
# print(isNumeric(s7))
# print(isNumeric(s8))
# print(isNumeric(s9))
# print(isNumeric(s10))
# print(isNumeric(s11))
print(isNumeric(s12))