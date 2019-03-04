def hasPath(matrix, rows, cols, path):
	for i in range(len(matrix)):
		vis = [0] * len(matrix)
		result = onepath(matrix, rows, cols, path, i, vis)
		if result == True: return True
	return False

def onepath(matrix, rows, cols, left_path, start, vis):
	
	row = start // cols
	col = start % cols
	# print('start:', start, 'row:', row, 'col:', col)
	# print('number:', matrix[start], 'left_path:', left_path)
	# print('---------------------')
	if matrix[start] != left_path[0]: return False
	else:
		vis[start] = 1
		if len(left_path) == 1: return True
		elif len(left_path) > 1:
			up, down, left, right = False, False, False, False
			if row > 0 and vis[start - cols] == 0 : up = onepath(matrix, rows, cols, left_path[1:], start - cols, vis)
			if row < rows - 1 and vis[start + cols] == 0: down = onepath(matrix, rows, cols, left_path[1:], start + cols, vis)
			if col > 0 and vis[start - 1] == 0: left = onepath(matrix, rows, cols, left_path[1:], start - 1, vis)
			if col < cols - 1 and vis[start + 1] == 0: right = onepath(matrix, rows, cols, left_path[1:], start + 1, vis)
			result = up or down or left or right
			if result == True: return True
			else: 
				vis[start] = 0
				print("after turn left_path:", left_path)
				return False


matrix =  ['a', 'b', 'c', 'e', 's', 'f', 'c', 's', 'a,', 'd', 'e', 'e']
path = ['b','c','c','e','d']
path = ['a', 'b', 'c', 'b']
result = hasPath(matrix, 3, 4, path)
print(result)