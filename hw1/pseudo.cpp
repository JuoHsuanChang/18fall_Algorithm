smallMat(size, mat1, mat2)
	if size <= 158
		////SCHOOL-BOOK METHOD
		for i = 0 --> size, j = 0 --> size
			mat[i][j] = 0;
		for i = 0 --> size, j = 0 --> size
			for k = 0 --> size
				mat[i][j] += mat1[i][k] * mat2[k][j];

	else
		////METHOD 1 & 2
		if size % 2 == 1
			在column與row增加一行zero vector;
		 
		(令pi = mati1 * mati2)
		mat11 = mat1A + mat1D; mat12 = mat2A + mat2D;
		mat21 = mat1C + mat1D; mat22 = mat2A;
		...
		mat71 = mat1B - mat1D; mat72 = mat2C + mat2D;
		
		for i = 1 --> 7
			pi = smallMat(newSize, mati1, mati2);

		(加總)
		for i = 0 --> newSize - 1, j = 0 --> newSize - 1
			mat = p1 + p4 - p5 - p7;
		for i = 0 --> newSize - 1, j = newSize --> size
			mat = p3 + p5;
		for i = newSize --> size, j = 0 --> newSize - 1
			mat = p2 + p4;
		for i = newSize --> size, j = newSize --> size
			mat = p1 + p3 - p2 + p6;
					  
	return mat;
	
main function
	[matSiz, mat1, mat2] = getMat(); (讀入方陣大小與兩方陣)
	mat = smallMat(matSiz, mat1, mat2);
	outfile(mat); (輸出計算結果)
	
	
	
	
	/////////METHOD 1!!!!!!!!
smallMat(size, mat1, mat2)
	if size == 2
		return mat1 * mat2;
	else
		if size % 2 == 1
			在column與row增加一行zero vector;
		 
		(將mat1, mat2拆為4個newSize的Martix);
			   [mat1A | mat1B]
		mat1 = [------+------]
			   [mat1C | mat1D];
			   
			   [mat2A | mat2B]
		mat2 = [------+------]
			   [mat2C | mat2D];
		
		for i = 0 --> newSize - 1, j = 0 --> newSize - 1
			mat = smallMat(newSize, mat1A, mat2A)
				+ smallMat(newSize, mat1B, mat2C);
		
		for i = 0 --> newSize - 1, j = newSize --> size
			mat = smallMat(newSize, mat1A, mat2B)
				+ smallMat(newSize, mat1B, mat2D);

		for i = newSize --> size, j = 0 --> newSize - 1
			mat = smallMat(newSize, mat1C, mat2A)
				+ smallMat(newSize, mat1D, mat2C);
		
		for i = newSize --> size, j = newSize --> size
			mat = smallMat(newSize, mat1C, mat2B)
				+ smallMat(newSize, mat1D, mat2D);
					  
	return mat;
	
main function
	[matSiz, mat1, mat2] = getMat(); (讀入方陣大小與兩方陣)
	mat = smallMat(matSiz, mat1, mat2);
	outfile(mat); (輸出計算結果)
	
	
	
smallMat(size, mat1, mat2)
	if size == 2
		return mat1 * mat2;
	else
		if 矩陣size為奇數
			在column與row增加一行


