def multiply(A):
	C = [1] * len(A)
	D = [1] * len(A)
	B = [1] * len(A)
	for i in range(1, len(A), 1):
		C[i] = A[i - 1] * C[i - 1]

	for i in range(len(A) - 2, -1, -1):
		D[i] = A[i + 1] * D[i + 1]

	for i in range(len(A)):
		B[i] = C[i] * D[i]

	return B

A = [1,2,3,4,5]
print(multiply(A))