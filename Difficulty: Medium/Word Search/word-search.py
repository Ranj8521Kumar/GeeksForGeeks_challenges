class Solution:
	def isWordExist(self, mat, word):
	    n, m = len(mat), len(mat[0])
	    
	    visited = [[False]*m for i in range(n)]
	    
		def dfs(mat, i, j, word, k):
		    if k == len(word):
		        return True
		        
		    if 0 <= i < n and 0 <= j < m and not visited[i][j]:
		        if mat[i][j] == word[k]:
		            visited[i][j] = True
		            ans = (
		                dfs(mat, i-1, j, word, k+1) or
		                dfs(mat, i+1, j, word, k+1) or
		                dfs(mat, i, j-1, word, k+1) or
		                dfs(mat, i, j+1, word, k+1)
		                )
		            visited[i][j] = False
		            return ans
		       
		    return False
	    
	    for i in range(n):
	        for j in range(m):
	            if dfs(mat, i, j, word, 0):
	                return True
	    
	    return False
#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for tt in range(T):
        n = int(input())
        m = int(input())
        mat = []
        for i in range(n):
            a = list(input().strip().split())
            b = []
            for j in range(m):
                b.append(a[j][0])
            mat.append(b)
        word = input().strip()
        obj = Solution()
        ans = obj.isWordExist(mat, word)
        if ans:
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends